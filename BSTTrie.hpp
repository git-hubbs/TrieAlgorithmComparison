//
// Created by Jason Hubbs on 12/6/2019.
//

#ifndef FINALP3_BSTTRIE_HPP
#define FINALP3_BSTTRIE_HPP

#include "BSTNode.hpp"


class BSTTrie {
public:
    BSTNode *head;
    int nodeCount;

    BSTTrie(){
        nodeCount = 0;
        head = nullptr;
    }

    void Insert(string key);
    bool Search(string key);
    void Print(BSTNode *returnedNode);
    BSTNode* ReturnSubNode(string key);

};


#endif //FINALP3_BSTTRIE_HPP
