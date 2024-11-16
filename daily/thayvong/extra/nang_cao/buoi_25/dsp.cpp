#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "dsp"
using namespace std;
const int N = 25;

int n, a[N], last[2000005], ans = 1 ;
ll s[2000005];
bool dp[2000005];
vector<int> d[30], ds;
bitset<20> b;

void update(int e){
    b = bitset<20> (e);
    for (int j = 0; j < b.size(); j ++)
        if ( b[j] )
            if ( s[e - (1 << j)] % a[j] == 0 && dp[e - (1 << j)] ){
                ans = e;
                dp[e] = 1;
                last[e] = j;
                return;
            }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    memset(s, 0, sizeof s);

    int x = ( 1 << n ) - 1;

    for (int i = 1; i <= x; i ++){
        b = bitset<20> (i);
        d[b.count()].push_back(i);
    }

    for (int i = 0; i < n; i ++){
        dp[( 1 << i )] = 1;
        last[( 1 << i )] = i;
        s[(1 << i)] = a[i];
    }

    for (int i = 2; i <= n; i++)
        for ( auto e : d[i] ){
            b = bitset<20> (e);
            for (int j = 0; j < b.size(); j++)
                if ( b[j] ) s[e] += a[j];
        }

    for (int i = 2; i <= n; i ++)
        for ( auto e : d[i] )
            update(e);

    b = bitset<20> (ans);
    int len = b.count();

    cout << len << '\n';

    for (int t = 1; t <= len; t++){
        b = bitset<20> (ans);
        int i = last[ans];
        ds.push_back(i+1);
        b[i] = 0;
        ans = b.to_ulong();
    }

    reverse(ds.begin(), ds.end());

    for (int i=0; i<ds.size(); i++)
        cout << ds[i] <<' ';

    return 0;
}
