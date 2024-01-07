#include <iostream>
#include <vector>
using namespace std;

double lagrange(vector<double>wezly, vector<double>wartosci, double p, double w);

int main(){
    vector<double> wezly;
    vector<double> wartosci;
    double p;
    double w;
    double rob;

    cout << "podaj ilosc wezlow: ";
    cin >> w;
    for(int i = 0; i < w; i++){
        cout << "Podaj x[" << i << "]: ";
        cin >> rob;
        wezly.push_back(rob);
    }

    for(int i = 0; i < w; i++){
        cout << "Podaj y[" << i << "]: ";
        cin >> rob;
        wartosci.push_back(rob);
    }

    cout << "Podaj punkt, w którym ma byc liczona przyblizona wartosc funkcji: ";
    cin >> p;

    for(int i = 0; i < w - 1; i++){
        if(wezly[i] >= wezly[i+1]){
            cout <<"Zalozenia dot wezlow nie sa spelnione." << endl << "nie mozna wyznaczyc wielomianu interpolacyjnego Lagrangea.";
            return 0;
        }
    }

    if(p < wezly[0] || p > wezly[w-1]){
        cout << "p jest poza zakresem interpolacji." << endl << "Nie mozna obliczyc interpolacyjnie wartosci wielomianu w tym punkcie.";
        return 0;
    }

    cout << "wartosc wielomianu w punkcie p = " << p << " wynosi: " << lagrange(wezly, wartosci, p, w);
}

double lagrange(vector<double> wezly, vector<double> wartosci, double p, double w)
{
    double wynik = 0;
  
    for(int i = 0; i < w; i++){
        double l = 1;
        for(int k = 0; k < w; k++){
            if(k != i)
                l *= ((p - wezly[k])/(wezly[i] - wezly[k]));
        }
        wynik += wartosci[i]*l;
    }
    
    return wynik;
}
