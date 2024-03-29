// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

class Solution{
public:
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isLeaf;
        TrieNode() {
            isLeaf = false;
        }
    };
    
    void insert(TrieNode *root,  const string key) {
        TrieNode *cur = root;
        for (char ch: key) {
            if (!cur->children[ch]) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isLeaf = true;
    }
    
    void suggestionsRec(TrieNode* root, string currPrefix, vector<string>& vec) {
        // found a string in Trie with the given prefix
        if (root->isLeaf) {
            vec.push_back(currPrefix);
        }
     
        for (auto it: root->children) {
            // append current character to currPrefix string
            currPrefix.push_back(it.first);
            // recur over the rest
            suggestionsRec(it.second, currPrefix, vec);
            // remove last character
            currPrefix.pop_back();
        }
    }

    int fun(TrieNode* root, string query, vector<string>& vec) {
        TrieNode* cur = root;

        for (char ch: query) {
            if (!cur->children[ch]) {
                return 0;
            }
            cur = cur->children[ch];
        }
        
        suggestionsRec(cur, query, vec);
        return 1;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < n; i++) {
            insert(root, contact[i]);
        }
        
        vector<vector<string>> res;
        for(int i = 0; i < s.size(); i++) {
            vector<string> vec;
            int x = fun(root, s.substr(0, i+1), vec);
            if(x == 0) {
                vec.push_back("0");
            }
            res.push_back(vec);
        }
        
        return res;
    }
};
