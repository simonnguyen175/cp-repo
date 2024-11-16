#include <bits/stdc++.h>
using namespace std;

int t, a, b;

void solve(int a, int b){
    if ( (2*a - b) % 3 == 0 ){
        float y=(2*a-b)/3;
        float x=a-2*y;
        if ( x >= 0 && y >= 0 )
            cout << "YES" <<'\n';
        else cout << "NO" <<'\n';
    }
    else cout <<"NO"<<'\n';
}

int main(){
    freopen("PopCandy.inp","r",stdin);
    freopen("PopCandy.out","w",stdout);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
