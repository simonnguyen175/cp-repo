#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
using ll = long long;
//using ld = long double;
#define X first
#define Y second
using ii = pair < int , int > ;
using iii = pair < int , ii > ;
const ll MAX=500005;
int a[MAX],b[MAX],e[MAX];
int dp[MAX];
int pos[MAX][31];
int bel[MAX];
int main(){
    //freopen("1398e.inp", "r", stdin);//freopen("xormst.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    //priority_queue < int , vector < int > , greater < int > Q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=b[i-1]|a[i];
    }
    for(int i=n;i>0;i--) e[i]=e[i+1]|a[i];
    int ans=0;
    int pre=30;
    for(int i=1;i<=n;i++) pos[i][30]=i;
    for(int j=29;j>=0;j--){
        int lim=ans|(1<<j);
        int near=0;
        //memset(bel,0,sizeof bel);
        for(int i=1;i<=n;i++){

            if(a[i]&(1<<j)) near=i;
            pos[i][j]=min(pos[i][pre],near);
            if(pos[i][j]) {
                dp[i]=dp[pos[i][j]-1]+1;
                bel[i]=bel[pos[i][j]-1];
            }
            else {
                dp[i]=0;
                bel[i]=i;
            }
        }
        if(dp[n]>=k){
            ans|=(1<<j);pre=j;
            continue;
        }
        if(dp[n]<k-1)
            continue;
        bool tt=0;
        for(int i=n;i>0;i--)
            if(dp[i]==k-1){
                if( ((e[i+1]|b[bel[i]])&lim)==lim ){
                    tt=1;break;
                }
            }
            else break;
        if(tt){
            ans|=(1<<j);pre=j;
            continue;
        }
    }
    cout<<ans;
}
