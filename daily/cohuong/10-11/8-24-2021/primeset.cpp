#include<bits/stdc++.h>
#define simon "primeset"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define BIT(mask, k) ((mask>>k)&1)
using namespace std;
const int N = 205;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
int f[N][(1<<16)], mask[N];

int get(int maska, int maskb){
	int res = 0;
	for (int i = 0; i < m; i++)
        if ( BIT(maskb, i) && !BIT(maska, i) ) res += (1 << i);
	return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    // calc mask
    memset(mask, 0, sizeof mask);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( a[i] % b[j] == 0 ) mask[i] += (1 << (j - 1)) ;

    // calc f
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int cmask = 0; cmask < (1 << m) ; cmask ++){
            int pmask = get(mask[i], cmask);
            f[i][cmask] = (f[i-1][cmask] + f[i-1][pmask]) % MOD;
        }

    cout << f[n][(1 << m) - 1];

    return 0;
}

