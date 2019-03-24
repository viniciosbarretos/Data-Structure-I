//
// Vinicios Barretos Batista
// Ubuntu / G++ Compiler
// CLion
// 
// Allan de Godoi Contessoto
// Data Structure
// UNESP
//
// 31/05/2018
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <deque>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

/*
 * 1) Main
 *
 * 2) AVL Tree Manipulation
 *   2.1) Left Rotation
 *   2.2) Right Rotation
 *   2.3) Balance
 *   2.4) Update Nodes Height
 *   2.5) Add Element
 *   2.6) Remove Element
 *   2.7) Tree Height
 *   2.8) Tree Nodes Count
 *
 *  3) Visual Elements
 *    3.1) Clear Screen
 *    3.2) Print Elements In Order
 *    3.3) Print Elements Pre Order
 *    3.3) Print Elements Post Order
 *    3.4) Print Options
 *
 *  4) Print Tree Diagram
 *
*/

struct node {
    int number;
    int leftHeight;
    int rightHeight;
    struct node *left;
    struct node *right;
};

// AVL Tree Manipulation Section
node* leftRotation(node *aux);
node* rightRotation(node *aux);
node* balance(node *aux, int height);
node* updateheights(node *aux);
node* add(node *aux, int number);
node* remove(node *aux, int number);
int treeHeight(node *tree);
int countNodes(node *tree, int count);

// Visual Elements Section
void clearScreen();
void printInOrder(node *node);
void printPreOrder(node *node);
void printPostOrder(node *node);
void printOptions();

// Print Tree Diagram Section
string intToString(int num);
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue);
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue, int optHeight);
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<node*>& nodesQueue, int optHeight);
void printTree(node *root, int level, int indentSpace, int optHeight);


/////////////////////////////////////////////////////////////////////// Main Section

int main() {

    node *tree = NULL;
    int opt = 1;
    int number;
    int nodesQuantity;

    tree = add(tree, 50);
    tree = add(tree, 30);
    tree = add(tree, 55);
    tree = add(tree, 10);
    tree = add(tree, 15);
    tree = add(tree, 20);
    tree = add(tree, 80);
    tree = add(tree, 90);
    tree = add(tree, 68);

    tree = remove(tree, 50);
    tree = updateheights(tree);
    tree = remove(tree, 90);
    tree = updateheights(tree);

    clearScreen();
    cout << "[ AVL TREE MANAGER ]\n";
    printTree(tree, 1, 1, 0);
    cout << "\n\n[NODES WEIGHT]\n\n";
    printTree(tree, 1, 1, 1);
    printOptions();
    cin >> opt;

    while(opt != 0) {
        switch(opt) {
            case 1:
                cout << "\n Number to add: ";
                cin >> number;
                tree = add(tree, number);
                cout << "\n [Number " << number << " added!]\n";
                break;

            case 2:
                cout << "\n Number to remove: ";
                cin >> number;
                tree = remove(tree, number);
                // It's necessary update heights and balance tree after a removal
                tree = updateheights(tree);
                break;

            case 3:
                cout << "\n";
                printInOrder(tree);
                cout << "\n";
                break;

            case 4:
                cout << "\n";
                printPreOrder(tree);
                cout << "\n";
                break;

            case 5:
                cout << "\n";
                printPostOrder(tree);
                cout << "\n";
                break;

            case 6:
                cout << "\n Tree Height: " << treeHeight(tree) << "\n";
                nodesQuantity = countNodes(tree, 0);
                cout << " Quantity of nodes: " << nodesQuantity << "\n";
        }

        getchar();
        cout << "\n[PRESS ENTER TO CONTINUE]";
        getchar();

        clearScreen();
        cout << "[ AVL TREE CREATOR ]\n";
        printTree(tree, 1, 1, 0);
        cout << "\n\n[NODES WEIGHT]\n\n";
        printTree(tree, 1, 1, 1);
        printOptions();
        cin >> opt;
    }

    return 0;
}




/////////////////////////////////////////////////////////////////////// AVL Tree Manipulation Section

