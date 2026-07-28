//buat array berisi 2^k dari 0-61
//A = K - B
//cari x, nilai dalam array tersebut yang nilainya paling mendekati A tetapi <= A
//A = A - arr[x]
//ulangi

#include <bits/stdc++.h>
using namespace std;

long long duaPangkat[62];
long long hasil[62];

long long duaPangkat_i(int i) {
    if(i == 0) return 1;
    if(i == 1) return 2;
    if(i % 2 == 0) return duaPangkat[i / 2] * duaPangkat[i / 2];
    return 2 * duaPangkat[i / 2] * duaPangkat[i / 2];
}

void isiArrayDuaPangkat() {
    for(int i = 0; i <= 61; i++) {
        duaPangkat[i] = duaPangkat_i(i);
    }
}

long long cariArray(long long A) {
    long long* up_b = upper_bound(duaPangkat, duaPangkat + 62, A);
    return max(0LL, (up_b - duaPangkat) - 1LL);
}

int main() {
    long long B, K, jumlahPemberat = 0;
    cin >> B;
    cin >> K;
    
    isiArrayDuaPangkat();
    
    long long A = K - B;
    
    int ii = 0;
    
    while(A > 0) {
        hasil[ii] = cariArray(A);
        A -= duaPangkat[hasil[ii]];
        jumlahPemberat++;
        ii++;
    }
    
    for(int i = 0; i < jumlahPemberat; i++) {
        cout << duaPangkat[hasil[i]] << endl;
    }
}