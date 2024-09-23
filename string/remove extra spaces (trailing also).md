```cpp
#include <iostream>
#include <string>

using namespace std;

string removeExtraSpaces(const string& input) {
    string result;
    bool spaceFound = false;

    // Flag to track if the character is the first non-space character encountered
    bool firstCharFound = false;

    for (char c : input) {
        if (c != ' ') {
            // If the character is not a space, add it to the result
            result += c;
            // Set the flag to indicate the first non-space character is found
            firstCharFound = true;
            // Reset the spaceFound flag
            spaceFound = false;
        } else {
            // If the character is a space
            if (firstCharFound && !spaceFound) {
                // If it's not a leading space and consecutive spaces are not found
                result += c;
                spaceFound = true;
            }
            // If it's a leading space, ignore it
        }
    }

    // Trim trailing spaces if any
    while (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string input = "     hello    world   in   the    name   ";
    cout << "Input: \"" << input << "\"" << endl;

    string output = removeExtraSpaces(input);
    cout << "Output: \"" << output << "\"" << endl;

    return 0;
}

```
