#include <bits/stdc++.h>
using namespace std;

//cari panjang string
//cari akar
//jika akar x akar > panjang string maka tambahkan '.' sebanyak selesih keduanya
//keluarkan hasilnya, modif agar setelah sebanyak akar angka maka mengeluarkan secara terbalik

string Str;

int cariSisi() {
    int panjangStr = Str.size();
    int sisiPersegi = sqrt(panjangStr);
    if(sisiPersegi * sisiPersegi != panjangStr) {
        sisiPersegi++;
        int selisih = (sisiPersegi * sisiPersegi) - panjangStr;
        for(int i = 0; i < selisih; i++) {
            Str = Str + ".";
        }
    }
    return sisiPersegi;
}

void cetakHasil(int sisi) {
    bool terbalik = false;
    for(int i = 0; i < Str.size(); i++) {
        if(!terbalik) {
            cout << Str[i];
        } else {
            int x = i - (i % sisi);
            int y = sisi - (i % sisi) - 1;
            cout << Str[x + y];
        }
        if(i > 0 && i % sisi == sisi - 1) {
            cout << endl;
            terbalik = !terbalik;
        }
    }
}

//5 = 3, 4 = 4, 3 = 5
//i - (i % sisi) = 4 - 1 = 3 -> 3 + 1 = 4 

//2 = 0, 1 = 1, 0 = 2
//i % sisi = 0, sisi = 3
//sisi - (i % sisi) - 1

//i + sisi - (i % sisi) - 1 

int main() {
    cin >> Str;
    
    int sisi = cariSisi();
    cetakHasil(sisi);
}