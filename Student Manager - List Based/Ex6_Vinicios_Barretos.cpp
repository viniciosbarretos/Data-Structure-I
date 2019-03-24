//
// Student Manager - List Based
// Data Structure
// Vinicios Barretos Batista
// Exercise 6
// 07/04/2018
//

/* -----------------------------------------------
 1) Main Section
 2) List Manipulation Section
 2.1) Add Elements in a Simple List
 2.2) Add Sorted Elements in a Doubly Linked List
 2.3) Set and Add Elements from Simple List to Doubly Linked List
 3) Print Section
 3.1) Print names in Ascending Order
 3.2) Print names in Descending Order
 3.3) Return the Age Average of All Students
 3.4) Calculate Final Grade
 3.5) Print data of students with Final Grade bigger than 5
 3.6) Print Name and Final Grade of All Students
 3.7) Print Options
 3.8) Print Header
 ------------------------------------------------ */

#include <iostream>

using namespace std;

typedef struct node {
    string name;
    float grade1, grade2, finalGrade;
    int age, gender;
    node *next, *prev;
} data;

// List Initialization
data *maleListStart = NULL;
data *maleListEnd = NULL;
data *femaleListStart = NULL;
data *femaleListEnd = NULL;
data *startDoubly = NULL;
data *endDoubly = NULL;

// Functions prototypes
void add();                                                                                  // 2.1
void addDoublySorted(string name, int age, float grade1, float grade2, int gender);          // 2.2
void createDoubly();                                                                         // 2.3
void ascendingPrint();                                                                       // 3.1
void descendingPrint();                                                                      // 3.2
float ageAverage();                                                                          // 3.3
void average();                                                                              // 3.4
void goodNotePrint();                                                                        // 3.5
void averageNamePrint();                                                                     // 3.6
void printOptions();                                                                         // 3.7
void printHeader();                                                                          // 3.8

/* --------------------------- Main Section --------------------------- */
int main(int argc, const char * argv[]) {
    
    int i;
    
    printHeader();
    
    for(i=0; i<5; i++)
        add();
    
    createDoubly();
    
    printOptions();
    cin >> i;
    
    while(i != 0) {
        switch(i) {
            case 1: ascendingPrint(); break;
            case 2: descendingPrint(); break;
            case 3: cout << "\n > Age Average: " << ageAverage() << "\n\n"; break;
            case 4: averageNamePrint(); break;
            case 5: goodNotePrint();
        }
        printOptions();
        cin >> i;
    }
    
    return 0;
}

/* --------------------------- List Manipulation Section --------------------------- */

// 2.1
void add() {
    data *newData = new data();
    cout << "[?] Name: ";
    cin >> newData->name;
    cout << "[?] Age: ";
    cin >> newData->age;
    cout << "[?] Grade 1: ";
    cin >> newData->grade1;
    cout << "[?] Grade 2: ";
    cin >> newData->grade2;
    cout << "[?] Gender (1 -> Man / 2 -> Woman): ";
    cin >> newData->gender;
    cout <<"\n";
    newData->next = NULL;
    if(newData->gender == 1) { // Check the Gender
        if(maleListStart == NULL) {
            maleListStart = newData;
            maleListEnd = newData;
        }
        else {
            maleListEnd->next = newData;
            maleListEnd = newData;
        }
    }
    else {
        if(femaleListStart == NULL) {
            femaleListStart = newData;
            femaleListEnd = newData;
        }
        else {
            femaleListEnd->next = newData;
            femaleListEnd = newData;
        }
    }
    
}

