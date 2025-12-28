#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>
#include <set>
#include <iomanip>
#include <list>
#include <sstream>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <mutex>
#include <thread>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define INF 0x3f3f3f3f
#define MAX_LL 2000000000000000000LL
#define MOD 1000000007
#define CUSTOM_MOD 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define triplet tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

///__builtin_popcount(x)

/*
🎲 4 — Trie (Prefix Tree)

Problem: Implement a Trie for Autocomplete
Requirements:

void insert(const std::string& word) — add a word to the trie
bool search(const std::string& word) — return true if exact word exists
bool startsWith(const std::string& prefix) — return true if any word starts with prefix
std::vector<std::string> autocomplete(const std::string& prefix, int limit) — return up to limit words that start with prefix

*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void autocompleteHelper(TrieNode* node, const string& prefix, vector<string>& results, int limit) {
        if (results.size() >= limit) 
            return;
            
        if (node->isEndOfWord) {
            results.push_back(prefix);
        }
        for (auto& pair : node->children) {
            autocompleteHelper(pair.second, prefix + pair.first, results, limit);
        }
    }
    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        deleteTrie(root);
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    vector<string> autocomplete(const string& prefix, int limit) {
        vector<string> results;
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return results; // No words with given prefix
            }
            current = current->children[ch];
        }
        autocompleteHelper(current, prefix, results, limit);
        return results;
    }
};


int main(){

    fastio
    Trie trie;
    trie.insert("hello");
    trie.insert("helium");
    trie.insert("hey");
    trie.insert("helicopter");
    cout << trie.search("hello") << "\n"; // true
    cout << trie.startsWith("he") << "\n"; // true
    vector<string> suggestions = trie.autocomplete("he", 3);
    for (const string& word : suggestions) {
        cout << word << "\n";
    }
    

    
    

    
    return 0;
}
