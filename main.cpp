#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to find a character in a string with options for case sensitivity and starting position
int find(const string& str, char ch, bool case_sensitive = true, size_t start_pos = 0) {
    if (start_pos >= str.length()) {
        return -1;
    }
    
    if (!case_sensitive) {
        string lower_str = str.substr(start_pos);
        char lower_ch = tolower(ch);
        transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        size_t pos = lower_str.find(lower_ch);
        return pos == string::npos ? -1 : pos + start_pos;
    }
    
    size_t pos = str.find(ch, start_pos);
    return pos == string::npos ? -1 : pos;
}

// Function to find a substring in a string with options for case sensitivity, starting position, and wildcards
int find(const string& str, const string& substr, bool case_sensitive = true, size_t start_pos = 0) {
    if (start_pos >= str.length()) {
        return -1;
    }
    
    string modified_str = str.substr(start_pos);
    string modified_substr = substr;
    
    if (!case_sensitive) {
        transform(modified_str.begin(), modified_str.end(), modified_str.begin(), ::tolower);
        transform(modified_substr.begin(), modified_substr.end(), modified_substr.begin(), ::tolower);
    }
    
    size_t wildcard_pos;
    while ((wildcard_pos = modified_substr.find('*')) != string::npos) {
        string before_wildcard = modified_substr.substr(0, wildcard_pos);
        string after_wildcard = modified_substr.substr(wildcard_pos + 1);
        
        size_t before_pos = modified_str.find(before_wildcard);
        if (before_pos == string::npos) {
            return -1;
        }
        
        modified_str = modified_str.substr(before_pos + before_wildcard.length());
        modified_substr = after_wildcard;
    }
    
    size_t pos = modified_str.find(modified_substr);
    return pos == string::npos ? -1 : pos + start_pos;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    // Test cases for finding a character
    cout << "Finding 'e' in \"" << str << "\": " << find(str, 'e') << endl;
    cout << "Finding ' ' in \"" << str << "\": " << find(str, ' ') << endl;
    cout << "Finding 'z' in \"" << str << "\": " << find(str, 'z') << endl;
    
    // Test cases for finding a substring
    cout << "Finding \"e\" in \"" << str << "\": " << find(str, "e") << endl;
    cout << "Finding \"quick\" in \"" << str << "\": " << find(str, "quick") << endl;
    cout << "Finding \"quiet\" in \"" << str << "\": " << find(str, "quiet") << endl;
    
    // Test cases for case-insensitive search
    cout << "Finding 'E' in \"" << str << "\" (case-insensitive): " << find(str, 'E', false) << endl;
    cout << "Finding \"QUICK\" in \"" << str << "\" (case-insensitive): " << find(str, "QUICK", false) << endl;
    cout << "Finding \"QUIET\" in \"" << str << "\" (case-insensitive): " << find(str, "QUIET", false) << endl;
    
    // Test cases for starting position
    cout << "Finding 'e' in \"" << str << "\" starting from position 0: " << find(str, 'e', true, 0) << endl;
    cout << "Finding 'e' in \"" << str << "\" starting from position 1: " << find(str, 'e', true, 1) << endl;
    cout << "Finding 'e' in \"" << str << "\" starting from position 2: " << find(str, 'e', true, 2) << endl;
    cout << "Finding 'e' in \"" << str << "\" starting from position 3: " << find(str, 'e', true, 3) << endl;
    cout << "Finding 'e' in \"" << str << "\" starting from position 500: " << find(str, 'e', true, 500) << endl;
    
    // Test cases for single wildcard character
    cout << "Finding \"*mb\" in \"lamb\": " << find(str, "*mb") << endl;
    cout << "Finding \"*s\" in \"pits\": " << find(str, "*s") << endl;
    cout << "Finding \"y*l\" in \"yellow\": " << find(str, "y*l") << endl;
    cout << "Finding \"y*l\" in \"that's why I like milk\": " << find(str, "y*l") << endl;
    cout << "Finding \"*d\" in \"dumb\": " << find(str, "*d") << endl;
    cout << "Finding \"b*\" in \"dumb\": " << find(str, "b*") << endl;
    
    // Test cases for multiple wildcard characters
    cout << "Finding \"*bunnies\" in \"dumb bunnies\": " << find(str, "*bunnies") << endl;
    cout << "Finding \"b*b*n\" in \"dumb bunnies\": " << find(str, "b*b*n") << endl;
    cout << "Finding \"b*n*n\" in \"dumb bunnies\": " << find(str, "b*n*n") << endl;
    cout << "Finding \"u*n*n\" in \"dumb bunnies\": " << find(str, "u*n*n") << endl;
    
    return 0;
}
