//N
//S D
//buat vector end time (S + D), urutkan
//for i = 0 to N
//jika start time >= startTime sekarang maka:
//jawaban++, start time+= D

#include <bits/stdc++.h>
using namespace std;

int N;

struct traktir {
    int S;
    int F;
    int D;
};

int banyakTemanMaksimal(vector<traktir> teman) {
    int banyakTeman = 0;
    int startTime = 0;

    for(int i = 0; i < N; i++) {
        if(startTime <= teman[i].S) {
            banyakTeman++;
            startTime = teman[i].F;
        }
    }

    return banyakTeman;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    vector<traktir> teman(N);
    for(int i = 0; i < N; i++) {
        int start, time;
        cin >> start >> time;
        teman[i].S = start;
        teman[i].F = start + time;
        teman[i].D = time;
    }
    
    sort(teman.begin(), teman.end(), [] (traktir a, traktir b) {
        return a.F < b.F;
    });

    cout << banyakTemanMaksimal(teman) << endl;
}