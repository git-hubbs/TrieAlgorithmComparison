//
// Created by Jason Hubbs on 11/23/2019.
//

#ifndef P3_NODE_HPP
#define P3_NODE_HPP
#define CHAR_SIZE 26


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    string value;
    bool isLeaf;
    Node *children[CHAR_SIZE];
    int nodesUnder;

    Node(){
        nodesUnder = 0;
        isLeaf = false;
        value ="";
        for(int i = 0; i < CHAR_SIZE; i++){
            children[i] = nullptr;
        }
    }

    void SetValue(string v);
};


#endif //FINALP3_NODE_HPP
