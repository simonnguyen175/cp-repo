#include <bits/stdc++.h>
#define simon "DifferenceK"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=1e6+1;
const int oo=1e18;

int n, m, k;
int a[N], b[N];
vector<pair<ll, int>> s;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=m; i++)
        cin >> b[i];

    ll sa=0, sb=0, ans=oo;
    for (int i=1; i<=k; i++) sa+=a[i];
    s.push_back({sa, 0});
    for (int i=1; i<=k; i++) sb+=b[i];
    s.push_back({sb, 1});

    for (int i=k+1; i<=n; i++){
        sa=sa+a[i]-a[i-k];
        s.push_back({sa, 0});
    }
    for (int i=k+1; i<=m; i++){
        sb=sb+b[i]-b[i-k];
        s.push_back({sb, 1});
    }
    sort(s.begin(), s.end());
    for (int i=1; i<s.size(); i++){
        if ( s[i].se != s[i-1].se )
            ans=min(ans, s[i].fi-s[i-1].fi);
    }
    cout << ans;
    return 0;
}
