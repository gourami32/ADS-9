#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTtree;
  std::ifstream file(filename);
  std::string result;
  while (!file.eof()) {
    char s = file.get();
    if (s >= 'A' && s <= 'Z')
        s = s + ('a' - 'A');
    if (s >= 'a' && s <= 'z') {
      result = result + s;
    } else {
      BSTtree.add(result);
      result.clear();
    }
  }
  return BSTtree;
}
