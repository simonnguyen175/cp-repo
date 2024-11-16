#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("movie.inp", "r", stdin);
    freopen("movie.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int l = 1, ans = 1;
    for (int i = 1; i <= n; i ++){
        c[a[i]] ++;
        if ( c[a[i]] == 2 ){
            while ( c[a[i]] == 2 && l < i ){
                c[a[l++]] --;
            }
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans;

    return 0;
}
