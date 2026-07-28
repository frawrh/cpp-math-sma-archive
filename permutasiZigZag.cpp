#include <bits/stdc++.h>
using namespace std;

int N;
int hasil[10];
bool visited[10];

bool memenuhiSyarat(int i) {
    if(hasil[i - 1] < hasil[i] && hasil[i] > hasil[i + 1]) return true;
    if(hasil[i - 1] > hasil[i] && hasil[i] < hasil[i + 1]) return true;
    return false;
}

bool zigzag() {
    //dari 2-(N - 1) cek apakah memenuhi zig zag
    for(int i = 2; i < N; i++) {
        if(!memenuhiSyarat(i)) return false;
    }
    return true;
}

bool kurangDariTiga() {
    if(N == 1) return true;
    if(N == 2 && hasil[1] != hasil[2]) return true;
    return false; 
}

void coba(int kedalaman) {
    if(kedalaman > N) {
        if(kurangDariTiga() || zigzag()) {
            for(int i = 1; i <= N; i++) {
                cout << hasil[i];
            }
            cout << endl;
        }
    } else {
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                hasil[kedalaman] = i;
                coba(kedalaman + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> N;
    hasil[0] = 0;
    memset(visited, false, sizeof(visited));

    coba(1);
}