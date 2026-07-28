//N
//X[i]
//Y[i]

//urutkan X dari terbesar, Y dari terkecil
//kalikan sesuai indeks
//jumlahkan

#include <bits/stdc++.h>
using namespace std;

long long N;

long long perkalianSkalar(long long X[], long long Y[]) {
    long long hasil = 0;
    
    for(int i = 0; i < N; i++) {
        hasil += X[i] * Y[i];
    }
    
    return hasil;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    long long X[N], Y[N];
    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    
    sort(X, X + N, greater<long long>());
    sort(Y, Y + N);
    
    cout << perkalianSkalar(X, Y) << endl;


}