#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;

int k, n1, n2;
string s1, s2;
pair<int, int> st[3];
int tt[3], f[N][N];
int ans = 0;

void init(){
    cin >> k >> s1 >> s2;
    n1 = s1.size(); n2 = s2.size();
    s1 = ' ' + s1; s2 = ' ' + s2;

    // makeF
    f[0][0] = 0;
    for (int i = 1; i <= n1; i ++)
        for (int j = 1; j <= n2; j ++)
            if ( abs(s1[i] - s2[j]) <= k )
                f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = 0;
}

void solve(){
    for (int i = 1; i < n2 - 1; i ++)
        for (int j = i + 1; j < n2; j ++){
            st[0] = {i, i}; st[1] = {j, j-i}; st[2] = {n2, n2 - j};
            tt[0] = 0; tt[1] = 1; tt[2] = 2;
            do{

                int cnt = 0, pre = 0;
                for (int k = 0; k <= 2; k ++){
                    int abo = pre + st[tt[k]].se;
                    int low = st[tt[k]].fi;
                    if ( f[abo][low] >= st[tt[k]].se ) cnt ++;
                    pre += st[tt[k]].se;
                }
                if ( cnt == 3 ) {ans ++; break;}

            }while (next_permutation(tt, tt+3));
        }
    cout << ans;
}

int main(){
    init();
    solve();
    return 0;
}
