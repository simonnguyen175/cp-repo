#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int oo = 1e9;

int n, m, c[25][25], deg[25], sum = 0, f[(1<<22)];
vector <int> odd;

int BIT(int x , int k){
	return (x >> k) & 1;
}

int cal( int t){
	if (t == 0) return 0;
	if ( f[t] ) return f[t];
	int best = oo;
	for (int i = 0 ; i < odd.size() ; i++){
		for (int j = i + 1 ; j < odd.size() ; j++){
			if ( odd[i] == odd[j]) continue;

            int tmp = oo;
            if ( BIT(t, i) && BIT(t,j) )
                tmp = cal(t^(1<<i)^(1<<j)) + c[odd[i]][odd[j]];
            best = min(best , tmp);
		}
	}

	f[t] = best ;
	return best;
}

int main(){
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)0
            c[i][j] = oo;
    for (int i = 1 ; i <= m ; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	c[u][v] = min(c[u][v], w);
    	c[v][u] = min(c[v][u], w);
    	deg[u] ++; deg[v] ++;
    	sum += w;
	}

	for (int i = 1; i <= n; i++)
        if( deg[i] % 2 == 1 )
            odd.push_back(i);

	for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][j] > c[i][k] + c[k][j] )
                    c[i][j] = c[i][k] + c[k][j];

    bool flag = 1;
    for (int i = 1; i <= n; i ++){
        if ( deg[i] > 0 && c[1][i] == oo )
            flag = 0;
    }

    if ( !flag ){
        cout << -1;
        return 0;
    }

	cout << sum + cal((1<<(odd.size()))-1);
}
