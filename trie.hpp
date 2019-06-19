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

  ~Trie() {
    root->destroyRec();
    delete root;
  }
  
  void insert(string key) {
    root->insert(root, key, 0);
    //cout << "executando insert() com key = " << key << "\n";
  }
  bool search(string key) {
        Node* current = root;
        for (int i = 0 ; i < key.size(); ++i) {            
            for (int j = 0 ; j < current->sons.size(); j++) {
                if (current->sons[j]->letter == key[i]) {
                    current = current->sons[j];                    
                }
            }
        }
        if(current->length == key.size()) {
            return true;
        } else {
            return false;
        }
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

    Node* destroyRec() {
      int size = sons.size();
      if (size == 0) {
        return this;
      }
      for (int i = 0; i < size; ++i) {
        delete sons[i]->destroyRec();
      }
      return this;
    }

    void insert(Node* node, string key, int d) {
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
        //cout << "node com caractere = " << key[d] << " criado\n";        
        sons.push_back(next_node);
      }

      bool last = key.size() == d + 1;
      if (!last) {
        next_node->insert(node, key, d + 1);
      } else {
        next_node->length = d + 1;
        //cout << "nodo tem comprimento = " << d << " e seu caractere é igual a: " << key[d] << "\n";
      }
    }
};
    Node* root;        
  };
} // Namespace structures

#endif