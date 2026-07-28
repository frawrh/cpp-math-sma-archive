#include <bits/stdc++.h>
using namespace std;

long long N, Q;
vector <long long> A;

long long banyakBebek(long long X, long long Y) {
    //(indeks upper_bound Y - 1) - (indeks upper_bound X)
    long long ex = upper_bound(A.begin(), A.end(), X) - A.begin();
    
    long long up_bY = upper_bound(A.begin(), A.end(), Y) - A.begin();
    long long yee = up_bY- 1;
    
    if(yee - ex >= 0) return yee - ex + 1;
    return 0;
}

int main() {
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        long long X, Y;
        cin >> X >> Y;
        cout << banyakBebek(X, Y) << endl;
    }
}