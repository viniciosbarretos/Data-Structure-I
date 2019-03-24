//
//  Stack/Queue Adder
//
//  Created by Vinicios Barretos on 18/03/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int num;
    struct node *next;
} data;

data* push(data *x, int n) {
    data *newData = NULL;
    newData = new data();
    newData->next = x;
    newData->num = n;
    x = newData;
    return newData;
}

data *startQueue = NULL;
data *endQueue = NULL;

void addQueue (int n) {
    data *newData = new data();
    newData->num = n;
    newData->next = NULL;
    if(startQueue == NULL) {
        startQueue = newData;
        endQueue = newData;
    }
    else {
        endQueue->next = newData;
        endQueue = newData;
    }
}

void adderStackQueue (data *p) {
    data *auxStack = p;
    data *auxQueue = startQueue;
    int count=1;
    while(auxStack!=NULL && auxQueue!=NULL){
        cout << "   Sum " << count++ << ": " << auxStack->num + auxQueue->num << "\n";
        auxStack = auxStack->next;
        auxQueue = auxQueue->next;
    }
}

void printHeader() {
    cout << "---------------------------------------------------------------\n";
    cout << ">                      STACK/QUEUE ADDER                      <\n";
    cout << "---------------------------------------------------------------\n";
}

void printFooter() {
    cout << "\n---------------------------------------------------------------\n";
    cout << ">                           THANKS!                           <\n";
    cout << "---------------------------------------------------------------\n";
}

int main(int argc, const char * argv[]) {
    
    data *top = NULL;
    int i, number;
    
    printHeader();
    
    cout << "\n<> Please, insert numbers for the Stack\n" ;
    for(i=0; i<10; i++) {
        cout << "   Number " << i+1 << ": ";
        cin >> number;
        top = push(top, number);
    }
    
    cout << "\n<> Please, insert numbers for the Queue\n" ;
    for(i=0; i<10; i++) {
        cout << "   Number " << i+1 << ": ";
        cin >> number;
        addQueue(number);
    }
    
    cout << "\n---------------------------------------------------------------\n";
    cout << "\n<> Sum between Stack and Queue\n";
    adderStackQueue(top);
    
    printFooter();
    
    return 0;
}