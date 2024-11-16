#include <bits/stdc++.h>
using namespace std;
string inputString;
int main()
{
    cin >>inputString;
    int d = 0;
    string  s = inputString;
    string p=" ";
    for (int i = 0; i < s.length(); i++){
        string h = "";
        for (int j = i; j < s.length(); j++){
            h = h + s[j];
            string k = " "+h+" " ; cout << k <<"/"<<p; cout << p.find(k);
            if (p.find(k) < 0 || p.find(k) > p.length() - 1) {
                d++; cout << d <<"\n";
                p = p + h+ " ";
            }
        }
    }
    cout << endl ;
    cout << d;
    return 0;
}
