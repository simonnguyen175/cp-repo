#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;

struct edge{
    int u, v, w;
};

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int n;
vector<edge> canh;
int root[N];
long long ans = 0;

int getroot(int u){
    if ( root[u] == 0 ) return u;
    return root[u] = getroot(root[u]);
}

void makeKruskal(){
    sort(canh.begin(), canh.end(), cmp);
    for (auto x : canh){
        int u = x.u, v = x.v, w = x.w;
        u = getroot(u); v = getroot(v);
        if ( u == v ) continue;
        root[u] = v;
        ans += w;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int w; cin >> w;
        canh.push_back({0, i, w});
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        int w; cin >> w;
        canh.push_back({i, j, w});
    }

    makeKruskal();

    cout << ans;

    return 0;
}