// 2.1
node* leftRotation(node *aux) {
    node *aux1, *aux2;

    aux1 = aux->right;
    aux2 = aux1->left;
    aux->right = aux2;
    aux1->left = aux;

    //count the right height of the original root
    if(aux->right == NULL)
        aux->rightHeight = 0;
        //set the current side height as the highest height (or height) summed up of 1
    else if(aux->right->leftHeight > aux->right->rightHeight)
        aux->rightHeight = aux->right->leftHeight + 1;
    else
        aux->rightHeight = aux->right->rightHeight + 1;

    //count the left height of the new root
    if(aux1->left->leftHeight > aux1->left->rightHeight)
        aux1->leftHeight = aux1->left->leftHeight + 1;
    else
        aux1->leftHeight = aux1->left->rightHeight + 1;

    return aux1;
}

// 2.2
node* rightRotation(node *aux) {
    node *aux1, *aux2;

    aux1 = aux->left;
    aux2 = aux1->right;
    aux->left = aux2;
    aux1->right = aux;

    //count the left height of the original root
    if(aux->left == NULL)
        aux->leftHeight = 0;
    else if(aux->left->leftHeight > aux->left->rightHeight)
        aux->leftHeight = aux->left->leftHeight + 1;
    else
        aux->leftHeight = aux->left->rightHeight + 1;

    //count the right height of the new root
    if(aux1->right->leftHeight > aux1->right->rightHeight)
        aux1->rightHeight = aux1->right->leftHeight + 1;
    else
        aux1->rightHeight = aux1->right->rightHeight + 1;

    return aux1;
}

// 2.3
node* balance(node *aux, int height) {
    int childheight;

    if(height == 2) {
        //height of the right child
        childheight = aux->right->rightHeight - aux->right->leftHeight;

        if(childheight >= 0)
            aux = leftRotation(aux);
        else {
            aux->right = rightRotation(aux->right);
            aux = leftRotation(aux);
        }
    }
    else if(height == -2) {
        //height of the left child
        childheight = aux->left->rightHeight - aux->left->leftHeight;

        if(childheight <= 0)
            aux = rightRotation(aux);
        else {
            aux->left = leftRotation(aux->left);
            aux = rightRotation(aux);
        }
    }

    //return the balanced node
    return aux;
}

// 2.4
node* updateheights(node *aux) {
    if(aux != NULL) {

        //left children
        aux->left = updateheights(aux->left);

        if(aux->left == NULL)
            aux->leftHeight = 0;
        else if(aux->left->leftHeight > aux->left->rightHeight)
            aux->leftHeight = aux->left->leftHeight + 1;
        else
            aux->leftHeight = aux->left->rightHeight + 1;

        //right children
        aux->right = updateheights(aux->right);

        if(aux->right == NULL)
            aux->rightHeight = 0;
        else if(aux->right->leftHeight > aux->right->rightHeight)
            aux->rightHeight = aux->right->leftHeight + 1;
        else
            aux->rightHeight = aux->right->rightHeight + 1;

        //balance
        aux = balance(aux, (aux->rightHeight - aux->leftHeight));
    }

    return aux;
}

// 2.5
node* add(node *aux, int number) {
    int height;
    node *newNode;

    if(aux == NULL) {
        newNode = new node();
        newNode->number = number;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftHeight = 0;
        newNode->rightHeight = 0;
        aux = newNode;
    }
    else if(number < aux->number) {
        aux->left = add(aux->left, number);

        //set height
        if(aux->left->leftHeight > aux->left->rightHeight)
            aux->leftHeight = aux->left->leftHeight + 1;
        else
            aux->leftHeight = aux->left->rightHeight + 1;

        //balance
        height = (aux->rightHeight - aux->leftHeight);
        if(height == 2 || height == -2)
            aux = balance(aux, height);
    }
    else {
        aux->right = add(aux->right, number);

        if(aux->right->leftHeight > aux->right->rightHeight)
            aux->rightHeight = aux->right->leftHeight + 1;
        else
            aux->rightHeight = aux->right->rightHeight + 1;

        height = (aux->rightHeight - aux->leftHeight);
        if(height == 2 || height == -2)
            aux = balance(aux, height);
    }

    return aux;
}

