#include <bits/stdc++.h>

using namespace std;

int A[100007];

int main()
{
	int N,C;
	scanf("%d%d",&N,&C);

	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);


	int count = 1;
	for(int i=1;i<N;i++)
	{
		if(A[i]-A[i-1]<=C)
			count++;
		else
			count = 1;
	}

	printf("%d\n",count );


	return 0;
}