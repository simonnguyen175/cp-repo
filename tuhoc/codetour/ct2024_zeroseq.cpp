#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, q;
int a[N], f[N];
long long s[N];
map<long long, int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];

    while ( q -- ){
        int l, r;
        cin >> l >> r;

        f[l-1] = 0;
        for (int i = l; i <= r; i ++) f[i] = 0;

        d.clear();
        d[s[l-1]] = 0;

        for (int i = l; i <= r; i ++){
            f[i] = f[i-1];

            if ( d.find(s[i]) != d.end() )
                f[i] = max(f[i], d[s[i]] + 1);

//            cout << f[i] << ' ';

            d[s[i]] = max(d[s[i]], f[i]);
        }

        cout << f[r] << '\n';
    }

    return 0;
}
