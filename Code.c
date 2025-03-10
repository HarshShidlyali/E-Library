#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char author[100][100],book_name[100][100],author_name[100];
    int pages[100],i;
    float price[100];
    int Get_info,count=0;
    while (1)
    {
        printf("\n\n*****""\t""WELCOME TO E-LIBRARY ""\t""*****\n");
        printf("\n\n1. Add book information\n");
        printf("2. Number of books in the library\n");
        printf("3. All books of given Author\n");
        printf("4. Exit\n\n");
        printf("Enter the Choice : ");
        scanf("%d",&Get_info);
        printf("\nYou have choosen : %d",Get_info);
        if(Get_info==1)
        {
            printf("\n\nEnter book name = ");
            scanf("%s", book_name[count]);
            printf("Enter author name = ");
            scanf("%s", author[count]);
            printf("Enter pages = ");
            scanf("%d", &pages[count]);
            printf("Enter price = ");
            scanf("%f", &price[count]);
            count++;
            printf("\n\n");
            printf("***** The Information of book you have entered *****");
            printf("\nName of the Book : %s",book_name[count-1]);
            printf("\nName of the Author : %s",author[count-1]);
            printf("\nNumber of Pages : %d",pages[count-1]);
            printf("\nBook Price : %f",price[count-1]);
        }
        else if(Get_info==2)
        {
            printf("\n\nNumber of Books in the library : %d ",count);
        }
        else if(Get_info==3)
        {
            printf("\n\nEnter Author's name: ");
            scanf("%s", author_name);
            int ar_find = 0;
            for (i = 0; i < count; i++) {
                if (strcmp(author_name, author[i]) == 0) 
                {
                    printf("\nName of the Book = %s\n", book_name[i]);
                    printf("Author name = %s\n", author[i]);
                    printf("Number of Pages = %d\n", pages[i]);
                    printf("Price of the Book = %f\n", price[i]);
                    ar_find = 1;
                }
            }
            if (!ar_find) 
            {
                printf("No books found by the author %s\n", author_name);
            }
        }
        else if(Get_info==4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Input !");
        }
    }
    return 0;
}
