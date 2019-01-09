#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int booking();
char buses();
char book();
char cancel();
char about();
char get_gender(int);
int get_age(int);
long long int get_number(int);
char try_again(int);
int user_gen();
int user_log();
long long int get_num_login();

long long int get_num_login()
{
  long long int n, numm;
  int valid=0, count=0;
  while(!valid)
  {
      printf("Enter phone number:\n");
      scanf("%lld", &n);
      numm=n;
      while(numm != 0)
      {
          numm /=10;
          count++;
      }
      if(count==10)
      {
          valid=1;
      }
      else
      {
          printf("\nInvalid input, phone number should be of 10 digits. Try again\n");
          count=0;
      }
  }
  return n;
}

int user_gen()
{
	struct user_info
  {
      long long ph_no;
		  char name[25];
		  char passwd[9];
	 };

	struct user_info ui;

	FILE *f1;
	int i;
	f1=fopen("user_dat.txt","a");
	if(f1==NULL)
  {
		printf("\nFile cannot be opened.\n");
		getch();
		exit(0);
	}

	printf("Enter Name:\n");
	scanf("%s",ui.name);
  ui.ph_no=get_num_login();
	printf("Enter Password:\n");
	scanf("%s",ui.passwd);
	fprintf(f1,"%s\n%lld\n%s\n",ui.name,ui.ph_no,ui.passwd);
	system("cls");
	fclose(f1);
	return 0;
}


char try_again(int x)
{
  char choice;

  if(x <= 0)
  {
    printf("Number of tries exceeded limit: Try again after sometime.");
    Sleep(4000);
    system("cls");
    printf("\n******Visit Again!!******\n");
    exit(0);
  }

  printf("Invalid credentials.\nEnter 'Y' to try again or 'N' to quit.\n");

  while(1)
  {
      scanf(" %c",&choice);
      fflush(stdin);

      if(choice=='Y' || choice=='y')
      {
          return 0;
      }

      else if(choice=='N' || choice=='n')
      {
          printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
          Sleep(3000);
          exit(0);
      }

      else
      {
          system("cls");
          printf("\nWrong choice. Try again, enter 'Y' to try again or 'N' to quit:");
          Sleep(2000);
       }
  }
}

int user_log()
{
	FILE *f1;
	int tries=3;
  struct user_info
  {
    long long ph_no;
    char name[25];
    char passwd[9];
  };

  struct user_info ui,ch;
  while(1)
  {
	  tries--;
	  f1=fopen("user_dat.txt","r");
    if(f1==NULL)
    {
      printf("file cannot be opened ");
      getch();
      exit(0);
    }

	system("cls");
	printf("------User login------\n");
	printf("Enter Name:\n");
	scanf("%s",&ch.name);
	printf("Enter phone number:\n");
	scanf("%lld",&ch.ph_no);
	printf("Enter Password:\n");
	scanf("%s",&ch.passwd);

	while(fscanf(f1,"%s\n%lld\n%s",ui.name,&ui.ph_no,&ui.passwd)!=EOF)
  {
		if((!strcmp(ch.name,ui.name))&&(ch.ph_no==ui.ph_no)&&(!strcmp(ch.passwd,ui.passwd)))
    {
			printf("\nPassword correct...Loading...");
			Sleep(3000);
			system("cls");
			booking();
		}
	}
  try_again(tries);
}
	return 0;
}


int booking()
{
	while(1)
	{
			int choice;
			printf("Bus Reservation System.\n\nAvailable choices:\n");
			printf("1. Buses available\n2. Book Ticket\n3. Cancel Ticket\n4. Exit\n\n");
			printf("Enter your choice: ");
			fflush(stdin);
			scanf("%d", &choice);
			system("cls");
			switch(choice)
			{
					case 1:
					{
							buses();
							break;
					}
					case 2:
					{
							book();
							break;
					}
					case 3:
					{
							cancel();
							break;
					}
					case 4:
					{
							printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
              Sleep(5000);
							exit(0);
							break;
					}
					default:
					{
							printf("\nInvalid input try again.\n\n");
							booking();
							break;
					}
			}
	}
return 0;
}


char buses()                    //info about case 1 (buses available)
{
    char back_1;
    printf("\nBuses available:\n\n");
    printf("1. Aditya Travels    (Shimla - Palampur)\n2. Asif Travels      (Shimla - Una)\n3. Sahil Travels     (Shimla - Hamirpur)\n4. Harshita Travels  (Shimla - Mandi)\n5. Vaishnav Travels  (Shimal - Manali)\n");
    printf("\nWant to return to home page press 'H':");
    scanf(" %c", &back_1);
    if(back_1=='h' || back_1=='H')
    {
        system("cls");
        return 0;
    }
    else
    {
        system("cls");
        printf("\nInvalid choice entered, Try Again.\n\n");
        buses();
    }
}

