#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int t, n, A, O, X, q[N];

void solve() {
	cin >> n >> A >> O >> X;
	memset(q, 0, sizeof q);
	for(int i = 0; i <= 30 ; i ++) {
		int a = BIT(A , i);
		int o = BIT(O , i);
		int x = BIT(X , i);
		if ( a == 1 ){
			if ( o == 0 || n % 2 != x ){
				cout << -1 << '\n';
				return ;
			}
			else
                for (int j = 1; j <= n; j++)
                    q[j] += (1 << i);
		}
		else if ( o == 0 ){
			if ( x != 0 ){
                cout << -1 << '\n'; return;
			}
		}
		else{
			if ( n <= 2 && x != 1) { cout << -1 << '\n'; return; }
			else
			    q[2] += (1<<i), q[3] += abs(x-1) * (1<<i);
		}
	}

	for (int i = 1; i <= n; i ++)
        cout << q[i] << ' ';

	cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	cin >> t;
	while ( t -- ) solve();
	return 0;
}

