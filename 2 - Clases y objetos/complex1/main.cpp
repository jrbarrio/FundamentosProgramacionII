#include <iostream>

using namespace std;

class complejo {
public:
    float real, imag;
    void visualiza(void);
    void aniade(complejo &comp);
};

void complejo::visualiza(void) {
    cout << '\n' << real << " + " << imag << "i\n";
}

void complejo::aniade(complejo& comp) {
    real += comp.real;
    imag += comp.imag;
}

int main(void) {
    complejo comp_a, comp_b;
    
    comp_a.real = 5;
    comp_a.imag = 2;
    comp_b = comp_a;
    comp_a.aniade(comp_b);
    comp_a.visualiza();
}