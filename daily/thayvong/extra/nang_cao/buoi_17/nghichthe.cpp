#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1;

int n, a[N], ans;

void sub1(){
    ans=INT_MAX;
    for (int i=2; i<=n; i++)
        for (int j=1; j<i; j++)
            if ( a[i] < a[j] )
                ans=min(ans, a[j]-a[i]);
    cout << ans;
}

void sub2(){
    ans=INT_MAX;
    bool b[101];
    memset(b, 0, sizeof b);
    b[a[1]]=1;
    for (int i=2; i<=n; i++){
        for (int j=a[i]+1; j<=100; j++)
            if ( b[j] ) ans=min(ans, j-a[i]);
        b[a[i]]=1;
    }
    cout << ans;
}

int main(){
    freopen("nghichthe.inp","r",stdin);
    freopen("nghichthe.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    if ( n <= 1000 ) sub1();
    else sub2();
    return 0;
}
