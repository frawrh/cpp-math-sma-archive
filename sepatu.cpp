//N M
//ukuran sepatu
//ukuran kaki bebek
//urutkan ukuran sepatu & ukuran kaki bebek
//dari 0-(M-1) selama N masih ada, cek kesesuaian dengan toleransi +1

#include <bits/stdc++.h>
using namespace std;

long long N, M;

int bebekYangDapatSepatuBaru(int S[], int B[]) {
    int jawaban = 0;
    int j = 0;

    for(int i = 0; i < N; i++) {
        if(j == M) break;

        if(S[j] == B[i] || S[j] == B[i] + 1) {
            jawaban++;
            j++;
        } else if(S[j] < B[i]) {
            while(S[j] < B[i] && j < M - 1) {
                j++;
                if(S[j] == B[i] || S[j] == B[i] + 1) {
                    jawaban++;
                    j++;
                }
            }
        }
    }

    return jawaban;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int ukuranKakiBebek[N];
    int ukuranSepatu[M];

    for(int i = 0; i < N; i++) {
        cin >> ukuranKakiBebek[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> ukuranSepatu[i];
    }

    sort(ukuranSepatu, ukuranSepatu + M);
    sort(ukuranKakiBebek, ukuranKakiBebek + N);
