#include <iostream>
#include <vector>
using namespace std;

void wyswietl_lagrange(vector<double>wezly, vector<double>wartosci, double w);
int main(){
    vector<double> wezly;
    vector<double> wartosci;
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

    for(int i = 0; i < w - 1; i++){
        if(wezly[i] >= wezly[i+1]){
            cout <<"Zalozenia dot wezlow nie sa spelnione." << endl << "nie mozna wyznaczyc wielomianu interpolacyjnego Lagrangea.";
            return 0;
        }
    }

    wyswietl_lagrange(wezly, wartosci, w);
}


void wyswietl_lagrange(vector<double> wezly, vector<double> wartosci, double w)
{

}
