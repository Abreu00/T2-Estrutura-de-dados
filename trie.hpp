#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

namespace structures {

class Trie {
 public:
	Trie() {
    root = new Node('\0');
  }
  
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
      this->sons = vector<Node*>();
    }

    Node* insert(Node* node, string key, int d) {
      bool hasChild = false;
      Node* next_node;
      for (int i = 0; i < sons.size(); ++i) {
        if (sons[i]->letter == key[d]) {
          next_node = sons[i];
          hasChild = true;
          break;
        }
      }

      if (!hasChild) {
        next_node = new Node(key[d]);
        sons.push_back(next_node);
      }

      bool last = key.size() == d + 1;
      if (!last) {
        next_node->insert(node, key, d + 1);
      }
    }
};
    Node* root;        
  };
} // Namespace structures

#endif