#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int maxn=200000+10;
const int INF=10000+10;
const double eps=1e-11;

int n,k=100;
double a[maxn],dp1[maxn],dp2[maxn];

double get_max(double x,double y)
{
	return x>y?x:y;
}

double get_min(double x,double y)
{
	return x<y?x:y;
}

double f(double x)
{
	int i;
	double max=0,b[maxn];
	for(i=0;i<n;i++)
		b[i]=a[i]-x;
	dp1[0]=b[0];
	for(i=1;i<n;i++)
		dp1[i]=get_max(dp1[i-1]+b[i],b[i]);
	dp2[0]=b[0];
	for(i=1;i<n;i++)
		dp2[i]=get_min(dp2[i-1]+b[i],b[i]);
	for(i=0;i<n;i++)
	{
		//cout<<dp1[i]<<' '<<dp2[i]<<endl;
		max=get_max(max,abs(dp1[i]));
		max=get_max(max,abs(dp2[i]));
	}
	//cout<<max<<endl;
	return max;
}

double divide(double &l,double &r)
{
	double mid,mmid,fmid,fmmid;
	
	if(r-l<eps)
		return (l+r)/2;
	mid=(r+2*l)/3;
	mmid=(l+2*r)/3;
	fmid=f(mid);
	fmmid=f(mmid);
	if(fmid<=fmmid)
		r=mmid;
	else if(fmid>fmmid)
		l=mid;
	return divide(l,r);
}

int main()
{
	int i;
	double ans,max=-INF,min=INF;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	while(k--)
	{
		divide(min,max);
	}
	ans=divide(min,max);
	printf("%.6lf\n",f(ans));
	return 0;
}
