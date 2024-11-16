#include<bits/stdc++.h>
#define BG(u) (*(u.begin()))
#define ED(u) (*(--u.end()))
#define ptbg(u) (u.begin())
#define pted(u) (--u.end())
using namespace std;

const int inf = 1e9 + 7;

int m, n;
string st[25];
int res = inf;
int num[3][36][16];
int BB[3];

void cal(int bit, int numBit1){
    if (bit > n) {
        int ans = 0;
        BB[0] = n - numBit1;
        BB[1] = numBit1;
        for (int type = 0; type < 2; type++){
            for (int i = 0; i < m; i++){

                int foo = 0, sum = 0, med = -1;
                for (int itr = 0; itr < 10; itr++){
                    foo += num[type][i][itr];
                    sum += num[type][i][itr] * itr;
                    if (foo >= ((BB[type] + 1) / 2)){
                        med = itr;
                        break;
                    }
                }
                ans = ans + foo * med - sum;
                foo = 0; sum = 0;
                for (int itr = med + 1; itr < 10; itr++){
                    foo += num[type][i][itr];
                    sum += num[type][i][itr] * itr;
                }
                ans = ans + sum - foo * med;
            }
        }
        res = min(res, ans);
        return;
    }

    for (int type = 0; type < 2; type++){
        for (int i = 0; i < m; i++)
            num[type][i][st[bit][i] - '0']++;
        cal(bit + 1, numBit1 + type);
        for (int i = 0; i < m; i++)
            num[type][i][st[bit][i] - '0']--;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("dabstr.inp", "r", stdin);
    freopen("dabstr.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> st[i];
    }
    m = st[n].size();
    cal(1, 0);
    cout << res;
}
