#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e2 + 5;

int n, m = 0;
int a[N][N], big[N][N];
pii b[N*2];
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i <= 1; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    if ( n == 2 ){
        int res = max({a[0][1] + a[0][2], a[0][2] + a[1][2],
                      a[1][2] + a[1][1], a[1][1] + a[0][1]});

        if ( res == a[0][1] + a[0][2] ) cout << 0;
        else if ( res == a[0][2] + a[1][2] ) cout << 1 << '\n' << 1;
        else if ( res == a[1][2] + a[1][1] ) cout << 2 << '\n' << 1 << ' ' << 1;
        else cout << 3 << '\n' << 1 << ' ' << 1 << ' ' << 1;

        return 0;
    }

    for (int i = 0; i <= 1; i ++)
    for (int j = 1; j <= n; j ++)
        b[++m] = {a[i][j], {i, j}};

    memset(big, 0, sizeof big);

    sort(b + 1, b + 1 + m, greater<pii>());
    for (int i = 1; i <= n; i ++)
        big[b[i].se.fi][b[i].se.se] = 1;

    while ( true ){
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= n; i ++){
            if ( !big[0][i] ) p1 = i;
            if ( big[1][i] ) p2 = i;
        }

        if ( !p1 ) break;

        if ( p1 == p2 ){
			if ( p1 == 1 ){
				ans.pb(p1 + 1); ans.pb(p1 + 1);
				ans.pb(p1 + 1); ans.pb(p1);
				ans.pb(p1 + 1); ans.pb(p1);
				ans.pb(p1 + 1);
				bool tmp = big[0][p1];
				big[0][p1] = big[0][p1 + 1]; big[0][p1 + 1] = big[0][p1 + 2];
				big[0][p1 + 1] = big[1][p1]; big[1][p1] = big[1][p1 + 1];
				big[1][p1 + 1] = big[1][p1 + 2]; big[1][p1 + 1] = tmp;
			}
			else if (p1 == 2){
				ans.pb(p1 - 1); ans.pb(p1);
				ans.pb(p1 - 1); ans.pb(p1);
				ans.pb(p1); ans.pb(p1);
				bool tmp = big[0][p1];
				big[0][p1] = big[0][p1 - 1]; big[0][p1 - 1] = big[0][p1 + 1];
				big[0][p1 + 1] = big[1][p1]; big[1][p1] = big[1][p1 - 1];
				big[1][p1 - 1] = tmp;
			}
			else{
				ans.pb(p1 - 2); ans.pb(p1 - 1);
				ans.pb(p1 - 2); ans.pb(p1 - 2);
				ans.pb(p1 - 2);
				bool tmp = big[0][p1];
				big[0][p1] = big[1][p1]; big[1][p1] = big[1][p1 - 2];
				big[1][p1 - 2] = big[1][p1 - 1]; big[1][p1 - 1] = tmp;
			}
        }
        else{
			if ( p1 < p2 ){
				for (int j = p2 - 1; j >= p1; --j) {
					ans.pb(j);
					bool tmp = big[1][j];
					big[1][j] = big[0][j]; big[0][j] = big[0][j + 1];
					big[0][j + 1] = big[1][j + 1]; big[1][j + 1] = tmp;
				}
			} else {
				for (int j = p2; j <= p1 - 1; ++j) {
					ans.pb(j); ans.pb(j); ans.pb(j);
					bool tmp = big[1][j];
					big[1][j] = big[1][j + 1]; big[1][j + 1] = big[0][j + 1];
					big[0][j + 1] = big[0][j]; big[0][j] = tmp;
				}
			}
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';

    return 0;
}
