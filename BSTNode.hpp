//
// Created by Jason Hubbs on 12/6/2019.
//

#ifndef FINALP3_BSTNODE_HPP
#define FINALP3_BSTNODE_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BSTNode {
public:
    string value;
    char letter;
    bool isLeaf;
    BSTNode *leftSubTree;
    BSTNode *rightSubTree;
    BSTNode *middleSubTree;
    int nodeCount;

    BSTNode(){
        nodeCount = 0;
        isLeaf = false;
        value = "";
        leftSubTree = nullptr;
        rightSubTree = nullptr;
        middleSubTree = nullptr;
    }
    void SetValue(string v);
};


#endif //FINALP3_BSTNODE_HPP
