#include <bits/stdc++.h>
using namespace std;

int n, w1, w2, ans=INT_MIN;
int a[23], b[23];
long long s=0;

void solve(){
    long long p=0;
    int dem=0;
    for (int i=1; i<=n; i++)
        if ( b[i] == 1 )
            p+=a[i];
    if ( p <= w1 ){
        long long tmp = s-p;
        if ( tmp <= w2 ){
            ans=max(ans,n);
            return;
        }
        else{
            dem = n;
            for (int i=n; i>=1; i--){
                if ( tmp <= w2 ){
                        ans = max(ans, dem);
                        break;
                }
                else
                    if ( b[i] == 0 ){
                        tmp-=a[i]; dem--;
                    }
            }
        }
    }
}

void gen(int j){
    for (int i=0; i<=1; i++){
        b[j]=i;
        if ( j == n ) solve();
        else
            gen(j+1);
    }
}

int main(){
    freopen("Knap2.inp","r",stdin);
    freopen("Knap2.out","w",stdout);
    cin >> n >> w1 >> w2;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s+=a[i];
    }
    sort(a+1,a+1+n);
    gen(1);
    cout << ans;
    return 0;
}
