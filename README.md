# BÀI TẬP 1: AN TOÀN VÀ BẢO MẬT THÔNG TIN
## Tìm hiểu các phương pháp mã hoá cổ điển
1. Caesar
2. Affine
3. Hoán vị
4. Vigenère
5. Playfair
## Với mỗi phương pháp, cần tìm hiểu:
1. Tên gọi
2. Thuật toán mã hoá, thuật toán giải mã
3. Không gian khóa
4. Cách phá mã (mà không cần khoá)
5. Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript.
### Cách làm.
1. ***CAESAR***</p>
-- ***TÊN GỌI***: mật mã của Caesar, mật mã chuyển vị, mã của Caesar, mật mã chuyển vị hay chuyển vị Caesar).</p>
<img width="1000" height="500" alt="caesar" src="https://github.com/user-attachments/assets/34630b35-7370-4f3f-890f-414d35c124d7" /></p>
-- ***THUẬT TOÁN MÃ HOÁ, THUẬT TOÁN GIẢI MÃ***</p>
1.**Bảng Chữ Cái:** Thuật toán sử dụng một bảng chữ cái cố định, ví dụ là bảng chữ cái tiếng Anh gồm 26 ký tự: A, B, C, ..., Z. </p>
2.**Khóa (Key):** Một số nguyên k được chọn làm khóa mã hóa. Khóa này xác định số lượng ký tự dịch chuyển. Ví dụ, nếu k = 3, mỗi ký tự sẽ được dịch chuyển 3 vị trí trong bảng chữ cái.</p>
- [x] ***Thuật toán mã hoá***
1. **Mã hoá**
+ Đối với mỗi ký tự trong bản rõ, tìm vị trí của nó trong bảng chữ cái.
+ Dịch chuyển ký tự đó về phía trước trong bảng chữ cái bằng số lượng vị trí tương ứng với khóa.
+ Nếu vượt quá cuối bảng chữ cái, quay vòng lại bắt đầu từ ký tự đầu tiên.
+ Ký tự dịch chuyển mới này chính là ký tự đã được mã hóa.
2. **Công thức**</p>
`C = (P + k) mod 26`
+ P: Ký tự sau khi giải mã.
+ C: Vị trí của ký tự đã mã hóa trong bảng chữ cái.
+ k: Khóa.
- [x] ***Thuật toán giải mã***
1. **Mã hoá**
+ Để giải mã một ký tự đã mã hóa, thực hiện quy trình ngược lại: dịch chuyển ký tự đó về phía sau trong bảng chữ cái bằng số lượng vị trí tương ứng với khóa.
+ Nếu vượt quá đầu bảng chữ cái, quay vòng lại từ ký tự cuối cùng.
2. **Công thức**</p>
`P = (C - k) mod 26`
+ P: Ký tự sau khi giải mã.
+ C: Vị trí của ký tự đã mã hóa trong bảng chữ cái.
+ k: Khóa.</p>
-- ***KHÔNG GIAN KHOÁ***
+ Không gian khoá = 26 (nếu tính cả 0)
+ Không gian khoá thực sự hữu ích = 25 (nếu loại 0)</p>
-- ***CÁCH PHÁ MÃ (MÀ KHÔNG CẦN KHOÁ)***
+ *Tấn công bằng **Brute Force***: Với số lượng khóa chỉ có 25 giá trị có thể (vì bảng chữ cái tiếng Anh có 26 ký tự), kẻ tấn công có thể thử từng khóa một để giải mã bản mật. Phương pháp này không yêu cầu nhiều kiến thức về văn bản gốc.
+ *Phân tích tần số*: Ngôn ngữ tự nhiên có đặc điểm thống kê riêng. Ví dụ, trong tiếng Anh, các chữ cái như 'E', 'T', 'A' xuất hiện thường xuyên. Kẻ tấn công có thể so sánh tần số các ký tự trong bản mật với tần số chuẩn của ngôn ngữ để suy ra khóa mã hóa.
+ *Tấn công dựa trên bản rõ đã biết*: Khi kẻ tấn công có được một phần văn bản gốc (plaintext) và bản mật (ciphertext) tương ứng, họ có thể tính toán trực tiếp khóa và giải mã phần còn lại.
+ *Tấn công chọn trước bản rõ*: Trong một số tình huống, kẻ tấn công có thể yêu cầu mã hóa một văn bản cụ thể để phân tích và suy luận khóa. Đây là một dạng tấn công có chủ ý nhằm khai thác hệ thống mã hóa.</p>
-- ***CÀI ĐẶT THUẬT TOÁN MÃ HOÁ VÀ GIẢI MÃ BẰNG CODE C++ VÀ BẰNG HTML+CSS++JAVACRIPT.***
+ **Giải mã bằng code C++**</p>
``` cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string caesar(const string &s, int k){
    string r; k = ((k%26)+26)%26;
    for(size_t i=0;i<s.size();++i){
        unsigned char c = s[i];
        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            r += char((c - base + k) % 26 + base);
        } else r += c;
    }
    return r;
}
int main(){
    string text;
    int k, choice;
    cout<<"Nhap chuoi: ";
    getline(cin, text);
    cout<<"Nhap khoa (0-25): ";
    cin>>k;
    cout<<"\nChon: 1-Encrypt: , 2-Decrypt: ";
    cin>>choice;

    if(choice==1){
        cout<< caesar(text, k) << endl;
    } else if(choice==2){
        cout<< caesar(text, 26 - (k%26)) << endl;
    } else if(choice==3){
        string enc = caesar(text, k);
        cout << "Encrypted: " << enc << endl;
}
}
```
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/6728d403-a22e-4db4-a207-ade50fc9dcde" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/84bce59c-9b54-4caf-b1a5-3507fd21a64c" /></P>

