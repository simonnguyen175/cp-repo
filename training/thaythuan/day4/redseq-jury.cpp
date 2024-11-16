#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define f first
#define s second

int i,j,n,m,k,a,bitmask[ (1<<16) ],s[20],f[20],r[20],ev[300],st[10010],val[300],norm1[300],ans[16 * 10010],ok,mini,bmsk;
char tr,multimea,expx[1010],evexp[1019];
int valori[ 20 ];
pair<int,int> sortare[16 * 10010];

int INDEX = 0;

char top()
{
    return evexp[ INDEX ];
}

char pop()
{
    return evexp[ INDEX ++ ];
}

int solveR();

int solveP()
{
    if( top() != '(' )
        return pop()-'0';
    else if( top() == '(' )
    {
        pop();
        int rez = solveR();
        pop();
        return rez;
    }
return 0;
}

int solveI()
{
    int rez = solveP();
    while( top() == '*' )
    {
        pop();
        rez = min( rez , solveP() );
    }
    return rez;
}

int solveR()
{
    int rez = solveI();
    while( top() == '+' )
    {
        pop();
        rez = max( rez , solveI() );
    }
    return rez;
}

int main()
{
    cin>>n;
    assert( n <= 16 );

    cin.get();
    for( int i = 1 ; i <= n ; i++ )
    {
        cin>>multimea>>tr>>valori[i]>>tr>>f[i]>>tr>>r[i];
        norm1[ multimea ] = 'A' + i - 1;
        ev[ multimea ] = i;
        assert( f[ i ] <= 1000000000 );
    }
    cin.get();
    cin.get( expx , 10005 );
    k = strlen( expx );
    assert( k >= 3 );
    assert( k <= 1000 );

    for( int i = 0 ; i < k ; i++ )
    {
        if( expx[ i ] >= 'A' && expx[ i ] <= 'Z' )
            expx[ i ] = norm1[ expx[ i ] ];
    }

    val[ '+' ] = '+';
    val[ '*' ] = '*';
    val[ '(' ] = '(';
    val[ ')' ] = ')';

    for( int i = 0 ; i < ( 1<<(n) ) ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            val[ 'A' + j ] = '1';
            if( ( i & (1<<(j)) ) == 0 )
                val[ 'A' + j ] = '0';
        }
        for( int j = 0 ; j < k ; j++ )
            evexp[ j ] = val[ expx[ j ] ];
        INDEX = 0;
        bitmask[ i ] = solveR();
    }

    ok = 0;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = valori[ i ] ; j <= f[ i ] ; j += r[ i ] )
        {
            sortare[ ++ok ] = { j , i };
        }
    }

    sort( sortare + 1 , sortare + ok + 1 );

    for( int i = 1 ; i <= ok ; i++ )
    {
        j = i;
        bmsk = 0;
        while( sortare[ i ].f == sortare[ j ].f )
        {
            bmsk += ( 1 << ( sortare[ j ].s - 1 ) );
            j++;
        }
        i = j - 1;
        if( bitmask[ bmsk ] == 1 )
            ans[ ++ans[ 0 ] ] = sortare[ i ].f;
    }

    cout<<ans[ 0 ]<<'\n';
    for( int i = 1 ; i <= ans[ 0 ] ; i++ )
        cout<<ans[ i ]<<' ';


    return 0;
}
