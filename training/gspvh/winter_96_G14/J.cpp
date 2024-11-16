#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define simon "dtas"
#define int long long
using namespace std;
const int N = 6e5 + 5;

bool num(char x){
    return ( '0' <= x && x <= '9' );
}

int n, q;
struct candi{
    string name;
    ll point;
    int wro;
} a[N];
int cwa[N];
vector<int> wa[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 0; i <= n; i ++){
        string s;
        getline(cin, s);
        if ( !i ) continue;
        int j = 0;
        while ( !num(s[j]) ){
            a[i].name += s[j];
            j ++;
        }

        int cur = 0, cnt = 0;
        for (; j < s.size(); j ++){
            if ( s[j] == ' ' ){
                if ( !cur ) continue;
                if ( cnt ) cwa[cur] ++, wa[i].pb(cur);
                cur = 0;
                cnt ++;
            }
            else cur = cur * 10 + (s[j]-'0');
        }
        if ( cur ) cwa[cur] ++, wa[i].pb(cur);

        a[i].wro = wa[i].size();
    }

    ll tot = 0;
    for (int i = 1; i <= q; i ++) tot += cwa[i];

    for (int i = 1; i <= n; i ++){
        a[i].point = tot;
        for (auto x : wa[i]) a[i].point -= cwa[x];
    }

    sort(a + 1, a + 1 + n, [&](candi x, candi y){
        if ( x.point != y.point ) return x.point > y.point;
        else if ( x.wro != y.wro ) return x.wro < y.wro;
        else return x.name < y.name;
    });

    for (int i = 1; i <= n; i ++)
        cout << a[i].name << a[i].point << '\n';

    return 0;
}
