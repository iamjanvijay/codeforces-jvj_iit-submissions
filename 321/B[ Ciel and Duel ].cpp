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

int JiroATK[107];
int JiroDEF[107];
int Ciel[107];
int CielPrefSum[107];
int DP[107][107][107][2];
bool isCalc[107][107][107][2];

int ans0(int na, int nd, int m) // not kill all
{
	if( isCalc[na][nd][m][0] )
		return DP[na][nd][m][0];
	DP[na][nd][m][0] = INT_MIN;

	isCalc[na][nd][m][0] = true;
	if(na==0 || m==0)
	{
		DP[na][nd][m][0] = 0;
	}
	else
	{
		if(JiroATK[na]<=Ciel[m])
		{
			int temp = ans0(na-1, nd, m-1);
			if(temp!=INT_MIN)
				DP[na][nd][m][0] = max( DP[na][nd][m][0] , Ciel[m]-JiroATK[na] + temp );
		}
		DP[na][nd][m][0] = max( DP[na][nd][m][0] , ans0(na-1, nd, m) );
	}
	return DP[na][nd][m][0];
}

int ans1(int na, int nd, int m)
{
	if( isCalc[na][nd][m][1] )
		return DP[na][nd][m][1];
	DP[na][nd][m][1] = INT_MIN;

	isCalc[na][nd][m][1] = true;
	if(na==0 && nd==0)
	{
		DP[na][nd][m][1] = max( DP[na][nd][m][1] , CielPrefSum[m] );
	}
	else if(m==0)
	{
		DP[na][nd][m][1] = max( DP[na][nd][m][1] , INT_MIN );
	}
	else
	{
		if(na>0)
		{
			int temp = ans1(na-1,nd,m-1);
			if(temp!=INT_MIN && JiroATK[na]<=Ciel[m])
				DP[na][nd][m][1] = max( DP[na][nd][m][1] , Ciel[m]-JiroATK[na]+temp );
		}
		if(nd>0)
		{
			int temp = ans1(na,nd-1,m-1);
			if(temp!=INT_MIN && JiroDEF[nd]<Ciel[m])
				DP[na][nd][m][1] = max( DP[na][nd][m][1] , temp );
		}
		int temp = ans1(na,nd,m-1);
		if(temp!=INT_MIN)
			DP[na][nd][m][1] = max( DP[na][nd][m][1] , Ciel[m]+temp );
	}
	return DP[na][nd][m][1];
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,na,nd;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	string s;

	sd(n);	sd(m);	na = nd = 0;

	for(i=0;i<n;i++)
	{
		cin >> s;	sd(k);

		if(s=="ATK")
			JiroATK[++na] = k;
		else
			JiroDEF[++nd] = k;

	}

	for(i=1;i<=m;i++)
	{
		sd(Ciel[i]); 
		CielPrefSum[i] = CielPrefSum[i-1] + Ciel[i];
	}

	sort(JiroATK+1,JiroATK+na+1);
	sort(JiroDEF+1,JiroDEF+nd+1);
	sort(Ciel+1,Ciel+m+1);

	for(i=1;i<=m;i++)
	{
		CielPrefSum[i] = CielPrefSum[i-1] + Ciel[i];
	}	

	// for(i=1;i<=na;i++)
	// 	printf("%d ", JiroATK[i] );
	// printf("\n");

	// for(i=1;i<=nd;i++)
	// 	printf("%d ", JiroDEF[i] );
	// printf("\n");	

	printf("%d\n",  max(ans0(na,nd,m),ans1(na,nd,m))   );

	return 0;
}

