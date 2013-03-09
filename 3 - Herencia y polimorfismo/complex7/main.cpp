#include <iostream>

using namespace std;

class complejo {
protected:
    float real, imag;
public:
    complejo(void);
    complejo(float re, float im);
    complejo(float re);
    void visualiza(void);
    void aniade(complejo &comp);
    void asigna_valores(float re, float im);
};

complejo::complejo(void) {
    real = 1;
    imag = 1;
}

complejo::complejo(float re, float im) {
    real = re;
    imag = im;
}

complejo::complejo(float re) {
    real = re;
    imag = 1;
}

void complejo::visualiza(void) {
    cout << '\n' << real << " + " << imag << "i\n";
}

void complejo::aniade(complejo& comp) {
    real += comp.real;
    imag += comp.imag;
}

void complejo::asigna_valores(float re, float im = 0) {
    real = re;
    imag = im;
}

/////////////////////////////////////////////////////////////////////////////

class der_complejo : public complejo {
public:
    der_complejo(void);
    der_complejo(float re, float im);
    void visualiza(void);
    void aniade(float re, float im);
};

der_complejo :: der_complejo() : complejo() {
    // Vacio
}

der_complejo :: der_complejo(float re, float im) : complejo(re, im) {
    // Vacio
}

void der_complejo::visualiza(void) {
    cout << "PARTE REAL --------------->" << real << '\n';
    cout << "PARTE IMAGINARIA --------->" << imag << '\n';
}

void der_complejo::aniade(float re, float im) {
    real += re;
    imag += im;
}

/////////////////////////////////////////////////////////////////////////////

int main(void) {
    complejo comp_a(3, 4);
    der_complejo d_comp_b(5, 6);
    complejo *punt_base;
    der_complejo *punt_derivada;
    
    punt_base = &comp_a;
    punt_base->visualiza();
    
    punt_base = &d_comp_b;
    punt_base->visualiza();
    
    punt_derivada = (der_complejo *)&comp_a;
    punt_derivada->visualiza();
    
    punt_derivada = &d_comp_b;
    punt_derivada->visualiza();
}