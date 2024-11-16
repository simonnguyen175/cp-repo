#include<bits/stdc++.h>
#define simon "str5"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
string s[10];
int p[3005];

bool kmp(string &t, string &s){
    string st = t + '#' + s;
    int k = 0;

    for (int i = 0; i < st.size(); i ++) p[i] = 0;
    for (int i = 1; i < st.size(); i ++){
        while ( k > 0 && st[k] != st[i] ) k = p[k-1];
        if ( st[k] == st[i] ) k ++;
        p[i] = k;
    }

    bool flag = 0;

    for (int j = t.size() + 1; j < st.size(); j ++)
        if ( p[j] == t.size() ) { flag = 1; break; }

    if ( !flag ) return false;
    return true;
}

bool check(string &t){
    for (int i = 2; i <= n; i ++){
        string t1 = t; reverse(t1.begin(), t1.end());
        if ( !kmp(t, s[i]) && !kmp(t1, s[i]) )
            return false;
    }
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> s[i];
        s[i] += s[i];
    }

    int best = 0, m = s[1].size()/2;

    for (int i = 0; i < s[1].size()/2; i ++)
        for (int j = best + 1; j <= s[1].size()/2; j ++){
            string t1 = s[1].substr(i, j);
            if ( check(t1) ){
                best = j;
            }
            else break;
        }

    cout << best;
    return 0;
}

