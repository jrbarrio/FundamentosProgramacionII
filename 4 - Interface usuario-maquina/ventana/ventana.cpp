#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>

class Dibuja : public TApplication {
  public:
	 Dibuja() : TApplication() {}

	 void InitMainWindow()
	 {
		TFrameWindow * p_tfr_win;
		p_tfr_win = new TFrameWindow (0, "Mi propia ventana");
		SetMainWindow(p_tfr_win);
	 }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  Dibuja dibujo;

  return dibujo.Run();
}