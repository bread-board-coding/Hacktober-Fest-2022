Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10

*********************************************

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back({beginWord});
        int level=0;
        while(!q.empty()){
            vector<string>front=q.front();
            q.pop();
            if(front.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
            }
            string word=front.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(front);
                }
                else if(ans[0].size()==front.size()){
                     ans.push_back(front);
                }
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    front.push_back(word);
                    q.push(front);
                    front.pop_back();
                    usedOnLevel.push_back(word);
                }
                word[i]=original;
            }}
        }
        return ans;
    }
};
