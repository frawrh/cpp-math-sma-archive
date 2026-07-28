//K
//P[i] -> kapasitas masing2 kandang
//C[i] -> harga di masing2 kandang
//N
//B[i] -> berat bebek

//urutkan Ci dari terkecil
//urutkan Bi dari terbesar
//masukkan bebek dari terbesar, jawaban += Bi * Ci

#include <bits/stdc++.h>
using namespace std;

long long K, N;
vector<long long> beratBebek;

struct kandangBebek {
    long long kapasitas;
    long long harga;
};

long long hargaTermurah(vector<kandangBebek> kandang) {
    long long jawaban = 0;
    int j = 0; //indeks struct kandangBebek
    long long P = kandang[j].kapasitas;

    for(int i = 0; i < N; i++) { //i = indeks berat bebek
        if(P == 0) {
            j++;
            P = kandang[j].kapasitas;
        }

        jawaban += (beratBebek[i] * kandang[j].harga);
        P--;
    }

    return jawaban;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    vector<kandangBebek> kandang(K);
    for(int i = 0; i < K; i++) {
        cin >> kandang[i].kapasitas; //P
    }
    for(int i = 0; i < K; i++) {
        cin >> kandang[i].harga; //C
    }

    cin >> N;
    beratBebek.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> beratBebek[i]; //B
    }

    //urutkan harga dari termurah
    sort(kandang.begin(), kandang.end(), [] (kandangBebek a, kandangBebek b) {
        return a.harga < b.harga;
    });
    //urutkan berat bebek dari terberat
    sort(beratBebek.begin(), beratBebek.end(), greater<long long>());

    cout << hargaTermurah(kandang) << endl;
}