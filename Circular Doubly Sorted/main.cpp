//
//  main.cpp
//  Circular Doubly Sorted
//
//  Created by Vinicios Barretos on 10/04/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
    struct node *prev;
} data;

data *startList = NULL;
data *endList = NULL;

void add(int n) {
    data *newData;
    newData = new data();
    newData->num = n;
    if(startList == NULL) {
        newData->next = newData;
        newData->prev = newData;
        startList = newData;
        endList = newData;
    }
    else {
        data *aux = startList;
        while(aux!=endList && aux->num<newData->num)
            aux = aux->next;
        if(aux==startList && aux->next==startList) {
            newData->next = startList;
            newData->prev = startList;
            startList->prev = newData;
            startList->next = newData;
            if(newData->num < aux->num)
                startList = newData;
            else
                endList = newData;
        }
        else {
            if(aux == startList) {
                newData->next = startList;
                startList->prev = newData;
                endList->next = newData;
                newData->prev = endList;
                startList = newData;
            }
            else {
                if(aux == endList){
                    endList->next = newData;
                    newData->prev = endList;
                    newData->next = startList;
                    startList->prev = newData;
                    endList = newData;
                }
                else {
                    aux->prev->next = newData;
                    newData->next = aux;
                    newData->prev = aux->prev;
                    aux->prev = newData;
                }
            }
        }
    }
}

void print() {
    data *aux = startList;
    do {
        cout << aux->num << " ";
        aux = aux->next;
    } while(aux != startList);
}

int main(int argc, const char * argv[]) {

    add(1);
    add(4);
    add(20);
    add(99);
    print();
    
    return 0;
}
