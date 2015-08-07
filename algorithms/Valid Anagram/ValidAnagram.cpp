Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
class Solution {
public:
    //1)sort, 2)compare whther they are same
    bool isAnagram(string s, string t) {
         if(s.size() != t.size())return false;
         sort(s.begin(),s.end());
         sort(t.begin(),t.end());
         return s == t;
    }
};