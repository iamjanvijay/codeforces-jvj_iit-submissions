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

int A[100007];
int Count[100007];
int n,k;

bool moreThanK(int m) // m is len of current segment
{
	int i,j,dis=0;

	if(m<k)
		return false;

	for(i=0;i<100007;i++)
		Count[i] = 0;

	for(i=0;i<m;i++)
	{
		if( Count[ A[i] ] == 0 )
			dis++;
		Count[ A[i] ]++;
	}

	if(dis>=k)
		return true;

	for(i,j=0;i<n;i++,j++)
	{
		Count[ A[j] ]--;
		if( Count[ A[j] ] == 0 )
			dis--;

		if( Count[ A[i] ] == 0 )
			dis++;
		Count[ A[i] ]++;

		if(dis>=k)
			return true;
	}	
	return false;
}

int binary()
{
	int first = k,last = n,mid;
	
	if(!moreThanK(n))
		return -1;

	while(first+1 < last)
	{
		mid = (first+last)/2;

		if(moreThanK(mid))
			last = mid;
		else
			first = mid;
	}

	if(moreThanK(first))
		return first;
	else
		return last;		

}

int main()
{
	int i,j,l,m,dis=0;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		sd(A[i]);

	m = binary();

	if(m==-1)
		printf("-1 -1\n");
	else
	{

		for(i=0;i<100007;i++)
			Count[i] = 0;

		for(i=0;i<m;i++)
		{
			if( Count[ A[i] ] == 0 )
				dis++;
			Count[ A[i] ]++;
		}

		if(dis==k)
		{
			printf("%d %d\n",1,i);
			return 0;
		}

		for(i,j=0;i<n;i++,j++)
		{
			Count[ A[j] ]--;
			if( Count[ A[j] ] == 0 )
				dis--;

			if( Count[ A[i] ] == 0 )
				dis++;
			Count[ A[i] ]++;

			if(dis==k)
			{
				printf("%d %d\n",j+2,i+1);
				return 0;
			}
		}
	}	


	return 0;
}
