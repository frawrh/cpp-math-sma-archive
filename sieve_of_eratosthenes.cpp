#include <bits/stdc++.h>
using namespace std;

long long bilanganPrima[77780];
bool used[1000000];
bool prima[1000000];
long long jumlah = 1;
//buat fungsi untuk mencatat bilangan prima dari 2-1,000,000
void cariBilanganPrima() {
    long long a = 2;
    //2,4,8,12
    //3,6,12
    //5,10
    //7,14
    while(jumlah < 77780 && a < 1000000) {
        if(used[a]) { //
            a++;
            continue;
        }
        if(!prima[a]) {
            a++;
            continue;
        }
        
        bilanganPrima[jumlah] = a;
        used[a] = true;
        jumlah++;

        for(int i = a * 2; i <= 1000000; i += a) {//
            prima[i] = false;
        }
        
    }
}

//untuk setiap masukan, cek bilangan prima ke k
int main() {
    int T;
    cin >> T;
    memset(prima, true, sizeof(prima));
    memset(used, false, sizeof(used));
    cariBilanganPrima();
    
    for(int i = 0; i < T; i++) {
        int K;
        cin >> K;
        cout << bilanganPrima[K] << endl;
    }
}