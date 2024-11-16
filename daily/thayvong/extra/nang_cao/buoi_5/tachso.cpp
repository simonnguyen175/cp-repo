#include <bits/stdc++.h>
using namespace std;

string n;

long long ToInt(string s){
    stringstream str2num(s);
    long long x=0;
    str2num >> x ;
    return x;
}

int  main(){
    freopen("TachSo.inp","r",stdin);
    freopen("TachSO.out","w",stdout);
    cin >> n;
    n=' '+n;
    long long l=n.size(), res=0;
    for (int i=1; i<=l-2; i++){
        string temp1=n.substr(1,i);
        string temp2=n.substr(1+i,l-i);
        res += (ToInt(temp1)+ToInt(temp2));
    }
    cout << res ;
    return 0;
}
