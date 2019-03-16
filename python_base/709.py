
709.  To Lower Case
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:
Input: "Hello"
Output: "hello"
Example 2:
Input: "here"
Output: "here"
Example 3:
Input: "LOVELY"
Output: "lovely"

class Solution:
    def toLowerCase(self, str: str) -> str:
        return ''.join(map(lambda c: chr(ord(c)-ord('A') + ord('a')) if (ord(c)<91 and ord(c)>64) else c, str))

