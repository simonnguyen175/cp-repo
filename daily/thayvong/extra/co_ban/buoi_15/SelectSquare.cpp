#include <bits/stdc++.h>
using namespace std;

int n;
long long s;
pair <int, long long> a[100001];

int main(){
    freopen("SelectSquare.inp","r",stdin);
    freopen("SelectSquare.out","w",stdout);
    cin >> n >> s;
    for (int i=1; i<=n; i++){
        cin >> a[i].second;
        a[i].first= a[i].second*a[i].second;
    }
    sort (a+1,a+1+n);
    int ans=1;
    int i=1;
    for (int k=2; k <=n; k++){
        while ( a[k].first - a[i].first > s )
            i++;
        int l = k-i+1;
        ans =max(ans,l);
    }
    cout << ans;
    return 0;
}
