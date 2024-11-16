#include<bits/stdc++.h>
#define ll long long
#define BIT(t, k) ((t>>k)&1)
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, k;
ll avg;
int a[N];

namespace sub2{
    ll f[1<<23], trace[1<<23], ans[23];
    void solve(){
        memset(f, -1, sizeof f);
        f[0] = 0;
        for (int t = 0; t < (1<<n)-1; t ++) if ( f[t] != -1 )
            for (int i = 1; i <= n; i ++) if ( !BIT(t, i-1) && a[i] + f[t] <= avg ){
                int nt = t | (1<<(i-1));
                f[nt] = f[t] + a[i];
                trace[nt] = i;
                if ( f[nt] == avg ) f[nt] = 0;
            }

        if ( f[(1<<n)-1] != 0 ){
            cout << -1;
            return;
        }

        int t = (1<<n)-1, id = k;
        ll s = 0;

        while ( t ){
            int i = trace[t];
            ans[i] = id;
            s += a[i];
            t ^= (1<<(i-1));
            if ( s == avg )
                id --, s = 0;
        }

        for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    }
}

namespace sub3{
    bitset<3500> f[105][3500];
    int ans[105];

    void solve(){
        f[0][0][0] = 1;
        for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= avg; j ++){
            f[i][j] |= f[i-1][j];
            f[i][j] |= (f[i-1][j] << a[i]);
            if ( a[i] + j <= avg ) f[i][j+a[i]] |= f[i-1][j];
        }

        if ( !f[n][avg][avg] ){
            cout << -1;
            return;
        }

        int t = n, s1 = avg, s2= avg;
        while ( t ){
            if ( s1 >= a[t] && f[t-1][s1-a[t]][s2] ){
                ans[t] = 1;
                s1 -= a[t];
            }
            else if ( s2 >= a[t] && f[t-1][s1][s2-a[t]] ){
                ans[t] = 2;
                s2 -= a[t];
            }
            else ans[t] = 3;
            t --;
        }
        for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    }
}

namespace sub45{
	int id = 1, m, c[55], ans[N], f[55][1500];
	vector<int> pre[55][1500];

	void Print(){
		for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
		exit(0);
	}

	void calc(int i){
		if ( i == 0 ) Print();
		if ( !c[i] ){
			ans[i] = ++id;
			c[i] = avg;
		}

		for (auto j : pre[i][c[i] % avg]) if(!c[j]) {
			ans[j] = ans[i];
			c[j] = c[i] - a[i];
			calc(i - 1);
			c[j] = 0;
		}

		if ( c[i] == avg ){
			--id;
			c[i] = 0;
		}
	}

	void solve() {
		for (int i = 1; i <= min(50, n); i ++)
            if ( (n - i) % (2 * k) == 0 )
                m = i;

		for (int i = m + 1; i <= m + (n - m) / 2; i ++) {
			ans[i] = id ++;
			if ( id > k ) id = 1;
		}

		for (int i = n; i >= m + (n - m) / 2 + 1; i --) {
			ans[i] = id++;
			if ( id > k ) id = 1;
		}

		avg = 0;
		for (int i = 1; i <= m; i ++) avg += a[i];
		avg /= k;

		for (int i = 1; i <= m; i ++) if ( a[i] <= avg )
		    f[i][a[i] % avg] = 1, pre[i][a[i] % avg].pb(0);

		for (int i = 1; i <= m - 1; i ++)
		 for (int t = 1; t <= avg - 1; t ++) if ( f[i][t] )
		 	for (int j = i + 1; j <= m; j ++){
		 		ll new_t = t + a[j];
		 		if ( new_t <= avg ) {
		 			new_t %= avg;
		 			f[j][new_t] = 1;
		 			pre[j][new_t].pb(i);
				 }
			 }


		for (int i = 1; i <= m; i ++)
		 for(int j = 0; j < avg; j ++)
		   sort(pre[i][j].begin(), pre[i][j].end(), greater<int>() );

        id = 0;
        calc(m);
        cout << -1;
    }
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], avg += a[i];
    if ( avg % k ){
        cout << -1;
        return 0;
    }
    avg /= k;

    if ( n <= 20 ) { sub2::solve(); return 0; }

    if ( k == 3 && n <= 100 ) { sub3::solve(); return 0; }

    sub45::solve();

    return 0;
}
