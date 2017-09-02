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

ll Updates[200007];
ll Elements[200007];

ll getSum(ll index)
{
    ll sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += Updates[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll n, ll index, ll val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add &#39;val&#39;
    while (index <= n)
    {
       // Add &#39;val&#39; to current node of BI Tree
       Updates[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}


int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l=1,m,a,n,x,t,sum=0;
	double avg=0;

	slld(n);

	while(n--)
	{
		slld(t);

		if(t==1)
		{
			slld(a);	slld(x);
			// printf("YES\n");
			updateBIT(200005,1,x);	updateBIT(200005,a+1,-x);  
			sum += (a*x);
			avg = (double)(sum)/l;
		}
		else if(t==2)
		{
			slld(k);
			sum+=k;	l++;
			Elements[l] = k;
			avg = (double)(sum)/l;
		}
		else
		{
			m = Elements[l] + getSum(l);
			j = (getSum(l+1)-getSum(l));
			updateBIT(200005,l,j);
			updateBIT(200005,l+1,-j);
			sum-=m;
			avg = (double)(sum)/(l-1);
			l--;
		}
		printf("%.10lf\n", avg );	
	}	

	return 0;
}