// 2.2
void addDoublySorted(string name, int age, float grade1, float grade2, int gender) {
    data *newData = new data();
    newData->name = name;
    newData->age = age;
    newData->grade1 = grade1;
    newData->grade2 = grade2;
    newData->gender = gender;
    if(startDoubly == NULL) { // Add element if the list is Empty
        newData->prev = NULL;
        newData->next = NULL;
        startDoubly = newData;
        endDoubly = newData;
    }
    else {
        data *aux = startDoubly;
        while(aux!=NULL && aux->name<newData->name) // Find right place to add element
            aux = aux->next;
        if(aux == NULL) { // New Element is bigger than all elements
            newData->prev = endDoubly;
            newData->next = NULL;
            endDoubly->next = newData;
            endDoubly = newData;
        }
        else {
            if(newData->name < startDoubly->name) { // Add new element to start of the list
                newData->next = startDoubly;
                newData->prev = NULL;
                startDoubly->prev = newData;
                startDoubly = newData;
            }
            else { // Add new element in the midle of the list
                aux->prev->next = newData;
                newData->prev = aux->prev;
                newData->next = aux;
                aux->prev = newData;
            }
            
        }
        
    }
}

// 2.3
void createDoubly() { // Set elements from (Male Students) and (Female Students) Lists
    data *maleAux = maleListStart; //  and add they in a Doubly Linked List
    data *femaleAux = femaleListStart;
    while(maleAux != NULL) {
        addDoublySorted(maleAux->name, maleAux->age, maleAux->grade1, maleAux->grade2, maleAux->gender);
        maleAux = maleAux->next;
    }
    while(femaleAux != NULL) {
        addDoublySorted(femaleAux->name, femaleAux->age, femaleAux->grade1, femaleAux->grade2, femaleAux->gender);
        femaleAux = femaleAux->next;
    }
}


/* --------------------------- Print Section --------------------------- */

// 3.1
void ascendingPrint() { // Print names in Ascending Order
    if(startDoubly != NULL) {
        data *aux = startDoubly;
        cout << "\n > ";
        while(aux != NULL) {
            cout << aux->name << " / ";
            aux = aux->next;
        }
        cout << "\n\n";
    }
}

// 3.2
void descendingPrint() { // Print names in Descending Order
    if(endDoubly != NULL) {
        data *aux = endDoubly;
        cout << "\n > ";
        while(aux != NULL) {
            cout << aux->name << " / ";
            aux = aux->prev;
        }
        cout << "\n\n";
    }
}

// 3.3
float ageAverage() { // Function that returns the Age Average of All Students
    float average = 0;
    if(startDoubly != NULL) {
        data *aux = startDoubly;
        int count = 0;
        while(aux != NULL) {
            average += aux->age;
            aux = aux->next;
            count++;
        }
        average /= count;
    }
    return average;
}

// 3.4
void average() { // Calculate Final Grade
    if(startDoubly != NULL) {
        data *aux = startDoubly;
        while(aux != NULL) {
            aux->finalGrade = (aux->grade1 + aux->grade2)/2.0;
            aux = aux->next;
        }
    }
}

// 3.5
void goodNotePrint() { // Print data of students with Final Grade bigger than 5
    if(startDoubly != NULL) {
        average();
        data *aux = startDoubly;
        cout << "\n";
        while(aux != NULL) {
            if(aux->finalGrade >= 5) {
                cout << " > " << aux->name << "\n";
                cout << "   Media: " << aux->finalGrade << "\n\n";
            }
            aux = aux->next;
        }
    }
}

// 3.6
void averageNamePrint() { // Print Name and Final Grade of All Students
    if(startDoubly != NULL) {
        average();
        data *aux = startDoubly;
        cout << "\n";
        while(aux != NULL) {
            cout << " > " << aux->name << "\n";
            cout << "   Media: " << aux->finalGrade << "\n\n";
            aux = aux->next;
        }
    }
}

// 3.7
void printOptions() {
    cout << "[0] Exit\n";
    cout << "[1] Print All Names in Ascending Order\n";
    cout << "[2] Print All Names in Descending Order\n";
    cout << "[3] Print Age Average of Students\n";
    cout << "[4] Print Final Grade and Students Name\n";
    cout << "[5] Print Final Grade and Name of Approved Students ";
}

//3.8
void printHeader() {
    cout << "---------------------------------------------------------------\n";
    cout << ">                       STUDENT MANAGER                       <\n";
    cout << "---------------------------------------------------------------\n\n";
}
