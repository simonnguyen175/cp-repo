#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    set<int> s;
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        auto it = s.lower_bound(a[i]); // con tro tra ve vi tri dau tien cua cac dinh thap
        // co gia tri the tich lon hon hoac bang khoi hop co gia tri the tich la ai
        if ( it == s.end() ){
            ans ++;
            cout << "them thap moi " << a[i] << '\n';
            s.insert(a[i]); // them khoi hop a[i] vao lam thap moi
        }
        else{
            cout << "xep " << a[i] << " len dinh thap co gtri " << *it << '\n';
            s.erase(it); // xoa dinh hien tai
            s.insert(a[i]); // them a[i] len dau cua dinh thap hien tai tim duoc
        }
    }

    cout << ans;
}
