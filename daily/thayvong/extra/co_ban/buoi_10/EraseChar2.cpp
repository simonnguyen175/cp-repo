#include <bits/stdc++.h>
using namespace std;

string s ;

int main(){
    cin >> s;
    int n= s.size()-1;
    s.erase(n-1,2);
    cout << s ;
}
