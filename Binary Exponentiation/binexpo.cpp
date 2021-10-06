int power (int a,int b)
{
    if(b==0) return 1;
    int c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
