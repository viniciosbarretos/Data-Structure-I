//
//  main.cpp
//  Decimal Number - List
//
//  Created by Vinicios Barretos on 08/04/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
} data;

data *startInt = NULL;
data *endInt = NULL;
data *startDec = NULL;
data *endDec = NULL;

// Option 0 -> INT
// Option 1 -> DEC

void add(int num, int opt) {
    data *newData = new data();
    newData->num = num;
    newData->next = NULL;
    if(opt == 0) {
        if(startInt == NULL) {
            startInt = newData;
            endInt = newData;
        }
        else {
            endInt->next = newData;
            endInt = newData;
        }
    }
    else {
        if(startDec == NULL) {
            startDec = newData;
            endDec = newData;
        }
        else {
            endDec->next = newData;
            endDec = newData;
        }
    }
}

void print() {
    data *aux = startInt;
    cout <<"\n";
    while(aux!=NULL){
        cout << aux->num;
        aux = aux->next;
    }
    aux = startDec;
    cout << ".";
    while(aux!=NULL){
        cout << aux->num;
        aux = aux->next;
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    
    char ch = '0';
    
    cin >> ch;
    do {
        add(atoi(&ch), 0);
        cin >> ch;
    } while(ch != '.');
    
    cin >> ch;
    do {
        add(atoi(&ch), 1);
        cin >> ch;
    } while(ch != '.');
    
    print();
    
    return 0;
}
