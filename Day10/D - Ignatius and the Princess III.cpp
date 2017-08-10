#include<iostream>
#include<cstring>
using namespace std;

const int maxn=120+10;

int main()
{
	int split[maxn][maxn],n; 
	for(int i=0;i<maxn;i++)
		split[0][i]=1;
	for(int i=1;i<maxn;i++)
		split[i][0]=0;
	for(int i=1;i<maxn;i++)
		for(int j=1;j<maxn;j++)
		{
			if(i>=j)
				split[i][j]=split[i][j-1]+split[i-j][j];
			else
				split[i][j]=split[i][i];
		}
	while(cin>>n)
		cout<<split[n][n]<<endl;
	return 0;
}
