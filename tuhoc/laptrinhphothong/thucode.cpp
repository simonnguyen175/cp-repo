#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int n,i;
int Bool[MAX] = { 0 };
int A[MAX];

void xuat() {
    for (int j = 1; j <= i; j++)
        cout << A[i] << " ";
    cout << endl;
}

void Try(int k) {
    for (int j = 1; j <= n; j++) {
        if (!Bool[j]) {
            A[k] = j; 
            Bool[j] = 1;
            if (k == i)
                xuat();
            else
                Try(k + 1);
            Bool[j] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (i=1; i<=n; i++)
    	Try(1);
}
