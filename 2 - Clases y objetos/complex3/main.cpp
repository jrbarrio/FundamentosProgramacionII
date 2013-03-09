#include <iostream>

using namespace std;

class complejo {
    float real, imag;
public:
    void visualiza(void);
    void aniade(complejo &comp);
    void asigna_valores(float re, float im);
    void pide_datos(void);
};

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

void complejo::pide_datos(void) {
    cout << "PARTE REAL --------------> ";
    cin >> real;
    cout << "PARTE IMAGINARIA --------> ";
    cin >> imag;
}

int main(void) {
    complejo comp_a, comp_b;
    
    comp_a.pide_datos();
    
    comp_b.asigna_valores(4, 3);
    comp_a.aniade(comp_b);
    comp_a.visualiza();
    
    comp_b.asigna_valores(8);
    comp_a.aniade(comp_b);
    comp_a.visualiza();
}