#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
int login(char username[20], char passwords[10])
{
    if (strcmp(username, "royal") &&strcmp(passwords, "123456"))
    {
        return 1;
    }
    else
        return 0;
}
struct item
{
    char name[40];
    int qty;
    float price;
};
struct item s;
char productname[40];
long int recsize;
int department() {
    int d;
    printf("\n\nHello Mr.Narasimha, Welcome to HOMESCREEN\n\nChoose which department do you want to access ?\n\n#Enter Number 1 for Laptops Department\n#Enter Number 2 for Cellphones Department\n#Enter Number 3 for Computer Department");
    printf("\n\n Please enter your choice :- ");
    scanf("%d", &d);
    return d;
}
int main()
{
    FILE* fp, * ft;
    int i = 0, r = 0, count = 0;
    char username[25], passwords[8], ch, another, choice;
logout:
    fflush(stdin);
    count = 0;
    printf("\t\t\t\t\t\t\t\t\t\t\t===========================================\n\t\t\t\t\t\t\t\t\t\t\t\t*WELCOME TO WAREHOUSE EXCHANGE*\n\t\t\t\t\t\t\t\t\t\t\t===========================================");
    printf("\t\t\t\t\t\t\t\t\t                                                        \n\t\t\t\t\t\t\t   TO ACCESS THE SYSTEM, PLEASE YOU NEED TO LOGIN FIRST \n\t\t\t\t\t\t\t   ===================================================");
    printf("\t\t\t\t\t\n\t");

    do {

        printf("\t\t\t\t\t           Enter Your Username:");
        scanf("%*[\n]");
        fgets(username, 10, stdin);
        username[10] = '\0';
        printf("\n\t\t\t\t\t\t\t   Enter Your Password:");
        for (i = 0;i < 7;i++)
        {
            passwords[i] = _getch();
            printf("*");
        }
        passwords[i] = '\0';
        r = login(username, passwords);
        count++;
        if (r) {
            printf("\n\t\t\t\t\t\t\t   ==============================================                                             \n\n\t\t\t\t\t\t\t\t\t#ACCESS GRANTED#\n\n\n");
            break;
        }
        else
            printf("\n\n\t\t\t\t\t\tWRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN :<\n\n\n\n");
    } while (count != 3);
    if (count == 3)
    {
        printf("\n\n/////ALL LOGIN ATTEMPTS FAILED.....PLEASE RESTART THE PROGRAM/////");
        _getch();
        return 0;
    }

switch (department()){
    struct item i;

        system("cls");
    case 1:
        fp = fopen("Elec.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("Elec.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);
        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t\t*WELCOME TO LAPTOPS DEPARTMENT'S*\n\t\t\t\t\t\t\t   **********************************************\n\n");
            printf("1. Add new laptop item\n");

            printf("2. Show all laptop items available\n");

            printf("3. Modify Records\n");

            printf("4. Delete Records\n");

            printf("5. Go to main menu :\n");

            printf("Your Choice : ");
            fflush(stdin);
            choice = _getch();
            switch (choice)
            {

            case '1':

                system("cls");
                fseek(fp, 0, SEEK_END);
                another = 'y';
                while (another == 'y')
                {
                    printf("____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)-> Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)-> %s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)-> Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n**Add another record ??---(y/n)** ");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                    printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t####################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                _getch();
                break;

            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter itemm's name, which is to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n)->Enter new name,quantity and price :-\n");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\n**Modify another record??...(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\nEnter name of item to be deleted : ");
                    scanf("%s", productname);
                    ft = fopen("Temp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Elec.txt");
                    rename("Temp.txt", "Elec.txt");
                    fp = fopen("Elec.txt", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }

    case 2:
        fp = fopen("BOOK.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("BOOK.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }


        recsize = sizeof(i);

        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   #####################################################\n\t\t\t\t\t\t\t\t*WELCOME TO CELLPHONES DEPARTMENT'S DATABASE*\n\t\t\t\t\t\t\t\t   #####################################################\n\n");
            printf("1. Add new cellphone item to Stock\n");

            printf("2. Show all available cellphones\n");
            printf("3. Modify Records\n");

            printf("4. Delete cellphones\n");

            printf("5. Exit\n\n");

            printf(")>Your Choice : ");
            fflush(stdin);
            choice = _getch();
            switch (choice)
            {
            case '1':
                system("cls");
                fseek(fp, 0, SEEK_END);

                another = 'y';
                while (another == 'y')
                {
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n  %s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n**Add another record?....(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t#####################################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                _getch();
                break;
            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter item's name, which is to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n)->Enter new name,quantity and price :- \n");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\n**Modify another record?...(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)->Enter name of book to be deleted: ");
                    scanf("%s", productname);
                    ft = fopen("Temp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("BOOK.txt");
                    rename("Temp.txt", "BOOK.txt");
                    fp = fopen("BOOK.txt", "rb+");
                    printf("Delete another record?...(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }
    case 3:
        fp = fopen("SP.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("SP.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);
        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   #####################################################\n\t\t\t\t\t\t\t*WELCOME TO COMPUTER DEPARTMENTS DATABASE*\n\t\t\t\t\t\t\t   #####################################################\n\n");
            printf("1. Add New Computer item to Stock\n");

            printf("2. Show all available computers\n");

            printf("3. Modify Records\n");

            printf("4. Delete items\n");

            printf("5. Exit\n");

            printf(")>Your Choice : ");
            fflush(stdin);
            choice = _getch();
            switch (choice)
            {
            case '1':
                system("cls");
                fseek(fp, 0, SEEK_END);


                another = 'y';
                while (another == 'y')
                {
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)>%s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\nAdd another record?...(y/n) ");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t#####################################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                _getch();
                break;

            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("Enter equipment's name, whose details are to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\nEnter new name,quantity and price :- ");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)>Enter name of item to be deleted: ");
                    scanf("%s", productname);
                    ft = fopen("Temp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("SP.txt");
                    rename("Temp.txt", "SP.txt");
                    fp = fopen("SP.txt", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }
    default:
        printf("\n\nUNEXPECTED INPUT DETECTED\nREDIRECTING TO LOGIN PAGE.........................................");
        _getch();
        goto logout;
    }
    _getch();
    return 0;
}





