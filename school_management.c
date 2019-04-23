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
//sarthak starts
int password()
 
{
 
        char pass[15]={0},check[15]={0},ch;
 
        FILE *fpp;
 
        int i=0,j;
 
        printf("::FOR SECURITY PURPOSE::");
 
        printf("::ONLY THREE TRIALS ARE ALLOWED::");
 
        for(j=0;j<3;j++)
 
        {
 
                        i=0;
 
                        printf("\n\n\tENTER THE PASSWORD:");
 
                        pass[0]=getch();
 
                        while(pass[i]!='\r')
 
                        {
 
                            if(pass[i]=='\b')
 
                            {
 
                                i--;
 
                                printf("\b");
 
                                printf(" ");
 
                                printf("\b");
 
                                pass[i]=getch();
 
                            }
 
                            else
 
                            {
 
                                printf("*");
 
                                i++;
 
                                pass[i]=getch();
 
                            }
 
                        }
 
                        pass[i]='\0';
 
                        fpp=fopen("SE","r");
 
                        if (fpp==NULL)
 
                        {
 
                            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
 
                            getch();
 
                            return 1;
 
                        }
 
                        else
 
                        i=0;
 
                        while(1)
 
                        {
 
                            ch=fgetc(fpp);
 
                            if(ch==EOF)
 
                            {
 
                                check[i]='\0';
 
                                break;
 
                            }
 
                            check[i]=ch-5;
 
                            i++;
 
                        }
 
                        if(strcmp(pass,check)==0)
 
                        {
 
                            printf("\n\n\tACCESS GRANTED...\n");
 
                            return 0;
 
                        }
 
                        else
 
                        {
 
                            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
 
                        }
 
        }
 
        printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");
 
        getch();
 
        return 1;
 
}
//sarthak ends

