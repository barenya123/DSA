

#include <iostream>
#include <string>

using namespace std;

bool linear_search_recursive(const string& main_string, const string& item_string, int main_index, int item_index) {

    if (item_index == item_string.length()) {
        return true;
    }
    
    
    if (main_index == main_string.length()) {
        return false;
    }


    if (main_string[main_index] == item_string[item_index]) {
        return linear_search_recursive(main_string, item_string, main_index + 1, item_index + 1);
    }
    
    else {
        return linear_search_recursive(main_string, item_string, main_index + 1, 0);
    }
}

int main() {
    string main_str, item_str;
    
    cout << "Enter the main string: ";
    getline(cin, main_str);
    
    cout << "Enter the item string to search: ";
    getline(cin, item_str);

    if (linear_search_recursive(main_str, item_str, 0, 0)) {
        cout << "'" << item_str << "' is found in the main string." << endl;
    } else {
        cout << "'" << item_str << "' is not found in the main string." << endl;
    }

    return 0;
} 

