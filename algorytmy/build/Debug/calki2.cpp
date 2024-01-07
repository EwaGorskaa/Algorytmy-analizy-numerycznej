#include <iostream> 
#include <math.h>
#include <vector>
using namespace std;

double kwadratury(int wybor);

int main(){
    int w;

    cout << "jaka calke chcesz obliczyc?" << endl;
    cout << "1. /int_ {-1}^{1} / x^2/sqrt(1-x^2) dx   n = 3" << endl;
    cout << "2. /int_ {-1}^{1} / 1/sqrt(1+x^2) dx   n = 4" << endl;
    cout << "3. /int_ {0}^{inf} /e^(-2x)*(sinx/x) dx    n = 3" << endl;
    cout << "4. /int_ {inf}^{inf} /e^((-x)^2)*cosx dx    n = 4" << endl;

    cout << "wybor: ";
    cin >> w;
    
    while(w < 1 || w > 4){
        cout << "nie ma takiego numeru calki do policzenia" << endl;
        cout << "podaj calke jeszcze raz: ";
        cin >> w;
    }

    cout << "wartosc calki nr " << w << " = " << kwadratury(w) << endl;

    return 0;
}

double kwadratury(int wybor){
    double wynik;
    double rob;
    vector <double> wezly;
    vector<double> Hj;

    if (wybor == 1){
        double H = M_PI / 4;

        for(int i = 0; i < 4; i++){
            wezly.push_back(cos(((2*i + 1)*M_PI)/8));
        }

        for(int i = 0; i < 4; i++){
            rob = H*pow(wezly[i], 2);
            wynik += rob;
        }
    }

    else if(wybor == 2){
        Hj = {0.236927, 0.478629, 0.568889, 0.478629, 0.236927};

        wezly.push_back(-0.906180);
        wezly.push_back(-0.538469);
        wezly.push_back(0);
        wezly.push_back(0.538469);
        wezly.push_back(0.906180);

         for(int i = 0; i < 5; i++){
            rob = Hj[i] /( sqrt(1 + pow(wezly[i], 2)));
            wynik += rob;
        }
    }

    else if(wybor == 3){
        Hj = {0.603154, 0.357419,  0.038888, 0.000539};

        wezly.push_back(0.322548);
        wezly.push_back(1.745761);
        wezly.push_back(4.536620);
        wezly.push_back(9.395071);

        for(int i = 0; i < 4; i++){
            rob = Hj[i]*pow(M_E, -wezly[i])*sin(wezly[i])/wezly[i]; 
            wynik += rob;
        }
    }

    else{
        Hj = {0.019953, 0.393619, 0.945309, 0.393619, 0.019953};

        wezly.push_back(-2.020183);
        wezly.push_back(-0.958572);
        wezly.push_back(0);
        wezly.push_back(0.958572);
        wezly.push_back(2.020183);

        for(int i = 0; i < 5; i++){
            rob = Hj[i]*cos(wezly[i]);
            wynik += rob;
        }
    }

    return wynik;
}
