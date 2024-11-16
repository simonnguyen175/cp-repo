#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool check(string s){
    int dem=0;
    for (int i=0; i<s.size(); i++){
        if ( s[i] == '(' ) dem++;
        else
            dem--;
    }
    if ( dem == 0 ) return true;
    else return false;
}

int main(){
    freopen("brackets1.inp","r",stdin);
    freopen("brackets1.out","w",stdout);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> s;
        cout << check(s) <<"\n";
    }
    return 0;
}
