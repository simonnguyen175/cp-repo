#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int sl[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    /// sang uoc tinh so luong uoc cua tat ca các số từ 1->N( N = 1e6 )
    for (int i = 1; i <= N-5; i ++) // ước của j
    for (int j = i; j <= N-5; j += i) // bội của i
        sl[j] ++;

    int q;
    cin >> q;
    while ( q -- ){
        int n;
        cin >> n;
        cout << sl[n] << '\n';
    }

    return 0;
}
