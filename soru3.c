#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie düğümü yapısı
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// Yeni bir trie düğümü oluşturur
TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    memset(node->children, 0, sizeof(node->children));
    return node;
}

// Trie'ye kelime ekler
void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = 1;
}

// Trie'de kelimenin var olup olmadığını kontrol eder
int search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}

// Belleği temizler
void freeTrie(TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    TrieNode *root = createNode();

    // Kelimeleri trie'ye ekle
    const char *words[] = {"apple", "app", "banana", "bat"};
    for (int i = 0; i < 4; i++) {
        insert(root, words[i]);
    }

    // Kelimeleri ara ve sonuçları yazdır
    const char *queries[] = {"apple", "app", "apples", "banana", "bat", "bath"};
    for (int i = 0; i < 6; i++) {
        printf("%s: %s\n", queries[i], search(root, queries[i]) ? "bulundu" : "bulunamadı");
    }

    // Trie'yi serbest bırak
    freeTrie(root);
    return 0;
}