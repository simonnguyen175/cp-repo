#include <bits/stdc++.h>
using namespace std;

int n, a[100];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        a[i]=i;
    do{
        for (int i=1; i<=n; i++) cout << a[i] <<' ';
        cout <<'\n';
    }while( next_permutation(a+1,a+1+n));
    return 0;
}
