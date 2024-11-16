#include <bits/stdc++.h>
#define simon "seqd"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e3+1;
const int oo=1e18;

int n, a[N], dp[N][4][2], ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    ///khởi tạo
    for (int i=1; i<=n; i++)
        for (int j=0; j<=3; j++){
            dp[i][j][0]=1;
            dp[i][j][1]=1;
        }

    for (int i=1; i<=n; i++)
        dp[i][0][1]=0;
    ///DP
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            if ( a[j] <= a[i] ) dp[i][0][0]=max(dp[i][0][0], dp[j][0][0]+1);
    //dp[i][j][k] là dãy con độ dài lớn nhất xét đến số thứ i đổi dấu j số và số thứ i có đổi dấu hay ko
    for (int i=1; i<=n; i++)
        for (int j=1; j<=3; j++)
            for (int k=1; k<i; k++){
                if ( -a[k] <= a[i] ) dp[i][j][0]=max(dp[i][j][0], dp[k][j][1]+1);
                if ( a[k] <= a[i] ) dp[i][j][0]=max(dp[i][j][0], dp[k][j][0]+1);
                if ( -a[k] <= -a[i] ) dp[i][j][1]=max(dp[i][j][1], dp[k][j-1][1]+1);
                if ( a[k] <= -a[i] ) dp[i][j][1]=max(dp[i][j][1], dp[k][j-1][0]+1);
            }
    for (int i=1; i<=n; i++)
        for (int j=0; j<=3; j++)
            ans=max({ans, dp[i][j][0], dp[i][j][1]});
    cout << ans;
    return 0;
}
