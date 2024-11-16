#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    cin >> n >> s ;
    int red= 0, blue=0;
    for (int i=0; i<=n-1; i++){
        if (s[i]=='R') red++;
        if (s[i]=='B') blue++;
    }
    if (red > blue) cout <<"Red";
    if (blue > red) cout <<"Blue";
    if (red== blue) cout <<"RedEqualBlue";
    return 0;
}
