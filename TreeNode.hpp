
#include "TrieNode.hpp"

class TreeNode {
public:
    TreeNode(): left(nullptr), right(nullptr), tnode(nullptr) {} 
    TreeNode( char n ): left(nullptr), right(nullptr), data(n), tnode(new TrieNode(n)) {} 

    TreeNode *leftSubtree() {return left;}
    TreeNode *rightSubtree() {return right;}
	TrieNode *nodeTrie() {return tnode;}
	
    void leftSubtree( TreeNode *left ) { this->left = left; }
    void rightSubtree(TreeNode *right) { this->right = right; }
    void nodeTrie(TrieNode *tnode) { this->tnode = tnode; }	

private:
    TreeNode *left, *right;
    char data;
	TrieNode *tnode;
};  
