#include <bits/stdc++.h>
#define ll long long
#define nmax 100005

using namespace std;

ll n,t,x,y;
vector<ll> adj[nmax],ad[nmax],ans;
bool vs1[nmax],vs2[nmax];

void dfsx(ll u)
{
    vs1[u]=true;
    for(auto v:adj[u]){
        if(!vs1[v])
            dfsx(v);
    }
}

void dfsn(ll u)
{
    vs2[u]=true;
    for(auto v:ad[u]){
        if(!vs2[v])
            dfsn(v);
    }
}

int main()
{
    freopen("fenceplan.inp","r",stdin);
    freopen("fenceplan.out","w",stdout);
    cin>>n>>t;
    while(t--){
        cin>>x>>y;
        adj[x].push_back(y);
        ad[y].push_back(x);
    }

    dfsx(1);
    for(int i=1;i<=n;i++){
        if(!vs1[i]){
            ans.push_back(i);
        }
    }

    if(!ans.empty()){
        cout<<"NO\n";

            cout<<"1 "<<ans[0]<<"\n";
        return 0;
    }

    for(int i=2;i<=n;i++){
        if(vs1[i]){
            memset(vs2,false,nmax);
            dfsn(i);
            if(!vs2[1])
                ans.push_back(i);
        }
    }

    if(ans.empty()){
        cout<<"YES";
    }

    else{
        cout<<"NO\n";
        cout << ans[0] << ' '  << 1 << '\n';
    }
}
