#include<bits/stdc++.h>
using namespace std;

int main(){
    cin >> S;
    for (int i = 0; i < S.size(); i ++){
        s[i+1] += S[i] - '0';
    }

    for (int i = 0; i < S.size(); i ++){
        if ( !d[s[i+1]] ) d[s[i+1]] = i + 1;
    }

}
