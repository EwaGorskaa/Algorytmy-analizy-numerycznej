#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


double trapezy(int nr_calki, int l_podprzedzialow);
double simpson(int nr_calki, int l_podprzedzialow);

int main(){
    int m, wybor;
    char wzor;

    cout << "podaj jaka funkcje chcesz calkowac: " << endl;
    cout << "0. /int_ {0}^{1} /sqrt(1+x)dx" << endl;
    cout << "1. /int_ {0}^{2/pi} (/sin^2(x) +2)dx" << endl;
    cout << "2. /int_ {0}^{2} /e^x*2x^3dx" << endl;

    cout << "nr calki: ";
    cin >> wybor;
    while(wybor != 0 && wybor !=1 && wybor != 2) {
        cout << "nie ma takiej calki do wyboru, podaj nr calki jeszcze raz: ";
        cin >> wybor;
    }

    cout << "podaj jakim wzorem chcesz ja obliczyc(t/s): ";
    cin >> wzor;
    while(wzor != 't' && wzor != 's'){
        cout << "nie ma takiego wzoru do wyboru, podaj wzor jeszcze raz: ";
        cin >> wzor;
    }

    cout << "podaj liczbe podprzedzialow(m > 1): ";
    cin >> m;
    
    while(m <= 1){
        cout << "musza byc min 2 podprzedzialy, podaj poprawna wartosc: ";
        cin >> m;
    }

    while( m & 1 == 1 && wzor == 's'){
        cout << "liczba podprzedzialow musi byc parzysta, podaj poprawna wartosc: ";
        cin >> m;
    }

    cout << "przyblizona wartosc calki wynosi: ";

    if(wzor == 's'){
        cout << simpson(wybor, m);
    }
    else cout << trapezy(wybor, m);

    return 0;
}

double trapezy(int nr_calki, int l_podprzedzialow){
    double wynik = 0;
    double krok;
    vector <double> x;
    vector <double> y;

    

    if(nr_calki == 0){
        krok = (double)1/l_podprzedzialow;
        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(sqrt(1 + x[i]));
        }
        
        wynik = y[0]/2 + y[l_podprzedzialow]/2;
        for(int i = 1; i < y.size() - 1; i++){
            wynik += y[i];
        }
        wynik *=krok;
        
    }

    else if(nr_calki == 1){
        krok = (double)(M_PI*2/l_podprzedzialow);

        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(pow(sin(x[i]), 2) + 2);
            cout << "f x" << i <<  "=" << y[i] << endl;
        }
    }

    else{
        krok = (double)2/l_podprzedzialow;

        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(pow(M_E, x[i])*pow(x[i], 3)*2);
        }

    }

    wynik = y[0]/2 + y[l_podprzedzialow]/2;
        for(int i = 1; i < y.size() - 1; i++){
            wynik += y[i];
        }
    wynik *=krok;

    return wynik;
}

double simpson(int nr_calki, int l_podprzedzialow)
{
double wynik = 0;
    double krok;
    vector <double> x;
    vector <double> y;

    

    if(nr_calki == 0){
        krok = (double)1/l_podprzedzialow;
        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(sqrt(1 + x[i]));
        }
        
        wynik = y[0]/2 + y[l_podprzedzialow]/2;
        for(int i = 1; i < y.size() - 1; i++){
            wynik += y[i];
        }
        wynik *=krok;
        
    }

    else if(nr_calki == 1){
        krok = (double)M_PI*2/l_podprzedzialow;

        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(pow(sin(x[i]), 2) + 2);
        }
    }

    else{
        krok = (double) 2/l_podprzedzialow;
        for(int i = 0; i <= l_podprzedzialow; i++){
            x.push_back(i*krok);
            y.push_back(pow(M_E, x[i])*pow(x[i], 3)*2);
        }

    }

    wynik = y[0] + y[l_podprzedzialow];
        for(int i = 1; i < y.size() - 1; i++){
            if((i & 1) == 0){
                wynik += (y[i]*2);
            }
            else {
                wynik += (y[i]*4);
            }
            //cout << "wynik: " << wynik << endl;
        }
    wynik *=(double) krok/3;
    
    return wynik;
}
