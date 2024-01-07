#include <iostream> 
#include <vector>
#include <math.h>
using namespace std;

double newton(vector<double> wezly, vector<double> wartosci, double punkt, double ile_w);

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
   
    cout << "wartosc wielomianu w punkcie p = " << p << " wynosi: " << newton(wezly, wartosci, p, w);
}


double newton(vector<double> wezly, vector<double> wartosci, double punkt, double ile_w){
    vector<double> IR;
    double wynik = 0;
    double rob;

    for(int i = 0; i < ile_w; i++){
        IR.push_back(wartosci[i]);
    }

    for(int k = 1; k < ile_w; k++){
        for(int i = ile_w; i >= k; i--){
            IR[i] = (IR[i] - IR[i - 1]) / (wezly[i] - wezly[i - k]);
          //cout << "IR: " << IR[i] << "  ";
        }
    }
    
    for(int i = 0; i < ile_w; i++){
        rob = 1;
        //cout  << "IR[" << i << "]" << IR[i] <<endl;
        for(int k = 0; k <= i - 1; k++){
            rob = rob * (punkt - wezly[k]);
        }
        wynik = wynik + (rob * IR[i]);
       // cout << " i = " << i << "  wynik: " << wynik ;
    }
    
    return wynik;
}
