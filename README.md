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
1. **Giải mã bằng code C++**</p>
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
2. **Giải mã bằng HTML+CSS+JAVACRIPT**</p>
**Kết quả**
<img width="995" height="576" alt="image" src="https://github.com/user-attachments/assets/bc93887e-d5b4-4971-897b-2d38eab97cd1" />





