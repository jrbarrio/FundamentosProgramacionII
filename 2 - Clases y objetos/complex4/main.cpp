#include <iostream>

using namespace std;

class complejo {
    float real, imag;
public:
    complejo(void);
    complejo(float re, float im);
    complejo(float re);
    complejo(const complejo& comp);
    ~complejo(void);
    void visualiza(void);
    void aniade(complejo &comp);
    void asigna_valores(float re, float im);
    void pide_datos(void);
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

complejo::complejo(const complejo& comp) {
    real = comp.real;
    imag = comp.imag;
}

complejo::~complejo(void) {
    cout << "\nObjeto complejo destruido";
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

void complejo::pide_datos(void) {
    cout << "PARTE REAL --------------> ";
    cin >> real;
    cout << "PARTE IMAGINARIA --------> ";
    cin >> imag;
}

int main(void) {
    complejo comp_a(5, 2);
    complejo comp_b(comp_a);

    comp_a.aniade(comp_b);
    comp_a.visualiza();
}