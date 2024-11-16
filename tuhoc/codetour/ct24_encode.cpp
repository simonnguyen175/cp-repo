#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

long long m;
bool isPrime[N];

int main(){
    cin >> m;

    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= N; i ++) if ( isPrime[i] ){
        for (int j = i*i; j <= N; j += i)
            isPrime[j] = 0;
    }

//    for (int i = 1; i <= 10; i ++)
//        cout << isPrime[i] << ' ';
//    cout << '\n';

    string s = "";
    for (int i = 2; i <= N-5; i ++) if ( isPrime[i] && m % i == 0 ){
        s += (char)'A' + i%26;
        while ( m % i == 0 ){
            m /= i;
        }
    }
    if ( m > 1 ) s += (char)'A' + m%26;
    sort(s.begin(), s.end());

    cout << s;

    return 0;
}
