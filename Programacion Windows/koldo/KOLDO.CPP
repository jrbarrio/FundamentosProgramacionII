//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step06.cpp
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <owl/inputdia.h>
#include <classlib/arrays.h>
#include <stdlib.h>
#include "koldo.rc"


class TDrawWindow : public TWindow {
  public:
	 TDrawWindow(TWindow* parent = 0);
  protected:
	 // Override member function of TWindow
	 bool CanClose();

	 // Message response functions
	 void EvLButtonDown(uint, TPoint&);
	 void EvRButtonDown(uint, TPoint&);
	 void CmSalir();
	 void CmInsertar();
	 void CmBorrar();

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_COMMAND(CM_SALIR, CmSalir),
  EV_COMMAND(CM_INSERTAR, CmInsertar),
  EV_COMMAND(CM_BORRAR, CmBorrar),
END_RESPONSE_TABLE;

TDrawWindow::TDrawWindow(TWindow* parent)
{
  Init(parent, 0, 0);
}

bool
TDrawWindow::CanClose()
{
  return MessageBox("¿Esta seguro de querer salir?", "Salir",
						  MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES;
}

void
TDrawWindow::EvLButtonDown(uint, TPoint& )
{
  char cadena [20];
  TClientDC dc(*this);

if ((TInputDialog (this,"Insertar Texto","Inserte el texto que desee",
							cadena, sizeof (cadena))).Execute() == IDOK)

	dc.TextOut (1,1,cadena, strlen (cadena));

}

void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  Invalidate ();
}


void
TDrawWindow::CmSalir()
{
  CloseWindow();
}

void
TDrawWindow::CmInsertar()
{
  char cadena [20];
  TClientDC dc (*this);

if ((TInputDialog (this,"Insertar Texto","Inserte el texto que desee",
							cadena, sizeof (cadena))).Execute() == IDOK)

	dc.TextOut (1,1,cadena, strlen (cadena));

}

void
TDrawWindow::CmBorrar()
{
  Invalidate ();
}


class TDrawApp : public TApplication {
  public:
	 TDrawApp() : TApplication() {}

	 void InitMainWindow()
	 {
		SetMainWindow(new TFrameWindow(0, "Practica", new TDrawWindow));
		GetMainWindow()->AssignMenu("MENU_1");
	 }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
