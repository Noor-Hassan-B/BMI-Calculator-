#include <stdio.h>
#include <string.h>

#define TABLES 10

struct Table
{
    int tableNo;
    int booked;
    char customerName[30];
};

struct Table hotel[TABLES];

// Function to initialize all tables
void initializeTables()
{
    int i;

    for(i = 0; i < TABLES; i++)
    {
        hotel[i].tableNo = i + 1;
        hotel[i].booked = 0;
        strcpy(hotel[i].customerName, "None");
    }
}

// Display all tables
void displayTables()
{
    int i;

    printf("\n------------ TABLE STATUS ------------\n");

    for(i = 0; i < TABLES; i++)
    {
        printf("Table %d : ", hotel[i].tableNo);

        if(hotel[i].booked == 0)
            printf("Available\n");
        else
            printf("Booked by %s\n", hotel[i].customerName);
    }
}

// Book a table
void bookTable()
{
    int table;

    printf("\nEnter Table Number (1-10): ");
    scanf("%d", &table);

    if(table < 1 || table > 10)
    {
        printf("Invalid Table Number!\n");
        return;
    }

    if(hotel[table-1].booked == 1)
    {
        printf("Sorry! Table is already booked.\n");
    }
    else
    {
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", hotel[table-1].customerName);

        hotel[table-1].booked = 1;

        printf("Table Booked Successfully!\n");
    }
}

// Cancel booking
void cancelBooking()
{
    int table;

    printf("\nEnter Table Number: ");
    scanf("%d",&table);

    if(table < 1 || table > 10)
    {
        printf("Invalid Table Number!\n");
        return;
    }

    if(hotel[table-1].booked == 0)
    {
        printf("This table is already available.\n");
    }
    else
    {
        hotel[table-1].booked = 0;
        strcpy(hotel[table-1].customerName, "None");

        printf("Booking Cancelled Successfully!\n");
    }
}

int main()
{
    int choice;

    initializeTables();

    while(1)
    {
        printf("\n");
        printf("===================================\n");
        printf("   HOTEL TABLE BOOKING SYSTEM\n");
        printf("===================================\n");
        printf("1. View Tables\n");
        printf("2. Book Table\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displayTables();
                break;

            case 2:
                bookTable();
                break;

            case 3:
                cancelBooking();
                break;

            case 4:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}