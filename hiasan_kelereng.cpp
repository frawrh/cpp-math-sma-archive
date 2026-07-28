//urutkan string berdasarkan leksikografis
//buat 3 variabel
//kumpulkan huruf pertama simpan dalam array a
//jika jumlah huruf selanjutnya > a, maka...
//b = a lalu simpan banyak huruf itu di a
//begitu juga selanjutnya sehingga a >= b >= c
//jika c bernilai 0, maka hasil = -1
//jika tidak, hasil = c * 3
//jika a > b hasil++
//jika b > c hasil++

#include <bits/stdc++.h>
using namespace std;

int N;
int a = 0, b = 0, c = 0;
vector <char> str;

void cariTempatDi_abc(int jumlah) {
    if(jumlah >= a) {
        c = b;
        b = a;
        a = jumlah;
    } else if(jumlah >= b) {
        c = b;
        b = jumlah;
    } else if(jumlah >= c) {
        c = jumlah;
    }
}

int jumlahKelereng() {
    char sementara = str[0];
    int jumlahSementara = 1;
    int hasil;

    for(int i = 1; i <= N; i++) {
        if(str[i] == sementara && i != N) {
            jumlahSementara++;
        } else {
            cariTempatDi_abc(jumlahSementara);
            jumlahSementara = 1;
            sementara = str[i];
        }
    }

    hasil = c * 3;
    if(a > c && a >= b) hasil++;
    if(b > c) hasil++;

    if(hasil < 3) return -1;
    return hasil;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    str.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> str[i];
    }

    sort(str.begin(), str.end());

    cout << jumlahKelereng() << endl;
}