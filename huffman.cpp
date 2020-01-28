#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef struct Node {
  int frequency;
  Node *left, *right;
  char value;

} Node;

struct Compare {
  bool operator()(const Node* lhs, const Node* rhs) const {
    return lhs->frequency > rhs->frequency;
  }
};

priority_queue<Node*, vector<Node*>, Compare> nodeQueue;

map<char, int> charFrequency;
map<char, char> codingTable;

fstream compressedFile;
fstream rawFile;
string filename;

void loadfile() {
  cout << "input file: ";
  cin >> filename;

  cout << "load file \"" << filename << "\"" << endl;
  rawFile.open(filename, ios::in);
  compressedFile.open(filename + ".output", ios::out);
}

void close() {
  compressedFile.close();
  rawFile.close();
}

string printNewLine(char c) {
  if (c == '\n') return "\\n";
  return string(1, c);
}

void countFrequency() {
  char c;
  while (rawFile.get(c)) {
    auto it = charFrequency.find(c);
    if (it != charFrequency.end())
      charFrequency[c] += 1;
    else
      charFrequency[c] = 1;
  }

  // print mapping
  for (const auto& kv : charFrequency)
    cout << "\'" << printNewLine(kv.first) << "\': " << kv.second << endl;

  // clear
  rawFile.clear();
  rawFile.seekg(0, ios::beg);
}

Node* newNode(Node* r, Node* l, int frequency, char value) {
  Node* node = new Node;
  node->left = l;
  node->right = r;
  node->frequency = frequency;
  node->value = value;
  return node;
}

void traversal(Node* root, string code) {
  if (root == nullptr) return;

  if (root->value != -1) {
    if (code == "") code = "0";
    cout << "\'" << printNewLine(root->value) << "\': " << code << endl;
  } else {
    traversal(root->left, code + "0");
    traversal(root->right, code + "1");
  }
}

void buildTree() {
  cout << "build tree" << endl;
  // make char node
  for (const auto& kv : charFrequency)
    nodeQueue.push(newNode(nullptr, nullptr, kv.second, kv.first));

  // build tree
  while (nodeQueue.size() > 1) {
    Node *node1, *node2;

    node1 = nodeQueue.top();
    nodeQueue.pop();

    node2 = nodeQueue.top();
    nodeQueue.pop();

    nodeQueue.push(
        newNode(node1, node2, node1->frequency + node2->frequency, -1));
  }

  // build table
  if (nodeQueue.size() == 0) {
    cout << "empty file?" << endl;
  } else
    traversal(nodeQueue.top(), "");
}

int main() {
  loadfile();

  countFrequency();
  buildTree();

  close();
  return 0;
}

