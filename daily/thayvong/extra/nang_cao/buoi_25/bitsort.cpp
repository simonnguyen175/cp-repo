#include<bits/stdc++.h>
#define simon "bitsort"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, a[N];

bool compare(int a, int b){
    bitset<50> fooa(a);
    bitset<50> foob(b);
    if ( fooa.count() < foob.count() ) return true;
    else{
        if ( fooa.count() == foob.count() ) return a < b;
        else return false;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i=1; i<=n; i++)
        a[i] = i;

    sort(a+1, a+1+n, compare);

    for (int i=1; i<=n; i++)
        cout << a[i] << '\n';
    return 0;
}

