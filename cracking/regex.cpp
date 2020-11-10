#include <iostream>
#include <string>

// Algorithm

// Validate input (can't begin with *?)
// Count the number of letters in the pattern and the input string text
// Check if the pattern has a star, this will have a special treatment
// If the pattern has *, get the * position, if the pattern position is in the same text position or next one continue
// If the pattern does not have a '*' && the text and pattern sizes match the comparison will be done by positions 
// Else If the pattern does not have a '*' and the sizes don't match, return false
// Else If the pattern size and the text input size are the same, then compare by positions e.g. str[0] == pattern[0] | '.'
// Else if the pattern has a '*' 
//   Check if pattern[n+1] = '*'
//      YES -> str[n+1] == 
using namespace std;

bool isMatch( const string &text, const string &pattern ) 
{
  // Get text size
  int sizeText = text.size();
  int sizePattern = pattern.size();
  std::cout << "Size of input string is: " << sizeText << std::endl;
  std::cout << "Size of input pattern is: " << sizePattern << std::endl;
  
  std::size_t spos = pattern.find('*'); // Find * position
  
  if (spos == 0) {
    std::cout << "Error, regex can't start with a star" << std::endl;
    return false;
  }
  
  // If the substring size after the star does not match the
  
  if (spos != std::string::npos) { // * found
    int ppos = 0;
    int tpos = 0;
    
    std::cout << "Printing * pos: " << spos << std::endl;
    for (; ppos < sizePattern; ++ppos) {
      std::cout << "Printing tpos: " << text[tpos] << std::endl;
      std::cout << "Printing ppos: " << pattern[ppos] << std::endl;
      // Check for the star pos
      // We need to perform a for loop for all letters in text matching the pattern letter before *
      // Need to consider when we have two asterisks in the pattern string
      if (spos == (ppos + 1)) {
        // Special case .*
        if (ppos == '.') {
          char letter = text[tpos];
          while (letter == text[tpos]) {
            ++tpos;
          }
          ++ppos;
          continue;
        }
        while (text[tpos] == pattern[spos-1]) {
          ++tpos;
        }
        ++ppos;   // We need to increment twice, to skip the star next time
        
        // If the pattern size after the pattern position is less than the remaining input text size, return false
        std::cout << "Remaining input string after the *: " << text.substr(tpos) << std::endl;
        std::cout << "Remaining input string after the *: " << pattern.substr(spos+1) << std::endl;
        std::cout << "Printing * pos: " << spos << std::endl;
        if (pattern.substr(spos+1).size() < text.substr(tpos).size()) {
          return false;
        }
        continue;
      } // No * wildcard, we need to check strictly the next pattern letter with the input letter
      else if (pattern[ppos] == '.' || text[tpos] == pattern[ppos]) {
        ++tpos;
        continue;
      }
      else {
        return false;
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
        return false;
      }
    }
  }
  else {
    return false;
  }
  
  return true;
}

int main() {
  bool ret = isMatch("aa","a*");
  std::cout << "ret is: " << ret << std::endl;
  return 0;
}