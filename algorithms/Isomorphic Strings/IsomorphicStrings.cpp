/*Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
*/
class Solution {
public: 
    bool isIsomorphic(string s, string t) {
         int smap[256]={0};
         int tmap[256]={0};
         int i = 0;
         while(i < s.size()){
            if(!smap[s[i]]){
                smap[s[i]] = t[i];
                if(tmap[t[i]])return false; //already mapped
                tmap[t[i]] = s[i];
            }else if(smap[s[i]] != t[i])
                return false;
             ++i;
         }
         
         return true;
    }
};