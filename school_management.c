#include<stdio.h>
 
#include<stdlib.h>
 
#include<conio.h>
 
#include<string.h>
//header files//
 
int password();
 
void addrecord();
 
void viewrecord();
 
void editrecord();
 
void editpassword();
 
void deleterecord();
 //functions initialisations//
struct record
 
{
 //variables initialisations//
    char time[6];
 
    char name[30];
 
    char place[25];
 
    char duration[10];
 
    char note[500];
 
} ;//structure completed//
 
int main()//main function//
 
{
 
    int ch;//variable declaration//
 
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
 
            switch(ch)//switch case//
 
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

//sarthak starts
void addrecord( )
 
{
 
                system("cls");
 
                FILE *fp ;
 
                char another = 'Y' ,time[10];
 
                struct record e ;
 
                char filename[15];
 
                int choice;
 
                printf("\n\n\t\t***************************\n");
 
                printf("\t\t* WELCOME TO THE ADD MENU *");
 
                printf("\n\t\t***************************\n\n");
 
                printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");
 
                fflush(stdin);
 
                gets(filename);
 
                fp = fopen (filename, "ab+" ) ;
 
                if ( fp == NULL )
 
                {
 
                fp=fopen(filename,"wb+");
 
                if(fp==NULL)
 
                {
 
                    printf("\nSYSTEM ERROR...");
 
                    printf("\nPRESS ANY KEY TO EXIT");
 
                    getch();
 
                    return ;
 
                }
 
                }
 
                while ( another == 'Y'|| another=='y' )
 
                {
 
                    choice=0;
 
                    fflush(stdin);
 
                printf ( "\n\tENTER TIME:[hh:mm]:");
 
                scanf("%s",time);
 
                rewind(fp);
 
                while(fread(&e,sizeof(e),1,fp)==1)
 
                {
 
                    if(strcmp(e.time,time)==0)
 //if statement//
                    {
 
                        printf("\n\tTHE RECORD ALREADY EXISTS.\n");
 
                        choice=1;
 
                    }
 
                }
 
                    if(choice==0)
 
                    {
 
                        strcpy(e.time,time);
 
                        printf("\tENTER NAME:");
 
                        fflush(stdin);
 
                        gets(e.name);
 
                        fflush(stdin);
 
                        printf("\tENTER PLACE:");
 
                        gets(e.place);
 
                        fflush(stdin);
 
                        printf("\tENTER DURATION:");
 
                        gets(e.duration);
 
                        fflush(stdin);
 
                        printf("\tNOTE:");
 
                        gets(e.note);
 
                        fwrite ( &e, sizeof ( e ), 1, fp ) ;
 
                        printf("\nYOUR RECORD IS ADDED...\n");
 
                    }
 
                        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;
 
                        fflush ( stdin ) ;
 
                        another = getchar( ) ;
 
                }
 
                fclose ( fp ) ;
 
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
 
                getch();
 
    }
//sarthak ends

//maulik starts
void editrecord()

{

        system("cls");

        FILE *fpte ;

       struct record customer ;

        char time[6],choice,filename[14];

        intnum,count=0;

printf("\n\n\t\t*******************************\n");

printf("\t\t* WELCOME TO THE EDITING MENU *");

printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=0)//if statement//

        {

            return ;

        }

        do

        {

           printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");

           fflush(stdin);

            gets(filename);

            printf("\n\tENTER TIME:[hh:mm]:");

                    gets(time);

           fpte = fopen( filename, "rb+" ) ;

                    if ( fpte == NULL )

                    {//if statement//

                         printf( "\nRECORD DOES NOT EXISTS:" ) ;

                         printf("\nPRESS ANY KEY TO GO BACK");

                         getch();

                         return;

                      }

          while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

           {

                if(strcmp(customer.time,time)==0)

               {

                   printf("\nYOUR OLD RECORD WAS AS:");

                   printf("\nTIME: %s",customer.time);

                   printf("\nMEETING WITH: %s",customer.name);

                   printf("\nMEETING AT: %s",customer.place);

                   printf("\nDURATION: %s",customer.duration);

                   printf("\nNOTE: %s",customer.note);

                   printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                  printf("\n1.TIME.");

                   printf("\n2.MEETING PERSON.");

                   printf("\n3.MEETING PLACE.");

                   printf("\n4.DURATION.");

                   printf("\n5.NOTE.");

                   printf("\n6.WHOLE RECORD.");

                   printf("\n7.GO BACK TO MAIN MENU.");

                do
//do while statement//
               {

                   printf("\n\tENTER YOUR CHOICE:");

                   fflush(stdin);

                   scanf("%d",&num);

                   fflush(stdin);

                   switch(num)//switch case//

                   {

                        case 1: printf("\nENTER THE NEW DATA:");

                                printf("\nNEW TIME:[hh:mm]:");

                                gets(customer.time);
                                break;

                        case 2: printf("\nENTER THE NEW DATA:");

                                printf("\nNEW MEETING PERSON:");

                                gets(customer.name);
                                break;

                        case 3: printf("\nENTER THE NEW DATA:");

                                printf("\nNEW MEETING PLACE:");

                                gets(customer.place);
                                break;

                        case 4: printf("\nENTER THE NEW DATA:");

                                  printf("\nDURATION:");
                     
                                  gets(customer.duration);
                                                break;

                        case 5: printf("ENTER THE NEW DATA:");

                                printf("\nNOTE:");

                                gets(customer.note);
                                        break;

                        case 6:  printf("\nENTER THE NEW DATA:");

                                 printf("\nNEW TIME:[hh:mm]:");

                                  gets(customer.time);

                                  printf("\nNEW MEETING PERSON:");

                                   gets(customer.name);

                                   printf("\nNEW MEETING PLACE:");

                                    gets(customer.place);

                                    printf("\nDURATION:");

                                     gets(customer.duration);

                                     printf("\nNOTE:");

                                       gets(customer.note);

                                                     break;

                          case 7: printf("\nPRESS ANY KEY TO GO BACK...\n");

                                  getch();

                                  return ;

                                   break;

                        default: printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                                                 break;

                   }

}while(num<1||num>8);

fseek(fpte,-sizeof(customer),SEEK_CUR);

fwrite(&customer,sizeof(customer),1,fpte);

fseek(fpte,-sizeof(customer),SEEK_CUR);

fread(&customer,sizeof(customer),1,fpte);
                 choice=5;

                   break;

                        }

                    }

                    if(choice==5)

                    {

                        system("cls");

                        printf("\n\t\tEDITING COMPLETED...\n");

                        printf("--------------------\n");

                        printf("THE NEW RECORD IS:\n");

                        printf("--------------------\n");

                        printf("\nTIME: %s",customer.time);

                        printf("\nMEETING WITH: %s",customer.name);

                        printf("\nMEETING AT: %s",customer.place);

                        printf("\nDURATION: %s",customer.duration);

                        printf("\nNOTE: %s",customer.note);

                        fclose(fpte);

                        printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");

                        scanf("%c",&choice);

                          count++;

                    }

                    else

                    {

                       printf("\nTHE RECORD DOES NOT EXIST::\n");

                       printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

                       scanf("%c",&choice);

                    }

}while(choice=='Y'||choice=='y');

fclose( fpte ) ;

            if(count==1)

                printf("\n%d FILE IS EDITED...\n",count);

            else if(count>1)

                printf("\n%d FILES ARE EDITED..\n",count);

            else

                printf("\nNO FILES EDITED...\n");

                 printf("\tPRESS ENTER TO EXIT EDITING MENU.");

getch();

}
//maulik ends//
