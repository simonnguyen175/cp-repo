void phantich(long long x)
{
    int i=2; m=0;
    while(i*i<=x)
    {
        if(x%i==0)
        {
            ++m;
            a[m]=i;
            b[m]=0;
            while(x%i==0)
            {
                ++b[m];
                x=x/i;
            }
        }
        ++i;
    }
    if(x>1)
    {
        ++m;
        a[m]=x;
        b[m]=1;
    }
    return;
}