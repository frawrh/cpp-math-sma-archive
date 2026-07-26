//kpk
#include <bits/stdc++.h>
using namespace std;

long long kpk(long long a, long long b) {
    return (a* b) / gcd(a,b);
}

int main() {
    int jumlahPedagang;
    long long kapeka;
    cin >> jumlahPedagang;
    long long kunjunganTiap[jumlahPedagang];
    
    for(int i = 0; i < jumlahPedagang; i++) {
        cin >> kunjunganTiap[i];
        if(i == 1) kapeka = kpk(kunjunganTiap[i], kunjunganTiap[i - 1]);
        else kapeka = kpk(kunjunganTiap[i], kapeka);
    }
    
    cout << kapeka << endl;
}