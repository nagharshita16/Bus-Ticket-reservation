#include<stdio.h>
#include<conio.h>

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
	
	getch();
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
			booking();
		}
	}
	///printf("invalid credentials");   Few things left to figure out
	getch();
	return 0;
}



int booking(){
	printf("Booking system comming soon");
	getch();
}



int main(){
	int a=0,b=1,d;
	printf("------User login------\n1 New User         enter 1 to cotinue\n2 Existing user    enter 2 to continue\n");
	while(b){
		printf("Enter Choice\n");    ///Entering chooice and comparing it
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
			case 1:
				user_gen();  ///Not using break so that newly created user can go to user login directly
			case 2:
				user_log();
				b=0;
				break;
			default:
				printf("Wrong choice Enter agian\n");
				getch();
				system("cls");               ///for clear screen as clrscr not working
				printf("------User login------\n1 New User         enter 1 to cotinue\n2 Existing user    enter 2 to continue\n");

		}
	}
	
	return 0;
}
