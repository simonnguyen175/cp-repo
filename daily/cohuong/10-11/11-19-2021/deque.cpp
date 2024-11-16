#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    stack<pair<int, int> > st;
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        while(!st.empty() && st.top().first < a)
            res += st.top().second, st.pop();
        if(!st.empty()) {
            if(st.top().first == a) {
                res += st.top().second++;
                if(st.size() > 1) ++res;
            } else {
                ++res;
                st.push(make_pair(a, 1));
            }
        } else st.push(make_pair(a, 1));
    }
    cout << res << '\n';
    return 0;
}
