O(n*k^2) k->length of longest
Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 2) same for checking the right side of current word: candidate | left | right.

 class Solution {
 public:
     vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string, int> dict;
         vector<vector<int>> ans;
         // build dictionary
         for(int i = 0; i < words.size(); i++) {
             string key = words[i];
             reverse(key.begin(), key.end());
             dict[key] = i;
         }
         // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }

         for(int i = 0; i < words.size(); i++) {
             for(int j = 0; j < words[i].size(); j++) {
                 string left = words[i].substr(0, j);
                 string right = words[i].substr(j, words[i].size() - j);

                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }

                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.push_back({dict[right], i});
                 }
             }
         }

         return ans;        
     }

     bool isPalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }

 };


O(n*k)
    construct a trie with reversed words. ab -> ba
traverse each word in trie
if we find a word ending before end of current word, then check if rest of the word is palindrome
if searching for ab and matched a in trie so far, check if b is palindrome
if we matched the whole word, we should look for every suffix under the ending node and check if they are palindrome


struct TrieNode{
    TrieNode *children[26];
    int index;
    TrieNode()  {
        index = -1;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string s, int i) {
    // first reverse and add strings into trie.
    reverse(s.begin(), s.end());
    TrieNode *ptr = root;
    for(char c : s) {
        int index = c - 'a';
        if(!ptr->children[index]) {
            ptr->children[index] = new TrieNode();
        }
        ptr = ptr->children[index];
    }
    // index of string.
    ptr->index = i;
    return;
}

void find(TrieNode* root, vector<int> &palindromes, string s = "") {
    // base condition, if formed string is a palindrome or not.
    if(root->index != -1) {
        int i = 0, j = s.length() - 1;
        //cout<<s<<endl;
        bool flag = true;
        while(i <= j) {
            if(s[i] != s[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if(flag)
            palindromes.push_back(root->index);
    }
    for(int i = 0; i < 26; i++) {
        if(root->children[i]) {
            char c = 'a' + i;
            s.push_back(c);
            find(root->children[i], palindromes, s);
            s.pop_back();
        }
    }
    return;
}

vector<int> search(TrieNode* root, string s) {
    vector<int> palindromes;
    TrieNode* ptr = root;
    for(int i = 0; i < s.length(); i++) {
        char c= s[i];
        int index = c - 'a';
        // If any strings ends here, then check if out left out string is palindrome or not.
        if(ptr->index != -1) {
            int j = i, k = s.length() - 1;
            bool flag = true;
            while(j <= k) {
                if(s[j] != s[k]) {
                    flag = false;
                    break;
                }
                j++;
                k--;
            }
            if(flag)
                palindromes.push_back(ptr->index);
        }
        // If no characters ahead matching.
        if(!ptr->children[index]) {
            return palindromes;
        }
        ptr = ptr->children[index];
    }
    find(ptr, palindromes);
    return palindromes;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        struct TrieNode* root = new TrieNode();
        int i = 0;
        for(string s : words) {
            // insert into trie.
            insert(root, s, i++);
        }
        vector<vector<int>> result;
        i = 0;
        for(string s : words) {
            // search for all palindromes.
            vector<int> palindromes = search(root, s);
            //cout<<s<<endl;
            // add all palindromes into result.
            for(int x : palindromes) {
                if(i != x)
                    result.push_back({i, x});
            }
            i++;
        }
        return result;
    }
};
