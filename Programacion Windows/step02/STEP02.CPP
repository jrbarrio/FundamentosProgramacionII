//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step02.cpp
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
										// , : modi_acceso  ident_clase_de _la_que_deriva
class Dibuja : public TWindow {                      // si deriva de más de una clase66666666666666666666666666666666666
  public:
	 Dibuja(TWindow* parent = 0);

  protected:
    // Override member function of TWindow
    bool CanClose();

    // Message response functions
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
  return MessageBox("¿Quiere guardar?", "El título ha cambiado",
						  MB_YESNO | MB_DEFBUTTON2| MB_ICONQUESTION) == IDNO;  // comprueba que devuelve un ident IDNO
}

void
Dibuja::EvLButtonDown(uint, TPoint&)
{
  MessageBox("Has apretado el botoncito izquierdo campeón",
	 "Larra & Jorge Corporation", MB_OK | MB_ICONSTOP);
}

void
Dibuja::EvRButtonDown(uint, TPoint&)
{
  MessageBox("Esta es el derecho, pulsa el otro a ver que pasa",
	 "ET,mi casa, teléfono", MB_OK | MB_ICONHAND);
}

class Vent_nom : public TApplication {
  public:
	 Vent_nom() : TApplication() {}

	 void InitMainWindow()
	 {
		TFrameWindow * p_tfr_win;
		p_tfr_win = new TFrameWindow(0, "Otro que sale",
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
