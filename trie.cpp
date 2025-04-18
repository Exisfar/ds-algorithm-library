#include "data_structure.h"


void Trie::insert(string word) {
  Trie *node = this;
  for (char ch : word) {
    ch -= 'a';
    if (node->children[ch] == nullptr)
      node->children[ch] = new Trie();
    node = node->children[ch];
  }
  node->is_end = true;
}

bool Trie::search(string word) {
  Trie *node = this;
  for (char ch : word) {
    ch -= 'a';
    if (node->children[ch] == nullptr)
      return false;
    node = node->children[ch];
  }
  return node->is_end;
}

bool Trie::startsWith(string prefix) {
  Trie *node = this;
  for (char ch : prefix) {
    ch -= 'a';
    if (node->children[ch] == nullptr)
      return false;
    node = node->children[ch];
  }
  return true;
}
