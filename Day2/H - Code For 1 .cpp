#include<iostream>
using namespace std;

typedef long long ll;

ll count=0,l,r,ans=0;

void divide(ll x)
{
	if(x==1)
	{
		count++;
		if(count>=l&&count<=r)
			ans++;
		return ;
	}
	if(count>r)
		return ;
	divide(x/2);
	count++;
	if(x%2==1&&count>=l&&count<=r)	
		ans++;
	divide(x/2);
}

int main()
{
	ll n;
	cin>>n>>l>>r;
	divide(n);
	cout<<ans<<endl;
	return 0;
}
