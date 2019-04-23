#include<stdio.h>
 
#include<stdlib.h>
 
#include<conio.h>
 
#include<string.h>
 
int password();
 
void addrecord();
 
void viewrecord();
 
void editrecord();
 
void editpassword();
 
void deleterecord();
 
struct record
 
{
 
    char time[6];
 
    char name[30];
 
    char place[25];
 
    char duration[10];
 
    char note[500];
 
} ;
 
int main()
 
{
 
    int ch;
 
    printf("\n\n\t***********************************\n");
 
    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");
 
    printf("\t***********************************");
 
   while(1)
 
        {
 
                printf("\n\n\t\tMAIN MENU:");
 
                printf("\n\n\tADD RECORD\t[1]");
 
                printf("\n\tVIEW RECORD\t[2]");
 
                printf("\n\tEDIT RECORD\t[3]");
 
                printf("\n\tDELETE RECORD\t[4]");
 
                printf("\n\tEDIT PASSWORD\t[5]");
 
                printf("\n\tEXIT\t\t[6]");
 
                printf("\n\n\tENTER YOUR CHOICE:");
 
                scanf("%d",&ch);
 
            switch(ch)
 
                    {
 
                            case 1:
 
                            addrecord();
 
                            break;
 
                            case 2:
 
                            viewrecord();
 
                            break;
 
                            case 3:
 
                            editrecord();
 
                            break;
 
                            case 4:
 
                            deleterecord();
 
                            break;
 
                            case 5:
 
                            editpassword();
 
                            break;
 
                            case 6:
 
                            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE BY:\n\n\tBIJAY PURI\n\n\tBHANU POUDEL\n\n\tNRIPASH AYER...");
 
                            getch();
 
                            exit(0);
 
                            default:
 
                            printf("\nYOU ENTERED WRONG CHOICE..");
 
                            printf("\nPRESS ANY KEY TO TRY AGAIN");
 
                            getch();
 
                            break;
 
                    }
 
                system("cls");
 
        }
 
            return 0;
 
}
//krishan ends

void viewrecord( )
 
{
 
        FILE *fpte ;
 
        system("cls");
 
        struct record customer ;
 
        char time[6],choice,filename[14];
 
        int ch;
 
        printf("\n\n\t\t*******************************\n");
 
        printf("\t\t* HERE IS THE VIEWING MENU *");
 
        printf("\n\t\t*******************************\n\n");
 
        choice=password();
 
        if(choice!=0)
 
            {
 
                return ;
 
            }
 
        do
 
            {
 
                    printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");
 
                    fflush(stdin);
 
                    gets(filename);
 
                    fpte = fopen ( filename, "rb" ) ;
 
                    if ( fpte == NULL )
 
                            {
 
                                puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
 
                                printf("PRESS ANY KEY TO EXIT...");
 
                                getch();
 
                                return ;
 
                            }
 
                            system("cls");
 
                printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");
 
                printf("\n\t1.WHOLE RECORD OF THE DAY.");
 
                printf("\n\t2.RECORD OF FIX TIME.");
 
                printf("\n\t\tENTER YOUR CHOICE:");
 
                scanf("%d",&ch);
 
                switch(ch)
 
                {
 
                    case 1:
 
                            printf("\nTHE WHOLE RECORD FOR %s IS:",filename);
 
                         while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
 
                         {
 
                            printf("\n");
 
                            printf("\nTIME: %s",customer.time);
 
                            printf("\nMEETING WITH: %s",customer.name);
 
                            printf("\nMEETING AT: %s",customer.place);
 
                            printf("\nDURATION: %s",customer.duration);
 
                            printf("\nNOTE: %s",customer.note);
 
                            printf("\n");
 
                         }
 
                         break;
 
                    case 2:
 
                            fflush(stdin);
 
                            printf("\nENTER TIME:[hh:mm]:");
 
                            gets(time);
 
                            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
 
                            {
 
                                if(strcmp(customer.time,time)==0)
 
                                {
 
                                    printf("\nYOUR RECORD IS:");
 
                                    printf("\nTIME: %s",customer.time);
 
                                    printf("\nMEETING WITH: %s",customer.name);
 
                                    printf("\nMEETING AT: %s",customer.place);
 
                                    printf("\nDUARATION: %s",customer.duration);
 
                                    printf("\nNOTE: %s",customer.note);
 
                                }
 
                            }
 
                            break;
 
                    default: printf("\nYOU TYPED SOMETHING ELSE...\n");
 
                             break;
 
                }
 
               printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
 
               fflush(stdin);
 
            scanf("%c",&choice);
 
        }while(choice=='Y'||choice=='y');
 
            fclose ( fpte ) ;
 
            return ;
 
}

void viewrecord( )
 
{
 
        FILE *fpte ;
 
        system("cls");
 
        struct record customer ;
 
        char time[6],choice,filename[14];
 
        int ch;
 
        printf("\n\n\t\t*******************************\n");
 
        printf("\t\t* HERE IS THE VIEWING MENU *");
 
        printf("\n\t\t*******************************\n\n");
 
        choice=password();
 
        if(choice!=0)
 
            {
 
                return ;
 
            }
 
        do
 
            {
 
                    printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");
 
                    fflush(stdin);
 
                    gets(filename);
 
                    fpte = fopen ( filename, "rb" ) ;
 
                    if ( fpte == NULL )
 
                            {
 
                                puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
 
                                printf("PRESS ANY KEY TO EXIT...");
 
                                getch();
 
                                return ;
 
                            }
 
                            system("cls");
 
                printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");
 
                printf("\n\t1.WHOLE RECORD OF THE DAY.");
 
                printf("\n\t2.RECORD OF FIX TIME.");
 
                printf("\n\t\tENTER YOUR CHOICE:");
 
                scanf("%d",&ch);
 
                switch(ch)
 
                {
 
                    case 1:
 
                            printf("\nTHE WHOLE RECORD FOR %s IS:",filename);
 
                         while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
 
                         {
 
                            printf("\n");
 
                            printf("\nTIME: %s",customer.time);
 
                            printf("\nMEETING WITH: %s",customer.name);
 
                            printf("\nMEETING AT: %s",customer.place);
 
                            printf("\nDURATION: %s",customer.duration);
 
                            printf("\nNOTE: %s",customer.note);
 
                            printf("\n");
 
                         }
 
                         break;
 
                    case 2:
 
                            fflush(stdin);
 
                            printf("\nENTER TIME:[hh:mm]:");
 
                            gets(time);
 
                            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
 
                            {
 
                                if(strcmp(customer.time,time)==0)
 
                                {
 
                                    printf("\nYOUR RECORD IS:");
 
                                    printf("\nTIME: %s",customer.time);
 
                                    printf("\nMEETING WITH: %s",customer.name);
 
                                    printf("\nMEETING AT: %s",customer.place);
 
                                    printf("\nDUARATION: %s",customer.duration);
 
                                    printf("\nNOTE: %s",customer.note);
 
                                }
 
                            }
 
                            break;
 
                    default: printf("\nYOU TYPED SOMETHING ELSE...\n");
 
                             break;
 
                }
 
               printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
 
               fflush(stdin);
 
            scanf("%c",&choice);
 
        }while(choice=='Y'||choice=='y');
 
            fclose ( fpte ) ;
 
            return ;
 
}
