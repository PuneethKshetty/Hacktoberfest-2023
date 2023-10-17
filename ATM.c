#include<stdio.h>
#include<time.h>
#include<string.h>
int main()
{
	time_t now;
	time(&now);
	printf("\t\t\t\t\t\t\t%s",ctime(&now));
	printf("\n\t\t\t\t\t\t\t----------ATM----------\n");
	int count=0, j=2;
	while(count != 3)
	{
		char pin[] = "0508", epin[100], ch;
		int i=0;
		printf("\n\t\tENTER PIN : ");
		while( (ch = getch()) != '\r')
		{
			epin[i++] = ch;
			printf("*");
		}
		epin[i] = '\0';
		if(strcmp(pin, epin) == 0)
		{
			count = 3;
			float amount = 699;
			int balance;
			system("cls");
			int choice = 0, c=1;
			while ( c == 1)
			{
				printf("\n\t\t\t\t\t\t\t%s",ctime(&now));
				printf("\n\t\t\t\t\t\t\t----------ATM----------\n");
				printf("\t\t1.BALANCE\n\t\t2.WITHDRAWL\n\t\t3.DEPOSIT\n\t\t4.CANCEL TRANSCATION OR EXIT\n");
				printf("\n\t\tENTER TRANSACTION : ");
				scanf("%d",&choice);
				system("cls");
				switch(choice)
				{
					case 1:
						printf("\n\t\t\t\t\t\t\t%.2f",amount);
						break;
					case 2:
						printf("\t\tENTER WITHDRAWL AMOUNT : ");
						scanf("%d",&balance);
						if( balance > amount)
						{
							printf("\n\t\t\t\t\t\t\tINSUFFICENT BALANCE");
							printf("\n\t\t\t\t\t\t\tBALANCE IS : %.2f", amount);
						}	
						else
						{
							amount = amount - balance;
							printf("\n\t\t\t\t\t\t\tBALANCE IS : %.2f", amount);
						}
						break;
					case 3:
						printf("\t\tENTER DEPOSIT AMOUNT : ");
						scanf("%d",&balance);
						amount = amount + balance;
						printf("\n\t\t\t\t\t\t\tBALANCE IS : %.2f", amount);
						break;
					case 4:
						c = 0;
						break;
					default :
						printf("\n\t\t\t\t\t\t\tENTER VALID TRANSCATION");
						Beep(500,400);
				}
				if(c == 0)
				{
					printf("\n\t\t\t\t\t\t\tTHANK YOU FOR USING");
				}
				else
				{
					printf("\n\t\tPRESS 1[CONTINUE], 0[DISCONTINUE] : ");
					scanf("%d",&c);
					system("cls");
					if( c== 0)
						printf("\n\t\t\t\t\t\t\tTHANK YOU FOR USING");
				}
			}
		}
		else
		{
			count++;
			if(count != 3)
			{
				printf("\n\t\t\t\t\t\t\tENTER VALID PIN %d TRY'S ARE LEFT",j--);
				Beep(500,400);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\tLIMIT EXCEEDED");
				Beep(900,600);
			}
				
		}
	}
}
