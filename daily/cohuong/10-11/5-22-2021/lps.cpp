#include<bits/stdc++.h>
#define simon "lps"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

string s;
stack<char> st;
int ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> s;
    for (int i = 0; i < s.size(); i ++){
        if ( s[i] == ')'  && st.size() > 0 ){
            ans += 2;
            st.pop();
        }
        if ( s[i] == '(' ) st.push(s[i]);
    }

    cout << ans;

    return 0;
}
