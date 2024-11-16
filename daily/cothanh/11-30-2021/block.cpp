#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, k;
ll a[N], f[N][105], g[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	if ( fopen("block.inp", "r") ){
        freopen("block.inp", "r", stdin);
        freopen("block.out", "w", stdout);
	}

	cin >> n >> k;
	f[0][1] = 0;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], f[i][1] = max(f[i-1][1], a[i]);

    for (int j = 2; j <= k; j ++){
        stack<int> st;
        for (int i = 1; i <= n; i ++){
            f[i][j] = g[i] = oo;

            while ( !st.empty() && a[i] > a[st.top()] ){
                g[i] = min(g[i], g[st.top()]);
                st.pop();
            }

            if ( !st.empty() )
                f[i][j] = min(f[st.top()][j-1] + a[i], f[st.top()][j]);

            f[i][j] = min(f[i][j], g[i] + a[i]);

            g[i] = min(g[i], f[i][j-1]);

            st.push(i);
        }
    }

    cout << f[n][k];

    return 0;
}

