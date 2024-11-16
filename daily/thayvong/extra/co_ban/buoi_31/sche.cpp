#include<bits/stdc++.h>
#define simon "sche"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n;
pair<int, int> a[N];
vector<int> t[N];
priority_queue<int> q;
long long ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n;  i ++){
        cin >> a[i].fi >> a[i].se;
        t[a[i].fi].push_back(a[i].second);
    }

    for (int i = 1000000; i >= 1; i --){
        if ( t[i].size() > 0 )
            for (auto f : t[i])
                q.push(f);

        if ( q.size() == 0 ) continue;
        ans += q.top();
        q.pop();
    }

    cout << ans;

    return 0;
}