// 2.6
node* remove(node *aux, int number) {
    // Check if the node is NULL
    if(aux == NULL)
        return aux;

    // Search the element
    if(number < aux->number)
        aux->left = remove(aux->left, number);
    else
    if(number > aux->number)
        aux->right = remove(aux->right, number);

        // Element has been found
    else {
        node *bkp = aux;

        // Check if element has children on both sides
        if(aux->left && aux->right) {

            // Parent receive the right son of element
            node *parent = aux->right;
            aux = parent->left;

            // Check if the left son of (parent) exist
            if(aux) {
                while(aux->left) {
                    parent = aux;
                    aux = aux->left;
                }
                parent->left = aux->right;
                aux->right = bkp->right;
            }
            else
                aux = parent;
            // Parent receive left children of element
            aux->left = bkp->left;
        }

            //Element does not have children on both sides.
        else
        if(aux->left)
            aux = aux->left;
        else
            aux = aux->right;
        delete(bkp);
    }
    return aux;
}

// 2.7
int treeHeight(node *tree) {
    // Use root node height to define tree height
    if(tree != NULL) {
        if (tree->leftHeight > tree->rightHeight)
            return tree->leftHeight;
        else
            return tree->rightHeight;
    } else
        return 0;
}

// 2.8
int countNodes(node *tree, int count) {
    if(tree != NULL) {
        count = countNodes(tree->left, count);
        count++;
        count = countNodes(tree->right, count);
    }
    return count;
}





/////////////////////////////////////////////////////////////////////// Visual Elements Section


// 3.1
// This function is to clear terminal both Windows and UNIX
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


// 3.2
void printInOrder(node *node){
    if(node != NULL){
        printInOrder(node->left);
        cout << " " << node->number;
        printInOrder(node->right);
    }
}

// 3.3
void printPreOrder(node *node){
    if(node != NULL){
        cout << " " << node->number;
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

// 3.4
void printPostOrder(node *node){
    if(node != NULL){
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << " " << node->number;
    }
}

// 3.5
void printOptions() {
    cout << "\n[OPTIONS]\n";
    cout << " 0 -> Exit\n";
    cout << " 1 -> Add Number\n";
    cout << " 2 -> Remove Number\n";
    cout << " 3 -> Print In Order\n";
    cout << " 4 -> Print Pre Order\n";
    cout << " 5 -> Print Post Order\n";
    cout << " 6 -> Print Tree Height and nodes quantity ";
}





/////////////////////////////////////////////////////////////////////// Tree Printer Section

/*
 * Codes at this section was based in: https://articles.leetcode.com/how-to-pretty-print-binary-tree/
 *                                     https://stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram/8948691
 *
 * Some changes has been done by: Vinicios Barretos
 *
 *
 * This implementation is based in Print Binary Tree in Level Order.
 *
 * For a level, each node is spaced equally with neighboring nodes.
 * This allows a Math equation to be derived easily to calculate the exact location a node will appear in a level.
 *
 */


// Convert an integer value to string
string intToString(int num) {
    ostringstream number;
    number << num;
    return number.str();
}

// Print the ( /  and  \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue) {
    deque<node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        cout << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        cout << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    cout << endl;
}

// Print underlines and number ( ___7___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue, int optHeight) {
    deque<node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        cout << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
        if(!optHeight)
            cout << setw(branchLen+2) << ((*iter) ? intToString((*iter)->number) : "");
        else
            cout << setw(branchLen+2) << ((*iter) ? intToString((*iter)->rightHeight - (*iter)->leftHeight) : "");
        cout << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    cout << endl;
}

// Print the leaves nodes
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<node*>& nodesQueue, int optHeight) {
    deque<node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        if(!optHeight)
            cout << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->number) : "");
        else
            cout << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->rightHeight - (*iter)->leftHeight) : "");
    }
    cout << endl;
}


// level 1 is the minimum space between nodes
// indentSpace -> add some indent space to the left
void printTree(node *root, int level, int indentSpace, int optHeight) {
    int h = treeHeight(root) + 1;
    int nodesInThisLevel = 1;

    int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);
    int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);
    int startLen = branchLen + (3-level) + indentSpace;

    deque<node*> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, optHeight);

        for (int i = 0; i < nodesInThisLevel; i++) {
            node *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left);
                nodesQueue.push_back(currNode->right);
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, optHeight);
}