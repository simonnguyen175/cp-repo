#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
vector<int> cont;
map<int, int> id;
int bit[N];

void update(int u){
    for (; u >= 1; u -= u&(-u)) bit[u] ++;
}

int get(int u){
    int res = 0;
    for (; u <= n; u += u&(-u)) res += bit[u];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("kite.inp", "r") ){
        freopen("kite.inp", "r", stdin);
        freopen("kite.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cont.pb(a[i]);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    for (int i = 1; i <= n; i ++){
        cout << get(id[a[i]]+1) + 1 << '\n';
        update(id[a[i]]);
    }

    return 0;
}
