#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll n, m;
int x[20];
ll f[20][1500][2];
bool isClear[1500];

bool check(int x){
    while ( x > 9 ){
        int sum = 0;
        while ( x ){
            sum += (x%10)*(x%10);
            x /= 10;
        }
        x = sum;
    }
    return isClear[x];
}

ll get(int i, int s, bool ok){
    if ( f[i][s][ok] != -1 ) return f[i][s][ok];

    if ( i > 18 )
        if ( isClear[s] ) return 1;
        else return 0;

    ll cnt = 0;
    for (int c = 0; c <= max(ok*9, x[i]); c ++)
        cnt += get(i+1, s + c * c, ok | (c < x[i]));

    f[i][s][ok] = cnt;

    //cout << i << ' ' << s << ' ' << ok << ' ' << f[i][s][ok] << '\n';

    return cnt;
}

ll calc(ll X){
    for (int i = 18; i >= 1;  i --) x[i] = X % 10, X /= 10;
    memset(f, -1, sizeof f);
    return get(1, 0, 0);
}

int main(){
    if ( fopen("d13clear.inp", "r") ){
        freopen("d13clear.inp", "r", stdin);
        freopen("d13clear.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(isClear, 0, sizeof isClear);
    isClear[1] = isClear[7] = 1;
    for (int i = 1; i <= 1458; i ++)
        isClear[i] = check(i);

    cin >> t;
    while ( t -- ){
        cin >> n >> m;
        ll cnt = calc(n) + m;
        //cout << cnt << '\n';
        ll lo = 1, hi = 1e18, res;
        while ( lo <= hi ){
            ll mid = ( lo + hi ) / 2;
            //cout << mid << ' ';
            if ( calc(mid) >= cnt ){
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        cout << res << '\n';
    }

    return 0;
}
