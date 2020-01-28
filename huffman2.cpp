#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct FileHeader {
  char tableSize;
  int lenght;
  char eofCounter;
} fileHeader;

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

void countFrequency() {
  char c;

  charFrequency.clear();

  while (rawFile.get(c)) {
    auto it = charFrequency.find(c);
    if (it != charFrequency.end())
      charFrequency[c] += 1;
    else
      charFrequency[c] = 1;
  }

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

map<char, string> bitString;

void genBitString(Node* root, string code) {
  if (root == nullptr) return;

  if (root->value != -1) {
    bitString[root->value] = code;
  } else {
    genBitString(root->left, code + "0");
    genBitString(root->right, code + "1");
  }
}

void clearTree(Node* root) {
  if (root == nullptr) return;

  clearTree(root->left);
  clearTree(root->right);

  delete root;
}

void buildTree() {
  nodeQueue = priority_queue<Node*, vector<Node*>, Compare>();
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
}

Node* curStep;
void step(bool right) {
  if (curStep == nullptr) {
    cout << "curStep error" << endl;
    curStep = nodeQueue.top();
  }

  if (right) curStep = curStep->right;
  if (!right) curStep = curStep->left;

  if (curStep->value != -1) {
    rawFile.put(curStep->value);
    curStep = nodeQueue.top();
  }
}

void compress() {
  // load file
  do {
    cout << "input file: ";
    cin >> filename;

    cout << "load file \"" << filename << "\"" << endl;
    rawFile.open(filename, ios::in);
  } while (!rawFile && cin);

  countFrequency();
  compressedFile.open(filename + ".output", ios::out);

  // build table
  buildTree();
  if (nodeQueue.size() == 0) {
    cout << "empty file?" << endl;
  } else {
    bitString.clear();
    genBitString(nodeQueue.top(), "");
  }

  // Allocate space for header table
  compressedFile.seekp(sizeof(int) + sizeof(char) * 2);
  fileHeader = {0};

  // save mapping table
  for (const auto& kv : charFrequency) {
    compressedFile.write((char*)&kv.first, sizeof(char));
    compressedFile.write((char*)&kv.second, sizeof(int));

    fileHeader.tableSize++;
  }

  // save data
  char c, writer = 0;
  char bitCounter = 0;
  while (rawFile.get(c)) {
    auto it = bitString.find(c);

    for (auto bit : it->second) {
      if (bit == '1') writer |= (0b10000000 >> bitCounter);

      bitCounter++;
      if (bitCounter >= 8) {
        compressedFile.write((char*)&writer, sizeof(char));
        bitCounter = 0;
        writer = 0;
        fileHeader.lenght++;
      }
    }
  }

  if (bitCounter != 0) {
    compressedFile.write((char*)&writer, sizeof(char));
    fileHeader.eofCounter = bitCounter;
    fileHeader.lenght++;
  }

  // save header
  compressedFile.seekp(ios::beg);
  compressedFile.write((char*)&fileHeader.tableSize, sizeof(char));
  compressedFile.write((char*)&fileHeader.lenght, sizeof(int));
  compressedFile.write((char*)&fileHeader.eofCounter, sizeof(char));

  // deconstruction
  if (nodeQueue.size() > 0) clearTree(nodeQueue.top());
  compressedFile.close();
  rawFile.close();
}

void decompress() {
  // load file
  do {
    cout << "input file: ";
    cin >> filename;

    cout << "load file \"" << filename << "\"" << endl;
    compressedFile.open(filename, ios::in);
  } while (!compressedFile && cin);

  rawFile.open(filename + ".raw", ios::out);

  // load header
  compressedFile.read((char*)&fileHeader.tableSize, sizeof(char));
  compressedFile.read((char*)&fileHeader.lenght, sizeof(int));
  compressedFile.read((char*)&fileHeader.eofCounter, sizeof(char));

  // load table
  charFrequency.clear();
  while (fileHeader.tableSize > 0) {
    char c;
    int fq;
    fileHeader.tableSize--;

    compressedFile.read((char*)&c, sizeof(char));
    compressedFile.read((char*)&fq, sizeof(int));
    charFrequency[c] = fq;
  }

  // build tree
  buildTree();
  if (nodeQueue.size() == 0) {
    cout << "empty file?" << endl;
  } else {
    bitString.clear();
    genBitString(nodeQueue.top(), "");
  }

  // write data
  curStep = nodeQueue.top();
  char reader;
  while (fileHeader.lenght > 1) {
    compressedFile.read((char*)&reader, sizeof(char));
    fileHeader.lenght--;
    for (int i = 0; i < 8; i++) step(reader & (0b10000000 >> i));
  }

  // last data
  if (fileHeader.lenght == 1) {
    compressedFile.read((char*)&reader, sizeof(char));
    for (int i = 0; i < fileHeader.eofCounter; i++)
      step(reader & (0b10000000 >> i));
  }

  // deconstruction
  if (nodeQueue.size() > 0) clearTree(nodeQueue.top());
  compressedFile.close();
  rawFile.close();
}

int main() {
  cout << "type \"1\" compress file" << endl;
  cout << "type \"2\" decompress file" << endl;
  string mode;
  while (cin >> mode) {
    if (mode == "1") compress();
    if (mode == "2") decompress();

    cout << "type \"1\" compress file" << endl;
    cout << "type \"2\" decompress file" << endl;
  }

  return 0;
}

