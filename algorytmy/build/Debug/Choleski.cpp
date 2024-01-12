#include <iostream>
#include <vector>
using namespace std;


vector<vector<double>> utworzmacierzl (int wym, vector<vector<double>> macierza);
vector<vector<double>> rozwiazmacierzdolna (int wym, vector<double>macierzl, vector<double>b);
vector<vector<double>> rozwiazmacierzgorna (int wym, vector<double>macierzl, vector<double>y);


int main(){
    int w;
    double rob;
    
    cout << "Podaj wymiar macierzy: ";
    cin >> n;

    vector<vector<double>> A(w, w);
    vector<double>b(w);

    for(int i = 0; i < w; i++){
        cout << "podaj wspolczynniki " << i + 1 << " wiersza:" << endl;
        for(int j = 0; j < w; j++){
            cin >> A[i][j];
            //A[i].push_back(rob);
        }
    }

    vector<vector<double>> L = utworzmacierz(w, A);
    vector<double> y = rozwiazmacierzdolna(w, L, b);
    vector<double> wynik = rozwiazmacierzgorna(w, L, y);

    cout << endl << "wynik: " << endl;
    for(int i = 0; i < w; i++){
        cout << "x"<< i+1 << " = " << wynik[i] << endl;
    }

    return 0;
}

vector<vector<double>> utworzmacierzl(int wym, vector<vector<double>> macierza){
    
    vector<vector<double>> macierzl(wym, wym) = {0};
    double robert;
    
        for(int j = 0; j < wym; j++){
            for(int i = j; i < wym; i++){
                if(j == i){
                    for(int k = 0; k < j - 1; k++){
                        robert += pow(macierzl[j][k], 2);
                    }
                    macierzl[i][j] = sqrt(macierza[i][j] - robert)
                }
                else{
                    for(int k = 0; k < j - 1; k++){
                        robert = macierzl[i][k]*macierzl[j][k];
                    }
                    macierzl[i][j] = 1.0*(macierza[i][j] - robert)/macierzl[j][j];
                }
            }
        }

        for(int i = 0; i < wym; i++){
            for(int j = 0; j < wym; j++){
                cout << macierzl[i][j] << "  ";
            }
            cout << endl;
        }

    return vector<vector<double>> macierzl;
}



vector<double> rozwiazmacierzdolna(int wym, vector<double> macierzl, vector<double> b){

    vector <double> y (wym);

    y[0] = b[0];
    y[0] /= macierzl[0][0];

    for(int i = 1; i < wym; i++){
        y[i] = b[i];
        for(int j = 0; j < i; j++){
            y[i] -= b[j]*macierzl[i][j];
        }
        y[i] /= macierzl[i][i];
    }

    return vector<double> y;
}



vector<vector<double>> rozwiazmacierzgorna(int wym, vector<double> macierzl, vector<double> y){

    vector<double> x (wym);

    cout << "MACIERZ LT" << endl;
    for(int i = 0; i < wym; i++){
        for(int j = 0; j < wym; j++){
            swap(macierzl[i][j], macierzl[j][i]);
            cout << macierz[i][j] << "  ";
        }
        cout << endl;
    }

    x[wym - 1] = y[wym - 1];
    x[wym - 1] /= macierzl[wym - 1][wym - 1];

    for(int i = wym - 2; i >= 0; i--){
        x[i] = y[i];
        for(int j = wym - 1; j > i; j--){
            x[i] -= y[j]*macierzl[i][j];
        }
        x[i] /= macierzl[i][i];
    }


    return vector<vector<double>> x;
}
