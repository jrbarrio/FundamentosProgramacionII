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
    
    cout << "PARTE REAL --------------> ";
    cin >> comp_a.real;
    cout << "PARTE IMAGINARIA --------> ";
    cin >> comp_a.imag;

    cout << "PARTE REAL --------------> ";
    cin >> comp_b.real;
    cout << "PARTE IMAGINARIA --------> ";
    cin >> comp_b.imag;

    comp_a.aniade(comp_b);
    comp_a.visualiza();
}