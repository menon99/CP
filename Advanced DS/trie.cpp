// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
private:
    vector<TrieNode *> charMap;
    bool endWord;

public:
    TrieNode()
    {
        endWord = false;
        charMap.resize(26);
    }

    TrieNode *getMapping(char a)
    {
        return charMap[a - 'a'];
    }

    bool isEnd()
    {
        return endWord;
    }

    void setMapping(char a, TrieNode *node)
    {
        charMap[a - 'a'] = node;
    }

    void setEnd(bool t)
    {
        endWord = t;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        int l = word.length();
        if (!l)
            return;

        TrieNode *temp = root;
        for (int i = 0; i < l; i++)
        {
            if (!temp->getMapping(word[i]))
            {
                TrieNode *node = new TrieNode();
                temp->setMapping(word[i], node);
                temp = node;
            }
            else
                temp = temp->getMapping(word[i]);
            if (i == l - 1)
                temp->setEnd(true);
        }
    }

    bool findWord(string word)
    {
        int l = word.length();
        if (!l)
            return false;

        TrieNode *temp = root;
        for (int i = 0; i < l; i++)
        {
            if (!temp->getMapping(word[i]))
                return false;
            else
                temp = temp->getMapping(word[i]);
            if (i == l - 1 && !temp->isEnd())
                return false;
        }

        return true;
    }

    bool findPrefix(string prefix)
    {
        int l = prefix.length();
        if (!l)
            return false;

        TrieNode *temp = root;

        for (int i = 0; i < l; i++)
        {
            if (!temp->getMapping(prefix[i]))
                return false;
            else
                temp = temp->getMapping(prefix[i]);
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Trie t1;
    t1.insert("akash");
    t1.insert("arsenal");
    t1.insert("arsene");
    t1.insert("zoo");
    t1.insert("zidane");
    t1.insert("country");

    string y = "found\n", n = "not found\n";

    vector<string> words = {"arsene", "messi", "ronaldo", "country", "akash", "henry"};
    vector<string> prefixes = {"arse", "zoo", "zid", "count", "zing", "prefix"};

    for (string i : words)
        if (t1.findWord(i))
            cout << i << ":" << y;
        else
            cout << i << ":" << n;

    cout << endl;

    for (string i : prefixes)
        if (t1.findPrefix(i))
            cout << i << ":" << y;
        else
            cout << i << ":" << n;

    return 0;
}