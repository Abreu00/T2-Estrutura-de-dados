#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

namespace structures {

class Trie {
	public:
	void insert(string key) {
        root->insert(root, key, 0);
        //cout << "executando insert() com key = " << key << "\n";
    }
    private:
    	struct Node {
        char letter;
        vector<Node *> sons;
        std::size_t pos;
        std::size_t length;
        
        explicit Node(char letter){
            this->letter = letter;
        }

        Node* insert(Node* node, string key, int d) {
          
            bool hasChild = false;

            for (int i = 0; i < sons.size(); ++i) {
              if (sons[i]->letter == key[d]) {
                node = sons[i];
                hasChild = true;
                break;
              }
            }

            if (!hasChild) {
              Node* node = new Node(key[d]);
              sons.push_back(node);
            }

            bool last = key.size() == d + 1;
            if (!last) {
              node->insert(node, key, d + 1);
            }
        }
    };
    Node* root;        
  };
} // Namespace structures

#endif