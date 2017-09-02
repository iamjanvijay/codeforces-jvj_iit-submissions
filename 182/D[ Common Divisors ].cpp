#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char S1[100007];	char S2[100007];
int F1[100007];		int F2[100007];
char V[100007];

void fillPF(int N,int PF[],int &PFN)
{
	int i;
	for(i=1 ; i*i<=N ; i++)
	{
		if( N%i == 0 )
		{
			PF[PFN++] = i;

			if(i*i != N)
			{
				PF[PFN++] = N/i;
			}

		}		
	}
	sort(PF,PF+PFN);	
}

int leastdiv(char S[],int SN,int F[],int FN)
{
	int i,j,temp,test;

	for(i=0;i<FN;i++)
	{
		temp = F[i];
		test = 1;
		for(j=0;j<SN;j++)
		{
			if(j<temp)
			{
				V[j] = S[j];
			}
			else
			{
				if(V[j%temp] != S[j])
				{
					test = 0;
					break;
				}	
			}	
		}
		if(test == 1)
			return temp;	
	}	
}

int main()
{
	int i,N1,N2,FN1 = 0,FN2 = 0;

	scanf("%s",S1);		scanf("%s",S2);
	N1 = strlen(S1);    N2 = strlen(S2);

	fillPF(N1, F1, FN1);	fillPF(N2, F2, FN2);

	// for(i=0;i<FN1;i++)
	// {
	// 	printf("%d ", F1[i] );
	// }	
	// printf("\n");

	// for(i=0;i<FN2;i++)
	// {
	// 	printf("%d ", F2[i] );
	// }	
	// printf("\n");

	int L1 = leastdiv(S1,N1,F1,FN1);	
	int L2 = leastdiv(S2,N2,F2,FN2);
	// printf("-> %d\n", L1);	

	if(L1 != L2)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		for(i=0;i<L1;i++)
		{
			if(S1[i]!=S2[i])
			{
				printf("0\n");
				return 0;
			}
		}
		int Ans = 0;
		for(i=1; L1*i <= N1 &&  L1*i <= N2 ; i++)
		{
			if( ( N1 % (L1*i)) == 0 && ( N2 % (L1*i)) == 0 )
				Ans++;
		}
		printf("%d\n",Ans);
		return 0;	
	}	

	return 0;
}