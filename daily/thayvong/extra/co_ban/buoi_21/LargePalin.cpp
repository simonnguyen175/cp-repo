#include <bits/stdc++.h>
using namespace std;
#define ll long long

int q;
string x;

void solve(string x){
    string y=x;
    int l=x.size();
    int i=0, j=l-1;
    while ( i < j ){
        y[j]=y[i];
        i++;
        j--;
    }
    if ( y >= x ) cout << y <<'\n';
    else{
        int e=(l-1)/2;
        while ( y[e] == '9' ){
            y[e]='0';
            e--;
        }
        y[e]++;
        int i=0, j=l-1;
        while ( i < j ){
            y[j]=y[i];
            i++;
            j--;
        }
        cout << y <<'\n';
    }
}

int main(){
    freopen("LargePalin.inp", "r",stdin);
    freopen("LargePalin.out", "w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> x;
        solve(x);
    }
    return 0;
}
