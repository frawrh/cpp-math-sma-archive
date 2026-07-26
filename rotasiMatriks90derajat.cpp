#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector <int>> matriks(N, vector<int> (M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matriks[i][j];
        }
    }
    
        for(int i = 0; i < M; i++) {
            for(int j = N - 1; j >= 0; j--) {
                cout << matriks[j][i] << " ";
            }
            cout << endl;
        }
}