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

struct Node
{
	int deg;
	int val;
	int num;

	Node(int i,int j,int k)
	{
		num = i;	deg = j;	val = k; 
	}

	Node()
	{

	}

};

struct LessThan
{
  bool operator()(const Node& lhs, const Node& rhs) const
  {
    return lhs.deg > rhs.deg;
  }
};

priority_queue<Node, vector<Node>, LessThan> P;

vector<int> G[65547];
bool checked[65547];
int curVal[65547];
int curDeg[65547];

int main()
{
	int i,j,k,l,m=0,n;
	Node temp;
	sd(n);

	for(i=0;i<n;i++)
	{
		sd(j);	sd(k);
		curVal[i] = k;
		curDeg[i] = j;
		P.push( Node(i,j,k) );
	}

	while(!P.empty())
	{
		temp = P.top();	P.pop();

		if(checked[temp.num])
			continue;

		checked[temp.num] = true;

		if(temp.deg == 0)
			continue;

		G[temp.num].push_back( temp.val );

		curDeg[temp.num]--;	curDeg[temp.val]--;	
		curVal[temp.num]^=temp.val;	curVal[temp.val]^=temp.num;

		P.push( Node(temp.val,curDeg[temp.val],curVal[temp.val]) );
		m++;
	}

	printf("%d\n", m );	

	for(i=0;i<n;i++)
	{
		for(j=0;j<G[i].size();j++)
		{
			printf("%d %d\n", i, G[i][j] );
		}	
	}	

	return 0;
}
