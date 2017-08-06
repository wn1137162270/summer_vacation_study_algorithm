#include<cstdio>
#include<cstring>

const int maxn=1e6+10;

char s[maxn];

int main()
{
	int n,len,count,flag;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		count=0;
		if(s[0]=='M')
		{
			flag=0;
			for(int j=1;j<len;j++)
			{
				if(s[j]=='I')
					count++;
				else if(s[j]=='U')
					count+=3;
				else
				{
					flag=1;
					break;
				}
			}
			if(flag==0&&(count==1||(count%2==0&&!(count%3==0))))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
