#include <string>
#include <list>
#define NUMCHAR 26
//const int NUMCHAR = 26;

class Trie {
    struct Node {
        Node* character[NUMCHAR];
        bool terminal_;
        char letter_;

        Node() {
            this->terminal_ = false;
            for (int i = 0; i < NUMCHAR; i++)
               this->character[i] = nullptr;
            letter_ = '\0';
        }
    };
    
    Node* root_ = new Node();
    void Suggestion(Node* tmp_, const std::string& partialWord, std::string suggestions[], int& numOfWords) const;
    
    public:
        Trie();
	    Trie(std::string data[],int sz);
	    void addWord(const std::string& newWord);
	    bool lookup(const std::string& word) const;
	    int suggest(const std::string& partialWord, std::string suggestions[]) const;
	    ~Trie();	
};