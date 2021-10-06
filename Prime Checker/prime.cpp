bool prime (int k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    int a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
