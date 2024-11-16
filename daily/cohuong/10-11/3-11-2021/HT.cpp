#include <bits/stdc++.h>
using namespace std;

string s;
map <string, int> dem;
string opt[]={"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

int main(){
    freopen("HT.inp","r",stdin);
    freopen("HT.out","w",stdout);
    cin >> s;
    for (int i=2; i<s.size(); i++){
        string tmp="";
        tmp+=s[i-2]; tmp+=s[i-1]; tmp+=s[i];
        dem[tmp]++;
    }
    for (int i=0; i<8; i++)
        cout << dem[opt[i]] <<' ';
    return 0;
}
