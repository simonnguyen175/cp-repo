#include<bits/stdc++.h>
using namespace std;

int n, m;
string s[2];

bool check(string a, string b){
    for (int i = 0; i < n; i ++)
        if ( a.substr(i, n) == b.substr(0, n) ){
            cout << a << ' ' << b << '\n';
            cout << a.substr(i, n) << ' ' << b.substr(0, n) << '\n';
            return true;
        }
    return false;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i <= 1; i ++)
        cin >> s[i], s[i] += s[i];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++){
            string v1 = s[0], v2 = s[1];
            for (int k = i; k <= i + 2; k ++)
                if ( v1[k] == '0' ) v1[k] = '1';
                else v1[k] = '0';
            for (int k = j; k <= j + 2; k ++)
                if ( v1[k] == '0' ) v1[k] = '1';
                else v1[k] = '0';
            if ( check(v1, v2) ) { cout << i << ' ' << j << '\n'; break; }
        }

    return 0;
}
