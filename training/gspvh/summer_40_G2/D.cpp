#include<bits/stdc++.h>
#define simon "minsum"
#define pb push_back
#define ll long long
using namespace std;
const ll oo = 2e9;

int t, n;
ll a, b, ans;
vector<int> fact;
map<int, int> d;
pair<int, int> res;

void gen(int id){
    for (int t = 0; t <= 1; t ++){
        if ( !t ){
            a *= fact[id];
            if ( id == n ){
                if ( ans > a + b )
                    res = {a, b}, ans = a + b;
            }
            else gen(id+1);
            a /= fact[id];
        }
        else{
            b *= fact[id];
            if ( id == n ){
                if ( ans > a + b )
                    res = {a, b}, ans = a + b;
            }
            else gen(id+1);
            b /= fact[id];
        }
    }
}

void solve(){
    cin >> a >> b;
    fact.clear();
    d.clear();

    for (int i = 2; i*i <= a; i ++) if ( a % i == 0 ){
        while ( a % i == 0 ){
            d[i] ++;
            a /= i;
        }
        fact.pb(i);
    }
    if ( a != 1 ) d[a] ++, fact.pb(a), a = 1;

    for (int i = 2; i*i <= b; i ++) if ( b % i == 0 ){
        while ( b % i == 0 ){
            d[i] ++;
            b /= i;
        }
        fact.pb(i);
    }
    if ( b != 1 ) d[b] ++, fact.pb(b), b = 1;

    sort(fact.begin(), fact.end());
    fact.erase(unique(fact.begin(), fact.end()), fact.end());

    for (int i = 0; i < fact.size(); i ++)
        if ( d[fact[i]]%2 == 0 ) fact[i] = 1;

    if ( fact.size() == 0 )
        { cout << 1 << ' ' << 1 << '\n'; return; }

    n = fact.size() - 1;

    ans = oo;

    gen(0);

    cout << res.first << ' ' << res.second << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;

    while ( t -- ) solve();

    return 0;
}
