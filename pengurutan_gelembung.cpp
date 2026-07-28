//1 3 4 7 8

//3 7 8 4 1
//1 3 7 8 4-> 4
//4 7 8-> 2

//cari min dari vector
//hasil += indeks min
//hapus min

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, hasil = 0;
    cin >> N;
    vector <int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    while(!(A.empty())) {
       auto min_it = min_element(A.begin(), A.end());
       int min_idx = distance(A.begin(), min_it);
       hasil += min_idx;
       A.erase(A.begin() + min_idx);
    }
    
    cout << hasil << endl;
    
}