#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=4000+10;
const int maxm=16*1e6+10;

int b[maxm];

int main()
{
	int i,j,n,a[maxn][4],t,k=0,*p1,*p2;
	ll count=0;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
			cin>>a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			t=a[i][2]+a[j][3];
			b[k++]=t;
		}
	sort(b,b+k);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			t=a[i][0]+a[j][1];
			p1=lower_bound(b,b+k,-t);
			p2=upper_bound(b,b+k,-t);
			count+=p2-p1; 
		}
	cout<<count<<endl;
	return 0;
}
