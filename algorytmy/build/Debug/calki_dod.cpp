#include <iostream> 
#include <vector>
#include <math.h>
using namespace std;


double simpson(int l_podprz);


int main(){

    int m;

    cout << "obliczymy calke:  /int_ {0}^{4} /x*e^(2*x) dx" << endl << "podaj liczbe podprzedzialow(musi byc podzielna przez 3): ";
    cin >> m;
 
    while( m % 3 != 0 || m < 2){
        if( m % 3 != 0 ) cout << "musi byc podzielna przez 3";
        if(m < 2) cout << "musza byc min 2 podprzedzialy";
        cout << "podaj liczbe podprzedzialow jeszcze raz: ";
        cin >> m;
    }

    cout << "przyblizona wartosc calki wynosi: " << simpson(m);

    return 0;

}

double simpson(int l_podprz){

    double wynik = 0;
    double krok;
    vector <double> x;
    vector <double> y;

    krok = (double) 4/l_podprz; //      h = 4 - 0 / m
        for(int i = 0; i <= l_podprz; i++){
            x.push_back(i*krok);
            y.push_back(x[i] * pow(M_E, 2*x[i]));
        }

    wynik = y[0] + y[l_podprz];

        for(int i = 1; i < l_podprz; i++){
            if( i % 3 == 0){
                wynik += (y[i] * 2);
            }
            else wynik += (y[i] * 3);
        }

    wynik *= 3;
    wynik *= krok;
    wynik /= 8;
    
    return wynik;

}
