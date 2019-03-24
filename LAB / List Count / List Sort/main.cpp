//
//  main.cpp
//  Stock Manager
//
//  Created by Vinicios Barretos on 23/03/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int number;
    struct node *next;
} data;

data *startList = NULL;
data *endList = NULL;

void add() {
    data *newData = NULL;
    newData = new data();
    cout << "Number: ";
    cin >> newData->number;
    newData->next = NULL;
    if(startList == NULL) {
        startList = newData;
        endList = newData;
    }
    else {
        endList->next = newData;
        endList = newData;
    }
}

void print() {
    if(startList == NULL)
        cout << "No data to print";
    else {
        data *aux = startList;
        while(aux != NULL) {
            cout << "   Number: " << aux->number << "\n";
            aux = aux->next;
        }
    }
}

int count() {
    data *aux = startList;
    int i=0;
    while(aux != NULL){
        i++;
        aux = aux->next;
    }
    return i;
}

int checkSort() {
    data *aux = startList;
    int i = 1;
    if(aux != NULL) {
        while(aux->next!=NULL && i==1){
            if(aux->next->number < aux->number)
                i = 0;
            aux = aux->next;
        }
    }
    return i;
}

int height(data *aux) {
    int i = 0;
    while(aux->next != NULL) {
        i++;
        aux = aux->next;
    }
    if(i>=1)
        i--;
    return i;
}

int depth(data *aux) {
    int i = 0;
    data *start = startList;
    while(start != aux) {
        i++;
        start = start->next;
    }
    if(i>=1)
        i--;
    return i;
}

int main(int argc, const char * argv[]) {
    
    int i=1;
    
    //header();
    
    while(i != 5) {
        add();
        i++;
        if(i>5) {
            cout << "\n0 Stop\n1 Continue ";
            cin >> i;
        }
    }
    
    data *aux = startList;
    
    cout << "\nElements: "<< count() << "\n";
    cout << "Height: "<< height(aux) << "\n";
    cout << "Depth: "<< depth(aux->next->next) << "\n";


    if(checkSort() == 1)
        cout << "\nSorted!\n";
    else
        cout << "NOPE! It isn't sorted\n";
    
    return 0;
}

