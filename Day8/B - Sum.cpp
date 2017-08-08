#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxn=1e5+10;
const ll mod=1e9+7;

ll quick_pow(ll a,ll n)
{
	if(n==0)
		return 1; 
	ll res=quick_pow(a,n/2);
	if(n%2==0)
		res=res*res%mod;
	else
		res=res*res%mod*a%mod;
	return res; 
}

int main()
{
	int len;
	char c[maxn];
	ll t,ans;
	while(scanf("%s",c)!=EOF)
	{
		t=0;
		len=strlen(c);
		for(int i=0;i<len;i++)
		{
			t=t*10+c[i]-'0';
			t%=mod-1;
		}
			ans=quick_pow(2,t-1);
		printf("%lld\n",ans);
	}
	return 0;
}

