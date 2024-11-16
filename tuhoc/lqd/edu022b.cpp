#include<bits/stdc++.h>
using namespace std;

int a[(int)1e5+5];
map<int, int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("NEGPAIRS.INP", "r", stdin);
    freopen("NEGPAIRS.out", "w", stdout);

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        ans += d[-x];
        d[x] ++;
    }
    cout << ans;
}
