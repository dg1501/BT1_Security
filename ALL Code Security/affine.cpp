#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int mod26(int x) {
    x %= 26;
    if (x < 0) x += 26;
    return x;
}

string affineEncrypt(const string &text, int a, int b) {
    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        unsigned char ch = text[i];
        if (isalpha((unsigned char)ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int P = ch - base;
            int C = mod26(a * P + b);
            result.push_back(char(C + base));
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);
    cout << "Nhap khoa a b (cach nhau boi dau cach): ";
    if (!(cin >> a >> b)) return 0;

    cout << "Ban ma hoa: " << affineEncrypt(text, a, b) << endl;
    return 0;
}

