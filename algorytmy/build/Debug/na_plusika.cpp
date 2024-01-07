#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


void euler(double punkt, int podprz);
void heun(double punkt, int podprz);
void euler2(double punkt, int podprz);


int main(){
    int wybor;
    double punkt;
    int n;

    cout << "podaj ktore rownanie chcesz rozwiazac: " << endl;
    cout << "1. y' = y^2 / (x + 1), warunek poczatkowy: y(0) = 3 - Metoda Eulera" << endl;
    cout << "2. y' = y / x^2, warunek poczatkowy: y(1) = 2 - Metoda Heuna" << endl;
    cout << "3. y' = 2xy, warunek poczatkowy: y(0) = 1 - Metoda zmodyfikowana Eulera" << endl;
    cout << "wybor: ";
    cin >> wybor;

    while(wybor != 1 && wybor != 2 && wybor !=3){
        cout << "nie ma takiego rownania do wyboru. Podaj nr rowania jeszcze raz: ";
        cin >> wybor;
    }

    cout << "podaj w ktorym punkcie podac rozwiazanie rownania: ";
    cin >> punkt;
    cout << "podaj liczbe podprzedzialow: ";
    cin >> n;

    while(n < 2){
        cout << "musza byc min 2 podprzedzialy. Podaj liczbe podprzedzialow jeszcze raz: ";
        cin >> n;
    }

    if(wybor == 1) euler(punkt, n);
    else if(wybor == 2) heun(punkt, n);
    else euler2(punkt, n);
}

void euler(double punkt, int podprz)
{
    double wynik = 3;
    double krok = (punkt - 0)/podprz;
    double x[podprz + 1];

    x[0] = 0;
    for(int i = 1; i <= podprz; i++){
        x[i] = x[i - 1] + krok;
    }
   
    for(int i = 0; i < podprz; i++){
        wynik += krok*(pow(wynik,2)/(x[i] + 1));
    }

    cout << "f(" << punkt << ") = " << wynik;
}

void heun(double punkt, int podprz)
{
    double wynik = 2;
    double krok = (punkt - 1)/podprz;
    double x[podprz + 1];
    double rob;

    x[0] = 1;
    for(int i = 1; i <= podprz; i++){
        x[i] = x[i - 1] + krok;
    }

    for(int i = 0; i < podprz; i++){
        rob = krok*wynik/pow(x[i], 2) + wynik;
        wynik += 0.5*krok*(wynik/pow(x[i], 2) + rob/pow(x[i] + krok, 2));
    }

    cout << "f(" << punkt << ") = " << wynik;
}

void euler2(double punkt, int podprz)
{
    double wynik = 1;
    double krok = (punkt - 0)/podprz;
    double x[podprz + 1];
    double rob1, rob2;

    x[0] = 0;
    for(int i = 1; i <= podprz; i++){
        x[i] = x[i - 1] + krok;
    }

    for(int i = 0; i < podprz; i++){
        rob1 = x[i] + 0.5*krok;
        rob2 = 0.5*krok*2*x[i]*wynik + wynik;
        wynik += krok*2*rob1*rob2;
    }

    cout << "f(" << punkt << ") = " << wynik; 
}
