#include <bits/stdc++.h>
#define simon "DelPrime"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e9+1;

string M;
map<int, int> dp, vis;
queue<string> q;

int string2Num(string s){
    int res=0;
    for (int i=0; i<s.size(); i++)
        res=res*10+(s[i]-'0');
    return res;
}

bool nto(int x){
    if ( x <= 1 ) return false;
    else
        for (int i=2; i<=sqrt(x); i++)
            if ( x % i == 0 ) return false;
    return true;
}

void BFS(){
    q.push(M);
    vis[string2Num(M)]=1;
    while ( !q.empty() ){
        string x=q.front();
        if ( nto(string2Num(x)) ){
            cout << dp[string2Num(x)];
            return;
        }
        q.pop();

        for (int i=0; i<x.size(); i++){
            string s=x;
            s.erase(i, 1);
            if ( vis[string2Num(s)] || s == "" ) continue;
            q.push(s);
            int k=string2Num(x);
            int t=string2Num(s);
            dp[t]=dp[k]+1;
            vis[t]=1;
            //cout << x<<' '<<s <<' '<<dp[t]<<'\n';
        }

        for (int i=1; i<x.size(); i++){
            string s=x;
            if ( x[i] == x[i-1] ){
                s.erase(i-1, 2);
                if ( vis[string2Num(s)] || s == "" ) continue;
                q.push(s);
                int k=string2Num(x);
                int t=string2Num(s);
                vis[t]=1;
                dp[t]=dp[k]+1;
                //cout << x <<' '<<s <<' '<<dp[t]<<'\n';
            }
        }
    }
    cout << -1;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> M;
    BFS();
}
