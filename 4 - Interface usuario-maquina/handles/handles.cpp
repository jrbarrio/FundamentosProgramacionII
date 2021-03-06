#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <string.h>

class TDrawWindow : public TWindow {
  public:
    TDrawWindow(TWindow* parent = 0);

  protected:
    bool CanClose();

    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;

TDrawWindow::TDrawWindow(TWindow* parent)
{
  Init(parent, 0, 0);
}

bool
TDrawWindow::CanClose()
{
  return MessageBox("�Realmente quieres salir?","Salir del programa",
						  MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES;
}

void
TDrawWindow::EvLButtonDown(uint, TPoint& point)
{
  char s[16];
  TClientDC dc(*this);

  wsprintf(s, "(%d,%d)", point.x, point.y);
  dc.TextOut(point, s, strlen(s));
}

void
TDrawWindow::EvRButtonDown(uint, TPoint& point)
{
  char cadena[]= "Jorge";
  TClientDC dc(*this);

  dc.TextOut(point, cadena, strlen(cadena));
  }

class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Mi propia ventana", new TDrawWindow));
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
