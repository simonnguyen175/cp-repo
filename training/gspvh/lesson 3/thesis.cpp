#include<bits/stdc++.h>
using namespace std;

long long n, ans = 0;
string s;
vector<int> pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("thesis.inp", "r") ){
        freopen("thesis.inp", "r", stdin);
        freopen("thesis.out", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 1; i <= n; i ++)
        if ( s[i-1] == 'T' ) pos.push_back(i);
    for (int i = 0, j = 1; i < pos.size(); i ++, j += 2)
        ans += abs(pos[i]-j);
    cout << ans;
    return 0;
}
