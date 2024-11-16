#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int temp=1;
    int ans=INT_MIN;
    for (int i=2; i<=n; i++){
        if (a[i]==a[i-1])
            temp++;
        else{
            ans = max(ans,temp);
            temp=1;
        }
    }
    ans = max(ans,temp);
    cout << ans;
    return 0;
}
