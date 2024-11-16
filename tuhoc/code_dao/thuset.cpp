#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(2); s.insert(1);
    cout << &(*s.find(2));
    return 0;
}
