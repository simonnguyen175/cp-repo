#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int d[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while ( t -- ){
        cin >> n >> s;
        d[0] = d[1] = d[2] = d[3] = 0;
        for (int i = 0; i < s.size(); i ++)
            if ( s[i] != '?' ) d[s[i]-'A'] ++;

        cout << min(d[0], n) + min(d[1], n) + min(d[2], n) + min(d[3], n) << '\n';
    }

    return 0;
}
