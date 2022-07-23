

You are given an integer array ranks and a character array suits. You have 5 cards where the ith card has a rank of ranks[i] and a suit of suits[i].

The following are the types of poker hands you can make from best to worst:

"Flush": Five cards of the same suit.
"Three of a Kind": Three cards of the same rank.
"Pair": Two cards of the same rank.
"High Card": Any single card.
Return a string representing the best type of poker hand you can make with the given cards.

Note that the return values are case-sensitive.

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int freq[14];
        memset(freq,0,sizeof(freq));
        int a[26];
        memset(a,0,sizeof(a));
        bool three=false,pair=false,five=false;
        for(int i=0;i<5;i++)
        {
            freq[ranks[i]]++;
            if(freq[ranks[i]]==2)
                pair=true;
            if(freq[ranks[i]]==3)
                three=true;
            a[suits[i]-'a']++;
            if(a[suits[i]-'a']==5)
                five=true;
        }
        if(five)
        {
            return "Flush";
        }
        else if(three)
        {
            return "Three of a Kind";
        }
        else if(pair)
        {
            return "Pair";
        }
        
        return "High Card";
        
    }
};
