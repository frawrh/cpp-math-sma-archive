//N B
//H[i]

//sort H[i] secara descending
//buat variabel total & hasil 
//selama total < B tambahkan H[i], hasil++
//cout hasil

#include <bits/stdc++.h>
using namespace std;

long long N, B;

long long jumlahBebekMinimal(long long H[]) {
    long long total = 0;
    long long i = 0;
    while(total < B) {
        total += H[i];
        i++;
    }
    return i;
}

int main() {
    cin >> N >> B;
    long long H[N];
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    sort(H, H + N, greater<long long>());
    
    cout << jumlahBebekMinimal(H) << endl;
    
}