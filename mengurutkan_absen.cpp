#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <string> nama(N);
    
    for(int i = 0; i < N; i++) {
        cin >> nama[i];
    }
    
    sort(nama.begin(), nama.end(),[](const string &A, const string &B){
        if(A.size() != B.size()) return A.size() < B.size();
        else return A < B;
    });
    
    for(int i = 0; i < N; i++) {
        cout << nama[i] << endl;
    }
}