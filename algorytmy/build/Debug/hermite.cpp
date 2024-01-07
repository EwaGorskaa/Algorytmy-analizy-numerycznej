#include <iostream>
#include <vector>
using namespace std;

void hermite(int l_wezlow, vector<double>wezly, vector<int>krotnosci, vector<double>wartosci, double punkt);
double hermiteU(int l_wezlow, vector<double>wezly, vector<int>krotnosci, vector<double>wartosci, double punkt);

int main(){

    int l_wezlow;
    vector<int> krotnosci;
    vector<double> wezly;
    double rob, punkt;
    vector<double> wartosci;

    cout << "podaj liczbe wezlow: ";
    cin >> l_wezlow;

    for(int i = 0; i < l_wezlow; i++){
        cout << "podaj " << i+1 << " wezel: ";
        cin >> rob;
        wezly.push_back(rob);
    }

    for(int i = 0; i < l_wezlow; i++){
        cout << "podaj " << i+1 << " wartosc: ";
        cin >> rob;
        wartosci.push_back(rob);
    }

    cout << "podaj punkt w ktorym bedzie liczona wartosc funkcji: ";
    cin >> punkt;

    hermite( l_wezlow, wezly, krotnosci, wartosci, punkt);

    double wynik = hermiteU( l_wezlow, wezly, krotnosci, wartosci, punkt);

    cout << "wartosc wielomianu Hermita w podanym punkcie wynosi" << wynik;
    
    return 0;
}


void hermite(int l_wezlow, vector<double>wezly, vector<int>krotnosci, vector<double>wartosci, double punkt){
    vector<vector<double>> tabelka(l_wezlow, vector<double>(3));
    double rob, p_pochodna, wartosc1, wartosc2;

    for(int i = 0; i < l_wezlow; i++){
        tabelka[i][0] = wezly[i];
        tabelka[i][1] = wartosci[i];
    }

    wartosc2 = tabelka[0][1];
    if(tabelka[0][0] == tabelka[1][0]){
        p_pochodna = tabelka[1][1];
    }
    for(int i = 1; i < l_wezlow; i++){
        if(tabelka[i - 1][0] != tabelka[i][0]){
            wartosc1 = wartosc2;
            wartosc2 = tabelka[i][1];
            if(i < l_wezlow - 1){
                if(tabelka[i][0] == tabelka[i + 1][0]) 
                    p_pochodna = tabelka[i + 1][1];
            }
        }
        if(tabelka[i][0] == tabelka[i - 1][0]){
            tabelka[i][2] = p_pochodna;  
            }
        else tabelka[i][2] = (wartosc2 - wartosc1)/ (tabelka[i][0] - tabelka[i - 1][0]);
    }

    for(int i = 0; i < l_wezlow; i++){
        cout << "x[" << i << "]: " << tabelka[i][0] << "    " << tabelka[i][1] << "    "; 
        if(i > 0){
            cout << tabelka[i][2] << "  ";
        }
        cout << endl;
    }
}


