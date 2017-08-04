#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=500+10;
const int maxm=maxn*maxn;

int coor[maxn][2],u[maxm],v[maxm],r[maxm],fa[maxn];
double w[maxm],rec[maxn];

int cmp(const int i,const int j)
{
	return w[i]<w[j];
}

int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	int n,s,p,x,y,h;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&s,&p);
		for(int j=0;j<p;j++)
			scanf("%d %d",&coor[j][0],&coor[j][1]);
		for(int j=0;j<p;j++)
			for(int k=0;k<p;k++)
			{
				x=coor[j][0]-coor[k][0];
				y=coor[j][1]-coor[k][1];
				u[j*p+k]=j;
				v[j*p+k]=k;
				w[j*p+k]=sqrt(x*x+y*y);
				//printf("%d %f",j*p+k,w[j*p+k]);
			}
		for(int j=0;j<p*p;j++)
			r[j]=j;
		for(int j=0;j<p;j++)
			fa[j]=j;
		sort(r,r+p*p,cmp);
		h=0;
		for(int j=0;j<p*p;j++)
		{
			x=find(u[r[j]]);
			y=find(v[r[j]]);
			if(x!=y)
			{
				fa[x]=y;
				rec[h++]=w[r[j]];
			}
		}
		printf("%.2f\n",rec[p-s-1]);
	}
	return 0;	
} 
