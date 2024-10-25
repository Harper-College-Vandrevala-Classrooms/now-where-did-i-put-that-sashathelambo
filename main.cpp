#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h> 
#include <windows.h>
#define ESC 27

using namespace std;

// Function to find a character in a string with an option for case sensitivity and starting position
int find_char(const string& str, char ch, bool case_sensitive = true, size_t start_pos = 0) {
    if (!case_sensitive) {
        string lower_str = str;
        char lower_ch = tolower(ch);
        transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        return lower_str.find(lower_ch, start_pos);
    }
    return str.find(ch, start_pos);
}

// Function to find a substring in a string with an option for case sensitivity and starting position
int find_substr(const string& str, const string& substr, bool case_sensitive = true, size_t start_pos = 0) {
    if (!case_sensitive) {
        string lower_str = str;
        string lower_substr = substr;
        transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        transform(lower_substr.begin(), lower_substr.end(), lower_substr.begin(), ::tolower);
        return lower_str.find(lower_substr, start_pos);
    }
    return str.find(substr, start_pos);
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    // Test cases for finding a character
    cout << "Finding 'e' in \"" << str << "\": " << find_char(str, 'e') << endl;
    cout << "Finding ' ' in \"" << str << "\": " << find_char(str, ' ') << endl;
    cout << "Finding 'z' in \"" << str << "\": " << find_char(str, 'z') << endl;

    // Test cases for finding a substring
    cout << "Finding \"e\" in \"" << str << "\": " << find_substr(str, "e") << endl;
    cout << "Finding \"quick\" in \"" << str << "\": " << find_substr(str, "quick") << endl;
    cout << "Finding \"quiet\" in \"" << str << "\": " << find_substr(str, "quiet") << endl;

    // Test cases for case-insensitive search
    cout << "Finding 'E' in \"" << str << "\" (case-insensitive): " << find_char(str, 'E', false) << endl;
    cout << "Finding \"QUICK\" in \"" << str << "\" (case-insensitive): " << find_substr(str, "QUICK", false) << endl;
    cout << "Finding \"QUIET\" in \"" << str << "\" (case-insensitive): " << find_substr(str, "QUIET", false) << endl;

    // Test cases for search with starting position
    cout << "Finding 'e' in \"" << str << "\" starting from position 2: " << find_char(str, 'e', true, 2) << endl;
    cout << "Finding \"quick\" in \"" << str << "\" starting from position 5: " << find_substr(str, "quick", true, 5) << endl;
    cout << "Finding 'E' in \"" << str << "\" (case-insensitive) starting from position 2: " << find_char(str, 'E', false, 2) << endl;
    cout << "Finding \"QUICK\" in \"" << str << "\" (case-insensitive) starting from position 5: " << find_substr(str, "QUICK", false, 5) << endl;

    char input;
    cout << "Press 'esc' to exit the program ";
    while (true) {
        input = _getch(); 
        if (input == ESC) { 
            return 0;
        }
    }
}
