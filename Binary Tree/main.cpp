//
//  main.cpp
//  BInary Tree
//
//  Created by Vinicios Barretos on 03/06/18.
//  Copyright © 2018 Vinicios Barretos. All rights reserved.
//

#include <iostream>

using namespace std;

struct node {
    int num;
    struct node *left;
    struct node *right;
};

node* add(node *tree, int num) {
    if(tree == NULL) {
        tree = new node();
        tree->num = num;
        tree->left = NULL;
        tree->right = NULL;
    }
    else {
        if(num < tree->num)
            tree->left = add(tree->left, num);
        else
            tree->right = add(tree->right, num);
    }
    return tree;
}

int search(node *tree, int num, int found) {
    if(tree != NULL && !found) {
        if(tree->num == num)
            found = 1;
        else {
            if(num < tree->num)
                found = search(tree->left, num, found);
            else
                found = search(tree->right, num, found);
        }
    }
    return found;
}

void printInOrder(node *tree) {
    if(tree != NULL) {
        printInOrder(tree->left);
        cout << tree->num << " ";
        printInOrder(tree->right);
    }
}

void printPreOrder(node *tree) {
    if(tree != NULL) {
        cout << tree->num << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void printPostOrder(node *tree) {
    if(tree != NULL) {
        printPreOrder(tree->left);
        printPreOrder(tree->right);
        cout << tree->num << " ";
    }
}

node* remove(node *tree, int num) {
    node *aux, *bigger;
    if(tree->num == num) {
        if(tree->left == tree->right) {
            delete(tree);
            return NULL;
        }
        else {
            if(tree->left == NULL) {
                aux = tree->right;
                delete(tree);
                return aux;
            }
            else {
                if(tree->right == NULL) {
                    aux = tree->left;
                    delete(tree);
                    return aux;
                }
                else {
                    aux = tree->left;
                    bigger = tree->left;
                    while(bigger->right != NULL)
                        bigger = bigger->right;
                    bigger->right = tree->right;
                    delete(tree);
                    return aux;
                }
            }
        }
    }
    else {
        if(num < tree->num)
            tree->left = remove(tree->left, num);
        else
            tree->right = remove(tree->right, num);
    }
    return tree;
}

int main(int argc, const char * argv[]) {
    
    node *tree = NULL;
    
    tree = add(tree,5);
    tree = add(tree,3);
    tree = add(tree,2);
    tree = add(tree,4);
    tree = add(tree,80);
    tree = add(tree,70);
    tree = add(tree,60);
    tree = add(tree,65);
    tree = add(tree,75);
    tree = add(tree,90);
    tree = add(tree,100);
    tree = add(tree,95);
    printInOrder(tree);
    cout << "\n";
    
    tree=remove(tree,80);
    
    printInOrder(tree);
    
    return 0;
}
