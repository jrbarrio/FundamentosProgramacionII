#include <iostream.h>
#include <math.h>

class complejo
	{
		double real, imag, modulo, angulo;
	public:
		void pide_datos (void);
		void ainade (complejo &comp);
		void multiplica (complejo &comp);
		void cartesianas_a_polares (void);
		void polares_a_cartesianas (void);
		double parte_real (void) {return real;}
		double parte_imag (void) {return imag;}
		double dame_modulo (void) {return modulo;}
		double dame_angulo (void) {return angulo;}
	};


//--------  polares_a_cartesianas  ---------//
void complejo::polares_a_cartesianas (void)
{
real = modulo * cos (angulo);
imag = modulo * sin (angulo);
}

//--------  cartesianas-a-polares  ---------//
void complejo::cartesianas_a_polares (void)
{
modulo = real*real - imag*imag;
angulo = atan (real/imag);
}

//------------  multiplica  ---------//
void complejo::multiplica (complejo &comp)
{
modulo *= comp.modulo;
angulo += comp.angulo;
}

//------------  ainade  ---------//
void complejo::ainade (complejo &comp)
{
real +=comp.real;
imag +=comp.imag;
}

//------------  pide_datos  -------//
	  //--  Tengo que acabarla con un switch  --//

void complejo::pide_datos (void)
{
int opcion;
cout << "1.POLARES\n2.CARTESIANAS\n" ;
cin >> opcion;
}


//------  prototipos de las funciones especificas  -------//

complejo suma2 (complejo &comp_1, complejo &comp_2);
complejo producto2 (complejo &comp_1, complejo &comp_2);
complejo divide2 (complejo &comp_1, complejo &comp_2);

//-----   definicion de las funciones especificas  -----//

 complejo suma2 (complejo &comp_1, complejo &comp_2)
 {
 complejo comp;

 comp.real = comp_1.parte_real () + comp_2.parte_real ();
 comp.imag = comp_1.parte_imag () + comp_2.parte_imag ();

 return comp;
 }

 //---------------------------//

 complejo producto2 (complejo &comp_1, complejo &comp_2)
 {
 complejo comp;

 comp.modulo = comp_1.dame_modulo () * comp_2.dame_modulo ();
 comp.angulo = comp_1.dame_angulo () + comp_2.dame_angulo ();

 return comp;
 }

 //-------------------------------//

 complejo divide2 (complejo &comp_1, complejo &comp_2)
 {
 complejo comp;

 comp.modulo = comp_1.dame_modulo () / comp_2.dame_modulo ();
 comp.angulo = comp_1.dame_angulo () - comp_2.dame_angulo ();

 return comp;
 }
