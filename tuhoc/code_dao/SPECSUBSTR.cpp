#include <bits/stdc++.h>
using namespace std;

string s;
int na=0, pa=0,  ans=0;

int main(){
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o'){
            na++;
            ans+=pa;
        }
        else{
            pa++;
            ans+=na;
        }
    }
    cout << ans;
    return 0;
}
