#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[10];
queue<long long> q;

int main(){
    freopen("taoso.inp","r",stdin);
    freopen("taoso.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> k >> n;
    for(int i=1; i<=k; i++)
        cin >> a[i];
    if ( k == 1 ){
        for (int i=1; i<=n; i++)
            cout << a[1];
        return 0;
    }
    sort(a+1, a+1+k);
    for(int i=1; i<=k; i++)
        q.push(a[i]);
    if ( n <= k ) cout << a[n];
    else{
        int cnt=k;
        while ( !q.empty() ){
            long long  x=q.front();
            q.pop();
            for (int i=1; i<=k; i++){
                q.push(x*10+a[i]);
                cnt++;
                if ( cnt == n ){
                    cout << q.back();
                    return 0;
                }
            }
        }
    }
}
