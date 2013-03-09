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
    void pide_datos(void);
    float parte_real(void) {return real;}
    float parte_imag(void) {return imag;}
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

void complejo::pide_datos(void) {
    cout << "PARTE REAL --------------> ";
    cin >> real;
    cout << "PARTE IMAGINARIA --------> ";
    cin >> imag;
}

/////////////////////////////////////////////////////////////////////////////

class der_complejo : public complejo {
public:
    der_complejo(void);
    der_complejo(float re, float im);
    void visualiza(void);
    void multiplica(der_complejo &comp);
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

void der_complejo::multiplica(der_complejo& d_comp) {
    float temp = real;
    real += real * d_comp.real - imag * d_comp.imag;
    imag += imag * d_comp.real + temp * d_comp.imag;
}

void der_complejo::aniade(float re, float im) {
    real += re;
    imag += im;
}

/////////////////////////////////////////////////////////////////////////////

complejo suma(complejo &comp_1, complejo &comp_2);

int main(void) {
    der_complejo d_comp_a;
    der_complejo d_comp_b(5, 6);
    complejo comp_c;
    
    comp_c.visualiza();
    d_comp_a.visualiza();
    
    d_comp_a.asigna_valores(3, 2);
    
    d_comp_a.multiplica(d_comp_b);
    
    d_comp_a.visualiza();
    d_comp_a.complejo::visualiza();
    
    d_comp_a.aniade(2, 1);
    d_comp_a.complejo::aniade(d_comp_b);
    
    d_comp_a.visualiza();
}

complejo suma(complejo &comp_1, complejo &comp_2) {
    complejo comp;
    
    comp.asigna_valores(comp_1.parte_real() + comp_2.parte_real(),
        comp_1.parte_imag() + comp_2.parte_imag());
    
    return comp;
}