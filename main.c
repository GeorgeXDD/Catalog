#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu();
void New_Student();
void Delete_Student();
void Show_Student();


struct element{
    char firstname[20];
    char lastname[20];
    char gender[20];
    char phone[20];
    char email[20];
}profile;

int main(void){      //The program will continue running until option 4 selected
    int a;

    for(a=0;;a++){
        Menu();
    }
    return 0;
}

void Menu()      //Main Menu to select option
{
    int n;
    printf("\n**********************************************");
    printf("\nMAIN MENU STUDENT REGISTER");
    printf("\n**********************************************");
    printf("\n1. Add new student");
    printf("\n2. Delete a student");
    printf("\n3. Show stored students");
    printf("\n4. Exit");
    printf("\n**********************************************");
    printf("\nPlease enter your option< 1 / 2 / 3 / 4 >: ");
    scanf("%d", &n);

    switch(n){
        case 1:
            New_Student();
            break;
        case 2:
            Delete_Student();
            break;
        case 3:
            Show_Student();
            break;
        case 4:
            printf("\n*** Thanks for using the program! Goodbye. ***");
            exit(0);
            break;
        default:
            printf("\nError! Wrong Number is Entered\nPlease Try Again");
            break;
    }
}

void New_Student()                        //Add New Student Profile
{
    int x;
    struct element profile;


    FILE *fp = fopen("output.txt", "r");
    FILE *fpx = fopen("output.txt", "a+");
    char c;
    int ln=1;
    while((c=getc(fp))!=EOF) {
        if (c=='\n'){
            ln++;
        }
    }
    fprintf(fpx,"%d ",ln);
    fclose(fp);
    fclose(fpx);



    FILE *fPtr;
    fPtr=fopen("output.txt","a+");

    printf("\n===Add New Student===");
    printf("\n\nPlease enter the following student information.");

    printf("\n\nFirst Name: ");
    scanf("%s", &profile.firstname);

    printf("Last Name\t: ");
    scanf("%s",&profile.lastname);

    printf("Gender\t: ");
    scanf("%s", &profile.gender);

    printf("Phone\t: ");
    scanf("%s", &profile.phone);

    printf("Email\t: ");
    scanf("%s", &profile.email);

    printf("\nSYSTEM: New Student Added Successfully.\n");

    fprintf(fPtr,"%s %s  %s  %s  %s\n",profile.firstname,profile.lastname,profile.gender,profile.phone,profile.email);

    fclose(fPtr);
}

void Delete_Student()         //Delete Student Profile
{
    FILE *fRead, *fWrite;
    char *TextFile;
    char c;
    int Delete_Id, temp = 1,ok=0;

    TextFile="output.txt";

    fRead = fopen(TextFile, "r");
    c = getc(fRead);

    while (c != EOF){
        ok=1;
        printf("%c", c);
        c = getc(fRead);
    }
    rewind(fRead);

    if(ok==0){
        printf("\n SYSTEM: The file is empty, please add at least a student first\n");
        fclose(fRead);
    }else {
        printf("\nDelete Student with key ID: ");
        scanf("%d", &Delete_Id);
    }

    fWrite = fopen("copy.c", "w");
    c = getc(fRead);


    while (c != EOF) {
        if (c == '\n')
            temp++;
        if (temp != Delete_Id) {
            putc(c, fWrite);
        }
        c = getc(fRead);
    }

    fclose(fRead);
    fclose(fWrite);


    remove(TextFile);

    rename("copy.c", TextFile);
    if(ok!=0) {
        printf("\nThe contents of file after being modified are as follows:\n");
    }

    fRead = fopen(TextFile, "r");
    c = getc(fRead);
    while (c != EOF) {
        printf("%c", c);
        c = getc(fRead);
    }

    fclose(fRead);
}

void Show_Student()           //Show all stored students
{
    FILE *fRead,*fPtr;
    char *TextFile;
    char c;
    int ok=0;

    TextFile="output.txt";

    fRead = fopen(TextFile, "r");
    c = getc(fRead);


    printf("\n");

    while (c != EOF){
        ok=1;
        printf("%c", c);
        c = getc(fRead);
    }
    if(ok==0){
        printf("\n SYSTEM: The file is empty, please add at least a student first\n");
    }else {
        printf("\nSYSTEM: All students have been printed\n");
    }

    fclose(fRead);
}