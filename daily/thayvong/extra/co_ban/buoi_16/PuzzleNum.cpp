#include <bits/stdc++.h>
using namespace std;

int k, a[11], d[11], b[1000000], m=0, x;

int main(){
    freopen("PuzzleNum.inp","r",stdin);
    freopen("PuzzleNum.out","w",stdout);
    cin >> k;
    for (int i=1; i<=k; i++){
        cin >> d[i];
        a[i]=d[i];
    }
    sort (a+1,a+1+k);
    do{
        x=0;
        for (int i=1; i<=k; i++) x=x*10+a[i];
        b[++m]=x;
    }while (next_permutation(a+1,a+1+k));

    for (int i=1; i<=k; i++){
        for (int t=1; t<=k; t++)
            a[t]=d[t];
        a[k+1]=d[i];
        sort(a+1,a+k+2);
        do{
            x=0;
            for (int i=1; i<=k+1; i++) x=x*10+a[i];
            b[++m]=x;
        }while (next_permutation(a+1,a+2+k));
    }
    sort(b+1,b+1+m);
    for (int i=1; i<=m; i++)
        cout << b[i] <<"\n";
    return 0;
}
