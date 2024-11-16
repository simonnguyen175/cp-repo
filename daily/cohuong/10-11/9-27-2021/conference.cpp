#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n , m , k;
int a[N], b[N], have[N], fir[N], ans[N];
set<int> s[N];

void query1(){
	memset(fir, -1, sizeof fir);

	for(int i = m ; i >= 1 ; i--)
		if ( a[i] <= k ){
			if ( b[i] <= k ){
				if ( fir[b[i]] != -1 && fir[a[i]] == -1 ) fir[a[i]] = i;
				if ( fir[a[i]] != -1 && fir[b[i]] == -1 ) fir[b[i]] = i;
			}
			else
				if( fir[a[i]] == -1 ) fir[a[i]] = i;
		}

	for(int i = 1 ; i <= k ; i++) cout << fir[i] << ' ';

	cout << '\n';
}

void query2(){
    int cnt = 0;
	for(int i = 1; i <= m; i ++)
		if ( a[i] <= k ){
			if ( i == fir[a[i]] ) have[a[i]] = 1;

			if ( b[i] > k ){
                if ( have[b[i]] == 0 && have[a[i]] )
                    have[b[i]] = 1, cnt++;
                if ( have[b[i]] ) have[a[i]] = 1;
			}

			if ( b[i] <= k ){
				if ( i >= fir[b[i]] ) have[b[i]] = 1;
				if ( have[a[i]] == 1 ) have[b[i]] = 1;
				if ( have[b[i]] == 1 ) have[a[i]] = 1;
			}
		}
		else{
			if ( have[b[i]] && have[a[i]] == 0 ) have[a[i]] = 1, cnt ++;
			if ( have[a[i]] && have[b[i]] == 0 ) have[b[i]] = 1, cnt ++;
		}

	cout << cnt << ' ';
	for(int i = k + 1 ; i <= n ; i++)
        if ( have[i] ) cout << i << ' ';
	cout << '\n';
}

void query3(){
	memset(ans, -1, sizeof ans);
    for(int i = 1; i <= m; i ++)
        if ( a[i] <= k ){
            if ( fir[a[i]] == i ) s[a[i]].insert(a[i]);

            if ( b[i] > k){
                for(auto x : s[a[i]])
                    if ( ans[x] == -1 )
                        ans[x] = b[i];
                s[a[i]].clear();
            }
            else{
                if ( fir[b[i]] == i ) s[b[i]].insert(b[i]);
                for ( auto x : s[b[i]] ) s[a[i]].insert(x);
                for ( auto x : s[a[i]] ) s[b[i]].insert(x);
            }
        }
    for (int i = 1; i <= k; i ++) cout << ans[i] << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("conference.in", "r") ){
        freopen("conference.in", "r", stdin);
        freopen("conference.out", "w", stdout);
    }

    cin >> n >> m >> k;

    for(int i = 1 ; i <= m ; i++) {
        cin >> a[i] >> b[i] ;
        if ( a[i] > b[i])
            swap(a[i], b[i]);
    }

    query1();

    query2();

    query3();

    return 0;
}

