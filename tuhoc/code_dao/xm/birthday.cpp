#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("birthday.inp", "r", stdin);
    freopen("birthday.out", "w", stdout);

    long long n;
    cin >> n;
    long long res = 1;
    while ( res * 2 <= n ) res *= 2;
    cout << res;

    return 0;
}
