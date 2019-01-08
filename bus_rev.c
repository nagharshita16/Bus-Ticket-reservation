#include<stdio.h>
#include<conio.h>
#include<windows.h>    /*Used for sleep function*/

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
			printf("Password correct");
			sleep(3);
			booking();
		}
	}
	try_again2:
	if(tries<=0){
		printf("number of tries exceeded limit: Try again after sometime");    ///to limit number of tries user can enter wrong password
		sleep(4);
		system("cls");
		printf("\n******Visit Again!!******\n");
		exit(0);
	}
	printf("invalid credentials\nEnter Y to try again or N to quit\n");   
	scanf("%c",&choice);
	if(choice=='Y' || choice=='y'){
		goto try_again;
	}
	else if(choice=='N' || choice=='n'){
		printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
        sleep(3);
		exit(0);
	}
	else{
		printf("Wrong choice");
		sleep(2);
		goto try_again2;
	}
	return 0;
}



int booking(){
	int choice;
    here:         /*Used for goto function to bring the control of program here*/
    system("cls");
	printf("Bus Reservation System.\n\nAvailable choices:\n");
    printf("1 Buses available  Enter 1 to continue\n2 Book Ticket      Enter 2 to continue\n3 Cancel Ticket    Enetr 3 to continue\n4 Exit             Enetr 4 to continue\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    system("cls");          /*Clears the screen, clrscr() can only be used in turbo C (must include 'stdlib.h' header file)*/
    switch(choice)
    {
        case 1:
        {
            char back_1;
            start1:
            printf("\nBuses available:\n\n");
            printf("1. Aditya Travels   --(Shimla - Palampur)\n2. Asif Travels     --(Shimla - Una)\n3. Sahil Travels    --(Shimla - Hamirpur)\n4. Harshita Travels --(Shimla - Mandi)\n5. Vaishnav Travels --(Shimal - Manali)\n");
            printf("\nWant to return to home page press y:");
            scanf(" %c", &back_1);
            if(back_1=='y' || back_1=='Y')
            {
                system("cls");
                goto here;
            }
            else
            {
                system("cls");
                printf("\nInvalid choice entered, Try Again.\n\n");
                goto start1;

            }
            break;
        }

        case 2:
        {
            FILE *info, *ticket;     /*Two files opened, info for saving details and ticket for saving ticket number*/
            int number, pass, i, j, x, y, k, z=65, ticket_num;
            char seat, back_2;
            struct info
            {
                char name[100];
                char gender[100];
                int age; 
				long long p_num;
            };
            struct info detail[50];

           start2:
            ///info=fopen("E:\\information.txt", "w");
            info=fopen("information.txt", "a");
            if(info==NULL)
            {
                system("cls");
                printf("\nCan'not open the file.\n");
                goto here;
            }
            else
            {

            printf("Ticket Booking\n\n");
            printf("Enter Bus Number:");
            scanf("%d", &number);
            fflush(stdin);
            fprintf(info, "Bus Number =%d\n", number);

            if(number >= 1 && number <= 5)
            {
                printf("\nEnter Number of passengers (<44) : ");
                scanf("%d", &pass);
                fflush(stdin);

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
                        goto here;
                    }

                    else if(back_2=='r' || back_2=='R')
                    {
                        system("cls");
                        goto start2;
                    }

                    else
                    {
                        system("cls");
                        printf("\nInvalid Entry, Try again.\n\n");
                        goto start2;
                    }
                }
                else
                {                	
                    printf("\nEnter details of passengers:\n\n");
                    fprintf(info, "Number of Passengers =%d\n", pass);
                    fprintf(info, "\nDetails of passengers:\n\n");

                    for(i=0; i<pass; i++)
                    {
                        fprintf(info, "Detail of %d passenger:\n", i+1);
                        printf("Name of %d passenger: ", i+1);
                        fflush(stdin);
                        scanf("%s", &detail[i].name);
                        fprintf(info, "Name =%s\n", detail[i].name);
                        printf("Gender of %d passenger(M/F): ", i+1);
                        fflush(stdin);
                        scanf(" %c", &detail[i].gender);
                        fprintf(info, "Gender =%s\n", detail[i].gender);
                        printf("Age of %d passenger: ", i+1);
                        fflush(stdin);
                        scanf("%d", &detail[i].age);
                        fprintf(info, "Age =%d\n", detail[i].age);
                        printf("Phone number of %d passenger: ", i+1);
                        fflush(stdin);
                        scanf("%lld", &detail[i].p_num);
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
                    fflush(stdin);
                    scanf(" %c", &seat);
                    printf("\n\nYour seat is confirmed!!\n\nThanks for using our Bus reservation system.\n");
                    ///ticket=fopen("E:\\ticket_num.txt", "w");
                    ticket=fopen("ticket_num.txt", "w");
                    ticket_num=((number*pass)+66001);
                    printf("\n******Your ticket number is: %d******\n", ticket_num);
                    printf("\nRemember your ticket number in order to cancel the ticket.\n");
                    printf("\n$$$$ You will be automatically redirected to home page in 10 seconds.$$$$");
                    fprintf(ticket, "%d", ticket_num );
                    fclose(ticket);
                    fclose(info);
                    sleep(10);
                    fflush(stdin);

                }
            }

            else
            {
                printf("Invalid bus number. Check the bus number from the 'Buses available' option on home page.\n");
                printf("\nTo return to home page press 'h'.\n\nTo return to starting of the Ticket Booking tab press 'r'.\n");
                printf("\nEnter your choice:");
                fflush(stdin);
                scanf(" %c", &back_2);
                fclose(info);

                if(back_2=='h' || back_2=='H')
                {
                    system("cls");
                    goto here;
                }

                else if(back_2=='r' || back_2=='R')
                {
                    system("cls");
                    goto start2;
                }

                else
                {
                    system("cls");
                    printf("\nInvalid Entry, Try again.\n\n");
                    goto start2;
                }
            }
          }
          system("cls");
          goto here;
          break;
        }

        case 3:
        {
            char tick, back_3;
            int num, sum=0, numb, n=10000;
            start3:
            printf("\nCancel Ticket.\n\n");
            FILE *ticke;
            ///ticke=fopen("E:\\ticket_num.txt", "r");
            ticke=fopen("ticket_num.txt", "r");
            if(ticke == NULL)
            {
                system("cls");
                printf("\nFirst book a ticket.\n");
                fclose(ticke);
                goto here;

            }
            else
            {
                printf("\nEnter your ticket number:");
                fflush(stdin);
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
                    printf("\n*To return to home page press 'H'.\n\n*To cancel other ticket press 'R'.\n");
                    printf("\nEnter your choice:");
                    fflush(stdin);
                    scanf(" %c", &back_3);

                    if(back_3=='h' || back_3=='H')
                    {
                        system("cls");
                        goto here;
                    }

                    else if(back_3=='r' || back_3=='R')
                    {
                        system("cls");
                        goto start3;
                    }

                    else
                    {
                        system("cls");
                        goto here;
                    }
                }
                else
                {
                    system("cls");
                    printf("Invalid ticket number, try again.\n");
                    goto start3;
                }
            }
            break;
      		}

	    case 4:
	    {
	        printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n\n");
	        exit(0);
	        break;
	    }

    }
	getch();
	return 0;
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
				printf("Wrong choice Enter agian\n");
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
        		sleep(1);
				exit(0);
							
		}
	}
	
	return 0;
}
