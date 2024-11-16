#include <bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "BS"
#define fi first
#define se second
using namespace std;
const int M=1e6+1;

int k, m, a[11], d[M];
bool vis[M];
vector<int> ver[M];
pair<int, char> trace[M];
queue<int> q;
vector<char> ans;

void BFS(){
    while ( !q.empty() ){
        int tmp=q.front(); //cout << tmp <<'\n';
        q.pop();
        for (int i=1; i<=k; i++){
            int x =(tmp*10+a[i])%m;
            if ( vis[x] ) continue;
            d[x]=d[tmp]+1;
            trace[x].fi=tmp;
            trace[x].se=(char) a[i]+'0';
            vis[x]=1;
            q.push(x);
        }
    }
}

int main(){
    FASTio
	if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> k >> m;
    for (int i=1; i<=k; i++)
        cin >> a[i];

    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);

    for (int i=1; i<=k; i++){
        if ( a[i] == 0 ) continue;
        q.push(a[i]%m);
        vis[a[i]%m]=1;
        d[a[i]%m]=1;
        trace[a[i]%m].fi=-1;
        trace[a[i]%m].se=a[i]+'0';

    }
    BFS();

    //cout <<'\n';
    if ( d[0] == 0  ) cout << -1;
    else{
        //cout << d[0] <<'\n';
        int res=0;
        while ( trace[res].fi != -1 ){
            ans.push_back(trace[res].se);
            //cout << trace[res].se <<'\n';
            res=trace[res].fi;
        }
        ans.push_back(trace[res].se);
        //cout << trace[res].se <<'\n';
    }
    for (int i=ans.size()-1; i>=0; i--)
        cout << ans[i];
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int M=1e6+1;

int k, m, a[11], d[M];
bool vis[M];
vector<int> ver[M];
pair<int, char> trace[M];
queue<int> q;
vector<char> ans;

void BFS(){
    while ( !q.empty() ){
        int tmp=q.front(); //cout << tmp <<'\n';
        q.pop();
        for (int i=1; i<=k; i++){
            int x =(tmp*10+a[i])%m;
            if ( vis[x] ) continue;
            d[x]=d[tmp]+1;
            trace[x].fi=tmp;
            trace[x].se=(char) a[i]+'0';
            vis[x]=1;
            q.push(x);
        }
    }
}

int main(){
    cin >> m >> k;
    for (int i=1; i<=k; i++)
        cin >> a[i];
    sort(a+1, a+1+k);

    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);

    for (int i=1; i<=k; i++){
        if ( a[i] == 0 ) continue;
        q.push(a[i]%m);
        vis[a[i]%m]=1;
        d[a[i]%m]=1;
        trace[a[i]%m].fi=-1;
        trace[a[i]%m].se=a[i]+'0';

    }
    BFS();

    //cout <<'\n';
    if ( d[0] == 0  ) cout << -1;
    else{
        //cout << d[0] <<'\n';
        int res=0;
        while ( trace[res].fi != -1 ){
            ans.push_back(trace[res].se);
            //cout << trace[res].se <<'\n';
            res=trace[res].fi;
        }
        ans.push_back(trace[res].se);
        //cout << trace[res].se <<'\n';
    }
    for (int i=ans.size()-1; i>=0; i--)
        cout << ans[i];
    return 0;
}
