#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int u = n & (-n);
    cout << u;
    return 0;
}

