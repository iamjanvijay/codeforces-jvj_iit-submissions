#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

ll A[100007];
multiset<ll> PriPos;
multiset<ll> SecPos;
multiset<ll> PriNeg;
multiset<ll> SecNeg;
multiset<ll>::iterator it;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r;
	ll i,j,k,l,m,n,x,y,z,a,b,r,s,spos,sneg;

	slld(n);	slld(l);

	for(i=0;i<n;i++)
		slld(A[i]);

	slld(k);

	s = m = spos = sneg = 0;
	for(i=0;i<l;i++)
	{
		s += A[i];
		if(k!=0)
		{
			if(A[i]<0)
			{
				if(sz(PriNeg)<k)
				{
					sneg += A[i];
					PriNeg.insert(A[i]);
				}
				else
				{
					it = PriNeg.end();	it--;
					if( A[i] < (*it) )
					{
						sneg -= (*it);
						sneg += A[i];
						SecNeg.insert(*it);
						PriNeg.erase(it);
						PriNeg.insert(A[i]);
					}
					else
					{
						SecNeg.insert(A[i]);
					}
				}
			}
			if(A[i]>0)
			{
				if(sz(PriPos)<k)
				{
					spos += A[i];
					PriPos.insert(A[i]);
				}
				else
				{
					it = PriPos.begin();	
					if( A[i] > (*it) )
					{
						spos -= (*it);
						spos += A[i];					
						SecPos.insert(*it);
						PriPos.erase(it);
						PriPos.insert(A[i]);
					}
					else
					{
						SecPos.insert(A[i]);
					}
				}
			}
		}
	}

	m = max( abs(s - 2*spos) , abs(s - 2*sneg) );

	// printf("%lld\n", m );

	for(j=0;i<n;i++,j++)
	{
		s -= A[j];
		s += A[i];
		if(k!=0)
		{
			if(A[j]<0)
			{
				it = SecNeg.find(A[j]);
				if( it != SecNeg.end() )
				{
					SecNeg.erase(it);
				}
				else
				{
					it = PriNeg.find(A[j]);
					sneg -= A[j];
					PriNeg.erase(it);
					if( sz(SecNeg) > 0 )
					{
						it = SecNeg.begin();
						sneg += *it;
						PriNeg.insert(*it);
						SecNeg.erase(it);
					}
				}
			}

			if(A[j]>0)
			{
				it = SecPos.find(A[j]);
				if( it != SecPos.end() )
				{
					SecPos.erase(it);
				}
				else
				{
					it = PriPos.find(A[j]);
					spos -= A[j];
					PriPos.erase(it);
					if( sz(SecPos) > 0 )
					{
						it = SecPos.end();	it--;
						spos += *it;
						PriPos.insert(*it);
						SecPos.erase(it);
					}
				}
			}

			if(A[i]<0)
			{
				if(sz(PriNeg)<k)
				{
					sneg += A[i];
					PriNeg.insert(A[i]);
				}
				else
				{
					it = PriNeg.end();	it--;
					if( A[i] < (*it) )
					{
						sneg -= (*it);
						sneg += A[i];
						SecNeg.insert(*it);
						PriNeg.erase(it);
						PriNeg.insert(A[i]);
					}
					else
					{
						SecNeg.insert(A[i]);
					}
				}
			}
			if(A[i]>0)
			{
				if(sz(PriPos)<k)
				{
					spos += A[i];
					PriPos.insert(A[i]);
				}
				else
				{
					it = PriPos.begin();	
					if( A[i] > (*it) )
					{
						spos -= (*it);
						spos += A[i];					
						SecPos.insert(*it);
						PriPos.erase(it);
						PriPos.insert(A[i]);
					}
					else
					{
						SecPos.insert(A[i]);
					}
				}
			}
		}
		m = max( m , abs(s - 2*sneg) );
		m = max( abs(s - 2*spos) , m );
	}

	printf("%lld\n", m );

	return 0;
}