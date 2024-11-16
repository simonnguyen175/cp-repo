#include<bits/stdc++.h>
using namespace std;

int t;;
long long n;
int f[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    f[0] = f[1] = f[2] = 0;
    for (int i = 3; i <= 11; i ++) f[i] = 1;
    cin >> t;
    while ( t -- ){
        cin >> n;
        cout << 2-f[n%12] << '\n';
    }

    return 0;
}
