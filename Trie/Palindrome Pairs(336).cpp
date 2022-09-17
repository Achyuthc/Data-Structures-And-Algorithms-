/*Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.*/


class Solution {
public:
    class Trie
    {
        public:
        int index=-1;
        Trie *next[26];
        vector<int> list;
        
    };
    vector<vector<int>> ans;
    
    bool ispalindrome(string &s,int i,int j)
    {
        
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;  
        }   
        
        return true;
    }
    void addword(string &s,Trie *root,int indx)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!root->next[s[i]-'a'])
                root->next[s[i]-'a']=new Trie();
            
            if(ispalindrome(s,0,i))
                (root->list).push_back(indx);
            
            root=root->next[s[i]-'a'];
        }
        
        root->index=indx;
    }
    void search(string &s,Trie *root,int indx)
    {
        for(int i=0;i<s.size();i++)
        {
            if(root->index>=0&&root->index!=indx&&ispalindrome(s,i,s.size()-1))
            {
                ans.push_back({indx,root->index});
            }
            
            if(!root->next[s[i]-'a'])
                return ;
            
            root=root->next[s[i]-'a'];
        }
        
        if(root->index!=-1&&root->index!=indx)
            ans.push_back({indx,root->index});
        
        for(int j:root->list)
        {
            if(indx!=j)
                ans.push_back({indx,j});
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie *root=new Trie();
        
        for(int i=0;i<words.size();i++)
            addword(words[i],root,i);
        
        for(int i=0;i<words.size();i++)
            search(words[i],root,i);
        
        return ans;
        
    }
};



