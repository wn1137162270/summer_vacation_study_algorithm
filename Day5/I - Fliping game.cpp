#include<iostream>
using namespace std;

int main()
{
	int t,n,m,temp;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				cin>>temp;
		if(temp==0)
			cout<<"Bob"<<endl; 
		else
			cout<<"Alice"<<endl;
	}
	return 0;
}
