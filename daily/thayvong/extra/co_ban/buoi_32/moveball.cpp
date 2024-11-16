#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N];
string s;

int main(){
    freopen("moveball.inp","r",stdin);
	freopen("moveball.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int numRed = 0;
    for (int i = 1; i <= n; i ++)
        if ( s[i] == 'R' )
            numRed ++;

    vector<pair<int, int>> col;

    for (int i = numRed + 1; i <= n; i ++)
        if ( s[i] == 'R' ) col.push_back({1, a[i]});
    for (int i = 1; i <= numRed; i ++)
        if ( s[i] == 'B' ) col.push_back({2, a[i]});

    sort(col.begin(), col.end());
    int mid = col.size() / 2;

    long long ans = 0;
    for (int i = 0; i < mid; i ++){
        ans += max(col[i].second, col[i + mid].second);
        //cout << col[i].second << ' ' << col[i + mid].second << '\n';
    }
    cout << mid << '\n' << ans;
    return 0;
}
