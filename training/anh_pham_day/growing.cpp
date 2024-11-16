#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int K = 320;

int n, d;
struct oper{
    int l, r, w;
};
ll a[N], s[N];
vector<oper> ope[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> d;
    for (int i = 1; i <= d; i ++){
        int l, r, p, w;
        cin >> l >> r >> p >> w;
        if ( p > K )
            for (int j = l; j <= r; j += p)
                a[i] += w;
        else ope[p].pb({l, r, w});
    }

    for (int i = 1; i <= K; i ++) if ( ope[i].size() ){
        for (int j = 1; j <= n; j ++) s[j] = 0;

//        cout << i << " : \n";

        for (auto it : ope[i]){
            s[it.l] += it.w;
            if ( it.r + i <= n ) s[it.r+i] -= it.w;
//            cout << it.l << ' ' << it.r << ' ' << it.w << '\n';
        }

        for (int j = 1; j <= n; j ++){
            if ( j > i ) s[j] += s[j-i];
            a[j] += s[j];
        }

//        for (int j = 1; j <= n; j ++)
//            cout << s[j] << ' ';
//        cout << '\n';
//        cout << " -> ";
//        for (int j = 1; j <= n; j ++)
//            cout << a[j] << ' ';
//        cout << '\n';
    }

    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ';

    return 0;
}
