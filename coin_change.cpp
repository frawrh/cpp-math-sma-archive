//N
//A[i] -> nilai koin
//K -> kembalian

//coin change

#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> A, memo;

int banyakKoinMinimal(int K) {
    if(K == 0) return 0;
    if(memo[K] != -1) return memo[K];

    int best = INT_MAX - 1;
    for(int i = 1; i <= N; i++) {
        if(A[i] <= K) {
            best = min(best, banyakKoinMinimal(K - A[i]) + 1);
        }
    }

    memo[K] = best;
    return best;
}

int main() {
    cin >> N;
    A.resize(N + 1);
    A[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    int K;
    cin >> K;
    memo.resize(K + 1);
    fill(memo.begin(), memo.end(), -1);
    
    int jawaban = banyakKoinMinimal(K);
    
    if(jawaban > 0 && jawaban < INT_MAX - 1) cout<< jawaban << endl;
    else cout << -1 << endl;
    
    
}