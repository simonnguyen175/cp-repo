#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int n, a[N], nl, nr, t = 0;
bool isPrime[N], paired[N];
int vis[N], assigned[N];
int l[N], r[N], num1 = 0;
vector<int> adj[N];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0;
    for (int i = 1; i * i <= N; i ++)
        if ( isPrime[i] )
            for (int j = i*i; j <= N; j += i)
                isPrime[j] = 0;
}

bool visit(int u){
    if ( vis[u] != t ) vis[u] = t;
    else return false;

    for (auto v : adj[u]){
        if ( !assigned[v] || visit(assigned[v]) ){
            assigned[v] = u;
            return true;
        }
    }

    return false;
}

void sub12(){
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[i] % 2 ){
            if ( a[i] != 1 ) l[++nl] = i;
        }
        else r[++nr] = i;
    }

    for (int i = 1; i <= n; i ++)
        if ( a[i] == 1 ) l[++nl] = i, num1 ++;

    for (int i = 1; i <= nl; i ++)
        for (int j = 1; j <= nr; j ++)
            if ( isPrime[a[l[i]]+a[r[j]]] ){
                adj[l[i]].push_back(r[j]);
            }

    memset(vis, 0, sizeof vis);
    memset(paired, 0, sizeof paired);

    int cnt = 0;
    for (int i = 1; i <= nl; i ++){
        t ++;
        int tmp = visit(l[i]);
        cnt += tmp;
        if ( tmp ) paired[i] = 1;
        if ( tmp && a[l[i]] == 1 ) num1 --;
    }

    cout << cnt + num1/2 << '\n';
    for (int i = 1; i <= n; i ++)
        if ( int j = assigned[i] ){
            cout << i << ' ' << j << '\n';
        }

    for (int i = 1; i < nl; i ++)
        if ( a[l[i]] == 1 && !paired[i] ){
            cout << l[i] << ' ' << l[i+1] << '\n';
            i ++;
        }
}

pair<int,int> b[N];

void sub3(){
    for (int i = 1; i <= n; i ++) cin >> b[i].first, b[i].second = i;
    sort(b+1, b+1+n);
    pair<int, int> ans;
    if ( n % 2 == 0){
        cout << n/2 << '\n';
        int c = n, d = n - 1;
        while ( c > 0 ){
            while ( !isPrime[b[d].first+b[c].first] ) d --;
            int len = (c-d+1);
            for (int i = d; i <= d + len/2 - 1; i ++)
                cout << b[i].second << ' ' << b[c-(i-d)].second << '\n';\
            c = d - 1; d = c - 1;
        }
    }
    else{
        cout << n/2 << '\n';
        n --;
        int c = n, d = n - 1;
        while ( c > 0 ){
            while ( !isPrime[b[d].first+b[c].first] ) d --;
            int len = (c-d+1);
            for (int i = d; i <= d + len/2 - 1; i ++)
                cout << b[i].second << ' ' << b[c-(i-d)].second << '\n';
            c = d - 1; d = c - 1;
        }
    }
}

int main(){
    sieve();
    cin >> n;
    if ( n <= 1000 ) sub12();
    else sub3();
    return 0;
}
