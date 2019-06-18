#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>  // C++ exceptions

using namespace std;
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

string find_prefix_in_line(string line) {
	string return_string;
	int prefix_length = 0;
	int initial_index = (line.find("[") + 1);
	for (int i = initial_index ; i < line.size(); i++) {
		if (line[i] == ']') {
			break;
		}
		prefix_length++;		
	}
	return_string = line.substr(initial_index, prefix_length);
	return return_string;
}
int main() {
    
    using namespace std;    
    string filename;
    string word;
    Trie myTrie;
    cin >> filename;  // entrada

    string line;
    ifstream myfile (filename);
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {                       
        	string prefix_in_line;
        	prefix_in_line = find_prefix_in_line(line);
        	//cout << prefix_in_line << "\n"; 
        	myTrie.insert(prefix_in_line);        	        
        }       
        myfile.close();	
    }
    else cout << "Unable to open file";    
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        cout << word << endl;
    }

    return 0;
}
