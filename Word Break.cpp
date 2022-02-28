// CHECK IF POSSIBLE
#include <unordered_set>

// Declare a hash map.
unordered_set < string > hashMap;

bool wordBreakHelper(string & s, int start, vector < int > & dp) {
    // Base case
    if (start == s.size()) {
        return dp[start] = 1;
    }

    // If result is already calculated then return it.
    if (dp[start] != -1) {
        return dp[start];
    }

    // Run a loop from 1 to length of target string.
    for (int i = start + 1; i <= s.size(); i++) {
        /*
            If substring from 0 to i exist in hash map
            And remaining string recurs true.
        */
        if (hashMap.find(s.substr(start, i - start)) != hashMap.end()) {
            if (wordBreakHelper(s, i, dp)) {
                return dp[start] = 1;
            }
        }
    }

    // If no solution exist then return false.
    return dp[start] = 0;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Clear hash map for current test case.
    hashMap.clear();

    // Insert all strings of a into hashmap.
    for (string s: arr) {
        hashMap.insert(s);
    }

    // Declare dp array and initialize all values with -1.
    vector < int > dp(target.size() + 1, -1);

    // Call wordBreakHelper to return answer.
    return wordBreakHelper(target, 0, dp);
}


//RETURN ALL COMBINATION
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
