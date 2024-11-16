#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;

int n, m, k, ans;
string t;
int vr[N];

void anal(int len){
    for (int i = len+1; i <= m; i ++)
        if ( t[i] == t[i-len] ) vr[i] = 0;
        else vr[i] = 1;


    int s = 0;

    for (int i = len+1; i <= 2*len; i ++)
        s += vr[i];

    if ( s <= k ){
        ans = len;
        return;
    }

    for (int i = 2*len+1; i <= m; i ++){
        s = s + vr[i] - vr[i-len];
        if ( s <= k ){
            ans = len;
            return;
        }
    }
}

void solve(int k){
    for (int i = 1; i <= m/2; i ++)
        anal(i);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("virus.inp", "r") ){
        freopen("virus.inp", "r", stdin);
        freopen("virus.out", "w", stdout);
    }

    cin >> n >> t;

    m = t.size();
    t = ' ' + t;

    for (int i = 1; i <= n; i ++){
        cin >> k;
        solve(k);
    }

    return 0;
}
