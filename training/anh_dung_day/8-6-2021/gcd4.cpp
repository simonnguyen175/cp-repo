#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e4 + 5;

int n;
int factor[N], cnt[N];
vector<int> primeList;

void sieve(){
    for (int i = 2; i < N; i ++) factor[i] =  i;
    for (int i = 2; i < N; i ++)
        if ( factor[i] == i ){
            primeList.pb(i);
            for (int j = i * i; j < N; j += i)
            factor[j] = i;
        }
}

ll C4(int n){
    return 1LL * n * (n-1) * (n-2) * (n-3) / 24;
}

void anal(int x){
    vector<int> ListU;
    while ( x > 1 ){
        int u = factor[x];
        ListU.pb(u);
        while ( x % u == 0 ) x /= u;
    }

    for (int t = 0; t < (1<<ListU.size()); t ++){
        int lcm = 1;
        for (int i = 0; i < ListU.size(); i ++)
            if ( t & (1<<i) ) lcm *= ListU[i];
        cnt[lcm] ++;
    }
}

ll cal(int num, int lcm, int idx){
    if ( cnt[lcm] < 4 ) return 0;

    ll res, numCom = C4(cnt[lcm]);

    if ( num % 2 == 0 ) res = numCom;
    else res = -numCom;

    for (int i = idx; i < primeList.size(); i ++){
        int p = primeList[i];
        if ( lcm * p < N ) res += cal(num + 1, lcm * p, i + 1);
        else break;
    }

    return res;
}

int main(){
    sieve();
    while ( cin >> n ){
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i ++){
            int x;
            cin >> x;
            anal(x);
        }

        ll ans = cal(0, 1, 0);

        cout << ans << '\n';
    }

    return 0;
}
