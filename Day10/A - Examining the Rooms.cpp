#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

const int maxn=20+1;

int main()
{
	int t,n,k;
	long long s1[maxn][maxn],res1,res2;
	ios::sync_with_stdio(false);
	cin>>t;
	memset(s1,0,sizeof(s1));
	s1[0][0]=1;
	for(int i=1;i<maxn;i++)
		for(int j=1;j<=i;j++)
			s1[i][j]=s1[i-1][j-1]+s1[i-1][j]*(i-1);
//	for(int i=1;i<maxn;i++)
//	{
//		for(int j=1;j<=i;j++)
//			cout<<s1[i][j]<<' ';
//		cout<<endl;
//	}
	cout.setf(ios::fixed);
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		res1=0;
		res2=1;
		for(int i=1;i<=k;i++)
			res1=res1+s1[n-1][i]*(n-1); 
		for(int i=1;i<=n;i++)
			res2*=i;
		cout<<fixed<<setprecision(4)<<(double)res1/(double)res2<<endl;
	}
	return 0;	
} 
