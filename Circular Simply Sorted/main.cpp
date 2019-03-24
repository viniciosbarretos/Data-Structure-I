//
//  main.cpp
//  Circular Simply Sorted
//
//  Created by Vinicios Barretos on 09/04/18.
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

void add(int n) {
    data *newData = new data();
    newData->num = n;
    if(startList == NULL) {
        newData->next = newData;
        startList = newData;
        endList = newData;
    }
    else {
        data *aux = startList;
        data *prev = endList;
        do {
            if(aux->num < newData->num) {
                prev = aux;
                aux = aux->next;
            }
        } while(newData->num > aux->num && aux!=startList);
        if(prev == endList) {
            newData->next = startList;
            endList->next = newData;
            if(newData->num > endList->num)
                endList = newData;
            else
                startList = newData;
        }
        else {
            newData->next = aux;
            prev->next = newData;
            if(prev == endList)
                endList = newData;
        }
    }
}

void remove(int n) {
    if(startList != NULL) {
        data *aux = startList;
        data *prev = endList;
        data *bkp;
        do {
            if(aux->num == n) {
                if(aux == startList) {
                    prev->next = aux->next;
                    free(aux);
                    startList = prev->next;
                }
                else {
                    bkp = aux;
                    prev->next = aux->next;
                    if(aux == endList)
                        endList = prev;
                    if(aux == startList)
                        startList = aux->next;
                    delete(aux);
                    aux = prev->next;
                }
            }
            else {
                prev = aux;
                aux = aux->next;
            }
        } while(aux != startList);
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
    add(19);
    add(20);
    add(0);
    print();
    
    return 0;
}
