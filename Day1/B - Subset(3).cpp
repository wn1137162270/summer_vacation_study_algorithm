#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

const ll maxn=35+5;
const ll INF=1e17+10;

int f,minc;
ll a[maxn],minv;

int my_min(int x,int y)
{
	return x<y?x:y; 
}


void add(map<ll,int> &m,ll cur,int num,int len,int cou)
{
	//cout<<"num:"<<num<<endl;
	if(num==len)
	{
		if(f==0)
			f=1;
		else if((m[cur]&&cou<m[cur])||!m[cur])
		{
			m[cur]=cou;
			//cout<<cur<<' '<<cou<<endl;
		}
		return;
	}
	add(m,cur,num+1,len,cou);
	add(m,cur+a[num],num+1,len,cou+1);
}

void operate(ll first,int second,map<ll,int>::iterator it)
{
	ll t=labs(first+it->first);
	if(t<minv)
	{
		minv=t;
		minc=second+it->second;
	}
	else if(t==minv)
	{
		minc=my_min(minc,second+it->second);
	}
}

void operate_all(ll first,int second,map<ll,int>::iterator it,map<ll,int> &m)
{
	if(it==m.end())
	{
		it--;
		operate(first,second,it);
	}
	else if(it==m.begin())
	{
		operate(first,second,it);
	}
	else
	{
		operate(first,second,it);
		it--;
		operate(first,second,it);
	}
}

int main()
{
	int i,n,md;
	ll t;
	map<ll,int> ml,mr;
	while(cin>>n)
	{
		if(n==0) break;
		for(i=0;i<n;i++)
			cin>>a[i];	
		if(n==1)
			cout<<labs(a[0])<<" "<<1<<endl;
		else
		{
			ml.clear();
			mr.clear();
			md=n/2;
			f=0;
			add(ml,0,0,md,0);
			f=0;
			add(mr,0,md,n,0);
//			for(map<ll,int>::iterator itr=mr.begin();itr!=mr.end();itr++)
//			{
//				cout<<itr->first<<"--"<<itr->second<<endl;
//			}
			minv=INF;
			minc=maxn;
			for(map<ll,int>::iterator itl=ml.begin();itl!=ml.end();itl++)
			{
				//cout<<itl->first<<" "<<itl->second<<endl;
				map<ll,int>::iterator itr=mr.lower_bound(-(itl->first));
				operate_all(itl->first,itl->second,itr,mr);
			}
//			for(map<ll,int>::iterator itr=mr.begin();itr!=mr.end();itr++)
//			{
//				cout<<itr->first<<"-"<<itr->second<<endl;
//			}
			map<ll,int>::iterator itr=mr.lower_bound(0);
			//cout<<itr->first<<' '<<itr->second<<endl;
			operate_all(0,0,itr,mr);
			//cout<<"haha"<<endl;
			map<ll,int>::iterator itl=ml.lower_bound(0);
			operate_all(0,0,itl,ml);
			cout<<minv<<' '<<minc<<endl;
		}
	}
	return 0;
}
