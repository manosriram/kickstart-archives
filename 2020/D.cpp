#include <iostream>
#include <string>
#define alpha_size 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;
string word;
struct TrieNode {
    bool eOF;
    TrieNode *children[alpha_size];
    int freq;
};

struct TrieNode *createNode() {
    TrieNode *pNode = new TrieNode;
    pNode->eOF = false;

    for (int t = 0; t < alpha_size; t++) {
        pNode->children[t] = nullptr;
    }
    return pNode;
}

void insert(string key, TrieNode *root) {
    TrieNode *crawl = root;

    for (int t = 0; t < key.length(); t++) {
        int index = key[t] - 'a';

        if (!crawl->children[index]) {
            crawl->children[index] = createNode();
        }

        crawl = crawl->children[index];
    }
    crawl->freq++;
    crawl->eOF = true;
}
int suggestWords(TrieNode *root) {
    if (!root) return 0;

    int in, ct = 0;
    for (int t=0;t<26;++t) {
        if (root->children[t]) {
            in = t;
            ++ct;
        }
    }

    if (ct > 1)
        return 0;

    return 1 + suggestWords(root->children[in]);
}

TrieNode *root = createNode();
int main() {
    freopen("in", "r", stdin);
    int T, n, k;
    string s;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        cin >> n >> k;
        int ln = 0;
        while (n--) {
            cin >> s;
            ln += s.length();
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            insert(s, root);
        }
        int sm = 0;
        for (int t=0;t<26;++t) {
            sm += suggestWords(root->children[t]);
        }
        cout << ln - sm << endl;
    }
}
