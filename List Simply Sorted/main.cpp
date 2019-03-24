//
//  main.cpp
//  List Simply Sorted
//
//  Created by Vinicios Barretos on 08/04/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
} data;

data *startList = NULL;
data *endList = NULL;

void add(int num) {
    data *newData;
    newData = new data();
    newData->num = num;
    if(startList == NULL) { // List is empty
        newData->next = NULL;
        startList = newData;
        endList = newData;
    }
    else { // List is not empty
        data *aux = startList;
        data *prev = NULL;
        while(aux!=NULL && aux->num<newData->num) {
            prev = aux;
            aux = aux->next;
        }
        if(prev == NULL) {
            newData->next = startList;
            startList = newData;
        }
        else {
            if(aux == NULL) {
                newData->next = NULL;
                prev->next = newData;
                endList = newData;
            }
            else {
                prev->next = newData;
                newData->next = aux;
            }
        }
    }
}

void remove(int n) {
    if(startList != NULL) {
        data *aux = startList;
        data *prev = NULL;
        while(aux != NULL) {
            if(aux->num == n) {
                if(aux == startList) {
                    startList = startList->next;
                    free(aux);
                    aux = startList;
                }
                else {
                    if(aux == endList) {
                        prev->next = NULL;
                        free(aux);
                        endList = prev;
                        aux = endList->next;
                    }
                    else {
                        prev->next = aux->next;
                        free(aux);
                        aux = prev->next;
                    }
                }
            }
            else {
                prev = aux;
                aux = aux->next;
            }
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
    
    add(0);
    add(1);
    remove(0);
    
    print();
    
    return 0;
}
