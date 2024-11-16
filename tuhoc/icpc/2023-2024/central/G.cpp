#include <bits/stdc++.h>

#define fileopen(a, b) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)b + ".out").c_str(), "w", stdout);
#define fileopen1(a) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)a + ".out").c_str(), "w", stdout);

using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18, MAXVAL = 1e4 + 5;

ll tc,n;
ll a[MAXN];

ll grundy[MAXVAL];
ll mx = 0;

ll solve(ll num){
    if (num == 0) return 0;
    if (grundy[num] != -1) return grundy[num];

    vector<ll> tmp;
    bool vis[MAXVAL];
    
    for (int i = 0 ; i < MAXVAL ; i++){
        vis[i] = false;
    }

    for (int i = 1 ; i <= num ; i++){
        vis[solve(num - i)] = true;
    }

    for (int i = 1 ; i < num ; i++){
        vis[solve(i) ^ solve(num - i)] = true;
    }
    
	for (int i = 0 ; i <= MAXVAL ; i++){
        if (vis[i] == false){
            return grundy[num] = i;
        }
    }
}

void caau(){
	// calm
    cin >> n;
    memset(grundy,-1,sizeof(grundy));

    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    ll sg = 0;
    for (int i = 1 ; i <= n ; i++){
        sg ^= solve(a[i]);
    }

    if (sg){
        cout << "Alice";
    }
    else {
        cout << "Bob";
    }
}

signed main() {
#ifdef thisiscaau
	fileopen("input", "output");
#endif
#ifndef thisiscaau
	// fileopen1("LAH");
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    tc = 1;
	while (tc--) caau();
}
