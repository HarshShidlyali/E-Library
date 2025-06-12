#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E_LIB "E-Library.txt"
char author[1000][1000],book_name[1000][1000],author_name[1000];
int pages[1000],i;
float price[1000];
int Get_info,count=0;
void load_data() {
    FILE *LIB = fopen(E_LIB, "r");
    if (LIB == NULL) {
        return; 
    }

    while (fscanf(LIB, "%s %s %d %f", book_name[count], author[count], &pages[count], &price[count]) == 4) {
        count++;
    }

    fclose(LIB);
}
void save_data() {
    FILE *LIB = fopen(E_LIB, "w");
    if (LIB == NULL) {
        printf("Error saving data!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(LIB, "%s %s %d %.2f\n", book_name[i], author[i], pages[i], price[i]);
    }

    fclose(LIB);
}
int main()
{
    load_data();
    while (1)
    {
        printf("\n\n*****""\t""WELCOME TO E-LIBRARY ""\t""*****\n");
        printf("\n\n1. Add book information\n");
        printf("2. Number of books in the library\n");
        printf("3. All books of given Author\n");
        printf("4. View all books in the Library\n");
        printf("5. Exit\n\n");
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
            count++;
            save_data();
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
            if(count==0)
            {
                printf("\nSorry! No books are available in the Library");
            }
            else
            {
                printf("\n\nList of the books in the Library\n");
                for(i=0;i<count;i++)
                {
                    printf("\nBook Name : %s",book_name[i]);
                    printf("\nAuthor name = %s\n\n", author[i]);
                }
            }
        }
        else if(Get_info==5)
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
