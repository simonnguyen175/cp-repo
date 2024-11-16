#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int n;
string s, seq;

string conv(int x){
    string res = "";
    while (x > 0){
        res += (x % 10) + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    if ( fopen("table.inp", "r") ){
        freopen("table.inp", "r", stdin);
        freopen("table.out", "w", stdout);
    }

	cin >> n >> s;

    for(int i = 1 ; i <= n; i ++) seq += ' ';
    for(int i = 1 ; i < N ; i ++)
        seq += conv(i);

    string t = seq.substr(0, n);
    int len = seq.size();

    if ( s == t ){
        cout << 0;
        return 0;
    }

    for(int i = 1 ; i < len; i++ ){
        seq.erase(0, 1);
        t += seq[i+n-1];
        if ( t == s ){
            cout << i;
            return 0;
        }
    }

    return 0;
}
