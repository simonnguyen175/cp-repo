#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e7 + 5;
const ll MX = 1e14;

ll n, k;
bool isPrime[N];
vector<int> prime;
map<ll, int> d;

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0;
    for (int i = 2; i * i < N; i ++) if ( isPrime[i] )
    for (int j = i*i; j < N; j += i)
        isPrime[j] = 0;
}

void solve(){
    cin >> n >> k;

    if ( n == 1 ) { cout << "No\n"; return; }

    bool nto = 1;
    for (int x : prime)
        if ( x > n ) break;
        else if ( n % x == 0 ) nto = 0;

    if ( nto ){
        if ( k == 1 ) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    if ( d[n] == k ) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("tichsnt.inp", "r", stdin);
    freopen("tichsnt.out", "w", stdout);

    sieve();
    for (int i = 2; i < N; i ++)
        if ( isPrime[i] ) prime.pb(i);

    for (int i = 0; i < prime.size(); i ++){
        ll cur = 1;
        int j = i;
//        cerr << prime[i] << " : \n";
        while ( j < prime.size() && cur <= MX/prime[j] ){
            cur *= prime[j];
//            cerr << cur << ' ';
            d[cur] = j-i+1;
            j ++;
        }
//        cerr << '\n';
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
