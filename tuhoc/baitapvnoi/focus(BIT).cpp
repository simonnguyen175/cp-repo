#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int oo = 1e9;

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
int bit[4*N], child[4*N], brother[4*N], ans;

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

void buildchild(int x)
{
    int t;
    while(x<=N)
    {
        t=x;
        x+=x&(-x);

        child[x]=min(child[x], t);
    }
}

void buildbrother(int x)
{
    int t;
    while(x>=1)
    {
        t=x;
        x-=x&(-x);
        brother[x]=max(brother[x], t);
    }
}

void init(){
    input();
    make_age();
    roirac_age();

    for(int i=1; i<=N; i++) child[i]=INT_MAX;
    for(int i=1; i<=N; i+=2)
    {
        child[i]=0;
        buildchild(i);
    }
    for(int i=N; i>=1; i--) buildbrother(i);
    child[0]=0;
    brother[0]=0;
}

void updatePoint(int u, int v){
    int idx = u;
    while ( idx <= nage ){
        bit[idx] += v;
        idx += idx & (-idx);
    }
}

int getSum(int p){
    int idx = p, res = 0;
    while ( idx > 0 ){
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void getans(int l, int x, int t)
{
    if(x==0) return;
    if(bit[x]<t)
    {
        getans(l, brother[x], t-bit[x]);
        return;
    }
    ans=min(x, ans);
    getans(l, child[x], t);
    return;
}

int get(int x)
{
    int s;
    while(x>=1)
    {
        s=x;
        x-=x&(-x);
    }
    return s;
}

void solve_bit(){

    for (int i = 1; i <= n; i ++){
        if ( q[i].type == '+' ) updatePoint(q[i].x, 1);
        if ( q[i].type == '-' ) updatePoint(q[i].x, -1);
        if ( q[i].type == '?' ){
            int u = q[i].a;
            int v = q[i].b;
            int duv = getSum(v) - getSum(u-1);

            if ( duv < q[i].k ){ cout << 0 << '\n'; continue; }

            int t = get(v);
            ans=INT_MAX;
            getans(u, t, q[i].k+getSum(u-1));
            cout << realage[ans] <<'\n';
        }
    }
}


int main(){
    init();
    solve_bit();
    return 0;
}
