#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Mã hóa Transposition Cipher
string transposeEncrypt(const string &text, const vector<int> &key) {
    int cols = key.size();
    int rows = (text.size() + cols - 1) / cols;
    vector<vector<char> > matrix(rows, vector<char>(cols, 'X')); // padding 'X'

    int idx = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (idx < (int)text.size()) matrix[r][c] = text[idx++];
        }
    }

    string result;
    for (size_t k = 0; k < key.size(); ++k) {
        int c = key[k] - 1;
        for (int r = 0; r < rows; ++r) result.push_back(matrix[r][c]);
    }
    return result;
}

// Gi?i mã Transposition Cipher
string transposeDecrypt(const string &cipher, const vector<int> &key) {
    int cols = key.size();
    int rows = (cipher.size() + cols - 1) / cols;
    vector<vector<char> > matrix(rows, vector<char>(cols, 'X'));

    int idx = 0;
    for (size_t k = 0; k < key.size(); ++k) {
        int c = key[k] - 1;
        for (int r = 0; r < rows; ++r) {
            if (idx < (int)cipher.size()) matrix[r][c] = cipher[idx++];
        }
    }

    string result;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            result.push_back(matrix[r][c]);
        }
    }

    // Lo?i b? padding X cu?i n?u c?n
    while (!result.empty() && result[result.size()-1] == 'X') result.erase(result.size()-1);
    return result;
}

int main() {
    string text;
    cout << "Nhap chuoi: ";
    getline(cin, text);

    int n;
    cout << "Nhap do dai khoa: ";
    cin >> n;
    vector<int> key(n);
    cout << "Nhap khoa (vi du: 3 1 2): ";
    for (int i = 0; i < n; ++i) cin >> key[i];

    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << transposeEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << transposeDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}

