#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to find a character in a string with an option for case sensitivity
int find(const string& str, char ch, bool case_sensitive = true) {
    if (!case_sensitive) {
        string lower_str = str;
        char lower_ch = tolower(ch);
        transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        return lower_str.find(lower_ch);
    }
    return str.find(ch);
}

// Function to find a substring in a string with an option for case sensitivity
int find(const string& str, const string& substr, bool case_sensitive = true) {
    if (!case_sensitive) {
        string lower_str = str;
        string lower_substr = substr;
        transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        transform(lower_substr.begin(), lower_substr.end(), lower_substr.begin(), ::tolower);
        return lower_str.find(lower_substr);
    }
    return str.find(substr);
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

    return 0;
}
