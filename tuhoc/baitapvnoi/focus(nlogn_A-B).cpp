#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct ques{
    char type;
    int x, k, a, b;
};

struct optage{
    int val;
    int id;
};

bool compare(optage a, optage b){
    return a.val < b.val;
}

int n, nage;
ques q[2*N];
optage age[2*N];
int realage[2*N];
int st[4 * N];
int res, cnt;

void input(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> q[i].type;
        if ( q[i].type == '+' || q[i].type == '-' ) cin >> q[i].x;
        else cin >> q[i].k >> q[i].a >> q[i].b;
    }
}

void make_age(){
    nage = 0;
    for (int i = 1;  i <= n; i ++)
        if ( q[i].type == '+' || q[i].type == '-' ){
            age[++nage].val = q[i].x;
            age[nage].id = i;
        }
        else{
            age[++nage].val = q[i].a;
            age[nage].id = i;
            age[++nage].val = q[i].b;
            age[nage].id = i;
        }
}

void roirac_age(){
    sort(age + 1, age + 1 + nage, compare);

    int nn = 1;

    if ( q[age[1].id].x > 0 ){
        realage[1] = age[1].val;
        q[age[1].id].x = 1;
    }
    else{
        realage[1] = age[1].val;
        q[age[1].id].a = min(q[age[1].id].a, 1);
        q[age[1].id].b = max(q[age[1].id].a, 1);
    }

    for (int i = 2; i <= nage; i ++){
        if ( q[age[i].id].x > 0 ){
            if ( age[i].val > age[i-1].val ){
                nn ++;
                realage[nn] = age[i].val;
                q[age[i].id].x = nn;
            }
            else
                q[age[i].id].x = nn;
        }
        else{
            if ( age[i].val > age[i-1].val ){
                nn ++;
                realage[nn] = age[i].val;
                q[age[i].id].a = min(q[age[i].id].a, nn);
                q[age[i].id].b = max(q[age[i].id].a, nn);
            }
            else{
                q[age[i].id].a = min(q[age[i].id].a, nn);
                q[age[i].id].b = max(q[age[i].id].a, nn);
            }
        }
    }

    nage = nn;
}

void update(int id, int l, int r, int u, int w){
    if ( l > u || r < u ) return;

    if ( l == r && l == u ){
        st[id] += w;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);

    st[id] = st[id * 2] + st[id * 2 + 1];
}


int getsum(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return getsum(id * 2, l, mid, u, v) + getsum(id * 2 + 1, mid + 1, r, u, v);
}


void get_logn_AB(int id, int l, int r, int u, int v){
    if ( l > v || r < u || res != 0 ) return;

    int mid = ( l + r ) / 2;

    if ( u <= l && r <= v ){
        if ( l == r && st[id] >= cnt ){
            res = realage[l];
            cnt = 0;
        }

        if ( st[id] < cnt ){
            cnt -= st[id];
            return;
        }

        get_logn_AB(id * 2, l, mid, u, v);
        get_logn_AB(id * 2 + 1, mid + 1, r, u, v);

        return;
    }

    get_logn_AB(id * 2, l, mid, u, v);
    get_logn_AB(id * 2 + 1, mid + 1, r, u, v);
}

void solve_nlogn_AB(){
    for (int i = 1; i <= n; i ++){
        if ( q[i].type == '+' ) {update(1, 1, nage, q[i].x, 1); continue;}
        if ( q[i].type == '-' ) {update(1, 1, nage, q[i].x, -1); continue;}
        if ( q[i].type == '?' ){
            int u = q[i].a;
            int v = q[i].b;

            int duv = getsum(1, 1, nage, u, v);

            if ( duv < q[i].k ) {cout << 0 << '\n'; continue;}

            cnt = q[i].k;
            res = 0;

            get_logn_AB(1, 1, nage, u, v);

            cout << res << '\n';
        }
    }
}

int main(){
    input();
    make_age();
    roirac_age();
    solve_nlogn_AB();
    return 0;
}
