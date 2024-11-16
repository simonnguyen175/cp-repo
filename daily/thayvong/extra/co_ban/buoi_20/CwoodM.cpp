#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int x, n, d[100000001], ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CwoodM.inp","r",stdin);
    freopen("CwoodM.out","w",stdout);
    cin >> x >> n;
    for (int i=1; i<=n; i++){
        cin >> d[i];
        q.push(d[i]);
    }
    while ( q.size() != 1 ){
        int a=q.top(); q.pop();
        int b=q.top(); q.pop();
        q.push(a+b);
        ans+=a+b;
    }
    cout << ans;
    return 0;
}