+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**</P>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/bc93887e-d5b4-4971-897b-2d38eab97cd1" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/aedf29ba-cec7-4670-9489-8918542a1d81" /></p>

2. ***AFFINE***</p>
-- ***TÊN GỌI***: Affine Cipher, hay Mã hoá affine
<img width="1200" height="712" alt="image" src="https://github.com/user-attachments/assets/b23fce9f-d0d8-44b0-ba1b-99e57560c743" /></p>
-- ***THUẬT TOÁN MÃ HOÁ, THUẬT TOÁN GIẢI MÃ***</p>
**Các hàm mã hoá và giải mã**
- Với a^-1 là nghịch đảo của a theo modul n
<img width="300" height="142" alt="image" src="https://github.com/user-attachments/assets/ab5e53b9-d761-4d64-9444-1b8f4206d94b" /></p>
-- ***KHÔNG GIAN KHOÁ***
+ **a** phải thỏa gcd(a, 26) = 1. → Các giá trị hợp lệ của a là: {1,3,5,7,9,11,15,17,19,21,23,25}
+ **b** có thể chọn từ 0 đến 25 (26 giá trị).</p>
-> Tổng số khóa: 12 x 26 = **312 giá trị**.</p>
-- ***CÁCH PHÁ MÃ (MÀ KHÔNG CẦN KHOÁ)***
+ **Brute-force**: vì chỉ có 312 cặp khóa (a,b), nên thử hết là có thể tìm plaintext hợp lý.
+ Tần suất ký tự: vì đây là phép thay thế đơn bảng chữ cái, phân bố tần suất của ngôn ngữ vẫn bảo toàn nên có thể phân tích tần suất để đoán.</p>
-- ***CÀI ĐẶT THUẬT TOÁN MÃ HOÁ VÀ GIẢI MÃ BẰNG CODE C++ VÀ BẰNG HTML+CSS++JAVACRIPT.***
+ **Giải mã bằng code C++**</p>
``` cpp
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
```
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/62754f83-000f-4eb0-a170-d44eeb6dd092" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/87218db7-b370-47e5-85d0-38f4caf2a31e" /></P>

+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**</P>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/a3dbb45f-665f-4d6b-afb1-d8ea3db4239b" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/41b51f1f-4c20-486b-9791-3fdb0c8299e0" /><P>

