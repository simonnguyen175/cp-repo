#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("1616D.inp", "r") ){
        freopen("1616D.inp", "r", stdin);
        freopen("1616D.out", "w", stdout);
    }

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
int a[n+1];
		for(int i=1; i<=n; i++) cin >> a[i];
		int x, ans=n; cin >> x;
		for(int i=1; i<=n; i++) a[i]-=x;
		for(int i=2; i<=n; i++){
			if(a[i]+a[i-1]<0||a[i]+a[i-1]+a[i-2]<0) ans--, a[i]=1e9;
		}
		cout << ans << endl;
	}
}
