#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
#define mk make_pair
using namespace std;
const int maxn = 100010;
int uf[maxn],be[maxn];
LL d[maxn];
bool vis[maxn] = {false};
vector< pair<int,int> >g[maxn];
vector< pair<LL,pair<int,int> > >e;
priority_queue< pair<LL,int> >q;
int Find(int x){
    if(uf[x] != x)
        uf[x] = Find(uf[x]);
    return uf[x];
}
int main(){
    //freopen("NOBITA.INP","r",stdin);
    //freopen("NOBITA.OUT","w",stdout);
    int u,v,i,k,tu,tv,n,m;
    LL w,ans = 0;
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d%I64d",&u,&v,&w);
        g[u].push_back(mk(v,w));
        g[v].push_back(mk(u,w));
    }
    memset(d,3,sizeof(d));
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        scanf("%d",&u);
        d[u] = 0;
        uf[u] = u;
        be[u] = u;
        q.push(mk(0,u));
    }
    while(!q.empty()){
        u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(i = 0; i < g[u].size(); i++){
            v = g[u][i].first;
            w = g[u][i].second;
            if(be[v]) e.push_back(mk(d[u]+d[v]+w,mk(be[u],be[v])));
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                be[v] = be[u];
                q.push(mk(-d[v],v));
            }
        }
    }
    sort(e.begin(),e.end());
    for(i = 0; i < e.size(); i++){
        u = e[i].second.first;
        v = e[i].second.second;
        tu = Find(u);
        tv = Find(v);
        if(tu != tv){
            ans += e[i].first;
            uf[tu] = tv;
        }
    }
    printf("%I64d\n",ans+d[1]);
    return 0;
}
