#include<iostream>
#include<cstring>
using namespace std;

const int mod=20090126;
const int maxn=100+10;

int main()
{
	int t,n;
	long long s2[maxn][maxn],fact[maxn],res;
	memset(s2,0,sizeof(s2));
	s2[0][0]=1;
	for(int i=1;i<maxn;i++)
		for(int j=1;j<=i;j++)
			s2[i][j]=(s2[i-1][j-1]+s2[i-1][j]*j)%mod;
	fact[0]=1;
	for(int i=1;i<maxn;i++)
		fact[i]=(fact[i-1]*i)%mod;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		res=0;
		for(int j=1;j<=n;j++)
		{
			res=res+(fact[j]*s2[n][j])%mod;
			res%=mod;
		}
		cout<<res<<endl;
	}
	return 0;
}
