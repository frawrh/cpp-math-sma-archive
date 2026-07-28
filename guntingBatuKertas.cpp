//N
//string GBK baris 1
//string GBK baris 2

//hitung jumlah GBK di masing2 baris
//hasil += min dari setiap pasangan GK, BG, & KB

#include <bits/stdc++.h>
using namespace std;

int N, G1, B1, K1, hasil = 0;

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        char GBK;
        cin >> GBK;

        if(GBK == 'G') G1++;
        else if(GBK == 'B') B1++;
        else if(GBK == 'K') K1++;
    }

    for(int i = 0; i < N; i++) {
        char GBK;
        cin >> GBK;

        if(GBK == 'G') {
            if(B1 > 0) {
                hasil++;
                B1--;
            }
        } else if(GBK == 'B') {
            if(K1 > 0) {
                hasil++;
                K1--;
            }
        } else if(GBK == 'K') {
            if(G1 > 0) {
                hasil++;
                G1--;
            }
        }
    }

    cout << hasil << endl;
}