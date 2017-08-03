#include<iostream>
#include<cstring>
using namespace std;

const int maxn=5000+10;
const int INF=1e9+10;

int get_min(int x,int y)
{
	return x<y?x:y;
}

int brush(int b[],int l,int r)
{
	if(r-l==1)
		return 1;
	if(r-l==0)
		return 0;
	int i,min=INF,tl=0,k=0,c[maxn],cnt1=0,cnt2=0;
	for(i=l;i<r;i++)
		if(b[i]<min)
			min=b[i];
	for(i=l;i<r;i++)
		c[k++]=b[i]-min;
	cnt1=r-l;
	tl=0;
	for(i=0;i<r-l;i++)
		if(c[i]==0)
		{
			cnt2+=brush(c,tl,i);
			tl=i+1;
		}
	cnt2+=brush(c,tl,r-l);
	cnt2+=min;
	return get_min(cnt1,cnt2);
}

int main()
{
	int i,n,a[maxn],ans;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	ans=brush(a,0,n);
	cout<<ans<<endl;
	return 0;	
} 
