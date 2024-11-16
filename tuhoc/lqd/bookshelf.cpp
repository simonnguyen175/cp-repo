#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N=2e3+5;

int n, l, h[N], w[N];
ll dp[N];

int main(){
    // input
    FASTio
    cin >> n >> l;
    for (int i=1; i<=n; i++)
        cin >> h[i] >> w[i];

    // solve
    for (int i=1; i<=n; i++)
        dp[i]=LLONG_MAX;
    dp[0]=0;

    for (int i=1; i<=n; i++){

        ll s=0; int stHigh=0;

        for (int j=i; j>=1; j--){

            if ( s + w[j] > l ) break;
            s += w[j];

            stHigh = max(stHigh, h[j]);
            dp[i] = min(dp[i], dp[j-1] + stHigh);

        }

    }

    cout << dp[n];
    return 0;
}