3. ***HOÁN VỊ***</p>
-- ***TÊN GỌI***: Mã hoán vị (Transposition Cipher): Là phương pháp mã hóa giữ nguyên ký tự gốc, chỉ thay đổi vị trí sắp xếp theo một khóa (permutation key).</p>
-- ***THUẬT TOÁN MÃ HOÁ, THUẬT TOÁN GIẢI MÃ***</p>
***Mã hoá***
+ Đầu vào: bản rõ P, khóa K = (k1, k2, …, kn) là một hoán vị của 1..n.
+ Viết bản rõ thành bảng có n cột. Nếu chưa đủ thì thêm ký tự đệm (X).
+ Đọc theo thứ tự cột được quy định bởi khóa.
+ Ghép lại → bản mã C.</p>
***Giải mã***
+ Đầu vào: bản mã C, khóa K.
+ Tính số hàng của bảng.
+ Chia bản mã thành các cột, sắp xếp lại đúng vị trí gốc theo khóa.
+ Đọc theo hàng ngang → bản rõ P.</p>
-- ***KHÔNG GIAN KHOÁ***
+ Với số cột là **n**, không gian khóa có **n!** (giai thừa n) khả năng.
+ Ví dụ: n=3 → có **3!=6** khóa.</p>
-- ***CÁCH PHÁ MÃ (MÀ KHÔNG CẦN KHOÁ)***
+ Brute-force: thử tất cả các hoán vị có thể (n! trường hợp).
+ Với bản rõ ngắn và n nhỏ → phá nhanh.
+ Với n lớn → số khóa cực kỳ lớn, khó brute-force.
+ Có thể dùng phân tích tần suất + thử nghiệm hoán vị để nhận diện từ có nghĩa.</p>
-- ***CÀI ĐẶT THUẬT TOÁN MÃ HOÁ VÀ GIẢI MÃ BẰNG CODE C++ VÀ BẰNG HTML+CSS++JAVACRIPT.***
+ **Giải mã bằng code C++**</p>
``` cpp
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
```
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/f306a9c5-1a64-42e3-8cbf-1c023b8f7c22" /></p>
GIẢI MÃ
<img width="1102" height="639" alt="image" src="https://github.com/user-attachments/assets/aa1327db-1ce8-40bc-ac5e-8de7ce2ef01e" /></p>

+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**</P>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/a9872ed1-e2e3-414e-a439-1d43060ab849" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/d2d3c753-8443-4832-b11b-f185633e10f0" /></P>

4. ***VIGENÈRE***</p>
-- ***TÊN GỌI***: Mật mã Vigenère (Vigenère Cipher) là một phương pháp mã hóa thay thế đa bảng (polyalphabetic substitution cipher). Nó dùng một từ khóa để quyết định dịch chuyển các chữ cái.</p>
-- ***THUẬT TOÁN MÃ HOÁ, THUẬT TOÁN GIẢI MÃ***</p>
***Mã hoá***</p>
Cho:
+ **Bản rõ**: P = p1 p2 ... pn
+ **Khóa**: K = k1 k2 ... km (lặp lại để đủ độ dài)
+ **Bản mã**: C = c1 c2 ... cn</p>
Công thức:
` Ci​=(Pi​+Ki​)mod26 `</p>
Trong đó:
+ **Pi** và **Ci**: vị trí chữ cái (A=0, B=1, …, Z=25).
+ **Ki** là vị trí chữ cái trong khóa.</p>
***Giải mã***</p>
` Pi =(Ci − Ki + 26)mod26 `</p>
-- ***KHÔNG GIAN KHOÁ***
+ Khóa là một chuỗi ký tự (chỉ cần độ dài ≥ 1).
+ Nếu bảng chữ cái có 26 ký tự, thì số lượng khóa = **26^m** (m = độ dài khóa).</p>
-- ***CÁCH PHÁ MÃ (MÀ KHÔNG CẦN KHOÁ)***
+ Tần suất chữ cái: với khóa ngắn, có thể đoán dựa vào chu kỳ lặp.
+ Kasiski Examination: tìm khoảng cách lặp lại trong bản mã để suy ra độ dài khóa.
+ Friedman Test: dựa trên chỉ số trùng khớp để ước lượng độ dài khóa.</p>
-- ***CÀI ĐẶT THUẬT TOÁN MÃ HOÁ VÀ GIẢI MÃ BẰNG CODE C++ VÀ BẰNG HTML+CSS++JAVACRIPT.***
+ **Giải mã bằng code C++**</p>
``` cpp
#include <iostream>
#include <string>
using namespace std;
string vigenereEncrypt(const string &text, const string &key) {
    string result = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int k = tolower(key[i % m]) - 'a';
            result += char((c - base + k) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}
string vigenereDecrypt(const string &text, const string &key) {
    string result = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int k = tolower(key[i % m]) - 'a';
            result += char((c - base - k + 26) % 26 + base);
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
    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Ban ma hoa: " << vigenereEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << vigenereDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
    return 0;
}
```
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/bd3c21e7-f7f3-458a-9529-86c77d44172b" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/7891b5a7-c9f7-4173-a4be-6820c9ab5965" /></P>

