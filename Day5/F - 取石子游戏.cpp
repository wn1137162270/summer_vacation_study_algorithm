#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n,a,b,t;
	cin>>n;
	while(n!=0)
	{
		a=b=1;
		while(b<n)
		{
			t=a;
			a=b;
			b=b+t;
		}
		if(b==n)
			cout<<"Second win"<<endl;
		else
			cout<<"First win"<<endl;
		cin>>n;
	}
	return 0;
}
