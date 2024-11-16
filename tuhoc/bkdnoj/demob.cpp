#include<bits/stdc++.h>
using namespace std;

int n;
string s;

void encode(){
    string t = "";
    char cnt = 1;
    for (int i = 1; i < s.size(); i ++){
        if ( s[i] == s[i-1] ){
            cnt ++;
        }
        else{
            t += (char) '0' + cnt;
            t += s[i-1];
            cnt = 1;
        }
    }
    t += (char) '0' + cnt;
    t += s[(int)s.size()-1];
    s = t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i ++){
        encode();
        cout << s << '\n';
    }
    cout << s;
    return 0;
}
