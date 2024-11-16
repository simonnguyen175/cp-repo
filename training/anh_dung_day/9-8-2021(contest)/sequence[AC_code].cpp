#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int n, a[100005];
vector<set<int>> ori;
string ans = "";

string getmin(string a, string b){
    if ( a ==  "" ) return b;
    if ( a.size() < b.size() ) return a;
    else
        if ( a.size() > b.size() ) return b;
            else
                if ( a < b ) return a;
                    else return b;
}

string solve(vector<set<int>> div, int cs){
    if ( div.size() == 2 ){
        if ( div[1].size() == 2 && *div[1].begin() == 0 && *div[1].rbegin() == 1 && div[0].size() == 0 )
        return "9";
    }

    if ( div.size() == 1 ){
        if ( *div[0].begin() == 0 && div[0].size() == 1 ) return "10";

        string res = "";
        for (auto it = div[0].begin(); it != div[0].end(); ++ it)
            res += (char) (*it+'0');
        sort(res.begin(), res.end());
        if ( res[0] == '0' ){
            res.erase(0, 1);
            res.insert(1, "0");
        }
        return res;
    }

    string res = "";
    vector<set<int>> ndiv;
    set<int> cont;

    int cnt = cs;
    for (int i = 0; i < div.size(); i ++){
        if ( cnt == 10 ){
            ndiv.pb(cont);
            cnt = 0; cont.clear();
            for (auto it = div[i].begin(); it != div[i].end(); it ++){
                if ( *it == cnt ) continue;
                cont.insert(*it);
            }
            cnt ++;
        }
        else{
            for (auto it = div[i].begin(); it != div[i].end(); it ++){
                if ( *it == cnt ) continue;
                cont.insert(*it);
            }
            cnt ++;
        }
    }
    ndiv.pb(cont);

    if ( ndiv.size() == div.size() ) return "11111111111111111111111111";

    for (int i = 0; i <= 9; i ++){
        string t = solve(ndiv, i);
        if ( a[1] == 0 && t == "" ) t = "1";
        res = getmin(res, t + (char)(cs+'0'));
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sequence.inp", "r") ){
        freopen("sequence.inp", "r", stdin);
        freopen("sequence.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        set<int> tmp; tmp.insert(a[i]);
        ori.pb(tmp);
    }

    if ( ori.size() == 1 ) { cout << (*ori[0].begin() == 0 ? 10 : *ori[0].begin()); return 0;}


    for (int i = 0; i <= 9; i ++){
        string t = solve(ori, i);
        while ( t[0] == '0' ) t.erase(0,1);
        ans = getmin(ans, t);
    }

    cout << ans;

    return 0;
}
