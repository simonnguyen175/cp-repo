#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for (int i = 1; i < N; i ++)
        pw2[i] = mul(pw2[i-1], 2);
    for (int i = 1; i < N; i ++)
        phi[i] = i;
    for (int i = 2; i <= N; i ++)

    return 0;
}
