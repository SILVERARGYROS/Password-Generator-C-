#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
    srand(time(NULL));
    int i, n, *password, lettertype, digits, spcharacters, lowercase, casesensitive, flag, num, uppercase;
    char choice;
    do
    {
        while((choice = getchar()) != '\n' && choice != EOF);
        system("tput clear");
        printf("Please enter the number of characters: ");
        scanf("%d", &n);
        password = (int*) malloc (sizeof(int)*n);
        system("tput clear");
        printf("Case Sensitive?? (1 == yes || 0 == no): ");
        do
        {
            scanf("%d", &casesensitive);
            if(casesensitive != 1 && casesensitive != 0)
            {
                printf("Wrong input! Please type again: ");
            }
        }while(casesensitive != 1 && casesensitive != 0);
        if(!casesensitive)
        {
            printf("Capital or Lower case letters ?? (1 == Capital || 0 == Lower case): ");
            do
            {
                scanf("%d", &lettertype);
                if(lettertype != 1 && lettertype != 0)
                {
                    printf("Wrong input! Please type again: ");
                }
            }while(lettertype != 1 && lettertype != 0);
            uppercase = lettertype;
            lowercase = 1 - lettertype;
        }
        else
        {
            uppercase = 1;
            lowercase = 1;
        }
        system("tput clear");
        printf("Digits?? (1 == yes || 0 == no): ");
        do
        {
            scanf("%d", &digits);
            if(digits != 1 && digits != 0)
            {
                printf("Wrong input! Please type again: ");
            }
        }while(digits != 1 && digits != 0);
        
        system("tput clear");
        printf("Special characters?? (1 == yes || 0 == no): ");
        do
        {
            scanf("%d", &spcharacters);
            if(spcharacters != 1 && spcharacters != 0)
            {
                printf("Wrong input! Please type again: ");
            }
        }while(spcharacters != 1 && spcharacters != 0);
        
        system("tput clear");
        do
        {    
            while((choice = getchar()) != '\n' && choice != EOF);
            for(i = 0;i < n; i++)
            {
                flag = 0;
                do
                {
                    num = rand() % 123;
                    if(num == 33 || num == 35 || num == 36 || num == 37 || num == 38 || num == 42 || num == 47 || num == 63|| num == 92 || num == 43 || num == 45 || num == 64|| num == 92 || num == 94 || num == 126)        //special characters
                    {
                        flag = spcharacters;
                    }
                    else if(num >= 48 && num <= 57)   //digits
                    {
                        flag = digits;
                    }
                    else if(num >= 65 && num <= 90)   //uppercase
                    {
                        flag = uppercase;
                    }
                    else if(num >= 97 && num <= 122)  //lowercase
                    {
                        flag = lowercase;
                    }
                }while(flag != 1);
                password[i] = num;
            }
            printf("New Password: ");
            for(i = 0; i < n; i++)
            {
                printf("%c", password[i]);
            }
            printf("\n");
            printf("\nIf you want a different password press 1");
            printf("\nIf you want to change settings press 2");
            printf("\nIf you want to terminate the programm press any other key\n");
            choice = getchar();
            system("tput clear");
        }while(choice == '1');
        free(password);
    }while(choice == '2');
    return 0;
}