#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n,k,t;
	cin>>n>>k;
	t=n/k;
	if(t%2==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
