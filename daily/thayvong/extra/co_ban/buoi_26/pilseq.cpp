#include <bits/stdc++.h>
#define simon "pilseq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e6+1;
const ll oo=1e18;

int k, n, a[N];

bool check(){
	sort(a+1, a+n+1);
	if( a[1] >= a[n/2+2] ) return false;
	if( a[n/2+1] >= a[n] ) return false;
	for(int i=2; i<=n/2; i++)
		if( a[i]>=a[i+n/2+1] || a[i]>=a[i+n/2])
            return false;
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> k;
    for (int i=1; i<=k; i++){
        cin >> n;
        for (int j=1; j<=n; j++)
            cin >> a[j];
        if ( check() ) cout << "YES" <<'\n';
        else cout << "NO" <<'\n';
    }
    return 0;
}
