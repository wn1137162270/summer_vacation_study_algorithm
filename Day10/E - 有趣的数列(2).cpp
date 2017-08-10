#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxn=1000000+10;

ll mod;
int n,count=0,flag[2*maxn],ind[2*maxn],prime[maxn],total[maxn];

void get_prime()
{
	for(int i=2;i<=2*n;i++)
	{
		if(!flag[i])
		{
			prime[count++]=i;
			ind[i]=count-1;
		}
		for(int j=0;j<count&&prime[j]*i<=2*n;j++)
		{
			flag[prime[j]*i]=1;
			ind[prime[j]*i]=j;
			if(i%prime[j]==0)
				break;
		}
	}
}

void resolve(int x,int k)
{
	while(x!=1)
	{
		total[ind[x]]+=k;
		x/=prime[ind[x]];
	}
}

int main()
{
	ll res=1;
	scanf("%d %lld",&n,&mod);
	get_prime();
	for(int i=n+1;i<=2*n;i++)
		resolve(i,1);
	for(int i=1;i<=n+1;i++)
		resolve(i,-1);
	for(int i=0;i<count;i++)
		while(total[i])
		{
			res=(res*prime[i])%mod;
			total[i]--;
		}
	if(n==1&&mod==1)
		printf("0\n");
	else
		printf("%lld\n",res);
	return 0;
}
