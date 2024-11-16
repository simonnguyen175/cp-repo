#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int m, n;
ll a[N], b[N], S = 0, E = 0, G = 0;
vector<ll> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("seq2sc.inp", "r") ){
        freopen("seq2sc.inp", "r", stdin);
        freopen("seq2sc.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    for (int i = 1; i <= n; i ++){
        ll s = 0;
        for (int j = i; j <= n; j ++)
            s += b[j], cont.pb(s);
    }

    sort(cont.begin(), cont.end());

    //for (auto x : cont) cout << x << ' '; cout << '\n';

    for (int i = 1; i <= m; i ++){
        ll s = 0;
        for (int j = i; j <= m; j ++){
            s += a[j];
            //cout << s << " : ";
            auto low = lower_bound(cont.begin(), cont.end(), s);
            auto up = upper_bound(cont.begin(), cont.end(), s);
            //cout << low - cont.begin() << ' ' << up - cont.begin() << '\n';
            if ( up != cont.end() ) S += cont.size() - ( up - cont.begin() );
            if ( low != cont.end() ){
                if ( *low == s ) E += up - low;
                //G += low - cont.begin();
            }
            G += low - cont.begin();
            //cout << " -> " << S << ' ' << E <<  ' ' << G <<  '\n';
        }
    }

    cout << S << ' ' << E << ' ' << G;

    return 0;
}
