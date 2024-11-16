#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;

int n, q, a[N];
vector<int> st[4 * N];

vector<int> MergeSort(vector<int> a, vector<int> b){
    vector<int> res;
    int i = 0, j = 0, n = a.size(), m = b.size();

    while ( i < n && j < m ){
        if ( a[i] <= b[j] ){
            res.push_back(a[i]);
            i ++;
        }
        else{
            res.push_back(b[j]);
            j ++;
        }
    }

    while ( i < n ){
        res.push_back(a[i]);
        i ++;
    }

    while ( j < m ){
        res.push_back(b[j]);
        j ++;
    }

    return res;
}

void update(int id, int l, int r){
    if ( l == r ){
        st[id].push_back(a[l]);
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);

    st[id] = MergeSort(st[id * 2], st[id * 2 + 1]);
}

int xuli(vector<int> x, int k){
    int l = 0, r = x.size() - 1, pos  = x.size();

    while ( l <= r ){
        int mid = (l + r) / 2;
        if ( x[mid] > k ){
            pos = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return x.size() - pos;
}

int get(int id, int l, int r, int u, int v, int k){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ){
        //cout << l <<' ' <<r <<':';
        //for (auto x : st[id] ) cout << x << ' ';
        //cout << ':';
        //cout << xuli(st[id], k) <<'\n';
        return xuli(st[id], k);
    }

    int mid = ( l + r ) / 2;


    return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    update(1, 1, n);

    /*
    for (int i = 1; i <= 2 * n; i ++){
        for (auto x : st[i]) cout << x <<' ';
        cout << '\n';
    }
    */

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int l, r, k;

        cin >> l >> r >> k;

        cout << get(1, 1, n, l, r, k) << '\n';
    }

    return 0;
}
