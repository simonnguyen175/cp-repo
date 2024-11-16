#include <bits/stdc++.h>
using namespace std;

string s ;

int main(){
    cin >> s ;
    while (s.find('a') != -1)
    {
        int pos = s.find('a');
        s.erase(pos,1);
        cout << s <<"\n";
    }
}
