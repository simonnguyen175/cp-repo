#include<bits/stdc++.h>
#define simon "dsp"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 25;

int n, a[N], ans;
bitset<20> b;
vector<pair<int, int>> u;
vector<int> ds;

bool check(){
    if ( u.size() == 1 ) return true;
    ll s = u[0].first;
    for (int i=1; i<u.size(); i++){
        if ( s % u[i].first != 0 ) return false;
        s += u[i].first;
    }
    return true;
}


void update(){
    sort(u.begin(), u.end());

    do{

        if ( check() && ans < u.size() ){
            ans = u.size();
            ds.clear();
            for (auto x : u ) ds.push_back(x.second);
        }

    }while (next_permutation(u.begin(), u.end()));
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int x = ( 1 << n ) -1;
    for (int i=1; i<=x; i++){
        u.clear();
        b = bitset<20> (i);
        for (int j=0; j<n; j++)
            if ( b[j] ) u.push_back({a[j], j+1});
        update();
    }


    cout << ans << '\n';
    for (auto x : ds) cout << x << ' ';

    return 0;
}
