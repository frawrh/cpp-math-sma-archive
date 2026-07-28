//jika sama lanjut, jika beda hapus a dan cek apakah sama

#include <bits/stdc++.h>
using namespace std;

string A, B;

bool bisa() {
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]) {
            A.erase(i, 1);
            if(A == B) return true;
        }
    }
    
    return false;
}

int main() {
   cin >> A;
   cin >> B;
   
   if(bisa()) cout << "Tentu saja bisa!" << endl;
   else cout << "Wah, tidak bisa :(" << endl;
}