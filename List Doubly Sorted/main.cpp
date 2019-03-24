//
//  main.cpp
//  List Doubly Sorted
//
//  Created by Vinicios Barretos on 08/04/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *prev;
    struct node *next;
} data;

data *startList = NULL;
data *endList = NULL;

void add(int n) {
    data *newData;
    newData = new data();
    newData->num = n;
    if(startList == NULL) {
        newData->prev = NULL;
        newData->next = NULL;
        startList = newData;
        endList = newData;
    }
    else {
        data *aux = startList;
        while(aux!=NULL && aux->num<newData->num)
            aux = aux->next;
        if(aux == startList) {
            newData->prev = NULL;
            newData->next = startList;
            startList->prev = newData;
            startList = newData;
        }
        else {
            if(aux == NULL) {
                endList->next = newData;
                newData->next = NULL;
                newData->prev = endList;
                endList = newData;
            }
            else {
                aux->prev->next = newData;
                newData->prev = aux->prev;
                newData->next = aux;
                aux->prev = newData;
            }
        }
    }
}

void remove(int n) {
    if(startList != NULL) {
        data *aux = startList;
        while(aux != NULL) {
            if(aux->num == n) {
                if(aux == startList) {
                    startList = startList->next;
                    startList->prev = NULL;
                    free(aux);
                    aux = startList;
                    if(startList == NULL)
                        endList = NULL;
                }
                else {
                    if(aux == endList) {
                        endList = endList->prev;
                        endList->next = NULL;
                        free(aux);
                        aux = endList->next;
                    }
                    else {
                        data *bkp = aux;
                        aux->prev->next = aux->next;
                        aux->next->prev = aux->prev;
                        aux = aux->next;
                        free(bkp);
                    }
                }
            }
            else
                aux = aux->next;
        }
    }
}

void print() {
    data *aux = startList;
    while(aux != NULL) {
        cout << aux->num << " ";
        aux = aux->next;
    }
}

int main(int argc, const char * argv[]) {
    
    int i;
    
    for(i=20; i>=0; i-=3)
        add(i);
    
    add(14);
    add(19);
    add(1);
    add(1);
    
    
    remove(14);
    
    print();
    
    return 0;
}
