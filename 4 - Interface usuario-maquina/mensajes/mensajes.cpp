#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>

class Dibuja : public TWindow {
  public:
	 Dibuja(TWindow* parent = 0);

  protected:
    bool CanClose();

    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);

  DECLARE_RESPONSE_TABLE(Dibuja);
};

DEFINE_RESPONSE_TABLE1(Dibuja, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;

Dibuja::Dibuja(TWindow* parent)
{
  Init(parent, 0, 0);
}

bool
Dibuja::CanClose()
{
  return MessageBox("�Realmente quiere salir?",
  		"Salir del programa", MB_YESNO | MB_DEFBUTTON1 | MB_ICONQUESTION) == IDYES;
}

void
Dibuja::EvLButtonDown(uint, TPoint&)
{
  MessageBox("Has apretado el bot�n izquierdo.",
	 "Bot�n izquierdo", MB_OK | MB_ICONSTOP);
}

void
Dibuja::EvRButtonDown(uint, TPoint&)
{
  MessageBox("Has apretado el bot�n derecho.",
	 "Bot�n derecho", MB_OK | MB_ICONHAND);
}

class Vent_nom : public TApplication {
  public:
	 Vent_nom() : TApplication() {}

	 void InitMainWindow()
	 {
		TFrameWindow * p_tfr_win;
		p_tfr_win = new TFrameWindow(0, "Mi propia ventana",
		  new Dibuja);
		SetMainWindow( p_tfr_win );
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  Vent_nom nuevo;
  return nuevo.Run();
}