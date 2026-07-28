//N K
//A[N] -> jumlahkan A dengan A sebelumnya
//B[K] -> cari dengan upper_bound - 1
#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector <long long> A, B;

long long lastPatok(long long sahur) {
    long long tungTung = upper_bound(A.begin(), A.end(), sahur) - A.begin();
    return tungTung - 1;
}

int main() {
   cin >> N >> K;
   A.resize(N + 1);
   B.resize(K + 1);
   A[0] = 0;
   for(int i = 1; i <= N; i++) {
       cin >> A[i];
       A[i] += A[i - 1];
   }
   for(int i = 1; i <= K; i++) {
       cin >> B[i];
       cout << lastPatok(B[i]) << endl;
   }
}