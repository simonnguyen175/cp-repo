#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int m, m1, m2, r;
string st;
string f[N];
int s[N], cost[5][N][30], org[N];

struct opt{
    int v, t, id;
    bool operator < (const opt &a) const{
        return v - org[id] > a.v - org[a.id];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi19_comstr.inp", "r") ){
        freopen("voi19_comstr.inp", "r", stdin);
        freopen("voi19_comstr.out", "w", stdout);
    }

    cin >> m >> m1 >> m2 >> r;
    cin >> st;
    m = st.size();
    st = ' ' + st;


    int k = 3;
    f[1] = "1"; f[2] = "2";
    s[1] = m1; s[2] = m2;
    while ( true ){
        s[k] = s[k-1] + s[k-2];
        f[k] = f[k-1] + f[k-2];
        if ( s[k] >= m ) break;
        k ++;
    }

    int n = f[k].size();
    f[k] = ' ' + f[k];
    for (int i = 1; i <= n; i ++){
        if ( f[k][i] == '1' ) s[i] = s[i-1] + m1;
        else s[i] = s[i-1] + m2;
    }

    int ans = m;

    for (int i = 1; i <= m; i ++){
        int lo = 0, hi = n, pos;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( s[mid] < i ) pos = mid, lo = mid + 1;
            else hi = mid - 1;
        }


        int t = f[k][pos+1] - '0';
        int id = i - s[pos];

        for (char c = 'A'; c <= 'Z'; c ++)
            cost[t][id][c-'A'+1] += ( st[i] == c );
    }

    vector<opt> cont;

    for (int i = 1; i <= m1; i ++){
        int tmp = 0;
        for (char c = 'A'; c <= 'Z'; c ++){
            if ( st[m2+i] != c ) cost[1][i][c-'A'+1] ++;
            else org[m2+i] = cost[1][i][c-'A'+1];
            tmp = max(tmp, cost[1][i][c-'A'+1]);
        }
        if ( cost[1][i][st[m2+i]-'A'+1] == tmp ) cont.pb({tmp, 0, m2+i});
        else cont.pb({tmp, 1, m2+i});
    }

    for (int i = 1; i <= m2; i ++){
        int tmp = 0;
        for (char c = 'A'; c <= 'Z'; c ++){
            if ( st[i] != c ) cost[2][i][c-'A'+1] ++;
            else org[i] = cost[2][i][c-'A'+1];
            tmp = max(tmp, cost[2][i][c-'A'+1]);
        }
        if ( cost[2][i][st[i]-'A'+1] == tmp ) cont.pb({tmp, 0, i});
        else cont.pb({tmp, 1, i});
    }

    sort(cont.begin(), cont.end());

    int cnt = 0;
    for (int i = 0; i < cont.size(); i ++){
        if ( cnt < r ) ans -= cont[i].v, cnt += cont[i].t;
        else ans -= org[cont[i].id];
    }

    cout << ans;

    return 0;
}

