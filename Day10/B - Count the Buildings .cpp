#include<cstdio>
#include<cstring>

const int mod=1e9+7;
const int maxn=2000+10;

long long s1[maxn][maxn],c[maxn][maxn];

int main()
{
	int t,n,f,b,m;
	long long ans;
	scanf("%d",&t);
	memset(s1,0,sizeof(s1));
	memset(c,0,sizeof(c));
	s1[0][0]=1;
	for(int i=0;i<maxn;i++)
		c[i][0]=1;
	for(int i=1;i<maxn;i++)
		for(int j=1;j<=i;j++)
		{
			s1[i][j]=(s1[i-1][j-1]+s1[i-1][j]*(i-1))%mod;
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	for(int i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&f,&b);
		if(f+b>n+1)		
			printf("0\n");
		else
		{
			m=f-1;
			if(m>(f-1+b-1)/2)
				m=b-1;
			ans=(c[f-1+b-1][m]*s1[n-1][b-1+f-1])%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
