#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <classlib/arrays.h>
#include <stdlib.h>

#include "recursos.rc"

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TDrawWindow : public TWindow {
  public:
    TDrawWindow(TWindow* parent = 0);
   ~TDrawWindow()
    {
      delete DragDC;
      delete Pen;
      delete Line;
    }

    void SetPenSize(int newSize);

  protected:
    TDC* DragDC;
    int PenSize;
    TPen* Pen;
    TPoints* Line;

    bool CanClose();

    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);
    void EvMouseMove(uint, TPoint&);
    void EvLButtonUp(uint, TPoint&);
    void Paint(TDC&, bool, TRect&);
    void CmSelectAll();
    void CmFileNew();
    void CmFileOpen();
    void CmFileSave();
    void CmFileSaveAs();
    void CmAbout();

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND(CM_SELECTALL, CmSelectAll),
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

TDrawWindow::TDrawWindow(TWindow* parent)
{
  Init(parent, 0, 0);
  DragDC  = 0;
  PenSize = 1;
  Pen     = new TPen(TColor::Black, PenSize);
  Line    = new TPoints(10, 0, 10);
}

bool
TDrawWindow::CanClose()
{
  return MessageBox("Quieres salir?", "El dibujo ha cambiado",
                    MB_YESNO | MB_ICONQUESTION) == IDYES;
}

void
TDrawWindow::EvLButtonDown(uint, TPoint& point)
{
  Line->Flush();
  Invalidate();

  if (!DragDC) {
    SetCapture();
    DragDC = new TClientDC(*this);
    DragDC->SelectObject(*Pen);
    DragDC->MoveTo(point);
    Line->Add(point);
  }
}

void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  char inputText[6];

  wsprintf(inputText, "%d", PenSize);
  if ((TInputDialog(this, "Grosor de línea",
                        "Introduzca el nuevo grosor:",
                        inputText,
                        sizeof(inputText))).Execute() == IDOK) {
    int newPenSize = atoi(inputText);

    if (newPenSize < 0)
      newPenSize = 1;

    SetPenSize(newPenSize);
  }
}

void
TDrawWindow::EvMouseMove(uint, TPoint& point)
{
  if (DragDC) {
    DragDC->LineTo(point);
    Line->Add(point);
  }
}

void
TDrawWindow::EvLButtonUp(uint, TPoint&)
{
  if (DragDC) {
    ReleaseCapture();
    delete DragDC;
    DragDC = 0;
  }
}

void
TDrawWindow::SetPenSize(int newSize)
{
  delete Pen;
  PenSize = newSize;
  Pen     = new TPen(TColor::Black, PenSize);
}

void
TDrawWindow::Paint(TDC& dc, bool, TRect&)
{
  bool first = true;
  TPointsIterator i(*Line);

  dc.SelectObject(*Pen);

  while (i) {
    TPoint p = i++;

    if (!first)
      dc.LineTo(p);
    else {
      dc.MoveTo(p);
      first = false;
    }
  }
}

void TDrawWindow::CmFileNew()
{
  Line->Flush();
  Invalidate();
}

void TDrawWindow::CmSelectAll()
{
  MessageBox("No implementado", "Abir fichero", MB_OK);
}

void TDrawWindow::CmFileOpen()
{
  MessageBox("No implementado", "Abir fichero", MB_OK);
}

void TDrawWindow::CmFileSave()
{
  MessageBox("No implementado", "Guardar fichero", MB_OK);
}

void TDrawWindow::CmFileSaveAs()
{
  MessageBox("No implementado", "Guardar fichero como", MB_OK);
}

void TDrawWindow::CmAbout()
{
  MessageBox("No implementado", "Sobre el programa", MB_OK);
}

class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Dibujo", new TDrawWindow));
      GetMainWindow()->AssignMenu("COMMANDS");
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
