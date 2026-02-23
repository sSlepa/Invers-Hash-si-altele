/// Simple AhoCorasick implementation.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct AhoTrieNode
{
    unordered_map<char, int> children; // Link-uri catre fiii nodului
    int parent;         // Link catre parinte
    int failure_link;   // Link de esec al nodului curent
    int end_word_link;  // Link catre un nod care contine sfarsitul unui cuvant (sablon) care poate fi construit din prefixul curent
    int word_ID;        // ID, eticheta, sablonului din multime
    char parent_char;   // Caracterul prin care s-a ajuns din parinte in nodul curent
    bool word_end;      // Flag care indica daca un sablon din multime se termina in acest nod

    AhoTrieNode();
};

AhoTrieNode::AhoTrieNode()
{
    parent = -1;
    failure_link = -1;
    end_word_link = -1;
    word_ID = -1;
    word_end = false; 
}

struct AhoTrie 
{
    vector<AhoTrieNode> trie; 
    vector<int> words_length;
    int size;
    int root;
    int wordID; // ID-ul ultimului cuvant inserat
    
    AhoTrie();

    void insert(string);
    void buildTree();
    int search(string);
    void calcFailureLink(int);
};

AhoTrie::AhoTrie() : size(0), root(0), wordID(0)
{
    trie.push_back(AhoTrieNode());
    size++;
}

void AhoTrie::insert(string s)
{
    int current = root;

    for (int i = 0; i < s.length(); i++) 
    {
        if (trie[current].children.find(s[i]) == trie[current].children.end()) 
        {
            trie.push_back(AhoTrieNode());
            trie[size].parent = current;
            trie[size].parent_char = s[i];
            trie[current].children[s[i]] = size;
            size++;
        }
        current = trie[current].children[s[i]];
    }

    trie[current].word_end = true;
    trie[current].word_ID = wordID++;
    words_length.push_back(s.length());
}

void AhoTrie::buildTree()
{
    queue<int> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) 
    {
        int current = nodesQueue.front();
        nodesQueue.pop();

        calcFailureLink(current);

        for (auto child : trie[current].children) 
        {
            nodesQueue.push(child.second);
        }
    }
}

void AhoTrie::calcFailureLink(int node)
{
    if (node == root) 
    {
        trie[node].failure_link = root;
        trie[node].end_word_link = root;
        return;
    }

    if (trie[node].parent == root) 
    {
        trie[node].failure_link = root;
        trie[node].end_word_link = trie[node].word_end ? node : root;
        return;
    }

    int parentFailure = trie[trie[node].parent].failure_link;
    char currentChar = trie[node].parent_char;

    while (true) 
    {
        if (trie[parentFailure].children.find(currentChar) != trie[parentFailure].children.end()) 
        {
            trie[node].failure_link = trie[parentFailure].children[currentChar];
            break;
        }

        if (parentFailure == root) 
        {
            trie[node].failure_link = root;
            break;
        }

        parentFailure = trie[parentFailure].failure_link;
    }

    int failure = trie[node].failure_link;
    trie[node].end_word_link = trie[failure].word_end ? failure : trie[failure].end_word_link;
}

int AhoTrie::search(string text)
{
    int currentState = root;
    int result = 0;

    for (int j = 0; j < text.size(); j++)
    {
        while (true)
        {
            if (trie[currentState].children.find(text[j]) != trie[currentState].children.end())
            {
                currentState = trie[currentState].children[text[j]];
                break;
            }

            if (currentState == root)
                break;

            currentState = trie[currentState].failure_link;
        }

        int checkState = currentState;

        while (true)
        {
            checkState = trie[checkState].end_word_link;

            if (checkState == root)
                break;

            result++;
            int indexOfMatch = j + 1 - words_length[trie[checkState].word_ID];
            string w = text.substr(indexOfMatch, words_length[trie[checkState].word_ID]);
            cout << "Sablonul '" << w << "' apare in text de la pozitia " << indexOfMatch << endl;

            checkState = trie[checkState].failure_link;
        }
    }

    return result;
}
