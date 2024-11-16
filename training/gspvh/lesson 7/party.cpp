#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int oo = 1e9;

int n;
int a[N], f[N][N], id[N];
vector<int> cont[N];

void trace(int l, int r){
	if ( l > r ) return;
	for (int mid = l + 1; mid <= r; mid += 2){
		if ( f[l][r] == f[l+1][mid-1] + f[mid+1][r] + (a[l] == a[mid]) ){
            cout << l << ' ' << mid << '\n';
			trace(l+1, mid-1);
			trace(mid+1, r);
			break;
		}
	}
}

int calc(int l, int r){
    if ( l >= r ) return 0;

    if ( f[l][r] != -1 ) return f[l][r];

    int res;

    if ( a[l] == a[l+1] ) res = 1 + calc(l+2, r);
    else if ( a[r] == a[r-1] ) res = 1 + calc(l, r-2);
    else if ( a[l] == a[r] ) res = 1 + calc(l+1, r-1);
    else{
        res = max({calc(l+2, r), calc(l, r-2), calc(l+1, r-1)});

        for (int i = id[l] + 1; i < cont[a[l]].size(); i ++){
            int mid = cont[a[l]][i];
            if ( mid > r ) break;
            if ( ( mid + l ) % 2 )
                res = max(res, 1 + calc(l+1, mid-1) + calc(mid+1, r));
        }

        for (int i = id[r] - 1; i >= 0; i --){
            int mid = cont[a[r]][i];
            if ( mid < l ) break;
            if ( ( mid + r ) % 2 )
                res = max(res, 1 + calc(mid+1, r-1) + calc(l, mid-1));
        }
    }

    f[l][r] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("party.inp", "r") ){
        freopen("party.inp", "r", stdin);
        freopen("party.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cont[a[i]].pb(i), id[i] = cont[a[i]].size() - 1;

    memset(f, -1, sizeof f);

    for (int i = 1; i <= n; i ++)
        f[i][i+1] = ( a[i] == a[i+1] );

    cout << calc(1, n) << '\n';

    for (int i = 1; i <= n + 1; i ++)
    for (int j = 1; j <= n + 1; j ++)
        if ( f[i][j] == -1 ) f[i][j] = 0;

    trace(1, n);

    return 0;
}
