//cari menggunakan upper_bound
//bandingkan selisih X antara upper_bound & upper_bound - 1
#include <bits/stdc++.h>
using namespace std;

long long N, X;

long long bandingkanUpperBound(long long* A) {
    long long* up_B1 = upper_bound(A, A + N, X);
    long long ex = up_B1 - A;
    long long ye = max(0ll, (up_B1 - A) - 1ll);
    if(abs(A[ex] - X) < abs(A[ye] - X)) return ex;
    return ye;
}

int main() {
    cin >> N >> X;
    long long A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    cout << A[bandingkanUpperBound(A)] << endl;
}