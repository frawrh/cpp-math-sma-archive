#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Q, N;
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        cin >> N;
        bool prima = 1;
        
        if(N == 1) {
            prima = 0;
        } else if(N == 2 || N == 3) {
            prima = 1;
        } else {
            for(int j = 2; j * j <= N; j++) {
                if (N % j == 0) {
                    prima = 0;
                    break;
                }
            }
        }
        
        if(prima) {
            cout << "YA" << endl;
        } else {
            cout << "BUKAN" << endl;
        }
    }
}