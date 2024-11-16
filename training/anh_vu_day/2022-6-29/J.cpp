#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, m;
struct query{
    int l, r, x;
} que[N];
int d[N], cnt[2][N];
char ans[N], s[] = {'R', 'B'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        cin >> que[i].l >> que[i].r >> que[i].x;
        que[i].l ++, que[i].r ++;
    }

    for (int i = 1; i <= m; i ++) if ( que[i].x == 1 ){
        d[que[i].l] ++;
        d[que[i].r] --;
    }
    for (int i = 1; i <= n; i ++) d[i] += d[i-1];

    int cur = 0;
    for (int i = 1; i <= n; i ++){
        ans[i++] = s[cur];
        while ( d[i-1] ){
            ans[i] = s[cur];
            i ++;
        }
        i --;
        cur ^= 1;
    }

    for (int i = 1; i <= n; i ++)
    for (int t = 0; t <= 1; t ++)
        cnt[t][i] = cnt[t][i-1] + ( ans[i] == s[t] );

    for (int i = 1; i <= m; i ++) if ( que[i].x == 2 )
        if ( cnt[0][que[i].r]-cnt[0][que[i].l-1] == 0
          || cnt[1][que[i].r]-cnt[1][que[i].l-1] == 0 ){
            cout << 0; return 0;
          }

    cout << 1 << '\n';
    for (int i = 1; i <= n; i ++)
        cout << ans[i];

    return 0;
}
