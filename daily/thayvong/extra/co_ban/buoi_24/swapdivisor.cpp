#include <bits/stdc++.h>
using namespace std;

int q, n, k;
int m, a[11];

bool swapDiv(int n, int k){
    m=0;
    int tmp=n;
    while ( n > 0 ){
        a[++m]=n%10;
        n/=10;
    }
    sort(a+1, a+1+m);
    if ( tmp % k == 0 ) return true;
    else{
        do{
            int ans=0;
            for(int i=1; i<=m; i++)
                ans=ans*10+a[i];
            if ( ans % k == 0 ) return true;
        }
        while(next_permutation(a+1, a+1+m));
    }
    return false;
}

int main(){
    freopen("swapdivisor.inp","r",stdin);
    freopen("swapdivisor.out","w",stdout);
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> n >> k;
        cout << swapDiv(n, k) <<'\n';
    }
    return 0;
}
