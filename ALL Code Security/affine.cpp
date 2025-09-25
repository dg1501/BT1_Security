#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm modulo 26
int mod26(int x) {
    x %= 26;
    if (x < 0) x += 26;
    return x;
}

// Tìm ngh?ch d?o modulo 26
int modInverse(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) return x;
    }
    return -1; // không t?n t?i
}

// Mã hóa Affine
string affineEncrypt(const string &text, int a, int b) {
    string result = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char ch = text[i];
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

// Gi?i mã Affine
string affineDecrypt(const string &text, int a, int b) {
    string result = "";
    int a_inv = modInverse(a);
    if (a_inv == -1) {
        return "Khong ton tai nghich dao modulo 26, khong the giai ma!";
    }

    for (size_t i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if (isalpha((unsigned char)ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int C = ch - base;
            int P = mod26(a_inv * (C - b));
            result.push_back(char(P + base));
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;
    int choice;

    cout << "Nhap chuoi: ";
    getline(cin, text);

    cout << "Nhap khoa a b (cach nhau boi dau cach): ";
    cin >> a >> b;

    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << affineEncrypt(text, a, b) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << affineDecrypt(text, a, b) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}

