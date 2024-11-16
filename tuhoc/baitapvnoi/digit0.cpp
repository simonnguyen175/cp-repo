#include<bits/stdc++.h>
using namespace std;

string s;
int cnt[256];

long long getNum(int n, int k){
    long long res = 0;
    int t = 1;
    while ( t <= n ){
        t *= k;
        res += n / t;
    }
    return res;
}

int main(){
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i ++)
        cnt[s[i]] ++;

    long long num2 = getNum(n, 2);
    for (char i = 'a'; i <= 'z'; i ++)
        num2 -= getNum(cnt[i], 2);

    long long num5 = getNum(n, 5);
    for (char i = 'a'; i <= 'z'; i ++)
        num5 -= getNum(cnt[i], 5);

    cout << min(num2, num5);

    return 0;
}
