208. Implement Trie (Prefix Tree)
Medium
Topics
Companies
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

```cpp
class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix==false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

```

Let's walk through this **Trie** implementation **step by step**, with a detailed explanation of every single line of code, followed by a dry run example for inserting a word and searching for a word. We'll also visualize the process along the way.

### Overview of Trie

A **Trie** is a tree-like data structure used to store strings. Each node in the Trie represents a single character, and by traversing from the root downwards, we can spell out the strings stored in the Trie.

Here are the main operations in this Trie:
- **Insert** a word: Add each character of the word into the Trie, and mark the last character as the end of the word.
- **Search** for a word: Check if the word exists in the Trie.
- **StartsWith**: Check if there is any word in the Trie that starts with a given prefix.

---

### Step 1: TrieNode Class

```cpp
class TrieNode {
public:
    TrieNode *child[26];  // Array of pointers to 26 possible children (for each letter 'a' to 'z')
    bool isWord;  // A flag to mark whether this node represents the end of a word

    TrieNode() {  // Constructor to initialize a TrieNode
        isWord = false;  // Initially, no word ends here, so set isWord to false
        for (auto &a : child) a = nullptr;  // Set all child pointers to nullptr (no children yet)
    }
};
```

#### Detailed Explanation:

- **TrieNode Class**: Each node in the Trie can have up to 26 children, one for each letter of the alphabet (`a` to `z`).
- **child[26]**: An array of 26 pointers, where each pointer can point to another TrieNode. Each slot in this array corresponds to a letter ('a' is at index 0, 'z' is at index 25).
- **isWord**: A boolean flag that indicates whether this node marks the end of a valid word in the Trie.
- **Constructor (`TrieNode()`)**: When a TrieNode is created:
  - **isWord** is initialized to `false` because initially, this node does not represent the end of any word.
  - **child[] array** is initialized to `nullptr`, indicating that this node has no children (no letters connected to it yet).

### Visualization

Imagine a blank TrieNode as follows:

```
Node -> child[0:26] = [null, null, null, ..., null]  // No children yet
        isWord = false  // Not the end of a word
```

---

### Step 2: Trie Class (Root Initialization)

```cpp
class Trie {
    TrieNode* root;  // The root of the Trie
public:
    Trie() {
        root = new TrieNode();  // Initialize the root node when Trie is created
    }
```

#### Detailed Explanation:

- **Trie Class**: This class will manage the Trie and provide methods to insert, search, and check for prefixes.
- **root**: A pointer to the root TrieNode. This is the starting point for all words in the Trie.
- **Trie Constructor (`Trie()`)**: When the Trie is created, the root node is initialized as a new TrieNode. Initially, the Trie is empty, and the root has no children.

### Visualization

At this point, we have an empty Trie with only the root node:

```
Root -> child[0:26] = [null, null, null, ..., null]
        isWord = false  // Root does not represent any word
```

---

### Step 3: Insert Method

```cpp
    void insert(string s) {  // Insert a word into the Trie
        TrieNode *p = root;  // Start at the root node
        for (auto &a : s) {  // Loop through each character of the word
            int i = a - 'a';  // Calculate the index for the current character ('a' = 0, 'z' = 25)
            if (!p->child[i]) p->child[i] = new TrieNode();  // If no node exists for this character, create a new one
            p = p->child[i];  // Move to the next node (the child representing the current character)
        }
        p->isWord = true;  // After all characters are inserted, mark the last node as the end of the word
    }
```

#### Detailed Explanation:

- **insert(string s)**: This method inserts the word `s` into the Trie.
- **p = root**: Start at the root node. We will move down the Trie one character at a time.
- **for (auto &a : s)**: Loop through each character of the word `s`.
  - **int i = a - 'a'**: Convert the character into an index. For example, 'a' becomes index 0, 'b' becomes index 1, ..., 'z' becomes index 25.
  - **if (!p->child[i])**: If there is no node for this character (the child pointer is `nullptr`), create a new TrieNode for this character.
  - **p = p->child[i]**: Move to the next node, which represents the current character in the word.
- **p->isWord = true**: After processing all characters, mark the last node as the end of the word by setting `isWord = true`.

### Dry Run for Insert

