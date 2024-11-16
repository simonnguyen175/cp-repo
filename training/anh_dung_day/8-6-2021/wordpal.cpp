#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
const ll oo = 1e18;

int n;
string s[N];
ll c[N];
ll f[N][25][2];
int vis[N][25][2];

bool palin(string t){
    string tmp = t;
    reverse(tmp.begin(), tmp.end());
    return ( tmp == t );
}

// xet den xau id, thua rem ben trai/phai (t=0/1)
ll calc(int id, int rem, bool t){
    vis[id][rem][t] ++;

    //cout << id << ' ' << rem << ' ' << t << ' ' << f[id][rem][t] << ' ' << vis[id][rem][t] << '\n';
    if ( f[id][rem][t] == -1 && vis[id][rem][t] > 1 ) return oo;

    if ( id != 0 ){
        if ( rem <= 1 ) return 0;

        if ( f[id][rem][t] != -1 ) return f[id][rem][t];

        string l = "", r = "";

        for (int j = s[id].size()-rem; j < s[id].size(); j ++) l += s[id][j];
        for (int j = 0; j < rem; j ++) r += s[id][j];

        if ( t == 0 ){
            if ( palin(l) ) return 0;
        }
        else{
            if ( palin(r) ) return 0;
        }
    }

    ll best = oo;
    for (int i = 1; i <= n; i ++){
        if ( id == 0 ){
            best = min(best, calc(i, s[i].size(), 0) + c[i]);
            best = min(best, calc(i, s[i].size(), 1) + c[i]);
            continue;
        }
        if ( t == 0 ){
            string st1 = s[id].substr(s[id].size()-rem, rem);
            string st2 = s[i];

            if ( st1.size() < st2.size() ){
                reverse(st2.begin(), st2.end());
                if ( st2.find(st1) == 0 ){
                    int nrem = st2.size() - st1.size();
                    int nt = 1;
                    best = min(best, calc(i, nrem, nt) + c[i]);
                }
            }
            else{
                reverse(st2.begin(), st2.end());
                if ( st1.find(st2) == 0 ){
                    int nrem = st1.size() - st2.size();
                    int nt = 0;
                    best = min(best, calc(id, nrem, nt) + c[i]);
                }
            }
        }
        else{
            string st1 = s[id].substr(0, rem);
            string st2 = s[i];

            if ( st1.size() < st2.size() ){
                reverse(st1.begin(), st1.end());
                if ( st2.find(st1) == 0 ){
                    int nrem = st2.size() - st1.size();
                    int nt = 0;
                    best = min(best, calc(i, nrem, nt) + c[i]);
                }
            }
            else{
                reverse(st1.begin(), st1.end());
                if ( st1.find(st2) == 0 ){
                    int nrem = st1.size() - st2.size();
                    int nt = 1;
                    best = min(best, calc(id, nrem, nt) + c[i]);
                }
            }
        }
    }

    f[id][rem][t] = best;

    return best;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    if ( fopen("wordpal.inp", "r") ){
        freopen("wordpal.inp", "r", stdin);
        freopen("wordpal.out", "w", stdout);
    }

    cin >> n;
    s[0] = "";
    for (int i = 1; i <= n; i ++)
        cin >> s[i] >> c[i];

    memset(f, -1, sizeof f);
    f[0][0][0] = 0;


    ll res = calc(0, 0, 0);
    cout << (res == oo ? -1 : res);

    return 0;
}
