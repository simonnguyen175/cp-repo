#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    cin >>n >> m;
    cout << (n*(n+1)/2) % (m+1);
    return 0;
}
