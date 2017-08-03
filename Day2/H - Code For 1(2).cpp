#include<iostream>
using namespace std;

typedef long long ll;

ll l,r,count=0,ans=0;

void divide(ll x,ll n,ll len)
{
	cout<<x<<' '<<n<<' '<<len<<endl;
	if(count>=r)
		return ;
	if(x==1)
	{
		count++;
		if(count>=l&&count<=r)
			ans++;
		return ;
	}
	if(r<=n)
	{
		divide(x/2,n/2,n/2);
		if(r==n)
		{
			count++;
			if(count>=l&&count<=r&&x%2==1)
				ans++;
		}
	}
	else if(l>=n)
	{
		count+=len;
		if(count>=l&&count<=r&&x%2==1)
			ans++;
		divide(x/2,n+n/2,n/2);
	}
	else
	{
		divide(x/2,n/2,n/2);
		count++;
		if(count>=l&&count<=r&&x%2==1)
			ans++;
		divide(x/2,n+n/2,n/2);
	}
}

int main()
{
	ll n,nt,num=1,q=1;
	cin>>n>>l>>r;
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	nt=n;
	while(nt!=1)
	{
		nt/=2;
		q*=2;
		num+=q;
	}
	cout<<"num:"<<num<<endl;
	divide(n,(num+1)/2,(num+1)/2);
	cout<<ans<<endl;
	return 0;
}
