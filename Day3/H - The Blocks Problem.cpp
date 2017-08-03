#include<iostream>
#include<string>
#include<vector>
using namespace std; 

const int maxn=25+2;

vector<int> piles[maxn];
int loc[maxn];

void ret_init(int x)
{
	int i,y,l=loc[x];
	for(i=piles[l].size()-1;piles[l][i]!=x;i--)
	{
		//cout<<i<<endl;
		y=piles[l][i];
		piles[y].push_back(y);
		piles[l].pop_back();
		loc[y]=y;
	}
}

int main()
{
	int i,j,n,a,b,flag;
	string str1,str2;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++)
	{
		piles[i].push_back(i);
		loc[i]=i;
	}
	while(cin>>str1)
	{
		flag=0;
		if(str1[0]=='q') break;
		cin>>a>>str2>>b;
		if(a==b||loc[a]==loc[b])
			continue;
		if(str2.compare("onto")==0)
			ret_init(b);
		if(str1.compare("move")==0)
		{
			ret_init(a);
			piles[loc[b]].push_back(a);
			piles[loc[a]].pop_back();
			loc[a]=loc[b];
		}
		if(str1.compare("pile")==0)
		{
			//cout<<"pile"<<piles[loc[a]].size()<<endl;
			for(i=0;i<piles[loc[a]].size();i++)
			{
				//cout<<piles[loc[a]][i]<<endl;
				if(piles[loc[a]][i]==a)
					flag=1;
				if(flag==1)
				{
					//cout<<loc[b]<<' '<<loc[a]<<' '<<piles[loc[a]][i]<<endl;
					piles[loc[b]].push_back(piles[loc[a]][i]);
				}
			}
			for(i=piles[loc[a]].size()-1;piles[loc[a]][i]!=a;i--)
			{
				piles[loc[a]].pop_back();
				loc[piles[loc[a]][i]]=loc[b];
			}
			piles[loc[a]].pop_back();
			loc[piles[loc[a]][i]]=loc[b];
		}
	//cout<<"-------"<<endl;
	}
	for(i=0;i<n;i++)
	{
		cout<<i<<':';
		if(piles[i].size()!=0)
		{
			for(j=0;j<piles[i].size();j++)
			{
				cout<<' '<<piles[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
