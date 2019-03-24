//
// Doubly Linked List
// Data Structure
// Vinicios Barretos Batista
// 05/04/2018
//

#include <iostream>

using namespace std;

typedef struct node {
    string name;
    float grade;
    struct node *prev;
    struct node *next;
} data;

data *startList = NULL;
data *endList = NULL;

void insert() {
    data *newData = new data();
    cout << "\n    Name: ";
    cin >> newData->name;
    cout << "    Grade: ";
    cin >> newData->grade;
    if(startList == NULL) {
        newData->prev = NULL;
        newData->next = NULL;
        startList = newData;
        endList = newData;
    }
    else {
        endList->next = newData;
        newData->prev = endList;
        newData->next = NULL;
        endList = newData;
    }
}

void printApproved() {
    data *aux = startList;
    int count = 0;
    while(aux != NULL) {
        if(aux->grade >= 5.0) {
            count++;
            cout << "\n    " << aux->name;
        }
        aux = aux->next;
    }
    cout << "\n";
    if(count == 0)
        cout << "    Nobody was approved\n";
    cout << "\n";
}

void header() {
    cout << "---------------------------------------------------------------\n";
    cout << ">            Doubly Linked List - Approved Students           <\n";
    cout << "---------------------------------------------------------------\n";
}

int main(int argc, const char * argv[]) {
    
    int i;
    
    header();
    
    cout << "\n[?] Please insert data of 5 students\n";
    
    for(i=0; i<5; i++)
        insert();
    
    cout << "\n[+] Approved Students (Grade >= 5)\n";
    
    printApproved();
    
    return 0;
}
