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

const int MAXTAM = 5;

void visualiza_array(complejo vector[]);

int main(void) {
    complejo vector_1[MAXTAM];
    complejo vector_2[MAXTAM];
    
    complejo *punt;
    int num_elem = 6;
    
    vector_1[0].visualiza();
    vector_1->visualiza();
    (vector_1 + 4)->visualiza();
    visualiza_array(vector_2);
    
    punt = new complejo;
    punt = new complejo();
    delete punt;
    punt = new complejo(3, 5);
    delete punt;
    
    punt = new complejo[num_elem];
    visualiza_array(punt);
    delete [] punt;
}

void visualiza_array(complejo vector[]) {
    for (int indice = 0; indice < MAXTAM; indice++) {
        (vector + indice)->visualiza();
    }
}