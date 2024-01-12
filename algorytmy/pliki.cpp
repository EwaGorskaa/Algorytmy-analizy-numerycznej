#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main(){

    ifstream plik("we.txt");
    string tekst;
    ofstream plik2("wy.txt");

    while(plik>>tekst){
        if(tekst == "jak"){
            cout << tekst << " ";
            plik2 << tekst << endl;
        }
    }
    plik.close();


    return 0;
}