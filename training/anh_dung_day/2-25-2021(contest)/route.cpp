#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
long long ans[6];
vector <int> ver[100001];
int da[100001], db[100001];
queue<int> q;
int trace[100001];

void nhap(){
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++)
        ver[i].clear();
    for(int i=1;i<=m;i++){
        int s,f;
        cin>>s>>f;
        ver[s].push_back(f);
        ver[f].push_back(s);
    }
}

void bfsa(){
    q.push(a);
    memset(da,0,sizeof da);
    memset(trace,0,sizeof trace);
    trace[a]=-1;
    while (!q.empty()){
        int u=q.front();
		q.pop();
        for (int v=0; v < ver[u].size(); v++)
            if ( trace[ver[u][v]] == 0 ){
                q.push(ver[u][v]);
                trace[ver[u][v]]=u;
                da[ver[u][v]]=da[u]+1;
            }
    }
}

void bfsb(){
    q.push(b);
    memset(db, 0, sizeof db);
    memset(trace, 0, sizeof trace);
    trace[b]=-1;
    while ( !q.empty() ){
        int u=q.front(); q.pop();
        for (int v=0; v < ver[u].size(); v++)
            if ( trace[ver[u][v]] == 0 ){
                q.push(ver[u][v]);
                trace[ver[u][v]]=u;
                db[ver[u][v]]=db[u]+1;
            }
    }
}

int tknp(int l, int r, int x){
    int d=l, c=r, res=0;
    while ( d <= c ){
        int mid=(d+c)/2;
        if ( db[mid] < x ){
            res=mid;
            d=mid+1;
        }
        else c=mid-1;
    }
    return res;
}

void xuli(int t){
    bfsa();
    bfsb();
    int dmax=da[b];
    sort (da+1, da+1+n);
    sort (db+1, db+1+n);

//    for (int i=1; i<=n; i++) cout <<da[i] <<' '; cout <<'\n';
//    for (int i=1; i<=n; i++) cout <<db[i] <<' '; cout <<'\n';
	int temp=0;
    for(int i=2;i<=n;i++)
    	if(db[i-1]==db[i])
    		temp++;
    	else break;
    ans[t]=0;
    for (int i=1; i<=n; i++){
    	if(i!=1 && da[i]==0 ) continue;
        int pos=tknp(1, n, dmax-da[i]-1);
        if ( pos == 0 ) continue;
//        cout << da[i] <<' '<< pos <<'\n';
        ans[t]+=pos-temp;
    }
}

int main(){
    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }
    cin >> t;
    for(int i=1; i<=t; i++){
        nhap();
        xuli(i);
    }
    for (int i=1; i<=t; i++) cout << ans[i] <<'\n';
    return 0;
}
