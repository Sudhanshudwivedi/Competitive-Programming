#include<iostream>
#define N 999999
#include<cmath>
#include<cstdio>
using namespace std;
int prime[N+1];
void sieve()
{
    prime[0]=1;
    prime[1]=1;
    //int x=sqrt(N);
    for(long long i=2;i<=N;i++)
	{
        if(!prime[i])
		{
            prime[i]=i;
            for(long long j=2;j*i<=N;j++)
			{
                prime[j*i]=i;
            }
        }
    }
}
long long int primeFactorize(int n)
{
    long long int yy=1;
    for( ; n > 1 ; )
	{
        int p = prime[n] , e = 0 ;
        for( ; n % p == 0 ; n /= p , e++ ) ;  
        yy*= ((p-1)*(pow((double)p,e-1)));
    }
    return yy;
}


int main()
{
   sieve();
   int t=1;
   double max=10.0;
   for(int i=N;i>87109;i++)
   {
   		double pp=double(i)/primeFactorize(i);
   		if(pp<max)
   		{
   			cout<<i<<" "<<pp<<endl;
   			max=pp;
   		}
   		
   }
   return 0;
}
