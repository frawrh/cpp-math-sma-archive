//cetak 1 2 3 4, jika seimbang lanjut 5 6 7 8
//jika berat kiri, timbang (bandingkan) kedua bilangan yang ada dikiri, begitu sebaliknya

#include <bits/stdc++.h>
using namespace std;

string dariSono;

void timbang(int a, int b) {
    cout << "?" << endl;
    cout << a << endl;
    cout << b << endl;
    
    cin >> dariSono;
    
    if(dariSono == "KIRI") {
        cout << "! " << a << endl;
    } else { //(kanan)
        cout<< "! " << b << endl;
    }
}

void timbangAwal() {
    cout<< "?" << endl;
    for(int i = 1; i <= 4; i++) {
        cout << i << " ";
        if(i % 2 == 0) cout << endl;
    }
    cin >> dariSono;
    
    if(dariSono == "SEIMBANG") {
        cout<< "?" << endl;
        for(int i = 5; i <= 8; i++) {
            cout << i << " ";
            if(i % 2 == 0) cout << endl;
        }
        cin >> dariSono;
        if(dariSono == "KIRI") {
            timbang(5, 6);
        } else {
            timbang(7, 8);
        }
    } else if(dariSono == "KIRI") {
        timbang(1, 2);
    } else { //(kanan)
        timbang(3, 4);
    }
}

int main() {
    timbangAwal();
}