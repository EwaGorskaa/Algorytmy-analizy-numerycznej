#include <iostream>
using namespace std;

void gauss();
void gaussprzyklad();

int main(){

    int wybor;

    cout << "Jaki uklad rownan chcesz rozwwiazac? " << endl << " - 1 - wlasny " << endl <<" - 2 - przykladowy " << endl << "wybor: ";
    cin >> wybor;

    if(wybor == 1){
        gauss();
    }
    else if (wybor == 2){
        gaussprzyklad();
    
    }
    else {
        cout << "nie ma takiej opcji do wyboru, wybierz uklad jeszcze raz: ";
        cin >> wybor;
    }

    return 0;
    
}


void gauss(){
    int rozmiar;
    double wspolczynnik;
    double mnoznik;
    
    cout << "podaj liczbe niewiadomych: ";
    cin >> rozmiar;
    double macierz[rozmiar][rozmiar + 1];
    double rozwiazanie[rozmiar];

    for(int i = 0; i < rozmiar; i++){
        cout << "podaj wspolczynniki " << i + 1 << " wiersza:" << endl;
        for(int j = 0; j < rozmiar + 1; j++){
            cin >> macierz[i][j];
        }
    }

    for(int i = 0; i < rozmiar; i++){
        for(int j = 0; j < rozmiar + 1; j++){
            cout << macierz[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i = 0; i < rozmiar; i++){
        if(macierz[i][i] == 0) {
            cout << "nie mozna rozwiazac ukladu ta metoda";
            return;
        }
        else{
            for(int j = i + 1; j < rozmiar; j++){
                mnoznik = macierz[j][i]/macierz[i][i];
                if(mnoznik == 0) continue;
                else{
                    for(int k = 0; k < rozmiar + 1; k++){
                        macierz[j][k] -= mnoznik * macierz[i][k];
                    }
                }
            }
        }
    }

    cout << endl;
    for(int i = 0; i < rozmiar; i++){
        for(int j = 0; j <= rozmiar; j++){
            cout << macierz[i][j] << "  ";
        }
        cout << endl;
    }

    rozwiazanie[rozmiar - 1] = macierz[rozmiar - 1][rozmiar];
    rozwiazanie[rozmiar - 1] /= macierz[rozmiar - 1][rozmiar - 1];
    for(int i = rozmiar - 2; i >= 0; i--){
        rozwiazanie[i] = macierz[i][rozmiar];  
        for(int j = rozmiar - 2; j >= i; j--){
            rozwiazanie[i] -= macierz[i][j + 1]*rozwiazanie[j + 1];
        }
        rozwiazanie[i] /= macierz[i][i];
    }

    cout << endl <<"ROZWIAZANIE:" << endl;
    for(int i = 0; i < rozmiar; i++){
        cout << "x" << i + 1 << "= " << rozwiazanie[i] << endl;
    }
}

void gaussprzyklad(){
    double macierz[4][5] = 
    {
        {1,2,-1,2,0},
        {1,0,-2,4,4},
        {0,-3,1.5,7,0},
        {0,-1,1,6,-1}
    };

    double rozwiazanie[4];
    double mnoznik;

    cout << "PRZYKLADOWA MACIERZ: " <<endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout << macierz[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            mnoznik = macierz[j][i]/macierz[i][i];
            if(mnoznik == 0) continue;
            else{
                for(int k = 0; k < 5; k++){ 
                    macierz[j][k] -=( mnoznik * macierz[i][k]);
                }
            }
        }
    }
      
    cout << endl << "MACIERZ Z WYZEROWANA DOLNA MACIERZA TROJKATNA: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout << macierz[i][j] << "  ";
        }
        cout << endl;
    }

    rozwiazanie[3] = macierz[3][4];
    for(int i = 2; i >= 0; i--){
        rozwiazanie[i] = macierz[i][4];  
        for(int j = 2; j >= i; j--){
            rozwiazanie[i] -= (macierz[i][j + 1]*rozwiazanie[j + 1]);
        }
        rozwiazanie[i] /= macierz[i][i];
    }

    cout << endl <<"ROZWIAZANIE:" << endl;
    for(int i = 0; i < 4; i++){
        cout << "x" << i + 1 << "= " << rozwiazanie[i] << endl;
    }
}



/*double macierz[5][6] = 
    {
        {1,-2,0,3,1,1},
        {2,-3,1,8,2,3},
        {1,-2,1,3,-1,1},
        {0,1,0,3,5,0},
        {1,-2,0,5,8,-1}
    };*/