char get_gender(int b)        //so gender can only be M of F*/
{
    char g;
    int valid=0;
    while(!valid)
    {
        printf("Gender of %d passenger(M/F): ", b+1);
        scanf(" %c", &g);
        if(g== 'M' || g== 'F' || g== 'm' || g=='f')
        {
            valid=1;
        }
        else
        {
            printf("\nInvalid input. Try again\n");
        }
    }
    return g;
}

int get_age(int c)           //so that age is between 1 and 130
{
  int a;
  int valid=0;
  while(!valid)
  {
      printf("Age of %d passenger: ", c+1);
      scanf("%d", &a);
      if(a>= 1 && a<=130)  /*122 is the maximum age of a human being till now */
      {
          valid=1;
      }
      else
      {
          printf("\nInvalid input, age can'not be more than 130 and less than 1. Try again\n");
      }
  }
  return a;
}

long long int get_number(int d)    //phone number of exact 10 digits
{
  long long int n, numm;
  int valid=0, count=0;
  while(!valid)
  {
      printf("Phone number of %d passenger: +91- ", d+1);
      scanf("%lld", &n);
      numm=n;
      while(numm != 0)
      {
          numm /=10;
          count++;
      }
      if(count==10)
      {
          valid=1;
      }
      else
      {
          printf("\nInvalid input, phone number should be of 10 digits. Try again\n");
          count=0;
      }
  }
  return n;
}

char book()           //code of case 2 (book ticket)
{
    FILE *info, *ticket;
    int number, pass, i, j, x, y, k, z=65, ticket_num;
    char seat, back_2;
    struct info
    {
      char name[100];
      char gender;
      int age;
      long long int p_num;
    };
    struct info detail[50];

    info=fopen("E:\\information.txt", "w");
    if(info==NULL)
    {
        system("cls");
        printf("\nCan'not open the file.\n");
        return 0;
    }
    else
    {
        printf("Ticket Booking\n\n");
        printf("Enter Bus Number:");
        scanf("%d", &number);
        fprintf(info, "Bus Number =%d\n", number);

        if(number >= 1 && number <= 5)
        {
            printf("\nEnter Number of passengers (<44) : ");
            scanf("%d", &pass);
            fprintf(info, "Number of Passengers =%d\n", pass);

            if(pass<1 || pass>45)
            {
                printf("\nNumber of passengers should be between 1 and 44.\n");
                printf("\nTo return to home page press 'h'.\n\nTo return to starting of the Ticket Booking tab press 'r'.\n");
                printf("\nEnter your choice:");
                scanf(" %c", &back_2);
                fclose(info);

                if(back_2=='h' || back_2=='H')
                {
                    system("cls");
                    return 0;
                }

                else if(back_2=='r' || back_2=='R')
                {
                    system("cls");
                    book();
                }

                else
                {
                    system("cls");
                    printf("\nInvalid Entry, Try again.\n\n");
                    book();
                }
            }

            else
            {
                printf("\nEnter details of passengers:\n\n");
                fprintf(info, "\nDetails of passengers:\n\n");

                for(i=0; i<pass; i++)
                {
                    fprintf(info, "Detail of %d passenger:\n", i+1);
                    printf("Name of %d passenger: ", i+1);
                    scanf("%s", &detail[i].name);
                    fprintf(info, "Name =%s\n", detail[i].name);
                    detail[i].gender=get_gender(i);
                    fprintf(info, "Gender =%c\n", detail[i].gender);
                    detail[i].age=get_age(i);
                    fprintf(info, "Age =%d\n", detail[i].age);
                    detail[i].p_num=get_number(i);
                    fprintf(info, "Phone number =%lld\n", detail[i].p_num);
                    printf("\n\n**************************\n\n");
                }

                printf("\nSelect your seat\n\n");
                for(x=1; x<=1; x++)
                {
                    printf("\n");
                    for(y=1; y<=10; y++)
                    {
                         printf(" %d\t", y);
                    }
                }

                printf("\n");
                for(x=1; x<=3; x++,z++)
                {
                    printf("\n");
                    printf("%c ", z);

                    for(y=1; y<=10; y++)
                    {
                        printf("- \t");
                    }
                }

                z=68;
                printf("\n");
                for(x=1; x<=2; x++,z++)
                {
                    printf("%c ", z);
                    for(y=1; y<10; y++)
                    {
                        printf("\t");
                    }
                    printf("- \n\n");
                }

                z=70;
                for(x=1; x<=2; x++,z++)
                {
                    printf("%c ", z);
                    for(y=1; y<3; y++)
                    {
                        printf("\t");
                    }
                    for(k=1; k<=6; k++)
                    {
                        printf("- \t");
                    }
                    printf("\n\n");
                }

                printf("\n\nEnter seat number(example: 1A): ");
                scanf(" %c", &seat);
                printf("\n\nYour seat is confirmed!!\n\nThanks for using our Bus reservation system.\n");
                ticket=fopen("E:\\ticket_num.txt", "w");
                ticket_num=((number*pass)+66001);
                printf("\n******Your ticket number is: %d******\n", ticket_num);
                printf("\nRemember your ticket number in order to cancel the ticket.\n");
                fprintf(ticket, "%d", ticket_num );
                printf("\n$$$$ You will be automatically redirected to home page in 10 seconds.$$$$");
                fclose(info);
                fclose(ticket);
                Sleep(10000);
                system("cls");
                return 0;
            }
        }

        else
        {
            printf("Invalid bus number. Check the bus number from the 'Buses available' option on home page.\n");
            printf("\nTo return to home page press 'h'.\n\nTo return to starting of the Ticket Booking tab press 'r'.\n");
            printf("\nEnter your choice:");

            scanf(" %c", &back_2);
            fclose(info);

            if(back_2=='h' || back_2=='H')
            {
                system("cls");
                return 0;
            }

            else if(back_2=='r' || back_2=='R')
            {
                system("cls");
                book();
            }

            else
            {
                system("cls");
                printf("\nInvalid Entry, Try again.\n\n");
                book();
            }
        }
    }
}

