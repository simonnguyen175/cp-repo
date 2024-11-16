#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 5e5 + 5;

int n, k;
int a[N], pre[N], suf[N];
int pos[N][31], b[N], dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        pre[i] = pre[i-1] | a[i];
    for (int i = n; i >= 1; i --)
        suf[i] = suf[i+1] | a[i];

    for (int i = 1; i <= n; i ++)
        pos[i][30] = i;
    int ans = 0, lb = 30;
    for (int t = 29; t >= 0; t --){
        int cur = 0;
        int req = ans|(1<<t);
        for (int i = 1; i <= n; i ++){
            if ( BIT(a[i], t) ) cur = i;
            pos[i][t] = min(pos[i][lb], cur);

            if ( pos[i][t] ){
                dp[i] = dp[pos[i][t]-1] + 1;
                b[i] = b[pos[i][t]-1];
            }
            else{
                dp[i] = 0;
                b[i] = i;
            }
        }

        if ( dp[n] >= k )
            ans |= (1<<t), lb = t;
        else if ( dp[n] == k - 1 ){
            bool ck = 0;
            for (int i = n; i >= 1; i --)
                if ( dp[i] == k - 1 && ((suf[i+1]|pre[b[i]])&req) == req ){
                    ck = 1; break;
                }
            if ( ck ) ans |= (1<<t), lb = t;
        }
    }

    cout << ans;

    return 0;
}
