#include <bits/stdc++.h>
using namespace std;

int n, q, j, a[200001], command, nb=0;
priority_queue<int> b;

int main(){
    freopen("PPStone.inp","r",stdin);
    freopen("PPStone.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> command;
        if ( command == 1 ){
            cin >> j;
            b.push(a[j]);
        }
        else{
            cout << b.top() <<'\n';
            b.pop();
        }
    }
    return 0;
}
