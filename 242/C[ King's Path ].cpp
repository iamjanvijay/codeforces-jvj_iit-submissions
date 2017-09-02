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

map< pair<int,int> , bool > A;
queue< pair< pair<int,int> , int > > Q;

int BFS(int x0,int y0,int x1,int y1)
{

	Q.push( make_pair( make_pair(x0,y0) , 0 ) );
	A[ make_pair(x0,y0) ] = false;
	pair< pair<int,int> , int > temp;

	while(! Q.empty())
	{
		temp = Q.front();	Q.pop();

		if(temp.first.first == x1 && temp.first.second == y1)
			return temp.second;

		if( A[ make_pair( temp.first.first - 1 , temp.first.second ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first - 1 , temp.first.second ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first - 1 , temp.first.second ) ] = false;
		}

		if( A[ make_pair( temp.first.first + 1 , temp.first.second ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first + 1 , temp.first.second ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first + 1 , temp.first.second ) ] = false;
		}

		if( A[ make_pair( temp.first.first , temp.first.second - 1 ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first , temp.first.second - 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first, temp.first.second - 1 ) ] = false;
		}

		if( A[ make_pair( temp.first.first , temp.first.second + 1 ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first , temp.first.second + 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first, temp.first.second + 1 ) ] = false;
		}	

		if( A[ make_pair( temp.first.first - 1 , temp.first.second - 1) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first - 1 , temp.first.second - 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first - 1 , temp.first.second - 1 ) ] = false;
		}

		if( A[ make_pair( temp.first.first + 1 , temp.first.second - 1 ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first + 1 , temp.first.second - 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first + 1 , temp.first.second  - 1) ] = false;
		}

		if( A[ make_pair( temp.first.first - 1, temp.first.second + 1 ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first - 1, temp.first.second + 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first - 1, temp.first.second + 1 ) ] = false;
		}

		if( A[ make_pair( temp.first.first + 1, temp.first.second + 1 ) ] )
		{
			Q.push( make_pair( make_pair( temp.first.first + 1, temp.first.second + 1 ) , temp.second + 1 ) );
			A[ make_pair( temp.first.first + 1, temp.first.second + 1 ) ] = false;
		}							

	}

	return -1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int x0,y0,x1,y1,r,a,b,n,i,j,k,l;

	sd(x0); sd(y0); sd(x1); sd(y1);

	sd(n);

	while(n--)
	{
		sd(r);	sd(a);	sd(b);

		for(i=a;i<=b;i++)
		{
			A[ make_pair(r,i) ] = true;
		}

	}	

	printf("%d\n", BFS(x0,y0,x1,y1) );
	
	return 0;
}