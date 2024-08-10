#include<stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int i,n,n1,n2,gcd,remainder,word,len,fact=1,flag=0,rev = 0;
	char a[100];
	do{
		printf("\n1. Factorial of a number\n2. Find GCD of two numbers\n3. Checking Primary number\n4. Reverse of a number\n5. Count Number of words in a sentence\n0. To Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("Enter an integer: ");
			scanf("%d", &n);
			if (n < 0)
			printf("Error! Factorial of a negative number doesn't exist.");
			else
			{
				for (i = 1; i <= n; ++i)
				{
					fact =fact * i;
					 }
					 printf("Factorial of %d = %llu", n, fact); //llu=unsigned long long
					 }
					 break;
					 case 2: printf("Enter two integers: ");
					 scanf("%d %d", &n1, &n2);
					 for(i=1; i <= n1 && i <= n2; ++i)
					 {
					 	if(n1%i==0 && n2%i==0)
					 	gcd = i;
					 	}
					 	printf("G.C.D of %d and %d is %d", n1, n2, gcd);
					 	break;
					 	case 3: printf("Enter a positive integer: ");
					 	scanf("%d", &n);
					 	for (i = 2; i <= n / 2; ++i)
					 	{
					 		if (n % i == 0)
					 		{
					 			flag = 1;
					 			break;
					 			}
					 			}
					 			if (n == 1)
					 			{
					 				printf("1 is neither prime nor composite.");
					 				}
					 				else
					 				{
					 					if (flag == 0)
					 					printf("%d is a prime number.", n);
					 					else
					 					printf("%d is not a prime number.", n);
					 					}
					 					break;
					 					case 4: printf("Enter an integer: ");
					 					scanf("%d", &n);
					 					while (n != 0)
					 					{
					 						remainder = n % 10;
					 						rev = rev * 10 + remainder;
					 						n =n/ 10;
					 						}
					 						printf("Reversed number = %d", rev);
					 						 break;
					 						 case 5: fflush(stdin);
					 						 printf("\nEnter a sentence:");
					 						 gets(a);
					 						 len=strlen(a);
					 						 for(i=0;i<len;i++)
					 						 {
					 						 	if(a[i]!=' ' && a[i+1]==' ')
					 						 	word=word+1;
					 						 	}
					 						 	printf("\nThere are %d words in the string",word);
					 						 	break;
					 						 	case 0:printf("\nThe end");
					 						 	break;
					 						 	default:printf("\nWrong choice babu");
					 						 	}
					 						 	}
					 						 	while(i!=0);
					 						 }
