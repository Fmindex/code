#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std; 
  
class TrieNode { 
public: 
    char val; 
  
    // Using map to store the pointers 
    // of children nodes for dynamic 
    // implementation, for making the 
    // program space efiicient 
    map<char, TrieNode*> children; 
  
    // Counts the number of times the node 
    // is visited while making the trie 
    int visited; 
  
    // Initially visited value for all 
    // nodes is zero 
    TrieNode(char x) 
    { 
        val = x; 
        visited = 0; 
    } 
}; 

int ans = 0;
int min_depth = 1e9;
int cur = 0;
int k = 0;
    void dfs(TrieNode* node, int depth) 
    { 
        // To store changed visited values from 
        // children of this node i.e. number of 
        // nodes visited by its children 
        
  
        for (auto child : node->children) { 
            dfs(child.second, depth + 1); 
            min_depth = min(min_depth, depth);
        } 
        min_depth = min(min_depth, depth); 
        
        if (node->visited > 0) {
          cur += node->visited;
          if (cur > k) {
            int diff = cur - k;
            cur = k;
            node->visited = diff;  
          } else {
            node->visited = 0;
          }
        // cout << node->val<<" "<< ans << " " << cur << " : " << min_depth << "\n";
        }
        if (cur == k) {
          ans += min_depth;
          cur = 0;
        }
        // Updating the visited variable, telling 
        // number of nodes that have 
        // already been visited by its children 
        // node->visited -= vis; 
        // int string_pair = 0; 
  
        // // If node->visited > 1, means more than 
        // // one string has prefix up till this node 
        // // common in them 
        // if (node->visited > 1) { 
  
        //     // Number of string pair with current 
        //     // node common in them 
        //     string_pair = (node->visited / 2); 
        //     ans += (depth * string_pair); 
  
        //     // Updating visited variable of current node 
        //     node->visited -= (2 * string_pair); 
        // } 
  
        // // Returning the total number of nodes 
        // // already visited that needs to be 
        // // updated to previous node 
        // return (2 * string_pair + vis); 
    } 
  
    // Function to run the dfs function for the 
    // first time and give the answer variable 
     
class Trie { 
public: 
    TrieNode* head; 
  
    // Head node of the trie is initialize 
    // as '\0', after this all strings add 
    Trie() 
    { 
        head = new TrieNode('\0'); 
    } 
  
    // Function to insert the strings in 
    // the trie 
    void addWord(string s) 
    { 
        TrieNode* temp = head; 
        const unsigned int n = s.size(); 
  
        for (int i = 0; i < n; i++) { 
  
            // Inserting character-by-character 
            char ch = s[i]; 
  
            // If the node of ch is not present in 
            // map make a new node and add in map 
            if (!temp->children[ch]) { 
                temp->children[ch] = new TrieNode(ch); 
            } 
            temp = temp->children[ch]; 
            if (i == n - 1) {
              temp->visited++;
            }    
        } 

    } 
   int dfshelper() 
    { 
  
        // Stores the final answer 
        // as sum of all depths 
        ans = 0; 
        cur = 0;
        min_depth = 1e9;
        dfs(head, 0); 
        return ans; 
    } 
    // Recursive function to calculate the 
    // answer argument is passed by reference 
    
}; 
  
// Driver Function 
int main() 
{ 
  int t;
  cin >> t;
  for (int l = 1; l <=t;l++) {
    int n;
    Trie T;
    cin >> n >> k;
    for (int i =0; i< n;i++) {
    string str; 
      cin >> str;
      T.addWord(str); 
    }

    int ans = T.dfshelper(); 
    cout << "Case #" << l << ": " << ans << "\n";
  }
  
    
    
  
    return 0; 
} 