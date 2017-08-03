#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll maxn=35+5;
const ll maxm=(1<<18)+10;
const ll INF=1e17+10;

ll a[maxn],l[maxm],r[maxm],k,f;

ll my_min(ll x,ll y)
{
	return x<y?x:y; 
} 

void add(ll b[],ll cur,ll num,ll len)
{
	if(num==len)
	{
		if(k==0&&f==0)
			f=1;
		else
			b[k++]=cur;
	}
	add(b,cur,num+1,len);
	add(b,cur+a[num],num+1,len);
}

ll getMin(ll b[],ll len,ll num)
{
	ll* t;
	ll min=INF;
	t=lower_bound(b,b+len,-num);
	if(b[t-b]==-num)
		return 0;
	if(t-b!=len)
		min=abs(num+b[t-b]);
	if(t-b-1>=0)
		min=my_min(min,abs(num+b[t-b-1]));
	return min;
}

int main()
{
	ll i,n,lenl,lenr,md,ans,min;
	cin>>n;
	while(n)
	{
		for(i=0;i<n;i++)
			cin>>a[i];
		md=n/2;
		k=0;
		f=0;
		add(l,0,0,md);
		lenl=k;
		k=0;
		f=0;
		add(r,0,md,n);
		lenr=k;
		sort(r,r+lenr);
		ans=INF;
		for(i=0;i<lenl;i++)
		{
			min=getMin(r,lenr,l[i]);
			ans=my_min(ans,min);
		}
		min=getMin(r,lenr,0);
		ans=my_min(ans,min);
		min=getMin(l,lenl,0);
		ans=my_min(ans,min);
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}
