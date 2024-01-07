#include <iostream>
#include <vector>
using namespace std;

double Horner(int n, vector<double> a, double c);
void HornerU(int n, vector<double>a, double c);
void tabelka(int n, vector<double>a, double c);

int main() {
    int n = 0, rob = 0;
    double c = 0;
    bool wybor;
    vector<double> a;
    cout << "podaj stopien wielomianu: ";
    cin >> n;
    cout << endl;
    for(int i = n;i >= 0; i--){
        cout << "podaj wspolczynnik przy " << i << " potedze: ";
        cin >> rob;
        a.push_back(rob);
    }

    cout << "podaj punkt, w ktorym bedzie liczona wartosc wielomianu: ";
    cin >> c;
    cout << endl;

    cout << "Wartosc wielomianu w punkcie p = " << c << " jest rowna " << Horner(n, a, c) << endl;
    HornerU(n, a, c);
    cout << "czy chcesz wyswietlic tabelke? (1 - tak, 0 - nie)";
    cin >> wybor;
    if(wybor) tabelka(n, a, c);
    return 0;
}

double Horner(int n, vector<double> a, double c){
    double w = a[0];
    for(int i = 1; i <= n; i++){
        w = w * c + a[i];
    }
    return w;
}

void HornerU(int n, vector<double> a, double c){

    for(int i = 0; i < n; i++){
        for(int k = 1; k <= n - i; k++){
            a[k] = a[k - 1] * c + a[k];
        } 
    }

    for(int i = n; i >= 0; i--){
            for(int j = 1; j <= n - i; j++)
                a[i] *= j; 
        }
    cout << "wartosci pochodnych wielomianu w punkcie p = " << c << " wynosza: " << endl;

    for(int i = n - 1; i >= 0; i--){
        cout << n - i << " pochodna = " << a[i] << endl;
    }
}


void tabelka(int n, vector<double> a, double c){
     cout << endl << "TABELKA (troche kulawa): " << endl;
    cout << "    ";
    for(int i = 0; i <= n; i++){
        cout << a[i] << " | ";
    }
    
    cout << endl << "------------------------------" << endl << " ";

    for(int i = 0; i < n; i++){
        cout << c << "| " << a[0] << " ";
        for(int k = 1; k <= n - i; k++){
            a[k] = a[k - 1] * c + a[k];
            cout << a[k] << " ";
        } 
        cout << endl;
        cout << " ";
    }
    cout << "    " << a[0] << endl << endl;
}
