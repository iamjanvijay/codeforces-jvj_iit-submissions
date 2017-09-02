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

pair<int,bool> A[400007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,m,nCur,mCur,nAns,mAns,maxi,i,j,k,l;

	sd(n);
	for(i=0;i<n;i++)	
	{
		sd(A[i].first);	A[i].second = true;
	}

	sd(m);
	for(i;i<m+n;i++)
	{
		sd(A[i].first);	A[i].second = false;
	}

	sort(A,A+n+m);

	nCur = n;	mCur = m;
	maxi = 3*(n-m);
	nAns = 3*n;	mAns = 3*m;

	i=0;

	while(i<n+m)
	{
		j=i;

		while(j+1<n+m && A[j].first == A[j+1].first)
		{
			if(A[j].second)
				nCur--;
			else
				mCur--;
			j++;
		}

		if(A[j].second)
			nCur--;
		else
			mCur--;	

		if( (nCur*3+(n-nCur)*2) - (mCur*3+(m-mCur)*2) > maxi )
		{
			maxi = (nCur*3+(n-nCur)*2) - (mCur*3+(m-mCur)*2);
			nAns = nCur*3+(n-nCur)*2;
			mAns = mCur*3+(m-mCur)*2;
		}
		// printf("*** %d %d\n",i,j );
		i=j+1;
	}

	printf("%d:%d\n", nAns, mAns );

	return 0;
}