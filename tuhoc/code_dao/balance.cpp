#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, a[N];
pair<ll, int> s[N];
int f[N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++){
        s[i].fi = s[i-1].fi + a[i];
        s[i].se = i + 1;
    }
    sort(s + 1, s + 1 + n);
    int cnt = 1;
    for (int i = 2; i <= n; i ++)
        if ( s[i].fi == s[i-1].fi ){
            f[s[i].se] -= cnt;
            cnt ++;
        }
        else cnt = 1;
    cnt = 1;
    for (int i = n-1; i >= 1; i --)
        if ( s[i].fi == s[i+1].fi ){
            f[s[i].se] += cnt;
            cnt ++;
        }
        else cnt = 1;
    for (int i = 1; i <= n; i ++)
        f[i] += f[i-1];
    for (int i = 1; i <= n; i ++)
        cout << f[i] << ' ';
    return 0;
}
