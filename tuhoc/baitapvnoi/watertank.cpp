#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int h[N], bit[N];
map<int, int> id;

void upd(int u, int v){
    for (; u >= 1; u -= u&-u) bit[u] = min(bit[u], v);
}

void upd1(int u, int v){
    for (; u >= 1; u -= u&-u) bit[u] = max(bit[u], v);
}

int get(int u){
    int res = n+1;
    for (; u <= n; u += u&-u) res = min(res, bit[u]);
    return res;
}

int get1(int u){
    int res = 0;
    for (; u <= n; u += u&-u) res = max(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    vector<int> cont;
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
        cont.pb(h[i]);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    long long ans = 0;
    for (int i = 1; i <= n; i ++) bit[i] = n + 1;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, 1LL*h[i]*(i-get(id[h[i]])-1));
        upd(id[h[i]], i);
    }

    for (int i = 1; i <= n; i ++) bit[i] = 0;
    for (int i = n; i >= 1; i --){
        ans = max(ans, 1LL*h[i]*(get1(id[h[i]])-i-1));
        upd1(id[h[i]], i);
    }

    cout << ans;

    return 0;
}
