#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7;
const int base = 31;
const int N = 1e6 + 5;

int L, R, n, k;
string w[N], s;
int d[N];
bool f[N];
unsigned long long Hash[N], Pow[N];
vector<ll> cont;

void make(int id){
    ll h = 0;
    for (int i = 0; i < w[id].size(); i ++){
        h = ( h * base + w[id][i] - 'a' + 1 );
        if ( (i + 1)%k == 0 ) cont.pb(h);
    }
}

ll get(int l, int r){
    return ( Hash[r] - Hash[l-1] * Pow[r-l+1] );
}

bool check(ll x){
    auto it = lower_bound(cont.begin(), cont.end(), x);
    if ( it != cont.end() && *it == x ) return true;
    return false;
}

void xuli(){
    cin >> s;
    int len = s.size();
    s = ' ' + s;

    if ( len%k ) { cout << "No\n"; return; }
    for (int i = 1; i <= len; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 );

    int pos = len+1;

    for (int i = len-k+1; i >= 1; i -= k)
        if ( check(get(i,pos-1)) )
            pos = i;

    cout << ( pos == 1 ? "Yes\n" : "No\n" );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> L >> R;
    int gcd = 0;
    for (int i = 1; i <= L; i ++)
        cin >> w[i], k = __gcd(k, (int)w[i].size());
    for (int i = 1; i <= R; i ++)
        cin >> d[i], k = __gcd(k, (int)d[i]);

    for (int i = 1; i <= L; i ++) make(i);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    Pow[0] = 1;
    for (int i = 1; i <= 1e6; i ++) Pow[i] = Pow[i-1] * base;

    cin >> n;
    for (int i = 1; i <= n; i ++)
        xuli();

    return 0;
}
