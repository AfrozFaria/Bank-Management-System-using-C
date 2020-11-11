#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Register();
void Login();
void Deposit();
void Withdraw();
void Logout();

struct Account
{
    char user[30];
    char password[15];


} acc;



void Register()
{
    FILE *p;
    p=fopen("ATMlogin.txt","a+");

    printf("Enter username to Register: ");
    scanf("%s",&acc.user);

    printf("\nEnter the Password: ");
    scanf("%s",&acc.password);

    fprintf(p,"USER\tPassword\n%s\t%s\n",acc.user,acc.password);

    fclose(p);
    printf("SUCCESSFULLY REGISTERED YOUR ACCOUNT!");
    printf("\nPress any key to LOGIN");
    getch();
    system("CLS");
    Login();



}
void Login()
{
    char user[30],password[15];
    FILE *p;
    p= fopen("ATMlogin.txt","r");
    printf("\t\t\t\t\tUSER ID : ");
    scanf("%s",&user);
    printf("\t\t\t\t\tPASSWORD: ");
    scanf("%s",&password);


    while(fread(&acc,sizeof(acc),1,p))
    {
        if(strcmp(user,acc.user)==0 && strcmp(password,acc.password)==0)
        {
            printf("LOGIN IS SUCCESSFUL");
        }
        else
        {
            printf("INCORRECT USERNAME AND PASSWORD!\nTRY AGAIN!");
        }

    }

    fclose(p);
}
FILE *p2;
float  balance1=0.00;

void Deposit()
{

    p2=fopen("Balance.txt","a+");
    float balance2;

    printf("\n\n\tENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
    scanf("%f",&balance2);


    balance1=balance1+balance2;
    printf("\nSuccessfully Deposited!");

    fprintf(p2,"%.2f\n",balance1);
    fclose(p2);
    printf("\nPress any key to continue...");
    getch();
    system("CLS");

}
void Withdraw()
{
    float balance,balance2,balance3;


    p2=fopen("Balance.txt","r");
    fscanf(p2,"%f",&balance1);
    fclose(p2);

    printf("\nENTER THE AMOUNT YOU WANT TO WITHDRAW: ");
    scanf("%f",&balance2);;
    if(balance1>=balance2)
    {
        balance3=balance1-balance2;
        p2=fopen("Balance.txt","w");
        fprintf(p2,"BALANCE:\n%.2f\n",balance3);
        fclose(p2);
        system("CLS");
    }
    else
    {
        printf("\nINSUFFICIENT BALANCE!");
    }

    system("CLS");



}


void Logout()
{


    main();

}

void main()
{

    int option;

    do
    {


        printf("\n******************Hello!*******************\n");
        printf("\n**********Welcome to ATM Banking***********\n\n");
        printf("****Please choose one of the options below****\n\n");
        printf("< 1 >  REGISTER\n");
        printf("< 2 >  LOGIN\n");
        printf("< 3 >  MONEY DEPOSIT\n");
        printf("< 4 >  MONEY WITHDRAW\n");
        printf("< 5 >  LOGOUT\n\n");


        printf("Select Your Option:\t");
        scanf("%d", &option);


        switch (option)
        {
        case 1:

            Register();
            break;
        case 2:
            Login();
            break;

        case 3:

            Deposit();
            break;

        case 4:
            Withdraw();
            break;
        case 5:
            Logout();
            break;


        case 0:
            exit(0);
            break;



        default:
            printf("\n!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!\n!!!!!!!!!!!!TRY AGAIN!!!!!!!!!!!!!!\n");
            break;
        }

    }
    while(option!=0);
}








