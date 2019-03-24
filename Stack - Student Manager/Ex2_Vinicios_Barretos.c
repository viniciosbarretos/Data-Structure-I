//
//  Data Estructure Class - Exercise 2
//  Stack and structs
//  Created by Vinicios Barretos on 11/03/18.
//  xCode 9.0
//  UNESP
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[50];
    int age;
    float grade;
    struct node *next;
} student;

student* push(student *x) {
    student *new = NULL;
    new = malloc(sizeof(student));
    new->next = x;
    printf("\n[ADD STUDENT]\n");
    getchar();
    printf(" > Name: ");
    scanf("%[^\n]", new->name);
    getchar();
    printf(" > Age: ");
    scanf("%d", &new->age);
    printf(" > Grade: ");
    scanf("%f", &new->grade);
    x = new;
    printf("\n---------------------------------------------------------------");
    printf("\n[+] %s was add\n", new->name);
    printf("---------------------------------------------------------------\n");
    return new;
}

student* pop(student *x) {
    if(x == NULL){
        printf("\n---------------------------------------------------------------\n");
        printf("[x] This operation could not be completed. There is no data.\n");
        printf("---------------------------------------------------------------\n");
    }
    else {
        student *y;
        y = x;
        x = x->next;
        printf("\n---------------------------------------------------------------");
        printf("\n[-] %s was removed\n", y->name);
        printf("---------------------------------------------------------------\n");
        free(y);
    }
    return x;
}

student* popAll(student *x) {
    if(x == NULL){
        printf("\n---------------------------------------------------------------\n");
        printf("[x] This operation could not be completed. There is no data.\n");
        printf("---------------------------------------------------------------\n");
    }
    else {
        student *y;
        y = x;
        printf("\n---------------------------------------------------------------\n");
        while(y != NULL) {
            x = x->next;
            printf("[-] %s was removed\n", y->name);
            free(y);
            y = x;
        }
        printf("---------------------------------------------------------------\n");
    }
    return x;
}

void print(student *x) {
    if(x == NULL){
        printf("\n---------------------------------------------------------------\n");
        printf("[x] This operation could not be completed. There is no data.\n");
        printf("---------------------------------------------------------------\n");
    }
    else {
        student *y;
        y = x;
        printf("\n---------------------------------------------------------------");
        while(y != NULL) {
            printf("\n> %s\n> Age: %d\n> Grade: %.2f\n", y->name, y->age, y->grade);
            y = y->next;
        }
        printf("---------------------------------------------------------------\n");
    }
}

void printWorseNote(student *x) {
    if(x == NULL){
        printf("\n---------------------------------------------------------------\n");
        printf("[x] This operation could not be completed. There is no data.\n");
        printf("---------------------------------------------------------------\n");
    }
    else {
        student *y, *worse;
        worse = x;
        y = x->next;
        while(y != NULL) {
            if(y->grade < worse->grade)
                worse = y;
            y = y->next;
        }
        printf("\n---------------------------------------------------------------\n");
        printf("<-> %s\n", worse->name);
        printf("    Age: %d\n", worse->age);
        printf("    Grade: %.2f\n", worse->grade);
        printf("---------------------------------------------------------------\n");
    }
}

void printGoodNotes(student *x) {
    if(x == NULL){
        printf("\n---------------------------------------------------------------\n");
        printf("[x] This operation could not be completed. There is no data.\n");
        printf("---------------------------------------------------------------\n");
    }
    else {
        student *y;
        y = x;
        printf("\n---------------------------------------------------------------");
        while(y != NULL) {
            if(y->grade >= 5) {
                printf("\n<+> %s\n", y->name);
                printf("    Age: %d\n", y->age);
                printf("    Grade: %.2f\n", y->grade);
            }
            y = y->next;
        }
        printf("---------------------------------------------------------------\n");
    }
}

void printOptions() {
    printf("\n[OPTIONS]\n");
    printf(" [0] Exit\n");
    printf(" [1] Add Student\n");
    printf(" [2] Remove Last Student\n");
    printf(" [3] Remove All Students\n");
    printf(" [4] Print Info Of All Students ");
}

void printOptionsComplete() {
    printf("\n[OPTIONS]\n");
    printf(" [0] Exit\n");
    printf(" [1] Add Student\n");
    printf(" [2] Remove Last Student\n");
    printf(" [3] Remove All Students\n");
    printf(" [4] Print Info Of All Students\n");
    printf(" [5] Print Info Of Students With Grade Greater Than 5\n");
    printf(" [6] Print Info Of Student With Worse Grade ");
}

void printHeader() {
    printf("---------------------------------------------------------------\n");
    printf(">                       STUDENT MANAGER                       <\n");
    printf("---------------------------------------------------------------\n");
}

void printFooter() {
    printf("\n---------------------------------------------------------------\n");
    printf(">                           THANKS!                           <\n");
    printf("---------------------------------------------------------------\n");
}

int main(int argc, const char * argv[]) {
    
    int option = 1, count = 0;
    
    student *top = NULL;
    
    printHeader();
    
    while(option != 0) {
        if(count >= 5) {
            printOptionsComplete();
            scanf("%d", &option);
            switch(option) {
                case 1: top = push(top); count++; break;
                case 2: top = pop(top); count--; break;
                case 3: top = popAll(top); count = 0; break;
                case 4: print(top); break;
                case 5: printGoodNotes(top); break;
                case 6: printWorseNote(top);
            }
        }
        
        if(count < 5) {
            printOptions();
            scanf("%d", &option);
            switch(option) {
                case 1: top = push(top); count++; break;
                case 2: top = pop(top); count--; break;
                case 3: top = popAll(top); count = 0; break;
                case 4: print(top);
            }
        }
    }
    
    printFooter();
    
    return 0;
}
