#include <bits/stdc++.h>
using namespace std;

stack <int> ans;
int n;

int main(){
    freopen("base2.inp","r",stdin);
    freopen("base2.out","w",stdout);
    cin >> n;
    if ( n == 0 ) cout << 0;
    else{
    while ( n > 0 ){
        ans.push(n % 2);
        n/=2;
    }
    while ( !ans.empty() ){
        cout << ans.top();
        ans.pop();
    }
    }
    return 0;
}
