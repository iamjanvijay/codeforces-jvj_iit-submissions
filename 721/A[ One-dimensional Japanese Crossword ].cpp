#include <bits/stdc++.h>

using namespace std;

char S[100007];
int A[100007];

int main()
{
	int i,j,k,N;

	scanf("%d",&N);
	scanf("%s",S);

	k = 0;
	for(i=0;i<N;i++)
	{
		if(S[i]==&#39;B&#39;)
		{
			int count = 0;

			j = i;
			while(j<N && S[j]==&#39;B&#39;)
			{
				count++;
				j++;
			}
			i = j-1;
			A[k++] = count;	
		}	
	}

	printf("%d\n",k);
	for(int i=0;i<k;i++)
		printf("%d ",A[i]);	
	if(k!=0)
	printf("\n");
	return 0;
}