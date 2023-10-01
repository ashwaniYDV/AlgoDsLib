// https://leetcode.com/problems/group-anagrams/
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/

class Solution {
public:
    vector<vector<string>> res;
    
    // counting sort of string
    string strCountingSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
    
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isWordEnd;
        vector<int> positions;
        TrieNode() {
            isWordEnd = false;
        }
    };


    void insert(TrieNode *root, string key, int pos) {
        TrieNode *cur = root;
        for (char ch: key) {
            if (!cur->children[ch]) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isWordEnd = true;
        cur->positions.push_back(pos);
    }

    void go(TrieNode* root, vector<string>& strs) {
        if(!root) return;

        if (root->isWordEnd) {
            vector<string> temp;
            for(int pos: root->positions) {
                temp.push_back(strs[pos]);
            }
            res.push_back(temp);
        }

        for (auto it: root->children) {
            go(it.second, strs);
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < strs.size(); i++) {
            insert(root, strCountingSort(strs[i]), i);
        }
        
        go(root, strs);
        return res;
    }
};
