/**************************************************
* Program: Project03
* File: Trie.cpp
* Class: CS 415
* Author: Jason Hubbs
* Date: 11-22-2019
**************************************************/
#include "Trie.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**************************************************
* Function: Trie::Trie()
* Description: Constructor. Assigns nodeCount to
 * zero and assigns head to a new node.
**************************************************/
Trie::Trie(){
    nodeCount = 0;
    head = new Node();
}

/**************************************************
* Function: void Trie::Insert(string key)
* Description: Insert key into Trie
**************************************************/
void Trie::Insert(string key) {
    string value;
    auto *curr = head;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        value+= key[i];

        if(curr->children[index] == nullptr){ //Create child node and add it to array[index], if there is not one already
            curr->nodesUnder+= 1;
            auto *newNode = new Node();
            newNode->SetValue(value);
            curr->children[index] = newNode;
            nodeCount++;
        }
        curr = curr->children[index]; //Iterates to next node
    }
    curr->isLeaf = true;
}

/**************************************************
* Function: bool Trie::Search(string key)
* Description: Search Trie for key
**************************************************/
bool Trie::Search(string key) {
    Node *curr = head;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if(curr->children[index] == nullptr) //Return false if next node doesn't contain next element in key
            return false;
        curr = curr->children[index]; //Iterates to next node
    }
    return true;
}

/**************************************************
* Function: Trie* Trie::ReturnSubTrie(string key)
* Description: Iterates through Trie and returns
* "pronoun" trie of key
**************************************************/
Node* Trie::ReturnSubNode(string key){
    Node *curr = head;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if(curr->children[index] == nullptr)
            return curr->children[index];
        curr = curr->children[index];
    }
    return curr;
}



/**************************************************
* Function: void Trie::Print(Trie *sub)
* Description: Recursively iterates through trie
* and prints all words that exist in *curr
**************************************************/
void Trie::Print(Node *pronoun) {
    Node *curr = pronoun;

    if(curr->isLeaf)
        cout << endl << curr->value;

    for (int i = 0; i < CHAR_SIZE; i++) {
        if (curr->children[i] != nullptr) {
            Print(curr->children[i]);
        }
    }
}