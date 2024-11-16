#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e5 + 5;

struct edge{
    int u, v, w;
};

bool cmp(edge a, edge b){
    return a.w > b.w;
}

int n, m;
edge canh[M];
int cha[N], hang[N], ans = 0;

int getroot(int u){
    if ( cha[u] == u ) return u;
    return cha[u] = getroot(cha[u]);
}

void makeKruskal(){
    for (int i = 1; i <= n; i ++)
        cha[i] = i;
    for (int i = 1; i <= m; i ++){
        int u = getroot(canh[i].u);
        int v = getroot(canh[i].v);

        if ( u == v ){
            ans += canh[i].w;
            continue;
        }

        if ( hang[u] < hang[v] ) swap(u, v);
        cha[v] = u;
        if ( hang[u] == hang[v] ) hang[u] ++;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> canh[i].u >> canh[i].v >> canh[i].w;
    }

    sort(canh + 1, canh + 1 + m, cmp);
    makeKruskal();

    cout << ans;

    return 0;
}
