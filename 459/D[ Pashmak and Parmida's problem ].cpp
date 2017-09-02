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

int A[1000007];
int Pre[1000007];
int Suf[1000007];
ll Temp[1000007];

map<int,int> Count;

ll getSum(int index)
{
    ll sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += Temp[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add &#39;val&#39;
    while (index <= n)
    {
       // Add &#39;val&#39; to current node of BI Tree
       Temp[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;
	ll ans=0;
	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
		Pre[i] = ++Count[A[i]];

	Count.clear();

	for(i=n-1;i>=0;i--)
		Suf[i] = ++Count[A[i]];	

	for(i=n-1;i>=0;i--)
		updateBIT(1000000,Suf[i],1);

	for(i=0;i<n;i++)
	{
		updateBIT(1000000,Suf[i],-1);
		ans += getSum(Pre[i]-1);
	}

	printf("%lld\n", ans );

	return 0;
}