/**************************************************
* Program: Project03
* File: Trie.hpp
* Class: CS 415
* Author: Jason Hubbs
* Date: 11-22-2019
**************************************************/

#ifndef P3_TRIE_HPP
#define P3_TRIE_HPP
#define CHAR_SIZE 26


#include <string>
#include <iostream>
#include <vector>
#include "Node.hpp"

using namespace std;

class Trie {
public:
    Trie();
    Node *head;
    int nodeCount;
	
    void Insert(string key);
    bool Search(string key);
    void Print(Node *sub);
    Node* ReturnSubNode(string key);
};


#endif //P3_TRIE_HPP
