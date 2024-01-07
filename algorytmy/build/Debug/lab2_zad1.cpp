#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double zamiana(int n, double a, int p);

int main(){
    int n = 0;
    double a = 0;
    int q = 0;

    cout << "podaj liczbe: ";
    cin >> a;
    cout << "podaj z jaka dokladnoscia chcesz ja przedstawic(ile cyfr po przecinku): ";
    cin >> n;
    cout << "podaj podstawe systemu: ";
    cin >> q;

    cout << "zapis liczby w systemie o podstawie " << q << " wynosi: " << zamiana(n, a, q);

}

double zamiana(int n, double a, int q){
    long long l = 0;
    a = a * pow(q,n);
    int rob;
    rob = (int)a;

    for(int i = 0; rob > 0; i++){
        l += (rob % q * pow(10,i));
        rob = rob / q;
    }
        
    double result = l;
    result = result / pow(10, n);
    cout << fixed << setprecision(n) << endl;

    return result; 
}
