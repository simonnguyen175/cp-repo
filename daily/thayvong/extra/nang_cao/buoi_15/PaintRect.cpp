#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;

int n;
ll a[N], l[N], r[N];
stack<int> sta;
ll ans=0;

int main(){
    freopen("PaintRect.inp","r",stdin);
    freopen("PaintRect.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    //INPUT
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    //SOLVE
    sta.push(0);
    for (int i=1; i<=n; i++){
        while ( a[i] <= a[sta.top()] ) sta.pop();
        l[i]=sta.top();
        sta.push(i);
    }

    while ( !sta.empty() ) sta.pop();

    sta.push(n+1);
    for (int i=n; i>=1; i--){
        while (a[i] <= a[sta.top()] ) sta.pop();
        r[i]=sta.top();
        sta.push(i);
    }

    for (int i=1; i<=n; i++)
        ans=max(ans, (r[i]-l[i]-1)*a[i] );
    cout << ans;
    return 0;
}
