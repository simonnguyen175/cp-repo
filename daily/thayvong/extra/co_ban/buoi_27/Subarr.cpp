#include <bits/stdc++.h>
#define simon "subarr"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=4e5+5;
const ll oo=1e15;
const int MOD=123456789;

ll n, k, pos, a[N], ans=0;
map<ll,ll> d;

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
	FASTio
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	pos=1; d[a[1]]=1;
	for(int i=2; i<=n; i++){
		d[a[i]]++;
		while( d[a[i]]==k ){
			ans+=n-i+1;
			d[a[pos]]--;
			pos++;
		}
	}
	cout << ans;
	return 0;
}
