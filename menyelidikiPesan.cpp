#include <bits/stdc++.h>
using namespace std;

//ikat setiap unsur dengan unsur lain, jangan sampai ada unsur yang sama
//jika ada yang ditemukan lebih dari sekali dengan hasil beda, cout bingung
//jika tidak keluarkan hasil, yang tidak ada informasi isi dengan '?'

int N;
string pesan1;
map <char, char> artiPesan;
map<char, char> jadiKode;

bool bingung() {
    //catat arti pesan dan deteksi apakah pak dengklek bingung
    for(int i = 0; i < N; i++) {
        char a;
        cin >> a;
        if(i == 0){
            artiPesan[a] = pesan1[i];
            jadiKode[pesan1[i]] = a;
        } else {
            auto it = artiPesan.find(a);
            if(it != artiPesan.end()) {
                if(artiPesan[a] != pesan1[i]) return true;
            }
            auto ti = jadiKode.find(pesan1[i]);
            if(ti != jadiKode.end()) {
                if(jadiKode[pesan1[i]] != a) return true;
            }
            
            artiPesan[a] = pesan1[i];
            jadiKode[pesan1[i]] = a;
        }
    }
    return false;
}

int main() {
    cin >> N;
    cin >> pesan1;
    
    if(bingung()) {
        int pesan2;
        cin >> pesan2;
        cout << "Pak Dengklek bingung" << endl;
    } else {
        for(int i = 0; i < N; i++) {
            char b;
            cin >> b;
            auto it = artiPesan.find(b);
            if(it != artiPesan.end()) cout << it->second;
            else cout << '?';
        }
        cout << endl;
    }
}