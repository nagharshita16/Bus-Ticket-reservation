


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

int n,c2,p;
char m[30];
int travel();
int  buses();
int book();
int cancel();
char try_again(int);
int user_gen();
int user_log();
int booking();
int dot_pattern();//just for making it user friendly






int user_gen() //New user register here
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
        exit(0);
    }
    printf("Enter username:\n");
    scanf("%s",ui.name);
    fflush(stdin);
    printf("Enter phone no. :\n");
    scanf("%lld",&ui.ph_no);
    fflush(stdin);
    printf("Enter password not more than 8 characters\n");
    scanf("%s",ui.passwd);
    fflush(stdin);
    fprintf(f1,"%s\n%lld\n%s\n",ui.name,ui.ph_no,ui.passwd);
    
    
    
    system("cls");
    fclose(f1);
    
    return 0;
}





char try_again(int x)          //If login info. is wrong control comes here.
{
    char choice;
    if(x <= 0)
    {
        printf("Number of tries exceeded limit: Try again after sometime.");
        Sleep(4000);
        system("cls");
        printf("\n******Visit Again!!******\n");
        Sleep(1000);
        system("cls");
        printf("EXITING");
        dot_pattern();
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
            printf("\nThanks for using our Bus Reservation System.\n\n******Visit Again!!******\n");
            printf("EXITING");
            dot_pattern();
            
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

int user_log()                 //Checking that login info is correct during login.
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
            printf("file cannot be opened. One obvious reason might be that you are a new user ");
            exit(0);
        }
        system("cls");
        printf("------User login------\n");
        printf("Enter username:\n");
        scanf("%s",ch.name);
        fflush(stdin);
        printf("Enter phone number:\n");
        scanf("%lld",&ch.ph_no);
        fflush(stdin);
        printf("Enter Password:\n");
        scanf("%s",ch.passwd);
        fflush(stdin);

        while(fscanf(f1,"%s\n%lld\n%s",ui.name,&ui.ph_no,&ui.passwd)!=EOF)
        {
            if((!strcmp(ch.name,ui.name))&&(ch.ph_no==ui.ph_no)&&(!strcmp(ch.passwd,ui.passwd)))
            {
                printf("\nPassword correct...Loading");
               strcpy(m,ch.name);
               
            dot_pattern();
                
                system("cls");
                booking();
            }

        }
        try_again(tries);
    }
    getch();

    return 0;
}






int booking()                      //Contains 4 cases Buses available, Book Ticket, Cancel Ticket, Exit.
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
            system("cls");
            printf("EXITING");
            dot_pattern();
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






int buses()                    //info about case 1 (buses available).
{
    char back_1;
    printf("\nBuses available:\n\n");
    printf("1. Aditya Travels(Shimla - Palampur)\n2. Asif Travels (Shimla - Una)\n3. Sahil Travels (Shimla - Hamirpur)\n4. Harshita Travels  (Shimla - Mandi)\n5. Vaishnav Travels  (Shimla - Manali)\n");
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
        return 0;
    }
}






