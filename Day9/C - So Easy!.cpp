#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int maxn=2;

ll mod;

struct Matrix
{
	ll m[maxn][maxn];
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
					ans.m[i][j]=(ans.m[i][j]+m[i][k]*x.m[k][j])%mod;
		return ans;
	}
};

Matrix matrix_quick_pow(Matrix &mat,ll n)
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
	ll res,a,b,n;
	while(cin>>a>>b>>n>>mod)
	{
		if(n==1)
			cout<<(2*a)%mod<<endl;
		else
		{
			Matrix mat;
			mat.m[0][0]=0;mat.m[0][1]=b-a*a;
			mat.m[1][0]=1;mat.m[1][1]=2*a;
			Matrix ans=matrix_quick_pow(mat,n-1);
			res=((2*ans.m[0][1]+2*a*ans.m[1][1])%mod+mod)%mod;
			cout<<res<<endl;
		}
	}
	return 0;
}
//可以看到b-a*a是一个负数，故ans矩阵中可能会存在负数元素，这个时候就要加一个mod，再对mod取余。 
