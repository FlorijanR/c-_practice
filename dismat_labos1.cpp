#include <iostream>
#include <math.h>
using namespace std;

float formula(float x_0, float x_1, float x_2, float a_0, float a_1, float a_2, int n) {
    if (n == 2) return a_2;
    if (n == 1) return a_1;
    if (n == 0) return a_0;
    
    float result;
    float det = (x_1*x_2*x_2 - x_2*x_1*x_1) - (x_0*x_2*x_2 - x_2*x_0*x_0) + (x_0*x_1*x_1 - x_1*x_0*x_0);
    float l_0 = (a_0*(x_1*x_2*x_2 - x_2*x_1*x_1) - a_1*(x_2*x_2 - x_1*x_1) + a_2*(x_2 - x_1)) / det;
    float l_1 = (-a_0*(x_0*x_2*x_2 - x_2*x_0*x_0) + a_1*(x_2*x_2 - x_0*x_0) - a_2*(x_2 - x_0)) / det;
    float l_2 = (a_0*(x_0*x_1*x_1 - x_1*x_0*x_0) - a_1*(x_1*x_1 - x_0*x_0) + a_2*(x_1 - x_0)) / det;

    result = l_0 * pow(x_0, n) + l_1 * pow(x_1, n) + l_2 * pow(x_2, n);

    return result;
}

float rekurzija(float x_0, float x_1, float x_2, float a_0, float a_1, float a_2, int n) {
    if (n == 2) return a_2;
    if (n == 1) return a_1;
    if (n == 0) return a_0;

    float c_1 = x_0 + x_1 + x_2;
    float c_2 = -(x_0 * x_1) - (x_0 * x_2) - (x_1 * x_2);
    float c_3 = x_0 * x_1 * x_2;

    float result;
    result = c_1 * rekurzija(x_0, x_1, x_2, a_0, a_1, a_2, n - 1)
             + c_2 * rekurzija(x_0, x_1, x_2, a_0, a_1, a_2, n - 2)
             + c_3 * rekurzija(x_0, x_1, x_2, a_0, a_1, a_2, n - 3);

    return result;
}

int main(void) {
    float x_0, x_1, x_2;
    float a_0, a_1, a_2;
    int n;
    
    cout << "Unesite prvo rjesenje x_0 karakteristicne jednadzbe: ";
    cin >> x_0;
    cout << "Unesite drugo rjesenje x_1 karakteristicne jednadzbe: ";
    cin >> x_1;
    cout << "Unesite trece rjesenje x_2 karakteristicne jednadzbe: ";
    cin >> x_2;
    cout << "Unesite vrijednost nultog clana niza a_0: ";
    cin >> a_0;
    cout << "Unesite vrijednost prvog clana niza a_1: ";
    cin >> a_1;
    cout << "Unesite vrijednost drugog clana niza a_2: ";
    cin >> a_2;
    cout << "Unesite redni broj n trazenog clana niza: ";
    cin >> n;

    cout << "Vrijednost n-tog clana niza pomocu formule: " << formula(x_0, x_1, x_2, a_0, a_1, a_2, n) << endl;
    cout << "Vrijednost n-tog clana niza iz rekurzije: " << rekurzija(x_0, x_1, x_2, a_0, a_1, a_2, n) << endl;

    return 0;
}