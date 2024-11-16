#include<bits/stdc++.h>
#define simon "BWT"
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
string s;

void decode(){
    n = s.size();
    vector<int> cont(n);
    for (int i = 0; i < n; i ++) cont[i] = i;
    stable_sort(cont.begin(), cont.end(), [&](int a, int b){
        return s[a] < s[b];
    });
    int cur = s.find_first_of('@');
    for (int i = 0; i < n-1; i ++){
        cur = cont[cur];
        cout << s[cur];
    }
    cout << '\n';
}

void encode(){
//    cerr << "here\n";
    n = s.size();
    vector<int> a(n);
    vector<pi> key(n), nkey(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i ++)
        key[i].fi = s[i];

    int d = 1;
    while ( true ){
        for (int i = 0; i < n; i ++)
            key[i].se = key[(i+d)%n].fi;
        sort(a.begin(), a.end(), [&](int i, int j){
            return key[i] < key[j];
        });
        int Rank = 0;
        for (int i = 0; i < n; i ++){
            if ( i && key[a[i]] != key[a[i-1]] )
                Rank ++;
            nkey[a[i]].fi = Rank;
        }
        swap(key, nkey);
        if ( d >= n ) break;
        d *= 2;
    }
    for (int i : a) cout << s[(i+n-1)%n];
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    while ( cin >> s )
        if ( s.find_first_of('@') < s.size() )
            decode();
        else{
            s += '@';
            encode();
        }

    return 0;
}
