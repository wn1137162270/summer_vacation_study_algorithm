#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10+2;
const int maxm=15+2;
const int maxu=150+10;
const int n=10,m=15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

char board[maxn][maxm];
int visit[maxn][maxm];
int num[maxu],ans,move;

int judge(int r,int c,char color)
{
	if(r>=0&&r<n&&c>=0&&c<m&&board[r][c]==color&&!visit[r][c])
		return true;
	return false;
}

void dfs(int r,int c,int k,char color)
{
	if(!judge(r,c,color))
		return ;
	visit[r][c]=k;
	for(int i=0;i<4;i++)
		dfs(r+dx[i],c+dy[i],k,color);
}

bool check()
{
	int k=1;
	memset(visit,0,sizeof(visit));
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!visit[i][j]&&board[i][j]!='W')
				dfs(i,j,k++,board[i][j]);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//			cout<<visit[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(visit[i][j]!=0)
				num[visit[i][j]]++;
	for(int i=1;i<k;i++)
		if(num[i]>1)
			return true;
	return false;
}

void operate()
{	
	int max=0,index,count[m],space[m],count2=0,tr,tc;
	memset(count,0,sizeof(count));
	memset(space,0,sizeof(space));
	for(int j=0;j<m;j++)
		for(int i=n-1;i>=0;i--)
			if(num[visit[i][j]]>max)
			{
				max=num[visit[i][j]];
				index=visit[i][j];
				tr=i; tc=j;
			}
	cout<<"Move "<<move++<<" at ("<<10-tr<<","<<tc+1<<"): removed "<<num[index]
		<<" balls of color "<<board[tr][tc]<<", got "<<(num[index]-2)*(num[index]-2)
		<<" points."<<endl;
	ans+=(num[index]-2)*(num[index]-2);
	for(int j=0;j<m;j++)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(visit[i][j]==index)
				count[j]++;
			else 
				board[i+count[j]][j]=board[i][j];
		}
		for(int i=0;i<count[j];i++)
			board[i][j]='W';
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//			cout<<board[i][j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
	for(int j=0;j<m;j++)
		if(board[n-1][j]=='W')
			space[j]=1;
	for(int j=0;j<m;j++)
	{
		if(space[j]==1)
			count2++;
		else
			for(int i=0;i<n;i++)
				board[i][j-count2]=board[i][j];
	}
	for(int j=m-1;j>=m-count2;j--)
		for(int i=0;i<n;i++)
			board[i][j]='W';
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//			cout<<board[i][j]<<' ';
//		cout<<endl;
//	}
}

int main()
{
	int t,k,r;
	//freopen("data.txt","r",stdin);
	cin>>t;
	for(int h=0;h<t;h++)
	{
		ans=0;
		move=1;
		for(int j=0;j<n;j++)
			cin>>board[j];
		cout<<"Game "<<h+1<<":"<<endl<<endl;
		while(check())
			operate();
		r=0;
		for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(board[i][j]!='W')
						r++;
		if(r==0)
			ans+=1000;
		cout<<"Final score: "<<ans<<", with "<<r<<" balls remaining."<<endl;
		if(h!=t-1)
			cout<<endl;
	}
	return 0;
}