+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**</P>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/b23e0d47-48db-466d-ba96-ca077dc78649" /></p>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/3828a5fd-4620-41b7-8893-c40486a2b11e" /></p>

5. ***PLAYFAIR***</p>
<img width="1280" height="720" alt="image" src="https://github.com/user-attachments/assets/92ce512e-00ad-4b7f-832a-654fd93431ec" /></P>
-- ***TÊN GỌI***: Mật mã Playfair (Playfair Cipher) là một dạng mã hóa thay thế theo cặp ký tự (digraph substitution cipher), được Charles Wheatstone phát minh (1854) và được Lord Playfair phổ biến.</p>
-- ***THUẬT TOÁN MÃ HOÁ, THUẬT TOÁN GIẢI MÃ***</p>
***Mã hoá***</p>
Chuẩn bị
+ Tạo ma trận 5x5 chứa 25 chữ cái tiếng Anh (I/J thường gộp chung).
+ Khóa là một từ/chuỗi ký tự → điền vào ma trận trước, bỏ chữ trùng lặp, sau đó điền các chữ cái còn lại.</p>
Ví dụ</p>
<img width="442" height="288" alt="image" src="https://github.com/user-attachments/assets/15e68b7b-9bd2-454a-ac5d-9a8c8faecab5" /></p>
***Mã hoá***</p>
+ Chia bản rõ thành các cặp chữ (digraph). Nếu hai chữ cái giống nhau thì chèn "X" vào giữa. Nếu số lẻ → thêm "X" cuối.
+ Với mỗi cặp (a, b):
1. Nếu cùng hàng → thay bằng ký tự bên phải (quay vòng).
2. Nếu cùng cột → thay bằng ký tự bên dưới (quay vòng).
3. Nếu khác hàng & cột → thay bằng ký tự cùng hàng nhưng cột của chữ kia (tạo hình chữ nhật).</p>
***Giải mã***</p>
Ngược lại với mã hóa:</p>
+ Cùng hàng → lấy chữ bên trái.
+ Cùng cột → lấy chữ bên trên.
+ Hình chữ nhật → hoán đổi ngược.</p>
-- ***KHÔNG GIAN KHOÁ***
+ Khóa là chuỗi ký tự bất kỳ → số lượng khóa rất lớn.
+ Với 25 chữ cái, số ma trận có thể = 25! (cực kỳ lớn, không thể vét cạn).</p>
-- ***CÁCH PHÁ MÃ (MÀ KHÔNG CẦN KHOÁ)***
+ Tần suất **digraphs**: vì mã hóa theo cặp chữ, phân tích thống kê cặp chữ cái có thể giúp suy ra ma trận.
+ **Known plaintext attack**: nếu biết một phần bản rõ, có thể suy ra cấu trúc ma trận.</p>
-- ***CÀI ĐẶT THUẬT TOÁN MÃ HOÁ VÀ GIẢI MÃ BẰNG CODE C++ VÀ BẰNG HTML+CSS++JAVACRIPT.***
+ **Giải mã bằng code C++**</p>
``` cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
string generateKeyMatrix(const string &key_input) {
    string key = key_input + "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J = I
    vector<bool> used(26, false);
    string matrix = "";
    for (size_t i = 0; i < key.size(); ++i) {
        char ch = key[i];
        if (!isalpha((unsigned char)ch)) continue;
        ch = toupper((unsigned char)ch);
        if (ch == 'J') ch = 'I';
        int idx = ch - 'A';
        if (!used[idx]) {
            used[idx] = true;
            matrix.push_back(ch);
        }
    }
    if (matrix.size() > 25) matrix = matrix.substr(0, 25);
    return matrix;
}
pair<int,int> findPos(char c, const string &matrix) {
    if (c == 'J') c = 'I';
    int idx = (int)matrix.find(c);
    return make_pair(idx / 5, idx % 5);
}

string prepareText(const string &text) {
    string res = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if (isalpha((unsigned char)ch)) {
            ch = toupper((unsigned char)ch);
            if (ch == 'J') ch = 'I';
            res.push_back(ch);
        }
    }
    string prepared = "";
    for (size_t i = 0; i < res.size(); ++i) {
        prepared.push_back(res[i]);
        if (i + 1 < res.size() && res[i] == res[i+1]) prepared.push_back('X');
    }
    if (prepared.size() % 2 != 0) prepared.push_back('X');
    return prepared;
}
string playfairEncrypt(const string &text, const string &key_input) {
    string matrix = generateKeyMatrix(key_input);
    string prepared = prepareText(text);
    string cipher = "";
    for (size_t i = 0; i + 1 < prepared.size(); i += 2) {
        char a = prepared[i];
        char b = prepared[i+1];
        pair<int,int> pa = findPos(a, matrix);
        pair<int,int> pb = findPos(b, matrix);
        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;
        if (ra == rb) {
            // same row -> shift right
            cipher.push_back(matrix[ra*5 + (ca + 1) % 5]);
            cipher.push_back(matrix[rb*5 + (cb + 1) % 5]);
        } else if (ca == cb) {
            // same column -> shift down
            cipher.push_back(matrix[((ra + 1) % 5) * 5 + ca]);
            cipher.push_back(matrix[((rb + 1) % 5) * 5 + cb]);
        } else {
            // rectangle swap columns
            cipher.push_back(matrix[ra*5 + cb]);
            cipher.push_back(matrix[rb*5 + ca]);
        }
    }
    return cipher;
}
string playfairDecrypt(const string &cipher, const string &key_input) {
    string matrix = generateKeyMatrix(key_input);
    string plain = "";
    for (size_t i = 0; i + 1 < cipher.size(); i += 2) {
        char a = cipher[i];
        char b = cipher[i+1];
        pair<int,int> pa = findPos(a, matrix);
        pair<int,int> pb = findPos(b, matrix);
        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;
        if (ra == rb) {
            // same row -> shift left
            plain.push_back(matrix[ra*5 + (ca + 4) % 5]);
            plain.push_back(matrix[rb*5 + (cb + 4) % 5]);
        } else if (ca == cb) {
            // same column -> shift up
            plain.push_back(matrix[((ra + 4) % 5) * 5 + ca]);
            plain.push_back(matrix[((rb + 4) % 5) * 5 + cb]);
        } else {
            // rectangle swap columns
            plain.push_back(matrix[ra*5 + cb]);
            plain.push_back(matrix[rb*5 + ca]);
        }
    }
    return plain;
}
int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);
    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Ban ma hoa: " << playfairEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << playfairDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
    return 0;
}
```
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/20127f8e-afa5-428e-825f-1e732b36043a" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/ef6cc24c-b6b7-489a-ae4c-7fb5ed636960" /></p>

+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**</p>
MÃ HOÁ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/95c68e6d-662a-4288-b3bc-8d200b953053" /></P>
GIẢI MÃ
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/94a87236-60b9-4bb2-bdde-284dda197a93" /></p>

