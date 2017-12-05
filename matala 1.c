/*
Assigned by:

Alex Zelentsov
#321233256
*/
#include <stdio.h>
int main ()
{
	int num, qCounter=0 ; 
	char answer;
	printf ("Please enter number in the range 1-5\n");
	scanf_s ("%d", &num);
	while (num!=5)// The loop will stop when the program get number 5.
		{
			
				qCounter++;// counting how much the main menu repeat.
				switch (num)
			{
				case 1:
					printf("Disconnecting\n");
					break;
				case 2:
					break;
				case 3:
					printf("Are you sure you would like to cancel your order ???\nPlease enter one char:\n");
					flushall();
					scanf("%c",&answer);
				
				if ((answer == 'Y') || (answer == 'y'))
					{
						printf("canceled\n");
						num = 5;//  if the member choose right options (Y or y). num wiil be equal to 5,and the program will end.
					}
					break;
				case 4: 
					printf("Your position in queue is:%d\n", qCounter); // the program will print how much the main menu repeat.
					break;
				default:
					printf("wrong input\n"); // the program will give an warning, when the input is incorrect.
					break;
				}
			
			if (num != 5) // the program will reveive a number until the number would be equal to 5.
			{
				printf("please enter number in the range 1-5\n");
				scanf("%d",&num);
			}
		}
}