double hermiteU(int l_wezlow, vector<double> wezly, vector<int> krotnosci, vector<double> wartosci, double punkt){

    vector<vector<double>> tabelka(l_wezlow, vector<double>(l_wezlow + 1));
    double wynik = 0;
    double rob, pochodna, wartosc1, wartosc2;
    int indeks_wartosci;

    //UZUPELNIAMY PIERWSZE 2 KOLUMNY TABLICY IR
    for(int i = 0; i < l_wezlow; i++){
        tabelka[i][0] = wezly[i];
        tabelka[i][1] = wartosci[i];
    }

    if(tabelka[0][0] == tabelka[1][0]){
        pochodna = tabelka[1][1];
    }

     wartosc2 = tabelka[0][1];
    if(tabelka[0][0] == tabelka[1][0]){
        pochodna = tabelka[1][1];
    }
    for(int i = 1; i < l_wezlow; i++){
        if(tabelka[i - 1][0] != tabelka[i][0]){
            wartosc1 = wartosc2;
            wartosc2 = tabelka[i][1];
            if(i < l_wezlow - 1){
                if(tabelka[i][0] == tabelka[i + 1][0]) 
                    pochodna = tabelka[i + 1][1];
            }
        }
        if(tabelka[i][0] == tabelka[i - 1][0]){
            tabelka[i][2] = pochodna;  
            }
        else tabelka[i][2] = (wartosc2 - wartosc1)/ (tabelka[i][0] - tabelka[i - 1][0]);
    }
    
    //LICZENIE ILORAZOW ROZNICOWYCH 
    for(int j = 3; j <= l_wezlow; j++){     //JEDZIEMY W DOL KOLUMNAMI
        wartosc2 = tabelka[0][0];
        indeks_wartosci = 0;

        for(int i = j - 1; i < l_wezlow; i++){  // LECIMY WIERSZ PO WIERSZU W KAZDEJ KOLUMNIE, ZA KAZDYM RAZEM ZACZYNAJAC NIZEj
            if(i < l_wezlow - j){
                if(wartosc2 == tabelka[indeks_wartosci + j - 1][0]);
                    pochodna = tabelka[indeks_wartosci + j - 1][1];
                }
                else{ 
                    for(int l = 0; indeks_wartosci + l < l_wezlow; l++){
                        if(wartosc2 != tabelka[indeks_wartosci + l][0]){
                            wartosc2 = tabelka[indeks_wartosci + l][0];
                            indeks_wartosci += l;
                            if(indeks_wartosci + l + j - 1 < l_wezlow + 1) 
                                pochodna = tabelka[indeks_wartosci + l + j - 1][1];
                            break;
                        }
                    }
                } 

            if(tabelka[i][0] == tabelka[i - j + 1][0]){
                tabelka[i][j] = pochodna;
                cout << pochodna << endl;
                for(int k = 1; k < j; k++) {
                    tabelka[i][j] /= k; //DZIELIMY PRZEZ ODPOWIEDNIA SILNIE 
                }

            }
            else{
                tabelka[i][j] = (tabelka[i][j - 1] - tabelka[i - 1][j - 1]) / (tabelka[i][0] - tabelka[i - j + 1][0]);
            }
        }
    }
    
    //OBLICZANIE WARTOSCI WIELOMIANU W PUNKCIE
    for(int i = 0; i < l_wezlow; i++){ //SUMUJEMY WSZYSTKIE GORNE IR
        rob = 1;
        for(int k = 0; k <= i - 1; k++){ //WYLICZAMY X - Xi OD PUNKTU
            rob *= (punkt - tabelka[k][0]); // TAK JAK W NEWTONIE
        }
        wynik += (tabelka[i][i + 1]*rob); // DODAJEMY ROBA
    }

    //WYSWIETLANIE TABELKI
    cout << endl << "TABELKA: " << endl;
    for(int i = 0; i < l_wezlow; i++){
        cout << "x[" << i << "]: " << tabelka[i][0] << "    " << tabelka[i][1] << "    "; 
        for(int j = 0; j < i; j++){
            cout << "tab " << i << " " << j + 2 << " :" << tabelka[i][j + 2] << "    ";
        }
        cout << endl;
    }
    cout << endl;

    return wynik;
}


/*

    //PRZYGOTOWUJEMY WARTOSC DO ODJECIA NIE WIEM CZY SIE PRZYDADZA, A I POCHODNA
    wartosc2 = tabelka[0][1];

 else {
        wartosc1 = wartosc2;
        wartosc2 = tabelka[1][1];


if(tabelka[i - 1][0] != tabelka[i][0]){ // ZAMIANA WARTOSCI W ZAGDNIEZDZONEJ PETLI
            wartosc1 = wartosc2;
            wartosc2 = tabelka[i][j - 1];
            indeks_wartosci = i;
            }



*/