#include <bits/stdc++.h>
using namespace std;

void cekAgakPrima(int bilangan) {
    int bisaDibagi = 0;
    for(int i = 1; i * i <= bilangan; i++) {
        if(bilangan % i == 0) {
            bisaDibagi+=2;
        }
    }
    
    if(bisaDibagi <= 4) {
        cout << "YA" << endl;
    } else {
        cout << "BUKAN" << endl;
    }
}

int main() {
    int N;
    cin >> N;
    
    int bilangan[N];
    
    for(int i = 0; i < N; i++) {
        cin >> bilangan[i];
        cekAgakPrima(bilangan[i]);
    }
}