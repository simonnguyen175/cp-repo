#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x, m;
int a[N], del[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        del[i] = del[i-1] + ( a[i] < x );
    }

    cin >> m;
    int id = 1, cnt = 0;
    for (int i = 1, type; i <= m; i ++){
        cin >> type;
        if ( type == 1 ){
            n ++;
            cin >> a[n];
            del[n] = del[n-1] + ( a[n] < x );
        }
        if ( type == 2 ){
            cnt += ( a[id] >= x );
            id ++;
        }
        if ( type == 3 ){
            int p; cin >> p;
            p += id-1;
            cout << p - del[p] - cnt << '\n';
        }
    }

    return 0;
}
