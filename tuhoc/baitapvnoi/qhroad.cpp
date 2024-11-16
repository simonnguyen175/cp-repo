#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, t;
int q[N];
pair<int, int> a[N];
bool era[N];
int hang[N], cha[N], ans[N];

int getroot(int u){
    if ( cha[u] == 0 ) return u;
    return cha[u] = getroot(cha[u]);
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m >> t;
    for (int i = 1; i <= m; i ++)
        cin >> a[i].first >> a[i].second;

    memset(era, 0, sizeof era);
    for (int i = 1; i <= t; i ++){
        cin >> q[i];
        era[q[i]] = 1;
    }

    int region = n;
    for (int i = 1; i <= m; i ++)
        if ( !era[i] ){
            int u = a[i].first; u = getroot(u);
            int v = a[i].second; v = getroot(v);

            if ( u == v ) continue;

            region --;
            if ( hang[u] < hang[v] ) swap(u, v);
            cha[v] = u;
            if ( hang[u] == hang[v] ) hang[u] ++;
        }

    ans[t] = region;
    for (int i = t; i >= 2; i --){
        int u = a[q[i]].first; u = getroot(u);
        int v = a[q[i]].second; v = getroot(v);

        if ( u == v ){
            ans[i-1] = region;
            continue;
        }

        region --;
        if ( hang[u] < hang[v] ) swap(u, v);
        cha[v] = u;
        if ( hang[u] == hang[v] ) hang[u] ++;
        ans[i-1] = region;
    }

    for (int i = 1; i <= t; i ++)
        cout << ans[i] << '\n';

    return 0;
}
