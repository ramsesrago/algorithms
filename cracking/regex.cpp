#include <iostream>
#include <string>
#include <vector>

// Algorithm

// Validate input (can't begin with *?)
// Count the number of letters in the pattern and the input string text
// Check if the pattern has a star, this will have a special treatment, store all the * positions in a vector
// If the pattern has * or more, we can use recursion of substrings to narrow down the problem
// If the pattern does not have a '*' && the text and pattern sizes match the comparison will be done by positions 
// Else If the pattern does not have a '*' and the sizes don't match, return false
// Else If the pattern size and the text input size are the same, then compare by positions e.g. str[0] == pattern[0] | '.'
// Else if the pattern has a '*' 
//   Check if pattern[n+1] = '*'
//      YES -> str[n+1] == 
using namespace std;

bool isMatchHelper(const string &text, const string &pattern, int textIndex, int pattIndex) {
  if (textIndex >= text.size()) {
    if (pattIndex >= pattern.size()) return true;
    
    else {
      if (pattIndex+1 < pattern.size() && pattern[pattIndex+1] == '*') {
        return isMatchHelper(text, pattern, textIndex, pattIndex+2);
      }
      else return false;
    }
  }
  
  else if (pattIndex >= pattern.size() && textIndex < text.size()) return false;
  
  // String matching for char followed by '*'
  else if ((pattIndex >= pattern.size()) && (pattern[pattIndex+1] == '*')) {
    if (pattern[pattIndex] == '.' || text[textIndex] == pattern[pattIndex]) {
      return isMatchHelper(text, pattern, textIndex, pattIndex+2) ||
             isMatchHelper(text, pattern, textIndex+1, pattIndex);
    }
    else return isMatchHelper(text, pattern, textIndex, pattIndex+2);
  }
  
  // String matching for '.' or normal char
  else if (pattern[pattIndex] == '.' || pattern[pattIndex] == text[textIndex]) {
    return isMatchHelper(text, pattern, textIndex+1, pattIndex+1);
  }
  else return false;
}

bool isMatch( const string &text, const string &pattern ) {
  return isMatchHelper(text, pattern, 0, 0);
}

int main() {
  bool ret = isMatch("aa","a*");
  std::cout << "ret is: " << ret << std::endl;
  return 0;
}