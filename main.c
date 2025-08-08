#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

#define MASTER_PASSCODE "Admin33" //Unlocks the program and can now perform all functions

int main() {
    char input[20]; //will store master password, includes null
    printf("Enter master password: ");
    scanf("%s", input);


    if(strcmp(input, MASTER_PASSCODE) != 0) { //compares user input to passcode, and if they are equal it returns 0
        printf("Access denied.\n");
        return 1;
    }

    int option; //will be what the user selects
    do{

        printf("\nPassword Manager\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Search Entries\n");
        printf("5. Add Entry with Check\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);


    //delete, update it (like if you have to change your password),
    switch(option) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            deleteEntry();
            break;
        case 4:
            searchEntry();
            break;
        case 5:
            addEntryCheck();
            break;
        case 6:
            printf("Goodbye, See you next time!\n");
            break;
        default:
            printf("Invalid option.\n");

        }
    } 
    while(option != 6); //continue looping until the user chooses to exit
    return 0;
}