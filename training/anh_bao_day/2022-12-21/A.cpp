#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], s[N];
int bit[2*N];

void upd(int u){
    for (; u <= 2*n; u += u&-u)
        bit[u] ++;
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res += bit[u];
    return res;
}

bool check(int x){
    for (int i = 1; i <= 2*n; i ++) bit[i] = 0;
    for (int i = 1; i <= n; i ++)
        if ( a[i] < x ) s[i] = -1;
        else s[i] = 1;

    ll cnt = 0;
    upd(0+n);
//    cerr << "here\n";
    for (int i = 1; i <= n; i ++){
        s[i] += s[i-1];
        cnt += get(s[i]+n);
        upd(s[i]+n);
    }

    return cnt >= 1ll * n * (n+1) / 4;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    vector<int> cont;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cont.pb(a[i]);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

//    cout << check(30) << '\n';
    int lo = 0, hi = cont.size()-1, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(cont[mid]) ) res = cont[mid], lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res;

    return 0;
}
