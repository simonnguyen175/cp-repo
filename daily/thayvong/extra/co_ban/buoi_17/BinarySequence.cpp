#include <bits/stdc++.h>
using namespace std;

int n, a[100];

void xuat(){
    for (int i=1; i<=n; i++)
        cout << a[i];
    cout <<"\n";
}

void gen(int i){
    for (int j=0; j<=1; j++){
        a[i]=j;
        if (i==n) xuat();
        else gen(i+1);
    }
}

int main(){
    freopen("BinarySequence.inp","r",stdin);
    freopen("BinarySequence.out","w",stdout);
    cin >> n ;
    gen(1);
    return 0;
}
