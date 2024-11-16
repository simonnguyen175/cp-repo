#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t, a, b, c;
string n;
ll f[10][100];

void solve(){
    int m = n.size();
    n = ' ' + n;

    memset(f, 0, sizeof f);
    for (int x = 0; x <= 9; x ++)
        for (int y = 0; y <= 9; y ++)
            for (int z = 0; z <= 9; z ++)
                if ( ( x*a + y*b + z*c ) % 10 == n[m] - '0' ){
                    int nho = ( x*a + y*b + z*c ) / 10;
                    f[m][nho] ++;
                }



    for (int i = m - 1; i >= 1; i --)
        for (int nho = 0; nho <= 92; nho ++)
            if ( f[i+1][nho] )
                for (int x = 0; x <= 9; x ++)
                    for (int y = 0; y <= 9; y ++)
                        for (int z = 0; z <= 9; z ++)
                            if ( ( x*a + y*b + z*c + nho ) % 10 == n[i]-'0'){
                                int nnho = ( x*a + y*b +z*c + nho ) / 10;
                                f[i][nnho] += f[i+1][nho];
                            }

		cout << f[1][0] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

	cin >> t;

	while( t -- ){
		cin >> n >> a >> b >> c;
		solve();
	}

	return 0;
}
