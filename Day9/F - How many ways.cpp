#include<iostream>
#include<cstring>
using namespace std;

const int maxn=20+2;
const int mod=1000;

struct Matrix
{
	int m[maxn][maxn];
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

Matrix matrix_quick_pow(Matrix mat,int n)
{
	Matrix ans;
	ans.init_identity();
	while(n)
	{
		if(n&1)
			ans=ans*mat;
		mat=mat*mat;
		n>>=1;
	}
	return ans; 
}

int main()
{
	int n,m,u,v,q,k;
	scanf("%d %d",&n,&m);
	while(n!=0||m!=0)
	{
		Matrix mat;
		mat.init_zero();
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			mat.m[u][v]=1;
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%d %d %d",&u,&v,&k);
			Matrix ans=matrix_quick_pow(mat,k);
			printf("%d\n",ans.m[u][v]);
		}
		scanf("%d %d",&n,&m);
	}
	return 0;	
} 
