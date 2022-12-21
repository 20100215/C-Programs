#include <stdio.h>

void main()
{
	int N, ctr=0, ans=0, placeval=0, digit;
	printf("Enter octal number\n");
	scanf("%d",&N);
	while (N>0)
	{
		digit=N%10;
		while (ctr>0)
		{
			digit=digit*8;
			ctr=ctr-1;
		}
		N=N/10;
		placeval=placeval+1;
		ctr=placeval;		
		ans=ans+digit;
	}
	printf("Decimal number is %d",ans);
}
