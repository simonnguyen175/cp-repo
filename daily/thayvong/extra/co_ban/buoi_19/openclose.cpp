#include <bits/stdc++.h>
using namespace std;

stack<int> b;
int n, a[500001], ans=INT_MIN;
string s;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    freopen("openclose.inp","r",stdin);
    freopen("openclose.out","w",stdout);
    cin >> n;
    cin >> s;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=0; i < n; i++)
        if ( s[i] == '(' ) b.push(a[i+1]);
        else{
            ans=max(ans, b.top()+a[i+1]);
            b.pop();
        }
    cout << ans;
    return 0;
}
