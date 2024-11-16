#include <bits/stdc++.h>
using namespace std;
const int MAX=1e7;

int k, m, a[11];
queue<int> q;

int main(){
    freopen("ghepso.inp","r",stdin);
    freopen("ghepso.out","w",stdout);
    cin >> k >> m;
    for (int i=1; i<=k; i++)
        cin >> a[i];
    sort(a+1, a+1+k);
    for (int i=1; i<=k; i++){
        q.push(a[i]);
        if ( q.front() % m == 0 ){
            cout << a[i];
            return 0;
        }
    }
    while ( !q.empty() ){
        int x =q.front();
        if ( x % m == 0 ){
            cout << x;
            return 0;
        }
        q.pop();
        for (int i=1; i<=k; i++)
            if ( x*10 + a[i] < MAX ) q.push(x*10+a[i]);
    }
    cout << -1;
    return 0;
}
