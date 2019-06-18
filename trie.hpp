#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <stdexcept>

using namespace std;

namespace structures {

class Trie {
	public:
	void insert(string key) {
        root = root->insert(root, key, 0);
        //cout << "executando insert() com key = " << key << "\n";
    }
    private:
    	struct Node {
        char letter;
        Node* sons[26];
        std::size_t pos;
        std::size_t length;
        Node* insert(Node* x, string key, int d) {
            if (x == NULL) x = new Node;
            if (d == key.size()) {
                return x;
            }
            char c = key[d];
            int intValueOfChar = (int) c;
            int index =  intValueOfChar % 97;
            x->sons[index] = insert(x->sons[index], key, d+1);
            //cout << "executando insert do node com key = " << key << " d = " << d << "\n";
            return x;
        }
    };
    Node* root;        
  };
} // Namespace structures

#endif