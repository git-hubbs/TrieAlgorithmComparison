//
// Created by Jason Hubbs on 12/6/2019.
//

#include "BSTTrie.hpp"

void BSTTrie::Insert(string key) {

    if(head == nullptr){
        auto *newNode = new BSTNode(); //create new node
        newNode->letter = key[0];
        head = newNode;
        cout << "creating initial node\n";
    }
    string value;
    char letter;
    auto *curr = head;


    for(int i = 0; i < key.length(); i++){
        letter = key[i];
        value+= key[i];
        if( letter < curr->letter ){
            if(curr->leftSubTree == nullptr){
                auto *newNode = new BSTNode(); //create new node
                newNode->SetValue(value);
                newNode->letter = key[i];
                curr->leftSubTree = newNode; //set left subtree to new node
                cout << "word inserted..\n";

            }
            curr = curr->leftSubTree;
        }
        else if (letter > curr->letter){
            if(curr->rightSubTree == nullptr) {
                auto *newNode = new BSTNode(); //create new node
                newNode->SetValue(value);
                newNode->letter = key[i];
                curr->rightSubTree = newNode; //set left subtree to new node
                cout << "word inserted..\n";

            }
            curr = curr->rightSubTree;
        }
        else if (letter == curr->letter){
            if(curr->middleSubTree == nullptr){
                auto *newNode = new BSTNode(); //create new node
                newNode->SetValue(value);
                newNode->letter = key[i];
                curr->middleSubTree = newNode; //set left subtree to new node
                cout << "word inserted..\n";

            }
            curr = curr->middleSubTree;
        }
    }
    curr->isLeaf = true;
}

bool BSTTrie::Search(string key) {
    auto *curr = head;

    for(int i = 0; i < key.length(); i++){

        if(key[i] < curr->letter)
            curr = curr->leftSubTree;
        else if(key[i] > curr->letter)
            curr = curr->rightSubTree;
        else
            curr = curr->middleSubTree;
        if(curr == nullptr)
            return false;
    }
    return true;
}

void BSTTrie::Print(BSTNode *returnedNode) {
    auto *curr = returnedNode;

    if(!curr){
        return;
    }

    if(curr->isLeaf) {
        cout << curr->value << endl;
    }

    Print(curr->middleSubTree);
    Print(curr->leftSubTree);
    Print(curr->rightSubTree);
}

BSTNode* BSTTrie::ReturnSubNode(string key){
    BSTNode *curr = head;
    char letter;

    for(int i = 0; i < key.length(); i++) {
        letter = key[i];
        if (letter < curr->letter){
            curr = curr->leftSubTree;
        }
        else if (letter > curr->letter){
            curr = curr->rightSubTree;
        }
        else if (letter == curr->letter){
            curr = curr->middleSubTree;
        }
    }
    return curr;
}