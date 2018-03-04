#include <stdio.h>

int main(void)
{
	int N = 0;
	char c = '\0';
	int used = 1;
	int order = 1;
	int i,j,k;	
	int indent = 0;

	scanf("%d %c", &N, &c);

	while(!(used > N))
	{
		if (used + 2*(2*(order+1)-1) <= N)
		{
			used = used + 2*(2*(order+1)-1);
			order++;
		}
		else
		{
			break;
		}
	}
	
	for(i=1; i<2*order; i++)
	{	
		if(i<=order)
		{
			indent++;
		}
		else
		{
			indent--;
		}

		for(k=1; k<indent; k++)
		{
			printf(" ");
		}

		for(j=1; j<2*(order-indent+1); j++)
		{
			printf("%c",c);
		}

		printf("\n");		
	}

	printf("%d\n", N-used);
	
	return 0;
}