char cancel()           // code of case 3 (cancela ticket)
{
    char tick, back_3;
    int num, sum=0, numb, n=10000;
    printf("\nCancel Ticket.\n\n");
    FILE *ticke;
    ticke=fopen("E:\\ticket_num.txt", "r");
    if(ticke == NULL)
    {
        system("cls");
        printf("\nFirst book a ticket.\n");
        fclose(ticke);
        return 0;
    }
    else
    {
        printf("\nEnter your ticket number:");
        scanf("%d", &num);
        while(1)
        {
            tick=fgetc(ticke);
            numb=atoi(&tick);
            sum=sum+(numb*n);
            n=n/10;

            if(tick==EOF)
            {
                break;
            }
        }
        fclose(ticke);
        if(sum == num)
        {
            printf("\n***Your ticket having number %d is being cancelled.***\n", num);
            printf("\n*To return to home page press, press any alphabet.\n\n*To cancel other ticket press 'R'.\n");
            printf("\nEnter your choice:");
            scanf(" %c", &back_3);

            if(back_3=='r' || back_3=='R')
            {
                system("cls");
                cancel();
            }

            else
            {
                system("cls");
                return 0;
            }
        }
        else
        {
            system("cls");
            printf("Invalid ticket number, try again.\n");
            cancel();
        }
    }
}

int main()
{
	int a=0,b=1,d;

	while(b)
  {
    printf("------User login------\n\n1. New User         enter 1 to continue\n2. Existing user    enter 2 to continue\n3. About Us         enter 3 to continue\n4. Exit             enter 4 to continue\n");
		printf("Enter Choice :");
		scanf("%d",&a);
		fflush(stdin);
		switch(a)
    {
			case 1:
      {
				system("cls");
				printf("*********Genrate new user********\n\n");
				user_gen();
      }
			case 2:
      {
				user_log();
				b=0;
				break;
      }

			case 3:
      {
	          system("cls");
	          printf("\nProject: Bus Reservation System.\n");
	          printf("\nGroup members:\n\n");
	          printf("1. Sahil Bhatia  (601)\n2. Asif Habib    (602)\n3. Aditya Naitan (603)\n4. Harshita      (604)\n5. Vaishnav      (607)\n");
	          printf("\nGroup established: 21 December 2018\n");
	          printf("\nGroup Leader: Netaji Subhash Chandra Bose\n");
	          printf("\nContact us:\n\nPhone number: 09149404216\nE-main address: adityanaitan@gmail.com\n");
	          printf("\nReturn to Home page, ''Press any key to continue'' :");
	          getch();
	          system("cls");
	          break;
	       }
			case 4:
      {
			  system("cls");
				printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
        Sleep(5000);
				exit(0);
      }
      default:
      {
        system("cls");
				printf("****Wrong choice, try again.******\n\n");
        break;
      }
    }
	}
 getch();
	return 0;
}
