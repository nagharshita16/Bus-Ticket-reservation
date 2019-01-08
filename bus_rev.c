#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>    /*Used for Sleep function*/

//Declerations of functions used below.
char buses();
char book();
char cancel();
char about();
char get_gender(int);
int get_age(int);
long long int get_number(int);

///Function to create new user
int user_gen(){
	struct user_info{
		long long ph_no;
		char name[25];
		char passwd[9];
	};     ///struture about user info

	struct user_info ui;


	FILE *f1;     ///New instance of file is created
	int i;
	f1=fopen("user_dat.dat","a");             ///opening the file
	if(f1==NULL){
		printf("file cannot be opened ");
		getch();
		exit(0);
	}
	printf("Enter Name\n");              ///well user info is entered but fflush is used regularly so as to clear the buffer of scanf otherwise some random useless errors occur on screen
	fflush(stdin);
	scanf("%s",ui.name);
	printf("Enter phone number\n");
	fflush(stdin);
	scanf("%lld",&ui.ph_no);
	printf("Enter Password\n");
	fflush(stdin);
	scanf("%s",ui.passwd);
	///printf("%s  %lld  %s",ui.name,ui.ph_no,ui.passwd);            do not uncomment only for debugging purposes
	fprintf(f1,"%s\n%lld%s\n",ui.name,ui.ph_no,ui.passwd);           ///adding user data to file
	system("cls");
	fclose(f1);
	///view_dat();                                                   ///function added for debugging purposes

	///getch();
	return 0;
}
///This is placed here for testing purposes only, feel free to try
/*int view_dat(){
	FILE *f1;
	f1=fopen("user_dat.dat","r");
	struct user_info{
		long long ph_no;
		char name[25];
		char passwd[9];
	};

	struct user_info ui;

	if(f1==NULL){
		printf("file cannot be opened ");
		getch();
		exit(0);
	}
	while(fscanf(f1,"%s%lld%s",&ui.name,&ui.ph_no,&ui.passwd)!=EOF){
		printf("\n%s%lld%s",ui.name,ui.ph_no,ui.passwd);
	}
	fclose(f1);
}
*/

int user_log(){                                           ///function for userlogin similar to user_gen so read previous comments for this function
	FILE *f1;
	int tries=3;
	char choice;
	try_again:
	tries--;
	f1=fopen("user_dat.dat","r");
	struct user_info{
		long long ph_no;
		char name[25];
		char passwd[9];
	};

	struct user_info ui,ch;
	system("cls");
	printf("------User login------\n");
	printf("Enter Name\n");
	fflush(stdin);
	scanf("%s",&ch.name);
	printf("Enter phone number\n");
	fflush(stdin);
	scanf("%lld",&ch.ph_no);
	printf("Enter Password\n");
	fflush(stdin);
	scanf("%s",&ch.passwd);
	fflush(stdin);

	if(f1==NULL){
		printf("file cannot be opened ");
		getch();
		exit(0);
	}
	///just reading the user data and comparing it
	while(fscanf(f1,"%s\n%lld%s",ui.name,&ui.ph_no,&ui.passwd)!=EOF){          ///warning do not remove \n from the middle of code
		if((!strcmp(ch.name,ui.name))&&(ch.ph_no==ui.ph_no)&&(!strcmp(ch.passwd,ui.passwd))){
			printf("Password correct...Loading...");
			Sleep(30000);             //Sleep() is for windows not sleep() and time is in miliseconds
			system("cls");
			booking();
		}
	}
	try_again2:
	if(tries<=0){
		printf("number of tries exceeded limit: Try again after sometime");    ///to limit number of tries user can enter wrong password
		Sleep(40000);
		system("cls");
		printf("\n******Visit Again!!******\n");
		exit(0);
	}
	printf("Invalid credentials.\nEnter 'Y' to try again or 'N' to quit.\n");
	scanf("%c",&choice);
	if(choice=='Y' || choice=='y'){
		goto try_again;
	}
	else if(choice=='N' || choice=='n'){
		printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
        Sleep(30000);
		exit(0);
	}
	else{
		printf("Wrong choice");
		Sleep(20000);
		goto try_again2;
	}
	return 0;
}



int booking(){
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

int main(){
	int a=0,b=1,d;
	here:         ///Used for goto function to bring the control of program here
	printf("------User login------\n1 New User         enter 1 to continue\n2 Existing user    enter 2 to continue\n3 About Us         enter 3 to continue\n4 Exit             enter 4 to continue\n");
	while(b){
		printf("Enter Choice :");    ///Entering chooice and comparing it
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
			case 1:
				system("cls");
				printf("*********Genrate new user********\n");
				user_gen();  ///Not using break so that newly created user can go to user login directly
			case 2:
				user_log();
				b=0;
				break;
			default:
				printf("Wrong choice, enter again\n");
				getch();
				system("cls");               ///for clear screen as clrscr not working
				printf("------User login------\n1 New User         enter 1 to cotinue\n2 Existing user    enter 2 to continue\n=>");
			case 3:{
	          system("cls");
	          printf("\nProject: Bus Reservation System.\n");
	          printf("\nGroup members:\n\n");
	          printf("1. Sahil Bhatia  (601)\n2. Asif Habib    (602)\n3. Aditya Naitan (603)\n4. Harshita      (604)\n5. Vaishnav      (607)\n");
	          printf("\nGroup established: 21 December 2018\n");
	          printf("\nGroup Leader: Netaji Subhash Chandra Bose\n");    ///Vande Matram
	          printf("\nContact us:\n\nPhone number: 09149404216\nE-main address: adityanaitan@gmail.com\n");
	          printf("\nReturn to Home page, ''Press any key to continue'' :");
	          getch();
	          system("cls");
	          goto here;
	          break;
	          }
			case 4:
				printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
        		Sleep(10000);
				exit(0);

		}
	}

	return 0;
}
