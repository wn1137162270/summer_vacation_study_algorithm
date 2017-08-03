#include<iostream>
using namespace std;

const int maxn=1000+10;
int k=1,tb[maxn];

void next_number(int cur,int n)
{
	int nt1,nt2;
	nt1=cur*10+0;
	nt2=cur*10+1;
	tb[k++]=nt1;
	if(n+1<9)
		next_number(nt1,n+1);
	tb[k++]=nt2;
	if(n+1<9)
		next_number(nt2,n+1);
}

int main()
{
	int i,n,count=0;
	cin>>n;
	tb[0]=1;
	next_number(1,1);
	tb[k++]=1e9;
	for(i=0;i<k;i++)
		if(tb[i]<=n)
			count++;
	cout<<count<<endl;
	return 0;
} 
