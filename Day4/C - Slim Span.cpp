#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=100+10;
const int maxm=10000+10;
const int INF=10000+10;

int u[maxm],v[maxm],w[maxm],p[maxn],r[maxm];

int get_min(int x,int y)
{
	return x<y?x:y;
}

int get_max(int x,int y)
{
	return x>y?x:y;
}

int cmp(const int i,const int j)
{
	return w[i]<w[j];
}

int find(int x)
{
	if(x==p[x])
		return x;
	return p[x]=find(p[x]);
}

int main()
{
	int n,m,t,ans,max,min,x,y,t2,flag;
	//freopen("data.txt","r",stdin);
	scanf("%d %d",&n,&m);
	while(n!=0||m!=0)
	{
		ans=INF;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u[i],&v[i],&w[i]);
			u[i]--;	v[i]--;
			r[i]=i;
		}
		sort(r,r+m,cmp);
		for(int i=0;i<m;i++)
		{
			max=-INF,min=INF;
			for(int j=0;j<n;j++)
				p[j]=j;
			for(int j=i;j<m;j++)
			{
				//printf("%d %d\n",j,m);
				x=find(u[r[j]]);
				y=find(v[r[j]]);
				//printf("%d %d\n",x,y);
				if(x!=y)
				{
					p[x]=y;
					max=get_max(max,w[r[j]]);
					min=get_min(min,w[r[j]]);
					//printf("%d %d\n",max,min);
				}
			}
			flag=0;
			for(int j=0;j<n;j++)
			{
				if(j==0)
					t=find(0);
				else 
				{
					t2=find(j);
					if(t2!=t)
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
			else if(max!=-INF&&min!=INF)
				ans=get_min(ans,max-min);
		}
		if(ans==INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
		scanf("%d %d",&n,&m);
	}
	return 0;
}
