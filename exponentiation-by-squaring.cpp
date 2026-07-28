//A B % 1.000.000
//jika genap maka A pangkat B/2 kuadrat
//jika ganjil maka pangkat dikurangi 1 & dikali A

//catat hasil tanpa dimodulo, jika hasilnya lebih dari 100,000 atau kurang dari 0 gunakan setw sama setfill

#include <bits/stdc++.h>
using namespace std;

long long mod = 1e6;

long long pangkat(long long A, long long B) {
    if(B == 1) return A;
    if(B == 2) return (A * A) % mod;

    if(B % 2 == 1) return (pangkat(A, B - 1) % mod)* A % mod;
    return pangkat(pangkat(A, B / 2), 2);
}

bool pangkatKecil(long long A, long long B) {
    int result = 1;
    
    while(B > 0) {
        if(B % 2 == 1) {
            result *= A;
            B--;
        }
        A *= A;
        B /= 2;
        
        if(result >= 1e5 || result <= 0) return false;
    }
    return true;
}

int main() {
    long long A, B;
    cin >> A >> B;

    A = A % mod;
    
    if(pangkatKecil(A, B)) {
        cout << pangkat(A, B) << endl;
    } else {
        cout << setw(6) << setfill('0') << pangkat(A, B) << endl;
    }
}