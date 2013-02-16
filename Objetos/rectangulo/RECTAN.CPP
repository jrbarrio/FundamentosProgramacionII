

#include <iostream.h>


class rectangulo
	{
	protected :
		float longitud, anchura;
	public :
		void introduce_datos (void);
		void visualiza_datos (void);
		float calcula_area (void);
	};

//-----  calcula_area  ------//

float rectangulo::calcula_area (void)
{
float area;
area = longitud * anchura;

return area;
}

//-----  visualiza_datos  ------//

void rectangulo::visualiza_datos (void)
{
cout << "LA ANCHURA ES " << anchura ;
cout << "\nLA LONGITUD ES " << longitud ;
}

//----- introduce_datos  -----//

void rectangulo::introduce_datos (void)
{
cout << "INTRODUCE LA LONGITUD --->" ;
cin >> longitud ;
cout << "INTRODUCE LA ANCHURA --->" ;
cin >> anchura ;
}





class caja : public rectangulo
	{
		float altura;
	public :
		void datos (void);
		void visualiza (void);
		float calcula_volumen (void);
	};

//------  calcula_volumen  ------//

float caja::calcula_volumen (void)
{
float volumen;
volumen = calcula_area () * altura;

return volumen;
}

//------  visualiza  ------//

void caja::visualiza (void)
{
visualiza_datos ();
cout << "\nLA ALTURA ES " << altura ;
}

//------  datos ------//

void caja::datos (void)
{
introduce_datos ();
cout << "\nINTRODUCE LA ALTURA -->" ;
cin >> altura ;
}



//******************   funcion main   *********************//

void main (void)
{
caja cosa;
cosa.datos ();

float volumen;
volumen = cosa.calcula_volumen () ;
cout << "\nEL VOLUMEN ES " << volumen ;
cosa.visualiza ();
}





