#include <bits/stdc++.h>
using namespace std;

int pangkat(int N, int i) {
    int jumlahPangkat = 0;
    
    while(N % i == 0) {
        N /= i;
        jumlahPangkat++;
    }
    
    return jumlahPangkat;
}

void cekFaktorisasiPrima(int N) {
    string hasil;
    string iniTemplate = " x ";
    bool pertama = true;
    
    for(int i = 2; i <= N; i++) {
        if(N % i == 0) {
            int Pangkat = pangkat(N, i);
            if(pertama) {
                if(Pangkat == 1) {
                    hasil = to_string(i);
                pertama = false;
                } else {
                    hasil = to_string(i) + '^' + to_string(Pangkat);
                pertama = false;
                }
            } else {
                if(Pangkat == 1) {
                    hasil = hasil + iniTemplate + to_string(i);
                } else {
                    hasil = hasil + iniTemplate + to_string(i) + '^' + to_string(Pangkat);
                }
            }
            while(Pangkat > 0) {
                N /= i;
                Pangkat--;
            }
        }
    }
    
    cout << hasil << endl;
}

int main() {
    int N;
    cin >> N;
    
    cekFaktorisasiPrima(N);
}