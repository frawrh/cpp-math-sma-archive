//N
//A[N] -> buat dalam array total hewan dengan A[i - 1] + A[i - 2]
//Q
//X[Q] -> cari menggunakan lower_bound

#include <bits/stdc++.h>
using namespace std;

long long N, Q;
vector<long long> A, X, totalHewan;

long long hewanJenisKe(long long cocomelon) {
    long long jenis = lower_bound(totalHewan.begin(), totalHewan.end(), cocomelon) - totalHewan.begin();
    return jenis;
}

int main() {
    cin >> N;
    A.resize(N + 1);
    totalHewan.resize(N + 1);
    totalHewan[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        totalHewan[i] = A[i];
        totalHewan[i] += totalHewan[i - 1];
    }
    
    cin >> Q;
    X.resize(Q + 1);
    for(int i = 1; i <= Q; i++) {
        cin >> X[i];
        cout << hewanJenisKe(X[i]) << endl;
    }
}