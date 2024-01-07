#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Neville(vector<double> wezly, vector<double>wartosci,int l_wezlow, double punkt);

int main(){
    vector<double>x;
    vector<double>y;
    double p;
    int w;
    double rob;

    cout << "podaj liczbe wezlow: ";
    cin >> w;

    for(int i = 0; i < w; i++){
        cout << "podaj x[" << i << "]: ";
        cin >> rob;
        x.push_back(rob);
    }

    for(int i = 0; i < w; i++){
           cout << "podaj y[" << i << "]: ";
        cin >> rob;
        y.push_back(rob);
    }

    cout << "podaj punkt, w ktorym bedzie liczona wartosc interpolowanej funkcji: ";
    cin >> p;
    cout << endl;
    sort(x.begin(), x.end());
    for(int i = 0; i < w - 1; i+=2){
        if(x[i] == x[i+1]) {
            cout << "Wezly interpolacji nie sa parami rozne." << endl << "Nie mozna obliczyc wielomianu wzorem Nevillea.";
            return 0;
        }
    }

    if(p < x[0] || p > x[w -1]){
        cout << "Punkt p jest poza przedzialem [" << x[0] << ", " << x[w-1] << "]." << endl << "Nie mozna obliczyc wielomianu wzorem Nevilla.";
        return 0;
    }

    cout << "Wezly sa parami rozne." << endl << "Punkt p nalezy do przedzialu [" << x[0] << ", " << x[w-1] << "]." << endl;
    cout << endl << endl;
    double wynik = Neville(x, y, w, p);
    cout << endl << endl;
    cout << "Wartosc wielomianu w punkcie p = " << p << " wynosi: " << wynik;
}


double Neville(vector<double> wezly, vector<double> wartosci, int l_wezlow, double punkt)
{
    vector<double>p(l_wezlow);
    double tabelka[l_wezlow][l_wezlow + 1];

    for(int i = 0; i < l_wezlow; i++){
            tabelka[i][0] = wezly[i];
            tabelka[i][1] = wartosci[i];
        }

    for(int k = 2; k <= l_wezlow; k++){
        for(int j = 0; j <= l_wezlow - k; j++){
            tabelka[j][k] = ((punkt - tabelka[j][0])*tabelka[j + 1][k - 1] - (punkt - tabelka[j + k - 1][0])*tabelka[j][k - 1])/(tabelka[j + k - 1][0] - tabelka[j][0]);
        }

    }

    for(int i = 0; i < l_wezlow; i++){
        for(int j = 0; j <= l_wezlow - i; j++){
            cout << "p[" << i << "][" << j << "] = " << tabelka[i][j] << "    ";
        }
        cout << endl;
    }

    return tabelka[0][l_wezlow];

}






/*

for(int i = 0; i < l_wezlow; i++){
        p[i] = wartosci[i];
        //tabelka.push_back(wezly[i]);
        //tabelka.push_back(wartosci[i]);
        for(int j = i - 1; j >= 0; j--){
            p[j] = p[j + 1] + (p[j + 1] - p[j]) * (punkt - wezly[i])/(wezly[i] - wezly[j]);
            tabelka.push_back(p[j]);
            cout << "j = " << j << endl;
            cout << "p[" << j << "] = " << p[j] << endl;
        }
    }

    
    for(int i = 0; i < l_wezlow; i++){
        cout << wezly[i] << "  " << wartosci[i] << "  ";
        for(int j = i; j < l_wezlow - i; j++){
            cout << tabelka[j] << "  ";
        }
        cout << endl;
    }

        */