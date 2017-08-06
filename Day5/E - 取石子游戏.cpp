#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main()
{
	ll a,b,t,flag;
	while(cin>>a>>b)
	{
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
		t=a-b;
		if(b==(int)(t*(sqrt(5)+1)/2))
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;	
} 
