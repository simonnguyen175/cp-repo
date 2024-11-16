#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

struct edg{
    int u, v, w;
};

bool cmp(edg a, edg b){
    return a.w < b.w;
}

int n, m;
edg canh[N];
int cha[N], hang[N];

int getroot(int u){
    if ( cha[u] == 0 ) return u;
    return cha[u] = getroot(cha[u]);
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> canh[i].u >> canh[i].v >> canh[i].w;
    sort(canh + 1, canh + 1 + m, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i ++){
        int u = getroot(canh[i].u), v = getroot(canh[i].v);
        if ( u == v ) continue;
        ans = max(ans, canh[i].w);
        if ( hang[u] < hang[v] ) swap(u, v);
        cha[v] = u;
        if ( hang[u] == hang[v] ) hang[u] ++;
    }
    cout << ans;
    return 0;
}
