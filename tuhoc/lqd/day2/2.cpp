#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
int x, y, z;
ll ans = 0;
int a[N], b[N], mxL[N], mxR[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("2.inp", "r") ){
        freopen("2.inp", "r", stdin);
        freopen("2.out", "w", stdout);
    }

    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i], a[i] -= b[i];

    for (int i = 1; i <= n; i ++) cout << a[i] << ' '; cout << '\n';

    for (int i = 1; i <= n; i ++) mxL[i] = mxR[i] = (x+y)/z;

    int pos = -1;
    for (int i = 1; i <= n; i ++)
        if ( a[i] > 0 ){
            if ( pos != -1 ){
                mxR[pos] = ( i - pos - 1 ) / 2;
                mxL[i] = i - ( pos + mxR[pos] ) - 1;
            }
            pos = i;
        }

    for (int i = 1; i <= n; i ++) cout << mxL[i] << ' ' << mxR[i] << '\n';

    for (int i = 1; i <= n; i ++)
        if ( a[i] > 0 ){
            for (int j = i + 1; j <= i + mxR[i]; j ++)
                if ( a[j] < 0 ){
                    if ( a[i] + a[j] > 0 )
                        ans += 1LL * abs(a[j]) * z * (j-i), a[i] += a[j], a[j] = 0;
                    else { ans += 1LL * a[i] * z * (j-i); a[j] += a[i]; a[i] = 0; break; }
                }

            for (int j = i - 1; j >= i - mxL[i]; j --)
                if ( a[j] < 0 ){
                    if ( a[i] + a[j] >= 0 )
                        ans += 1LL * abs(a[j]) * z * (i-j), a[i] += a[j], a[j] = 0;
                    else { ans += 1LL * a[i] * z * (i-j); a[j] += a[i]; a[i] = 0; break; }
                }
        }

    int j = 1;
    for (int i = 1; i <= n; i ++)
        if ( a[i] > 0 ){
            j = max(j, i+1);
            while ( j <= min(i+(x+y)/z, n) ){
                if ( a[j] < 0 ){
                    if ( a[i] + a[j] > 0 )
                        ans += 1LL * abs(a[j]) * z * (j-i), a[i] += a[j], a[j] = 0;
                    else { ans += 1LL * a[i] * z * (j-i); a[j] += a[i]; a[i] = 0; break; }
                }
                j ++;
            }
        }

    j = n;
    for (int i = n; i >= 1; i --)
        if ( a[i] > 0 ){
            j = min(j, i-1);
            while ( j >= max(i-(x+y)/z, 1) ){
                if ( a[j] < 0 ){
                    if ( a[i] + a[j] >= 0 )
                        ans += 1LL * abs(a[j]) * z * (i-j), a[i] += a[j], a[j] = 0;
                    else { ans += 1LL * a[i] * z * (i-j); a[j] += a[i]; a[i] = 0; break; }
                }
                j --;
            }
        }

    for (int i = 1; i <= n; i ++)
        if ( a[i] > 0 ) ans += 1LL * x * a[i];
        else ans += 1LL * y * abs(a[i]);

    cout << ans;

    return 0;
}
