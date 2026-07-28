//N
//A[i] #kebawah
//cari median, ganjil ditengah, genap rata2 2 di tengah

#include <bits/stdc++.h>
using namespace std;

int N;
double hasil;
vector <double> A;

void median() {
    if(N % 2 == 1) {
        hasil = A[N / 2];
    } else {
        hasil = (A[N/2] + A[N/2 - 1]) / 2;
    }
}

int main() {
    cin >> N; //2
    
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    median();
    cout << fixed << setprecision(1) << hasil << endl;
}