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

struct Leg
{
	int l,d;

	bool operator<(Leg &b)
	{
		return l < (b.l);
	}
};

Leg A[100007];

int B[100007];
int C[207];
int Z[100007];

int main()
{
	int i,j,k,l=0,m,p,q,N;

	sd(N);

	for(i=0;i<N;i++)
		sd(A[i].l);

	for(i=0;i<N;i++)
		sd(A[i].d);

	sort(A,A+N);

	B[N-1] = A[N-1].d;
	for(i=N-2;i>=0;i--)
		B[i] = A[i].d + B[i+1];

	i = 0;

	while(i<N)
	{
		j = i;
		while( A[i].l == A[j].l && j<N)
		{
			j++;
		}


		Z[l] = B[j];

		k = 1;	m = j-i;	p = j;

        if((p==1 && m==1) || (p==2 && m==2))
			q = 0;
		else if(m==1)
            q = p - 1;
		else
			q = p - (2*m - 1);

		while( q > 0 && k<=200)
		{
			if( C[k] <= q  )
			{
				Z[l] += C[k]*k;
				q -= C[k];
			}
			else
			{
				Z[l] += k*(q);
				q -= (q);
			}

			k++;
		}

		l++;

		j = i;
		while( A[i].l == A[j].l && j<N)
		{
			C[ A[j].d ] ++;
			j++;
		}
		i = j;

	}

	k = Z[0];
	for(i=0;i<l;i++)
    {
        // printf("%d ",Z[i]);
        if(k>Z[i])
			k= Z[i];
    }

	printf("%d\n",k);

	return 0;
}
