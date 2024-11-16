#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll maxx = 1e6 + 5;
vector<ll> ve[maxx];
ll n, x, sA[maxx], sB[maxx], ans=0, p, y;

void An(ll u, ll pu){
    for(int i = 0; i < ve[u].size(); ++i){
        ll au = ve[u][i];
        if(pu == au) continue;
        sA[au] = sA[u] + 1;
        An(au, u);
    }
}
void Binh(ll u , ll pu) {
    for(int i = 0; i < ve[u].size(); ++i){
        ll au = ve[u][i];
        if(pu == au) continue;
        sB[au] = sB[u] + 1;
        Binh(au, u);
    }
}

int main(){
    FASTio;
    cin >> n >> x;
    memset(sA, 0, sizeof sA);
    memset(sB, 0, sizeof sB);
    for (ll i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    An(1, 0);
    Binh(x, 0);
    for(ll i = 1 ; i <= n ; i++)
        if(sA[i] > sB[i])
            ans = max(ans , sA[i]);
    cout << 2*ans;
    return 0;
}
