#include<iostream>
#include<cstring>
using namespace std;

typedef unsigned long long ull;

const int maxn=2;

struct Matrix
{
	ull m[maxn][maxn];
	void init_zero()
	{
		memset(m,0,sizeof(m));
	}
	void init_identity()
	{
		init_zero();
		for(int i=0;i<maxn;i++)
			m[i][i]=1;
	}
	Matrix operator *(const Matrix &x)const
	{
		Matrix ans;
		ans.init_zero();
		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				for(int k=0;k<maxn;k++)
					ans.m[i][j]=(ans.m[i][j]+m[i][k]*x.m[k][j]);
		return ans;
	}
};

Matrix matrix_quick_pow(Matrix &mat,int n)
{
	Matrix ans;
	ans.init_identity();
	while(n)
	{
		if(n%2)
			ans=ans*mat;
		mat=mat*mat;
		n>>=1;
	}
	return ans;
}

int main()
{
	int t,n;
	ull p,q,res;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p>>q>>n;
		cout<<"Case "<<i+1<<": ";
		if(n==0)
		{
			cout<<2<<endl;
			continue;
		}
		else if(n==1)
		{
			cout<<p<<endl;
			continue;
		}
		Matrix mat;
		mat.m[0][0]=0;mat.m[0][1]=-q;
		mat.m[1][0]=1;mat.m[1][1]=p;
		Matrix ans=matrix_quick_pow(mat,n-1);
		res=2*ans.m[0][1]+p*ans.m[1][1];
		cout<<res<<endl;
	}
	return 0;
}
