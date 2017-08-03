#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=100+10;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

struct node
{
	int x,y,pre,step;	
}pre[4];

int n,m,k;
char maze[maxn][maxn];
bool visit[16][maxn][maxn];

int judge(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&maze[x][y]!='#')
		return true;
	return false;
}

int bfs(int sx,int sy)
{
	int i,j,flag=0;
	node nd,temp;
	queue<node> qu;
	nd.x=sx;
	nd.y=sy;
	nd.step=0;
	for(i=0;i<k;i++)
		if(nd.x==pre[i].x&&nd.y==pre[i].y)
		{
			flag=1;
			break;
		}
	if(flag==1)
		nd.pre=1<<i;
	else
		nd.pre=0;
	qu.push(nd);
	visit[nd.pre][nd.x][nd.y]=true;
	while(!qu.empty())
	{
		nd=qu.front();
		qu.pop();
		temp.step=nd.step+1;
		for(i=0;i<4;i++)
		{
			flag=0;
			temp.x=nd.x+dx[i];
			temp.y=nd.y+dy[i];
			for(j=0;j<k;j++)
				if(temp.x==pre[j].x&&temp.y==pre[j].y)
				{
					flag=1;
					break;
				}
			if(flag==1)
				temp.pre=nd.pre|(1<<j);
			else
				temp.pre=nd.pre;
			if(judge(temp.x,temp.y))
			{
				if(temp.pre==(1<<k)-1)
					return temp.step;
				if(!visit[temp.pre][temp.x][temp.y])
				{
					visit[temp.pre][temp.x][temp.y]=true;
					qu.push(temp);
				}
			}
		}
	}
	return -1;
}

int main()
{
	int ans;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	while(n!=0||m!=0)
	{
		for(int i=0;i<n;i++)
			cin>>maze[i];
		cin>>k;
		for(int i=0;i<k;i++)
		{
			cin>>pre[i].x>>pre[i].y;
			pre[i].x--;
			pre[i].y--;
		}
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(maze[i][j]=='@')
				{
					ans=bfs(i,j);
					break;
				}
		cout<<ans<<endl;
		cin>>n>>m;
	}
	return 0;
}
