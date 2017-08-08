#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxb=1000000+10;

ll phi(ll n)
{
	ll res=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res=res/i*(i-1);
			while(n%i==0)
				n/=i;
		}
	}
	if(n!=1)
		res=res/n*(n-1);
	return res;
}

ll quick_pow(ll a,ll tb,ll c)
{
	//printf("%lld %lld %lld\n",a,tb,c);
	if(tb==0)
		return 1;
	ll res;
	res=quick_pow(a,tb/2,c);
	//printf("res1:%lld\n",res);
	if(tb%2==0)
		res=res*res%c;
	else
		res=res*res%c*a%c;
	return res;
	//printf("res2:%lld\n",res);
}

int main()
{
	int len,flag;
	ll tb,a,c,ph,res;
	char b[maxb];
	while(scanf("%lld %s %lld",&a,b,&c)!=EOF)
	{
		len=strlen(b);
		ph=phi(c);
		//printf("ph:%lld\n",ph);
		tb=0;
		flag=0;
		for(int i=0;i<len;i++)
		{
			tb=tb*10+b[i]-'0';
			if(tb>ph)
			{
				flag=1;
				//printf("tb:%lld\n",tb);
				break;
			}
		}
		//printf("tb2:%lld\n",tb);
		if(flag==0)
			res=quick_pow(a,tb,c);
		else
		{
			tb=0;
			for(int i=0;i<len;i++)
			{
				tb=tb*10+b[i]-'0';
				tb%=ph;
			}
			res=quick_pow(a,tb+ph,c);
		}
		printf("%lld\n",res);
	}
	return 0;
}
