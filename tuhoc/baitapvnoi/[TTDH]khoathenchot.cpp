#include<bits/stdc++.h>
using namespace std;

int n;

void solve(string s){
    int len=s.size();
    s=' '+s;
    int l=1, r=len, lent;
    string tmp="";
    pair<string, int> res;
    while ( l <= r ){
        if ( s[l] == s[r] ){
            tmp+=s[l];
            l++; r--;
        }
        else{
            lent=tmp.size();
            if ( lent > res.second ){
                res.second=lent;
                res.first=tmp;
            }
            tmp="";
            l++; r--;
        }
    }
    lent=tmp.size();
    if ( lent*2-1 > res.second ){
        string t=tmp;
        reverse(tmp.begin(), tmp.end());
        res.first=t.substr(0,lent-1)+tmp;
    }
    cout << res.first <<'\n';
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
