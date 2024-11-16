#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define x first
#define y second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, Q;
int type[2*N];
pi a[N], q[2*N];
vector<int> contx, conty;
set<int> setx[2*N], sety[2*N];
map<int, int> idx, idy;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("triangle.inp", "r") ){
        freopen("triangle.inp", "r", stdin);
        freopen("triangle.out", "w", stdout);
    }

    cin >> n >> Q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        contx.pb(a[i].x); conty.pb(a[i].y);
    }

    for (int i = 1; i <= Q; i ++){
        cin >> type[i] >> q[i].x >> q[i].y;
        contx.pb(q[i].x); conty.pb(q[i].y);
    }

    sort(contx.begin(), contx.end());
    sort(conty.begin(), conty.end());

    contx.erase(unique(contx.begin(), contx.end()), contx.end());
    conty.erase(unique(conty.begin(), conty.end()), conty.end());

    for (int i = 0; i < contx.size(); i ++) idx[contx[i]] = i + 1;
    for (int i = 0; i < conty.size(); i ++) idy[conty[i]] = i + 1;

    for (int i = 1; i <= n; i ++){
        setx[idx[a[i].x]].insert(a[i].y);
        sety[idy[a[i].y]].insert(a[i].x);
    }

    for (int i = 1; i <= Q; i ++){
        if ( type[i] == 1 ){
            setx[idx[q[i].x]].insert(q[i].y);
            sety[idy[q[i].y]].insert(q[i].x);
        }

        if ( type[i] == 2 ){
            setx[idx[q[i].x]].erase(q[i].y);
            sety[idy[q[i].y]].erase(q[i].x);
        }

        if ( type[i] == 3 ){
            if ( setx[idx[q[i].x]].empty() || sety[idy[q[i].y]].empty() ) { cout << 0 << '\n'; continue; }
            ll l = max(abs(*setx[idx[q[i].x]].cbegin()-q[i].y), abs(*setx[idx[q[i].x]].rbegin()-q[i].y));
            ll r = max(abs(*sety[idy[q[i].y]].cbegin()-q[i].x), abs(*sety[idy[q[i].y]].rbegin()-q[i].x));
            ll ans = l * r;
            cout << ans / 2 << (ans % 2 ? ".5" : "" ) << '\n';
        }
    }

    return 0;
}
