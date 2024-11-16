#include<bits/stdc++.h>
using namespace std;

string p, s, t;
int d[10];

int main(){
    cin >> p >> s;
    for (int i = 0; i < s.size(); i ++)
        d[s[i] - '0'] = 1;

    string t = "";
    for (int i = 0; i < p.size(); i ++){
        if ( d[p[i] - '0'] == 0 ){
            t += p[i];
        }
        else{
            int x = p[i] - '0';
            while ( d[x] && x >= 0 ){
                x --;
            }
            if ( x == -1 ) { cout << -1; return 0; }
            t += (char) x + '0';

            int mx;
            for (int j = 0; j <= 9; j ++)
                if ( d[j] == 0 ) mx = j;

            for (int j = i+1; j < p.size(); j ++)
                t += (char) mx + '0';

            break;
        }
    }

    for (int i = 0; i < t.size(); i ++)
        if ( t[i] != '0' ){
            for (int j = i; j < t.size(); j ++)
                cout << t[j];

            break;
        }

    return 0;
}
