#include <bits/stdc++.h>
using namespace std;

int n, a[2001], l[2001];

int main(){
    freopen("daytang.inp","r",stdin);
    freopen("daytang.out","w",stdout);
    cin >> n ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    l[1]=1;
    int lmax;
    for (int i=2; i<=n; i++){
        lmax=0;
        for ( int j=1; j<i; j++){
            if ( a[i] > a[j] )
                if ( l[j] > lmax)
                    lmax=l[j];
        }
        l[i]= lmax+1;
    }
    lmax=0;
    int pos;
    for (int i=1; i<=n; i++)
        if ( l[i] > lmax){
            lmax = l[i];
            pos = i;
        }
    cout << lmax <<"\n";
    int temp = lmax, cpos = pos;
    int b[2001];
    b[lmax] = pos;

    for(int i = pos - 1; i >=1; i--)
       if(a[i] < a[cpos]&& l[i] + 1 == l[cpos])
       {
          temp--;
          b[temp] = i;
          cpos = i;
       }
    for (int i=1; i<=lmax; i++)
        cout << b[i] <<" ";
    return 0;
}
