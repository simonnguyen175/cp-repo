#include<bits/stdc++.h>
#define ll long long
#define bit(x, k) (((x)>>k)&1)
using namespace std;

const ll oo = 1e18;

ll a1, a2, a3, b1, b2, b3, f[55][2][2][2][2][2][2];
int csa1[55], csb1[55], csa2[55], csb2[55], csa3[55], csb3[55];

ll mn(int i, int oka1, int okb1, int oka2, int okb2, int oka3, int okb3 ){
    if( i<0 ) return 0;

    if( f[i][oka1][okb1][oka2][okb2][oka3][okb3] != -1 )
        return f[i][oka1][okb1][oka2][okb2][oka3][okb3];

    int minx, maxx, miny, maxy, minz, maxz;

    if( oka1 ) minx = 0; else minx = csa1[i];
    if( okb1 ) maxx = 1; else maxx = csb1[i];

    if( oka2 ) miny = 0; else miny = csa2[i];
    if( okb2 ) maxy = 1; else maxy = csb2[i];

    if( oka3 ) minz = 0; else minz = csa3[i];
    if( okb3 ) maxz = 1; else maxz = csb3[i];

    ll best = oo;

    for(int x = minx; x <= maxx; x ++)
        for(int y = miny; y <= maxy; y ++)
            for(int z = minz; z <= maxz; z ++){
                ll tmp = (x^y^z) * ( 1LL << ( i ) ) +
                mn(i-1, oka1|(x>csa1[i]), okb1|(x<csb1[i]), oka2|(y>csa2[i]), okb2|(y<csb2[i]), oka3|(z>csa3[i]), okb3|(z<csb3[i]));

                best = min(best, tmp);
            }

    f[i][oka1][okb1][oka2][okb2][oka3][okb3] = best;

    return best;
}

ll mx(int i, int oka1, int okb1, int oka2, int okb2, int oka3, int okb3){
    if( i<0 ) return 0;

    if( f[i][oka1][okb1][oka2][okb2][oka3][okb3] != -1 ) return f[i][oka1][okb1][oka2][okb2][oka3][okb3];

    int minx, maxx, miny, maxy, minz, maxz;

    if( oka1 ) minx = 0; else minx = csa1[i];
    if( okb1 ) maxx = 1; else maxx = csb1[i];

    if( oka2 ) miny = 0; else miny = csa2[i];
    if( okb2 ) maxy = 1; else maxy = csb2[i];

    if( oka3 ) minz = 0; else minz = csa3[i];
    if( okb3 ) maxz = 1; else maxz = csb3[i];

    ll best = 0;

    for(int x = minx; x <= maxx; x ++)
        for(int y = miny; y <= maxy; y ++)
            for(int z = minz; z <= maxz; z ++){
                ll tmp = (x^y^z) * ( 1LL << ( i ) ) +
                mx(i-1, oka1|(x>csa1[i]), okb1|(x<csb1[i]), oka2|(y>csa2[i]), okb2|(y<csb2[i]), oka3|(z>csa3[i]), okb3|(z<csb3[i]));

                best = max(best, tmp);
            }

    f[i][oka1][okb1][oka2][okb2][oka3][okb3] = best;

    return best;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    for(int i = 0; i <= 51; i ++) csa1[i] = bit(a1, i);
    for(int i = 0; i <= 51; i ++) csb1[i] = bit(b1, i);

    for(int i = 0; i <= 51; i ++) csa2[i] = bit(a2, i);
    for(int i = 0; i <= 51; i ++) csb2[i] = bit(b2, i);

    for(int i = 0; i <= 51; i ++) csa3[i] = bit(a3, i);
    for(int i = 0; i <= 51; i ++) csb3[i] = bit(b3, i);

    memset(f, -1, sizeof(f));
    cout << mn(51, 0, 0, 0, 0, 0, 0) <<'\n' ;

    memset(f, -1, sizeof(f));
    cout << mx(51, 0, 0, 0, 0, 0, 0);

    return 0;
}