int main()              // Contain 4 cases New user, existing user, About us and exit.
{
    int date=1;
    int b=1,d,a;
    while(b)
    {
        printf("------User login------\n\n1. New User  enter 1 to continue\n2. Existing user    enter 2 to continue\n3. About Us    enter 3 to continue\n4. Exit   enter 4 to continue\n");
        printf("Enter Choice :");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
        case 1:                     //Not using break so that user can directly go to user login.
        {
            system("cls");
            printf("*********Generate new user********\n\n");
            user_gen();
            printf("\n\nDirecting to User login.**Please Wait");
            dot_pattern();
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
            printf("1. Sahil Bhatia\t(601)\n2. Asif Habib\t(602)\n3. Aditya Naitan\t(603)\n4. Harshita Nag\t(604)\n5. Vaishnav Sharma\t(607)\n");
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
            system("cls");
            printf("EXITING");
            dot_pattern();
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






int book()
{
    
printf("Welcome to ASHVA Bus reservation system\n");
printf("_______________________________________\n");
    
    
    
bus:
    printf("Select the bus number(1-5)\n");
    scanf("%d",&c2);
    fflush(stdin);
    
    printf("Please wait");
    dot_pattern();
    system("cls");
    
    printf("Hi Customer!\n");
    switch(c2)
    {
    case 1:
        printf("Welcome to Sahil Travels\n");
        travel();
        break;
    case 2:
        printf("Welcome to Asif Travels\n");
        travel();
        break;
    case 3:
        printf("Welcome to Aditya Travels\n");
        travel();
        break;
    case 4:
        
            printf("Welcome to Harshita Travels\n");
            travel();
            break;

    case 5:
        printf("Welcome to Vaishnav Travels\n");
        travel();
        break;

    default:
    {
        printf("Wrong bus number selected\n");
        printf("Re-directing you");
        dot_pattern();
        goto bus;
        break;
    }
    }
    getch();
    return 0;
}







int travel()
{
    int i,tno,ag[30],se[30];//i will be used as for loop counter to print the ticket
    //tno is unique ticket no.&stores the value((c2*100+s4)+date)*n, where c2 is bus no, s4 is seat no. date is date of travel and n is no. of passengers
    //ag is integer array variable that stores ages of passengers whose booking is being done currently
    char gnd[30];   //gnd is character array variable that stores genders of passengers whose booking is being done currently
    char nam[30][30];   //nam is string array variable that stores names of passengers whose booking is being done currently
    char ch;

    struct t//Structure created to ensure that already booked seat of a specific date(of travelling) and specific bus can't be selected
    {
        int busno;
        int seatno;
        int dno;
        int mno;
        int yrno;
    };
    struct t k,l;
    struct e         
    {
        char name[30];
        int age;
        char gndr;
        int busn;
        int seatn;
        int dn;
        int mn;
        int yrn;
        char un[30];
 };
    struct e a;

    FILE *f4,*fj,*ft;//f4 is file pointer of file"travels.txt" in which seat layout is stored
    //fj is file pointer of file"temp1.txt" in which details  of each passenger+bus,seat and date information is stored
    /*ft is file pointer of file"buseatdate.txt" in which busno,seatno and date(of travelling) which have been booked is stored*/

    int p,s4;//p is just used for checking that while loop works the number of times=no. of passengers
    //s4 will store the seat no.
    char c4,ct;
    printf("Below is the seat layout of this bus. Each number represents a seat of that particular number.\n");
    f4=fopen("buslayout.txt","r");//opening the file that contains the seat layout
    if(f4==NULL) {
        printf("Sorry.There is some problem in the opening of a file.\n");
        exit(0);
    }
    while(1) { 
        c4=fgetc(f4);
        if(c4==EOF)
            break;
        else
            printf("%c",c4);
    }
    fclose(f4);//closing file
    printf("___________________________\n");
    printf("Enter the no. of passengers\n");
    scanf("%d",&n);
    p=n;
    again1:
    printf("Enter the day,month,year when you want to do booking.\n");
        printf("Day(1-30)\n");
        printf("Month(2/3)\n");
        scanf("%d%d%d",&l.dno,&l.mno,&l.yrno);
        if((l.dno>=1&&l.dno<=30)&&(l.mno==2||l.mno==3)&&(l.yrno==2019)) 
        {
        printf("______________________________________________________________________________________________________\n");
    while(p>=1)//loop will terminate if it has executed n times
    {
        ft=fopen("buseatdate.txt","r");//just opening the file that contains bus,seat and date information
        if(ft==NULL) {
            printf("File opening error\n");
            exit(0);
        }
        
                                                                                        
        while(1) {
            ct=fgetc(ft);
            if(ct==EOF)
                break;
            else
            
                printf("%c",ct);       
        }




        fclose(ft);
        printf("_______________________________________________________________________________________________________\n");
        printf("above data contains bus no,seat no and date of travelling of persons who have already made booking\n");
        printf("Make sure that you aren't choosing anyone of them in combination\n");
        printf("_______________________________________________________________________________________________________\n");
       
seat:
      
        
            printf("Enter seat number of passenger no.%d ",(n-p)+1);
            scanf("%d",&s4);
        
        if(s4>=1 && s4<=49)
        {
       ft=fopen("buseatdate.txt","r");
        while(fscanf(ft,"%d\t%d\t%d\t%d\t%d\n",&k.busno,&k.seatno,&k.dno,&k.mno,&k.yrno)!=EOF)
        {
            if((c2==k.busno)&&(s4==k.seatno)&&(l.dno==k.dno)&&(l.mno==k.mno)&&(l.yrno==k.yrno)) {
                printf("The above seat has been already booked.Select an unbooked seat.\n");
                
                
                printf("Re-directing you back");
                 dot_pattern();
                 printf("\n");
                
                goto seat;
            }
        }
        fj=fopen("temp1.txt","a");
        ft=fopen("buseatdate.txt","a");
again://if gender or username is wrong, control comes here
        printf("Enter name,age(1-100),gender of passenger\n");
        scanf("%s %d %c",a.name,&a.age,&a.gndr);
        fflush(stdin);
        if((a.gndr=='M'||a.gndr=='F'||a.gndr=='m'||a.gndr=='F')&&(a.age>=1&&a.age<=100))
         {
                                    a.busn=c2;
                                    a.seatn=s4;
                                    a.dn=l.dno;
                                    a.mn=l.mno;
                                    a.yrn=l.yrno;
                                    strcpy(a.un,m);
            fprintf(fj,"%s\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%s\n",a.name,a.age,a.gndr,a.busn,a.seatn,a.dn,a.mn,a.yrn,a.un);
            fclose(fj);
            l.busno=c2;
            l.seatno=s4;
            fprintf(ft,"%d\t%d\t%d\t%d\t%d\n",l.busno,l.seatno,l.dno,l.mno,l.yrno);

            fclose(ft);
           strcpy(nam[n-p],a.name);
            ag[n-p]=a.age;
            gnd[n-p]=a.gndr;
            se[n-p]=s4;
        }
        else
        {
            printf("Wrong passenger information\n");
            
            dot_pattern();
        goto again;
        }
        }
        else{
printf("Seat number is invalid");
dot_pattern();
goto seat;}
 
        p--;
    }
    
    

    tno=((c2*100+s4)+4*(l.dno)+10*(l.mno)+(l.yrno))*n;
    printf("Booking successful!\n");
    
    printf("...Please wait!...printing your ticket");
    dot_pattern();
    system("cls");//printing ticket
    printf("______________________\n");
    
    printf("Date: %d-%d-%d\n",l.dno,l.mno,l.yrno);
    printf("Ticket number: %d\n",tno);
    printf("Number of passengers:%d\n",n);
    printf("Bus number:%d\n",c2);
    
    
    printf("___________________________________________________________\n");

    for(i=0; i<(n-p); i++)
    {
        
        printf("Name: %s\t",nam[i]);
        printf("age: %d\t ",ag[i]);
        printf("gender: %c\n",gnd[i]);
        printf("Seat no:%d\n",se[i]);
        printf("___________________________________________________________\n");
    }
    printf("Do you want to quit?Press Y/N\n");
    again3:
    ch=getch();
    
    if(ch=='Y' ||ch=='y')
         {
               
    printf("\nThankyou for using our bus reservation system. Visit again!\n");
    Sleep(1000);
    system("cls");
    printf("EXITING");
    dot_pattern();
    
    Sleep(1000);
           system("cls");
           exit(0);
           }
            
            else if(ch=='N' || ch=='n')
            {
                 Sleep(1000);
                 system("cls");
                 printf("Please wait");
                 dot_pattern();
                 system("cls");
                 booking();
                 } 
                 
                 else
                 {
                 printf("Wrong choice.Enter again.Press Y/N \n");
                 goto again3;
                 }
    
}
else
{
    printf("Incorrect date information\nRedirecting you to enter the date again\n");
    printf("******Please Wait");
    
            dot_pattern();
    
    goto again1;
}
    
    getch();
    return 0;
}







int  cancel()
{
     printf("Cancel your booking here\n");
     printf("________________________\n");
     int k=0,j=0,x=1,y=1;
    char another,ch;
    FILE *fj,*fh,*ft,*fi;
    struct t
    {
        int busno;
        int seatno;
        int dno;
        int mno;
        int yrno;
    };
    struct t l;
    struct e
    {
        char name[30];
        int age;
        char gndr;
        int busn;
        int seatn;
        int dn;
        int mn;
        int yrn;
        char un[30];
    };
    struct e a,b;
    another='Y';
    while(another=='Y')
    {
   
        fj=fopen("temp1.txt","r");
         fh=fopen("temp2.txt","a");
        ft=fopen("buseatdate.txt","r");
         fi=fopen("tbuseatdate.txt","a");
        
   
       printf("\nEnter name,age,gender,bus no, seat no,date of travelling of passenger whose ticket you want to cancel\n");
        printf("Date should be entered in the format day month year\n");
        scanf("%s %d %c %d %d %d %d %d",b.name,&b.age,&b.gndr,&b.busn,&b.seatn,&b.dn,&b.mn,&b.yrn);

        
        while(fscanf(fj,"%s\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%s\n",a.name,&a.age,&a.gndr,&a.busn,&a.seatn,&a.dn,&a.mn,&a.yrn,a.un)!=EOF)
        {
            if((!strcmp(a.name,b.name))&&(a.age==b.age)&&(a.gndr==b.gndr)&&(a.busn==b.busn)&&(a.seatn==b.seatn)&&(a.dn==b.dn)&&(a.mn==b.mn)&&(a.yrn==b.yrn)&&!strcmp(m,a.un))
            k++;
            
            
            }
            fclose(fj);
            if(k==1)
            {
                   fj=fopen("temp1.txt","r");  
            while(fscanf(fj,"%s\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%s\n",a.name,&a.age,&a.gndr,&a.busn,&a.seatn,&a.dn,&a.mn,&a.yrn,a.un)!=EOF)
            
        {
            if(!((!strcmp(a.name,b.name))&&(a.age==b.age)&&(a.gndr==b.gndr)&&(a.busn==b.busn)&&(a.seatn==b.seatn)&&(a.dn==b.dn)&&(a.mn==b.mn)&&(a.yrn==b.yrn)))
            {
                                                                                                                                                               
                                                                                                                                         
                fprintf(fh,"%s\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%s\n",a.name,a.age,a.gndr,a.busn,a.seatn,a.dn,a.mn,a.yrn,a.un);
            l.seatno=a.seatn;
            l.busno=a.busn;
            l.dno=a.dn;
            l.mno=a.mn;
            l.yrno=a.yrn;
            fprintf(fi,"%d\t%d\t%d\t%d\t%d\n",l.busno,l.seatno,l.dno,l.mno,l.yrno);
            }
            }
            
            fclose(fj);
            fclose(fi);
            fclose(ft);
            fclose(fh);
            x= remove("temp1.txt");
            y=remove("buseatdate.txt");
            
            rename("temp2.txt","temp1.txt");
            rename("tbuseatdate.txt","buseatdate.txt");
            if(x==0&&y==0){
            printf("cancellation successful!!\n");}
            else{
            printf("ops!\n");}
            Sleep(3000);
            
            
            
            
            
            }
            else
            {
            printf("The details of the passenger entered by you do not exist. Enter correct information\n");
             printf("Re directing you to homepage...***Please wait***\n");
          Sleep(3000);
          system("cls");
      booking();
            }
            k=0;
            system("cls");
        printf("Do you want to cancel one more ticket?Y/N\n");
        another=getche();
        Sleep(1500);
        
        
    }
    
    
    
    printf("Do you want to quit?Press Y/N\n");
    again3:
    ch=getch();
    
    if(ch=='Y' ||ch=='y')
         {
    printf("\nThankyou for using our bus reservation system. Visit again!\n");
    Sleep(1000);
    system("cls");
    printf("EXITING");
    dot_pattern();
    Sleep(4000);
           system("cls");
           exit(0);
           }
            
            else if(ch=='N' || ch=='n')
            {
                 printf("\nPlease wait");
                 dot_pattern();
                 system("cls");
                 booking();
                 } 
                 
                 else
                 {
                 printf("Wrong choice.Enter again.Press Y/N \n");
                 goto again3;
                 }
                 
   
   
   
    getch();
    return 0;
}





 int dot_pattern()
 {
     int i;
     for(i=1;i<=10;i++)
     {
                      printf(".");
                      Sleep(180);
                      }
                      
                      return 0;
                      }
                      












