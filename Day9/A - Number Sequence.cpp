#include<iostream>
#include<cstring>
using namespace std;

const int maxn=2;
const int mod=7;

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

Matrix matrix_quick_pow(Matrix &mat,int n)
{
	Matrix ans;
	ans.init_identity();
	while(n)
	{
//		cout<<1<<" "<<mat.m[0][0]<<' '<<mat.m[0][1]<<endl;
//		cout<<1<<" "<<mat.m[1][0]<<' '<<mat.m[1][1]<<endl;
		if(n%2)
		{
			ans=ans*mat;
//			cout<<"ans:"<<ans.m[0][0]<<' '<<ans.m[0][1]<<endl;
//			cout<<"ans:"<<ans.m[1][0]<<' '<<ans.m[1][1]<<endl;
		}
		mat=mat*mat;
//		cout<<2<<" "<<mat.m[0][0]<<' '<<mat.m[0][1]<<endl;
//		cout<<2<<" "<<mat.m[1][0]<<' '<<mat.m[1][1]<<endl;
		n>>=1;
	}
	return ans;
}

int main()
{
	int a,b,n,res;
	cin>>a>>b>>n;
	while(a!=0||b!=0||n!=0)
	{
		if(n==1||n==2)
			cout<<1<<endl;
		else
		{
			Matrix mat;
			mat.m[0][0]=0;mat.m[0][1]=b;
			mat.m[1][0]=1;mat.m[1][1]=a;
			Matrix ans=matrix_quick_pow(mat,n-2);
			res=(ans.m[0][1]+ans.m[1][1])%mod;
			cout<<res<<endl;
		}
		cin>>a>>b>>n;
	}
	return 0;	
} 
