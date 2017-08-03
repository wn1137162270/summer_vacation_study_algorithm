#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=64+4;

int n,vis[maxn],a[maxn],len;

bool dfs(int m,int left)
{
	int i;
	if(m==0&&left==0)
		return true;
	if(left==0)
		left=len;
	for(i=0;i<n;i++)
	{
		if(!vis[i]&&a[i]<=left)
		{
			if(i>0&&a[i]==a[i-1]&&!vis[i-1])
				continue;
			vis[i]=true;
			if(dfs(m-1,left-a[i]))
				return true;
			else
			{
				vis[i]=false;
				if(left==a[i]||left==len)
					return false;
			}
		}
	}
	return false;
}

int main()
{
	int i,sum,ans;
	cin>>n;
	while(n!=0)
	{
		sum=0;
		ans=-1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n,greater<int>());
		for(i=a[0];i<=sum/2;i++)
		{
			if(sum%i!=0)
				continue;
			len=i;
			memset(vis,0,sizeof(vis));
			if(dfs(n,i))
			{
				ans=i;
				break;
			}
		}
		if(ans!=-1)
			cout<<ans<<endl;
		else
			cout<<sum<<endl;
		cin>>n;
	}
	return 0;
}
