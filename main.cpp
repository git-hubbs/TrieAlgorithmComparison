/**************************************************
* Program: BST/Array Based Trie Comparison
* File: main.cpp
* Class: CS 415
* Author: Jason Hubbs
* Date: 11-22-2019
**************************************************/

#include <iostream>
#include "Trie.hpp"
#include <fstream>
#include <string>
#include <chrono>
#include "conio.h"
#include "Trie.hpp"
#include "Node.hpp"
#include "BSTNode.hpp"
#include "BSTTrie.hpp"

using namespace std::chrono; //Chrono necessary for high_resolution_clock
string ParseLine(string line);

/**************************************************
* Function: int main()
* Description: Main program driver. Creates Trie
* class object, inserts word list into trie, and
* supports word search operations in the trie.
**************************************************/
int main() {
    Trie *trie = new Trie();
    BSTTrie *bstTrie = new BSTTrie();

    string line, subLine, pronoun, insert, inputContainer;
    ifstream file("short_words.txt");

    auto STDbuildstart = high_resolution_clock::now(); 	//start insert clock
    if (file.is_open()) {
        while (getline(file, line)) { //While a next line exists
            ParseLine(line);
            trie->Insert(line);
            bstTrie->Insert(line);
            bstTrie->nodeCount++;
        }
    }

    auto STDbuildstop = high_resolution_clock::now(); 	//ends insert clock
    auto STDbuildduration = duration_cast<microseconds>(STDbuildstop - STDbuildstart);
    cout << "Time taken to build the standard Trie is "
        << STDbuildduration.count() << " microseconds and space occupied ""by it is "
        << trie->nodeCount * 26 << " nodes" <<endl << endl; // number of nodes * 26 is the space needed in the worst case, not how many nodes there are


    std::cout << "Enter search query: ";
    cin >> inputContainer;
    while (inputContainer != "Q") {
        Node *pronounNode;
        BSTNode *pronounBSTNode;

        auto STDsearchstart = high_resolution_clock::now(); 	//start insert clock
        bool searchResult = trie->Search(inputContainer);
        auto STDsearchstop = high_resolution_clock::now(); 	//ends insert clock
        auto STDsearchduration = duration_cast<microseconds>(STDsearchstop - STDsearchstart);
        cout << "Time taken to search the array based Trie is "
             << STDsearchduration.count() << " microseconds" << endl; // number of nodes * 26

        auto BSTsearchstart = high_resolution_clock::now(); 	//start insert clock
        bstTrie->Search(inputContainer);
        auto BSTsearchstop = high_resolution_clock::now(); 	//ends insert clock
        auto BSTsearchduration = duration_cast<microseconds>(STDsearchstop - STDsearchstart);
        cout << "Time taken to search the BST base Trie is "
             << BSTsearchduration.count() << " microseconds" << endl; // number of nodes * 26


        if(!searchResult)
            cout << inputContainer << " does not exist\n\n";
        else{
            auto STDautostart = high_resolution_clock::now();
            pronounNode = trie->ReturnSubNode(inputContainer);
            trie->Print(pronounNode);
            auto STDautostop = high_resolution_clock::now();
            auto STDautoduration = duration_cast<microseconds>(STDautostop - STDautostart);
            cout << endl << "Time taken to find auto-complete results in the array Trie is " << STDautoduration.count() << " microseconds" << endl << endl;

            auto BSTautostart = high_resolution_clock::now();
            //pronounBSTNode = bstTrie->ReturnSubNode(inputContainer);
            bstTrie->Print(bstTrie->head);
            auto BSTautostop = high_resolution_clock::now();
            auto BSTautoduration = duration_cast<microseconds>(STDautostop - STDautostart);
            cout << endl << "Time taken to find auto-complete results in the BST based Trie is " << BSTautoduration.count() << " microseconds" << endl << endl;
        }
        cout << "Enter search query: ";
        cin >> inputContainer;
    }
    return 0;
}

/**************************************************
* Function: string ParseLine(string line)
* Description: Prepares word for input by removing
* special characters and setting all letters
* to lowercase.
**************************************************/
string ParseLine(string line) {
    for (int i = 0; i < line.length(); i++) {
        if (!isalpha(line[i]))
            line.erase(i);
        if (isupper(line[i]))
            tolower(line[i]);
    }
    return line;
}