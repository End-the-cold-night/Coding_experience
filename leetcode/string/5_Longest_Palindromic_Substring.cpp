第一版漏了“bbb”这种情况，只是考虑了“bab”



Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"



class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int index1=0, index2=0;
        string ret="";
        for(int i=0; i<s.size(); i++){
            int ii = i;
            while(i+1<s.size() && s[i]==s[i+1]) i++;
            int jj = i;
            if( (jj-ii)>(index2-index1)){index1=ii;index2=jj;}
            while(ii>=0 && jj<s.size()){
                if(s[ii]!=s[jj]) break;
                if((jj-ii)>(index2-index1)){index1=ii;index2=jj;}
                ii = ii -1;
                jj = jj +1;
            }
        }
        for(int i=index1; i<=index2; i++)
            ret+=s[i];
        return ret;
    }
};
