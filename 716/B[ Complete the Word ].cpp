#include <bits/stdc++.h>

using namespace std;

char S[50007];
int exists[26]={0};

int main()
{
	scanf("%s",S);
	int N = strlen(S);
	int left=26, QM=0 ;

	if(N<26)
	{
		printf("-1\n");
		return 0;
	}

	for(int i=0;i<26;i++)
	{
		if(S[i]==&#39;?&#39;)
			QM++;
		else
		{
			if(exists[S[i]-&#39;A&#39;] == 0)
			{
				left--;
			}
			exists[S[i]-&#39;A&#39;]++;

		}	
	}

	if(left==QM)
	{
		int j=0;

		for(int i=0;i<26;i++)
		{
			if(S[i]==&#39;?&#39;)
			{
				while(j<26)
				{
					if(exists[j]==0)
					{
						S[i] = j + &#39;A&#39;;
						exists[j] = 1;
						break;
					}
					j++;	
				}	
			}	
		}

		for(int i=26;i<N;i++)
		{
			if(S[i]==&#39;?&#39;)
				S[i] = &#39;A&#39;;
		}

		printf("%s\n",S);

		return 0;	

	}	

	bool flag = false;

	for(int i=26;i<N;i++)
	{
		if( S[i-26] != &#39;?&#39; )
		{
			exists[ S[i-26] - &#39;A&#39; ]--;
			if( exists[ S[i-26] - &#39;A&#39; ] == 0 )
			{
				left++;
			}
		}
		else
		{
			QM--;
		}

		if(S[i]==&#39;?&#39;)
			QM++;
		else
		{
			if(exists[S[i]-&#39;A&#39;] == 0)
			{
				left--;
			}
			exists[S[i]-&#39;A&#39;]++;

		}

		if(left==QM)
		{
			int j=0;

			for(int k=i-26+1;k<=i;k++)
			{
				if(S[k]==&#39;?&#39;)
				{
					while(j<26)
					{
						if(exists[j]==0)
						{
							S[k] = j + &#39;A&#39;;
							exists[j] = 1;
							break;
						}
						j++;	
					}	
				}	
			}

			for(int k=i+1;k<N;k++)
			{
				if(S[k]==&#39;?&#39;)
					S[k] = &#39;A&#39;;
			}
			for(int k=i-26;k>=0;k--)
			{
				if(S[k]==&#39;?&#39;)
					S[k] = &#39;A&#39;;
			}			

			printf("%s\n",S);

			flag = true;
			return 0 ;

		}					


	}	


	printf("-1\n");

	return 0;
}