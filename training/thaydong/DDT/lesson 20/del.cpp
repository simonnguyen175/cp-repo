#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n;
vector<int> ans;
char a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    int l = -1;
    for (int i = 0; i < n; i ++)
        if ( a[i] == 'X' ) { l = i; break; }
    if ( l == -1 ) { cout << 0; return 0; }

    a[l] = 'Z';
    for (int i = l + 1, j; i < n; i ++) if ( a[i] == 'Z' ){
        j = i-1;
        while ( a[j] != 'Z' )
            ans.pb(j), j --;
        ans.pb(i);
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';

    return 0;
}
