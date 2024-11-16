#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3;

int n, s;
pi a[N];
int id[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("rectcover.in", "r") ){
        freopen("rectcover.in", "r", stdin);
        freopen("rectcover.out", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        id[i] = i;
    }

    int ans = n+1;
    do{
        int mnx = a[id[1]].x, mxy = a[id[1]].y;
        int mxx = mnx;
        int cnt = 1;
        for (int i = 2; i <= n; i ++){
            mnx = min(mnx, a[id[i]].x);
            mxx = max(mxx, a[id[i]].x);
            mxy = max(mxy, a[id[i]].y);

            if ( 1LL*(mxx-mnx)*mxy > s ){
                mnx = mxx = a[id[i]].x, mxy = a[id[i]].y;
                cnt ++;
            }
        }
        ans = min(ans, cnt);
    }while ( next_permutation(id+1, id+1+n) );

    cout << ans;

    return 0;
}
