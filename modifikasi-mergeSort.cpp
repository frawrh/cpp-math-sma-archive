//merge short

#include <bits/stdc++.h>
using namespace std;

long long inversi = 0;

void merge(long long A[], long long aLeft, long long aRight, long long bLeft, long long bRight) {
    long long size = bRight - aLeft + 1;
    long long temp[size];
    long long i = 0;
    long long aIndex = aLeft;
    long long bIndex = bLeft;

    while(aIndex <= aRight && bIndex <= bRight) {
        if(A[aIndex] <= A[bIndex]) {
            temp[i] = A[aIndex];
            aIndex++;
        } else {
            inversi += (aRight - aIndex + 1);

            temp[i] = A[bIndex];
            bIndex++;
        }
        i++;
    }

    while(aIndex <= aRight) {
        temp[i] = A[aIndex];
        aIndex++;
        i++;
    }
    while(bIndex <= bRight) {
        temp[i] = A[bIndex];
        bIndex++;
        i++;
    }

    for(int j = 0; j < size; j++) {
        A[aLeft + j] = temp[j];
    }
}

void mergeShort(long long A[], long long left, long long right) {
    long long mid;

    if(left == right) {
        return;
    } else {
        mid = (left + right) / 2;
        mergeShort(A, left, mid);
        mergeShort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;
    long long A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mergeShort(A, 0, N - 1);

    cout << inversi << endl;
}