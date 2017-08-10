#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxn=1000000+10;

ll mod;
int num[2*maxn];

void resolve(int x,int k)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			while(x%i==0)
			{
				x/=i;
				num[i]+=k; 
			}
	if(x!=1)
		num[x]+=k;
}

int main()
{
	int n;
	ll res=1;
	scanf("%d %lld",&n,&mod);
	memset(num,0,sizeof(num));
	for(int i=n+1;i<=2*n;i++)
		resolve(i,1);
	for(int i=1;i<=n+1;i++)
		resolve(i,-1);
	for(int i=2;i<=2*n;i++)
		while(num[i])
		{
			res=res*i;
			res%=mod;
			num[i]--;
		}
	if(n==1&&mod==1)
		printf("0\n");
	else
		printf("%lld\n",res);
	return 0;
}
