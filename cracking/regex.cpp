#include <iostream>
#include <string>

// Algorithm

// Validate input (can't begin with *?)
// Count the number of letters in the pattern and the input string text
// Check if the pattern has a star, this will have a special treatment
// If the pattern does not have a '*' && the text and pattern sizes match the comparison will be done by positions 
// Else If the pattern does not have a '*' and the sizes don't match, return false
// Else If the pattern size and the text input size are the same, then compare by positions e.g. str[0] == pattern[0] | '.'
// Else if the pattern has a '*' 
//   Check if pattern[n+1] = '*'
//      YES -> str[n+1] == 
using namespace std;

bool isMatch( const string &text, const string &pattern ) 
{
  bool ret = true;
  // Get text size
  int sizeText = text.size();
  int sizePattern = pattern.size();
  std::cout << "Size of input string is: " << sizeText << std::endl;
  
  std::size_t spos = pattern.find('*'); // Find * position
  if (spos != std::string::npos) { // * found
    int ppos = 0;
    int tpos = 0;
    
    std::cout << "Printing * pos: " << spos << std::endl;
    for (; tpos < sizeText; ++tpos) {
      // Check for the star pos
      if (tpos == (spos-1)) {
        if (text[tpos] == pattern[spos-1]) {
          continue;
        }
      }
      ppos = spos + 1;
      if (text[tpos] == pattern[ppos]) {
        continue;
      }
      else {
        ret = false;
      }
    }
  }
  else if (sizeText == sizePattern){ // * not found, sizes must match
    for (int tpos = 0; tpos < sizeText; ++tpos) {
      std::cout << "Checking letter: " << text[tpos] << " from input string" << std::endl;
      if (pattern[tpos] == '.' || text[tpos] == pattern[tpos]) {
        continue;
      }
      else {
        ret = false;
        break;
      }
    }
  }
  else {
    ret = false;
  }
  
  return ret;
}

int main() {
  bool ret = isMatch("aa","a*");
  std::cout << "ret is: " << ret << std::endl;
  return 0;
}