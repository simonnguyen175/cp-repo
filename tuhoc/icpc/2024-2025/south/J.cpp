#include<bits/stdc++.h>
using namespace std;

long long get0(vector<long long> cont){
    long long s = 0;
    map<long long, long long> m;
    m[0] = 1;
    long long res = 0;
    for (int i = 0; i < cont.size(); i ++){
        s += cont[i];
        res += m[s];
        m[s] ++;
    }
    return res;
}

int main(){
    vector<long long> a = {3123213, 0};
    cout << get0(a);
}
