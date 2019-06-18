#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>  // C++ exceptions
#include "trie.hpp"

using namespace std;
using namespace structures;

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
