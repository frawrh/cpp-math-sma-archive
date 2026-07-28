//N X -> N karung beras, keranjang kapasitas X kg
//W[i] berat karung beras yang dijual
//C[i] harga beras per karung

//selain N tipe datanya double

//catat hargaPerKilo (C[i] / W[i]) dengan double, urutkan berdasarkan termahal
//jika X >= W[i] maka ambil semua, jawaban += C[i]
//jika X < W[i] && X > 0 ambil sebanyak sisa X dan jawaban += (X / W[i]) * C[i]

#include <bits/stdc++.h>
using namespace std;

int N;
double X;

struct karungBeras {
    double berat; //W
    double hargaPerKarung; //C
    double hargaPerKilo;
};

double hargaTermahal(vector<karungBeras> karung) {
    double jawaban = 0.0;
    int i = 0; //indeks karung

    while(X > 0 && i < N) {
        if(X >= karung[i].berat) {
            jawaban += karung[i].hargaPerKarung;
            X -= karung[i].berat;
        } else if(X < karung[i].berat) {
            jawaban += ((X / karung[i].berat) * karung[i].hargaPerKarung); //kepo kan tanpa tanda kurung
            X = 0;
        }
        i++;
    }

    return jawaban;
}

int main() {
    cin >> N >> X;
    vector <karungBeras> karung(N); 

    for(int i = 0; i < N; i++) {
        cin >> karung[i].berat; //W[i]
    }
    for(int i = 0; i < N; i++) {
        cin >> karung[i].hargaPerKarung; //C[i]
        karung[i].hargaPerKilo = karung[i].hargaPerKarung / karung[i].berat; //C[i] / W[i]
    }

    sort(karung.begin(), karung.end(), [] (karungBeras a, karungBeras b) {
        return a.hargaPerKilo > b.hargaPerKilo;
    });

    cout << fixed << setprecision(5) << hargaTermahal(karung) << endl;
}