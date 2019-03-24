//
//  main.cpp
//  Invert Stack Elements
//
//  Created by Vinicios Barretos on 21/03/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
} student;

student* push(student *x, int n) {
    student *new2 = NULL;
    new2 = new student();
    new2->next = x;
    new2->num = n;
    x = new2;
    return new2;
}

student* pop(student *x) {
    if(x == NULL)
        return NULL;
    else {
        student *y;
        y = x;
        x = x->next;
        free(y);
    }
    return x;
}

student* popAll(student *x) {
    if(x == NULL)
        return NULL;
    else {
        student *y;
        y = x;
        while(y != NULL) {
            x = x->next;
            free(y);
            y = x;
        }
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
        printf("\n---------------------------------------------------------------\n");
        while(y != NULL) {
            printf("> %d\n", y->num);
            y = y->next;
        }
        printf("---------------------------------------------------------------\n");
    }
}

student* printInvert (student *a) {
    student *b = NULL;
    while(a!=NULL) {
        b = push(b,a->num);
        a = a->next;
    }
    return b;
}

int main(int argc, const char * argv[]) {
    
    student *top = NULL;
    
    int n, i;
    
    for(i=0; i<4; i++){
        cout << "Add: ";
        cin >> n;
        top = push(top, n);
    }
    
    print(printInvert(top));
    
    print(top);
    
    return 0;
}