Let’s insert the word `"cat"` step by step.

1. **Start at Root**: Begin at the root node.

2. **Insert 'c'**:
   - `'c' - 'a' = 2`, so check `root->child[2]`.
   - `root->child[2]` is `nullptr`, so create a new TrieNode for 'c'.
   - Move to `root->child[2]`.

3. **Insert 'a'**:
   - `'a' - 'a' = 0`, so check `root->child[2]->child[0]`.
   - `root->child[2]->child[0]` is `nullptr`, so create a new TrieNode for 'a'.
   - Move to `root->child[2]->child[0]`.

4. **Insert 't'**:
   - `'t' - 'a' = 19`, so check `root->child[2]->child[0]->child[19]`.
   - `root->child[2]->child[0]->child[19]` is `nullptr`, so create a new TrieNode for 't'.
   - Move to `root->child[2]->child[0]->child[19]`.

5. **Mark the End of the Word**:
   - Set `root->child[2]->child[0]->child[19]->isWord = true`.

### Visualization After Insert

```
Root -> [null, null, Node_c, ..., null]   // Node_c represents 'c'
Node_c -> [Node_a, null, ..., null]       // Node_a represents 'a'
Node_a -> [null, ..., Node_t, ..., null]  // Node_t represents 't'
Node_t -> isWord = true                   // 't' is the end of the word "cat"
```

---

### Step 4: Search Method

```cpp
    bool search(string key, bool prefix = false) {  // Search for a word or a prefix
        TrieNode *p = root;  // Start at the root node
        for (auto &a : key) {  // Loop through each character of the word
            int i = a - 'a';  // Calculate the index for the character
            if (!p->child[i]) return false;  // If the character is not found, return false
            p = p->child[i];  // Move to the next node (the child representing the current character)
        }
        if (prefix == false) return p->isWord;  // If searching for a full word, check if it ends here
        return true;  // If searching for a prefix, return true
    }
```

#### Detailed Explanation:

- **search(string key, bool prefix = false)**: This method searches for the word `key` in the Trie.
- **p = root**: Start at the root node.
- **for (auto &a : key)**: Loop through each character of the word `key`.
  - **int i = a - 'a'**: Convert the character into an index.
  - **if (!p->child[i]) return false**: If there is no child node for the current character, return `false` (the word is not found).
  - **p = p->child[i]**: Move to the child node representing the current character.
- **if (prefix == false)**: If we're looking for a full word (not just a prefix), check if the last node marks the end of the word (`p->isWord`).
- **return true**: If searching for a prefix, return `true` if the prefix exists.

### Dry Run for Search

Let’s search for the word `"cat"`.

1. **Start at Root**: Begin at the root node.

2. **Search for 'c'**:
   - `'c' - 'a' = 2`, so check `root->child[2]`.
   - `root->child[2]` exists (it's `Node_c`), so move to `Node_c`.

3. **Search for 'a'**:
   -

 `'a' - 'a' = 0`, so check `Node_c->child[0]`.
   - `Node_c->child[0]` exists (it's `Node_a`), so move to `Node_a`.

4. **Search for 't'**:
   - `'t' - 'a' = 19`, so check `Node_a->child[19]`.
   - `Node_a->child[19]` exists (it's `Node_t`), so move to `Node_t`.

5. **Check for End of Word**:
   - `Node_t->isWord = true`, so the word `"cat"` exists in the Trie.

---

### Step 5: StartsWith Method

```cpp
    bool startsWith(string prefix) {
        return search(prefix, true);  // Use the search function with prefix = true
    }
};
```

#### Detailed Explanation:

- **startsWith(string prefix)**: This method checks if any word in the Trie starts with the given `prefix`.
- It simply calls the `search()` method with the `prefix` flag set to `true`.

---

### Final Visualization for Trie

After inserting the word `"cat"`:

```
Root -> [null, null, Node_c, ..., null]   // Node_c represents 'c'
Node_c -> [Node_a, null, ..., null]       // Node_a represents 'a'
Node_a -> [null, ..., Node_t, ..., null]  // Node_t represents 't'
Node_t -> isWord = true                   // 't' is the end of the word "cat"
```

This Trie can now support searching for `"cat"` and checking if any word starts with `"ca"`.
