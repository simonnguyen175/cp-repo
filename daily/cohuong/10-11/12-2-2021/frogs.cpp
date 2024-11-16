#include<bits/stdc++.h>
#define simon "frogs"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n;
int h[N], jum[N], nxt[N][21];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    for (int i = 1; i <= n; i ++) cin >> jum[i];

    memset(nxt, -1, sizeof nxt);

    stack<int> st;
    for (int i = n; i >= 1; i --){
        while ( !st.empty() && h[st.top()] <= h[i] ) st.pop();
        if ( !st.empty() ) nxt[i][0] = st.top();
        else nxt[i][0] = -1;
        st.push(i);
    }

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        if ( nxt[i][j-1] != -1 )
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    for (int i = 1; i <= n; i ++){
        int cur = i;
        for (int j = 20; j >= 0; j --)
            if ( cur != -1 && ((jum[i]>>j)&1) ){
                cur = nxt[cur][j];
            }
        if ( cur == -1 ) cout << -1 << ' ';
        else cout << h[cur] << ' ';
    }

    return 0;
}
