#include<bits/stdc++.h>
#define simon "uav"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e5 + 5;
const int oo = 1e9;

int l, n;
int a[N], u[N], fu[N], fd[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> l >> n;

    a[1] = 1000, a[n] = 1001;
    for (int i = 2; i < n; i ++)
        cin >> a[i];

    // go away
    multiset<int> cont;

    int nu = 1, u[1] = 1;
    for (int i = 2; i <= n; i ++)
        if ( a[i] % 2 == 1 ) u[++nu] = i;

    int id = 1; fu[1] = 1; cont.insert(1);
    for (int i = 2; i <= nu; i ++){
        while ( u[i] - u[id] > l ){
            cont.erase(cont.find(fu[id]));
            id ++;
        }
        fu[i] = *cont.begin() + 1;
        cont.insert(fu[i]);
    }
    cout << fu[nu] << ' ';

    // go back
    cont.clear(); cont.insert(1001); fd[n] = 1001;
    for (int i = n - 1; i >= 1; i --)
        if ( a[i] % 2 == 0 ){
            fd[i] = *cont.rbegin() - a[i];
            if ( i <= n - 10 ) fd[i] = max(fd[i], fd[i+10] + a[i]);
            cont.insert(fd[i]);
        }

    cout << fd[1];

    return 0;
}
