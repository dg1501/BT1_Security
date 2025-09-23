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
string encrypt(const string &s, int k) {
    string r;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isalpha((unsigned char)c)) {
            char b = isupper((unsigned char)c) ? 'A' : 'a';
            r += char((c - b + k) % 26 + b);
        } else r += c;
    }
    return r;
}
string decrypt(const string &s, int k) {
    return encrypt(s, 26 - (k % 26));
}
int main(){
    string t; int k;
    getline(cin, t);
    cin >> k;
    string e = encrypt(t, k);
    cout << e << '\n' << decrypt(e, k) << '\n';
}
```
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/6728d403-a22e-4db4-a207-ade50fc9dcde" /></P>
+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/bc93887e-d5b4-4971-897b-2d38eab97cd1" />

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
```
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/62754f83-000f-4eb0-a170-d44eeb6dd092" />
+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/a3dbb45f-665f-4d6b-afb1-d8ea3db4239b" />

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
string transposeEncrypt(const string &text, const vector<int> &key) {
    int cols = key.size();
    int rows = (text.size() + cols - 1) / cols;
    vector<vector<char> > matrix(rows, vector<char>(cols, 'X'));
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
int main(){
    string text;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);
    int n;
    cout << "Nhap do dai khoa: ";
    cin >> n;
    vector<int> key(n);
    cout << "Nhap khoa (vi du: 3 1 2): ";
    for (int i = 0; i < n; ++i) cin >> key[i];
    cout << "Ban ma hoa: " << transposeEncrypt(text, key) << endl;
    return 0;
}
```
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/f306a9c5-1a64-42e3-8cbf-1c023b8f7c22" />
+ **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/a9872ed1-e2e3-414e-a439-1d43060ab849" />
