// Code that adds and views saved password entries
#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

//Store Password Entries
void addEntry() {
    FILE *fp = fopen("vault.txt", "a"); //creates a file if it doesn't exist or adds it to the end

    if(!fp){
        printf("There was an error opening file.\n");
        return;
    }

    //Strings created to store different information
    char username[60], password[60], website[60];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    printf("Website: ");
    scanf("%s", website);

    fprintf(fp, "%s %s %s\n", website, username, password);
    fclose(fp); //make sure to close file

    printf("Entry has been added successfully.\n");
}

void deleteEntry(){
    char deletion[60];
    printf("Enter Website needed to delete: ");
    scanf("%s", deletion);

    FILE *fp = fopen("vault.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(!fp || !temp){
        printf("Error locating file.\n");
        return;
    }

    char username[60], password[60], website[60];
    int located = 0; //flag when found

    while(fscanf(fp, "%s %s %s", website, username, password) != EOF){
        if(strcmp(website, deletion) != 0){
            fprintf(temp, "%s %s %s\n", website, username, password);

        } else{
            located = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("vault.txt");
    rename("temp.txt", "vault.txt");

    if(located){
        printf("Entry was deleted successfully.\n");
    } else{
        printf("No entry was found for that website.\n");
    }

}


void viewEntries(){
    FILE *fp = fopen("vault.txt", "r"); //using read mode to view the saved entries

    if(!fp){
        printf("No entries were found.\n");
        return;
    }

    char username[60], password[60], website[60];
    printf("\nSaved Entries:\n");

    while(fscanf(fp, "%s %s %s", website, username, password) != EOF) {
        printf("Website: %s | Username: %s | Password: %s\n", website, username, password);
    }
    fclose(fp);
}


void searchEntry(){
    char word[60];
    printf("Enter website to begin search: ");
    scanf("%s", word);

    FILE *fp = fopen("vault.txt", "r");
    if(!fp){
        printf("Error opening this file.\n");
        return;
    }

    char username[60], password[60], website[60];
    int located = 0; 

    while(fscanf(fp, "%s %s %s", website, username, password) != EOF) {
        if(strstr(website, word)){
                printf("Website: %s | Username: %s | Password: %s\n", website, username, password);
                located = 1;
        }
        
    }

    fclose(fp);
    if(!located){
        printf("No entries matched the specific search.\n");
    }
}

void addEntryCheck(){ //used to warn user if password is too weak
    FILE *fp = fopen("vault.txt", "a");
    if(!fp){
        printf("Error opening file.\n");
        return;
    }

    char username[60], password[60], website[60];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    printf("Website: ");
    scanf("%s", website);

    //Checking strength of password

    int length = strlen(password);
    int number = 0;
    int upperCase = 0;
    int lowerCase = 0; 

    for(int i = 0; i<length; i++){
        if(password[i] >= '0' && password[i] <= '9') number = 1;
        if(password[i] >= 'A' && password[i] <= 'Z') upperCase = 1;
        if(password[i] >= 'a' && password[i] <='z') lowerCase = 1;

    }

    if(length < 8 || !(number && upperCase && lowerCase)){
        printf("CAUTION!! Weak Password. Make sure to have uppercase, lowercase, and numbers.\n");
    }

    fprintf(fp, "%s %s %s\n", website, username, password);
    fclose(fp);

    printf("Entry added successfully.\n");

}
 
