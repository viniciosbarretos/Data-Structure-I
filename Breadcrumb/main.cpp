//
// Breadcrumbs - Stack Based Algorithm
// Laboratory of Data Structure
// Vinicios Barretos Batista
// First Coursework
// 25/03/2018
//

/* -----------------------------------------------
1) Main Section
2) Stack Manipulation Section
 2.1) Push Function
 2.2) Pop Function
 2.3) Print Stack Inverted Function
3) News Catagories
 3.1) Sports
 3.2) News
 3.3) Entertainment
4) News Pages
 4.1) Soccer
 4.2) 404 Error
5) Visual Elements Section
 5.1) Print Header Function
 5.2) Print Breadcrumbs Function
 5.3) Universal Clear Screen for UNIX/Windows
6) Help Guide
------------------------------------------------ */

#include <iostream>

using namespace std;

typedef struct node {
    string page;
    node *next;
} data;

// Functions prototypes
void push(string page);             // 2.1
void pop();                         // 2.2
void printInverted(data *stack);    // 2.3
void sportsSection();               // 3.1
void newsSection();                 // 3.2
void entertainmentSection();        // 3.3
void soccerSection();               // 4.1
void notFoundSection();             // 4.2
void header();                      // 5.1
void printBreadCrumb();             // 5.2
void clearScreen();                 // 5.3


/* --------------------------- Main Section --------------------------- */

data *top = NULL; // Initialization of Stack

int main(int argc, const char * argv[]) {
    
    int opt = 1;
    
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  [SECTIONS]";
        cout << "\n  [0] Exit\n";
        cout << "  [1] Sports\n";
        cout << "  [2] News\n";
        cout << "  [3] Entertainment ";
        cin >> opt;
        switch(opt) {
            case 0: pop(); break;
            case 1: push("Sports"); sportsSection(); break;
            case 2: push("News"); newsSection(); break;
            case 3: push("Entertainment"); entertainmentSection();
        }
    }
    
    return 0;
}

/* --------------------------- Stack Manipulation Section --------------------------- */

// 2.1
void push(string page) {
    data *newData = new data();
    newData->page = page;
    if(top == NULL) {
        newData->next = NULL;
        top = newData;
    }
    else {
        newData->next = top;
        top = newData;
    }
}

// 2.2
void pop() {
    if(top != NULL) {
        data *aux = top;
        top = top->next;
        free(aux);
    }
}

// 2.3
void printInverted(data *stack) {
    if(stack != NULL) {
        printInverted(stack->next);
        cout << " / " << stack->page;
    }
}

/* --------------------------- News Categories ---------------------------  */

// 3.1
void sportsSection() {
    int opt = 1;
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  [0] Back\n";
        cout << "  [1] Basketball\n";
        cout << "  [2] Soccer\n";
        cout << "  [3] Tennis ";
        cin >> opt;
        switch(opt) {
            case 0: pop(); break;
            case 1: push("Basketball"); notFoundSection(); break;
            case 2: push("Soccer"); soccerSection(); break;
            case 3: push("Tennis"); notFoundSection();
        }
    }
}

// 3.2
void newsSection() {
    int opt = 1;
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  [0] Back\n";
        cout << "  [1] Campinas\n";
        cout << "  [2] Rio Preto\n";
        cout << "  [3] São Paulo ";
        cin >> opt;
        switch(opt) {
            case 0: pop(); break;
            case 1: push("Campinas"); notFoundSection(); break;
            case 2: push("Rio Preto"); notFoundSection(); break;
            case 3: push("São Paulo"); notFoundSection();
        }
    }
}

// 3.3
void entertainmentSection() {
    int opt = 1;
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  [0] Back\n";
        cout << "  [1] Novel\n";
        cout << "  [2] Gossip ";
        cin >> opt;
        switch(opt) {
            case 0: pop(); break;
            case 1: push("Novel"); notFoundSection(); break;
            case 2: push("Gossip"); notFoundSection();
        }
    }
}

/* --------------------------- News Pages ---------------------------  */

// 4.1
void soccerSection() {
    int opt = 1;
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  [0] Back\n";
        cout << "  [1] Corinthians\n";
        cout << "  [2] Palmeiras\n";
        cout << "  [3] Santos\n";
        cout << "  [4] São Paulo ";
        cin >> opt;
        switch(opt) {
            case 0: pop(); break;
            case 1: push("Corinthians"); notFoundSection(); break;
            case 2: push("Palmeiras"); notFoundSection(); break;
            case 3: push("Santos"); notFoundSection(); break;
            case 4: push("São Paulo"); notFoundSection();
        }
    }
}

// 4.2
void notFoundSection() {
    int opt = 1;
    while(opt != 0) {
        clearScreen();
        header();
        printBreadCrumb();
        cout << "\n  ERROR 404!\n  No data was found :/\n  Please, try again later.\n"; // This cout should be edited (HELP GUIDE)
        cout << "\n  [0] Back ";
        cin >> opt;
        if(opt == 0)
            pop();
    }
}


/* --------------------------- Visual Elements Section ---------------------------  */

// 5.1
void header() {
    cout << "---------------------------------------------------------------\n";
    cout << ">                          ED1 NEWS                           <\n";
    cout << "---------------------------------------------------------------\n";
}

// 5.2
void printBreadCrumb() {
    cout << "\nHome";
    if(top != NULL) {
        data *stack = top;
        printInverted(stack);
    }
    cout << "\n";
}

// 5.3
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


/* --------------------------- Help Guide --------------------------- */

/*
     1) How to change 404 error page to a functional page?
        You only need to replicate the notFoundSection() (Section 4), type a different name,
        change cout and in the category (Section 3), change the notFoundSection() call in Switch Case.
*/
