#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n

int A[5007];
int B[5007];
set<int> S;

int ans(int curLvl,int first,int last,int m)
{
	if(curLvl==m-1)
	{
		// printf("* %d %d %d : %d\n",curLvl,first,last ,0);
		return 0;
	}
	if(last-first+1==1)
	{
		// printf("* %d %d %d : %d\n",curLvl,first,last ,1);
		return 1;
	}

	int i,j,h=0;
	for(i=first;i<=last;i++)
	{
		j = i;
		if(A[j]>B[curLvl+1])
		{
			while(A[j]>B[curLvl+1] && j<=last)
			{
				j++;
			}	
			h += ans(curLvl+1,i,j-1,m);
			i = j-1;
		}
	}
	// printf("* %d %d %d : %d\n",curLvl,first,last ,min( (last-first+1),h+(B[curLvl+1]-B[curLvl])*(last-first+1) ));
	return min( (last-first+1),h+(B[curLvl+1]-B[curLvl]) );
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,h,m=0,n=0;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(A[i]);
		S.insert(A[i]);
	}

	set<int>::iterator it;
	B[m++] = 0;
	for(it = S.begin();it!=S.end();++it)
		B[m++] = *it;

	S.clear();

	printf("%d\n", ans(0,0,n-1,m) );

	return 0;
}