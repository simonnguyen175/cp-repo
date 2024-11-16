#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("HAPPYSTR.inp", "r") ){
        freopen("HAPPYSTR.inp", "r", stdin);
        freopen("HAPPYSTR.out", "w", stdout);
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        string s;
        getline(cin, s);
        string t = s;
        reverse(t.begin(), t.end());
        bool ck = 1;
        for (int j = 1; j < s.size(); j ++){
            if ( s[j] - s[j-1] != t[j] - t[j-1] ){
                ck = 0;
                break;
            }
        }

        if ( ck == 1 ){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
