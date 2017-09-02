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

char S[1000007];

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int main()
{
	// cout << "$" << endl;
	ss(S);

	int i,j,k,l,m,n;

	n = strlen(S);

	Node* head = (Node*)malloc(sizeof(Node));
	Node* curhead = head;

	head->data = 1;
	head->left = NULL;
	head->right = NULL;

	for(i=0,j=2;i<n-1;i++,j++)
	{

		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = j;

		if(S[i]==&#39;l&#39;)
		{
			if( curhead->left == NULL )
			{
				curhead->left = temp;
				temp->right = curhead;
				temp->left = NULL;
				head = curhead = temp;
			}
			else
			{
				temp->left = curhead->left;
				temp->right = curhead;
				(curhead->left)->right = temp;
				curhead->left = temp;
				curhead = temp;
			}	
		}
		else
		{
			if( curhead->right == NULL )
			{
				curhead->right = temp;
				temp->left = curhead;
				temp->right = NULL;
				curhead = temp;
			}
			else
			{
				temp->right = curhead->right;
				temp->left = curhead;
				(curhead->right)->left = temp;
				curhead->right = temp;
				curhead = temp;
			}	
		}	
	}

	while(head!=NULL)
	{
		printf("%d\n", head->data );
		head = head->right;
	}	



	return 0;
}
