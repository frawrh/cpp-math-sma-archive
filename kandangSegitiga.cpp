#include <bits/stdc++.h>
using namespace std;

int tigaFaktorial = 6;

int kaliMundur(int N, int jumlah) { //jumlah = berapa kali di kalikan
    if(N == 1 || jumlah == 0) return 1;
    return N * kaliMundur(N -  1, jumlah - 1);
}

int kombinasi(int N) {
    if(N < 3) return 0;
    if(N == 3) return 1;
    
    if(N - 3 > 3) return kaliMundur(N, 3) / tigaFaktorial;
    return kaliMundur(N, N - 3) / kaliMundur(N - 3, N - 3);
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
    }
    
    cout << kombinasi(N) << endl;
}