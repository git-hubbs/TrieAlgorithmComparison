
class BinSearchTree;

class TrieNode {
public:
	TrieNode(): child(nullptr) {}
	TrieNode( char n ): data(n), child(nullptr) {}

    bool &isEnd() { return isEndof; }
	void setIsEnd( bool isEndof) { this->isEndof = isEndof; }
	
    BinSearchTree *childTree() {return child;}
	
    void childTree( BinSearchTree *child ) { this->child = child; }
	
    char &value() { return data; } 

private:
    char data;
	BinSearchTree *child;
	bool isEndof;
};  
