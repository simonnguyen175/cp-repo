#include<bits/stdc++.h>
using namespace std;

int n, p, w[200001];

int main(){
    freopen("Ferriswheel.Inp","r",stdin);
    freopen("Ferriswheel.Out","w",stdout);
    cin >> n >> p;
    for (int i=1; i<=n; i++)
        cin >> w[i];
    sort(w+1,w+1+n);
    int l=1, r=n, ans=0;
    while( l <= r ){
        if ( w[l] + w[r] <= p ){
            ans++;
            l++; r--;
            continue;
        }
        else{
            ans++; r--;
        }
    }
    cout << ans;
    return 0;
}
