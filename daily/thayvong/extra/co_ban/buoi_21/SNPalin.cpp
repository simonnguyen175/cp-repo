#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;

int n, a[N];
long long ans=0;

bool palin(int x){
    string s;
    while ( x > 0 ){
        s+= (x%10)+'0';
        x/=10;
    }
    string tmp=s;
    reverse(s.begin(), s.end());
    return tmp==s;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("SNPalin.inp","r",stdin);
    freopen("SNPalin.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if ( palin(a[i]) ) ans+=a[i];
    }
    cout << ans;
    return 0;
}
