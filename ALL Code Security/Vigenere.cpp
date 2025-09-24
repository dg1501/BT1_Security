#include <iostream>
#include <string>
using namespace std;

string vigenereEncrypt(string text, string key) {
    string result = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(key[i % m]) - 'a';
            result += (c - base + k) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    cin >> key;
    cout << "Ban ma: " << vigenereEncrypt(text, key) << endl;
    return 0;
}

