# define MAXN 1e7      // MAXN, upto which we have to find the prime numbers
// Time Complexity :- O(n*log(log n))
// Used to find print/find Prime numbers upto MAXN
bool prime[MAXN];
void SieveOfEratosthenes(int n)
{
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=n;p++)
        if(prime[p]==true)
            for(int i=p*p;i<=n;i+=p)
                prime[i]=false;
}
