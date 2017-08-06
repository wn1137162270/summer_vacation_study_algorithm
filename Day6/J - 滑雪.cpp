#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

struct node
{
	int r,c;	
};

int height[maxn][maxn],dp[maxn][maxn],n;
node r[maxn*maxn];

int get_max(int x,int y)
{
	return x>y?x:y;
}

int cmp(const node i,const node j)
{
	return height[i.r][i.c]>height[j.r][j.c];
}

int main()
{
	int m,x,y,k=0,ans=0,tx,ty;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>height[i][j];
			r[k++]=(node){i,j};
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dp[i][j]=1;
	sort(r,r+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		x=r[i].r;
		y=r[i].c;
		for(int j=0;j<4;j++)
		{
			tx=x-dx[j];
			ty=y-dy[j];
			if(tx>=0&&tx<n&&ty>=0&&ty<m&&height[x][y]>height[tx][ty])
				dp[tx][ty]=get_max(dp[tx][ty],dp[x][y]+1);
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ans=get_max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}
