[chuyen_dề_tin_học_quay_lui_sinh_biểu_thức.md](https://github.com/user-attachments/files/24196045/chuyen_d._tin_h.c_quay_lui_sinh_bi.u_th.c.md)
# CHUYÊN ĐỀ TIN HỌC: QUAY LUI (BACKTRACKING)

---

## I. GIỚI THIỆU

**Quay lui (Backtracking)** là một kỹ thuật giải bài toán bằng cách **thử – sai có hệ thống**. Thuật toán xây dựng lời giải **từng bước**, nếu tại một bước nào đó nhận thấy không thể dẫn tới lời giải đúng thì **quay lui về bước trước** để thử lựa chọn khác.

👉 Có thể hiểu đơn giản: **Nếu đường này mà không đi được thì ta quay lui ngược trở lại chọn đường khác đi thôi.**

---

## II. KHI NÀO ÁP DỤNG QUAY LUI?

### 1️⃣ Nên dùng quay lui khi

- Cần **liệt kê tất cả nghiệm** (in ra mọi cách, mọi cấu hình)
- Số phần tử nhỏ (thường `n ≤ 10–15`)
- Lời giải có thể xây dựng **từng bước độc lập**
- Có khả năng **cắt nhánh sớm**

Ví dụ:

- Sinh xâu
- Sinh hoán vị, tổ hợp
- Sinh biểu thức toán học

---

### 2️⃣ Không nên dùng quay lui khi

- `n` lớn (≥ 20)
- Chỉ cần **1 nghiệm tối ưu** → ưu tiên DP / Greedy
- Không có cách cắt nhánh

---

## III. MẪU QUAY LUI CHUẨN

```cpp
void backtrack(int pos) {
    if (pos == end) {
        check();
        return;
    }
    for (auto choice : choices) {
        apply(choice);   // áp dụng lựa chọn
        backtrack(pos + 1);
        undo(choice);    // hoàn tác trạng thái
    }
}
```

### Giải thích chi tiết

- `pos`: vị trí đang xây dựng trong lời giải
- `choices`: các lựa chọn có thể thử tại vị trí `pos`
- `apply(choice)`: cập nhật trạng thái theo lựa chọn
- `undo(choice)`: đưa trạng thái về như cũ trước khi thử lựa chọn khác

👉 **Quy tắc vàng**: *apply bao nhiêu thì undo bấy nhiêu*.

---

## IV. CÁC BÀI QUAY LUI CƠ BẢN (KINH ĐIỂN)

---

### BÀI 1️⃣: SINH NHỊ PHÂN ĐỘ DÀI n

**Bài toán:** Sinh tất cả các xâu nhị phân gồm `n` bit.

```cpp
int n, a[100];

void backtrack(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j++) cout << a[j];
        cout << '\n';
        return;
    }
    for (int v = 0; v <= 1; v++) {
        a[i] = v;          // apply: gán bit tại vị trí i
        backtrack(i + 1); // sang vị trí tiếp theo
        // không cần undo vì a[i] sẽ bị ghi đè
    }
}
```

**Giải thích:**

- Mỗi vị trí có 2 lựa chọn: `0` hoặc `1`
- Độ sâu đệ quy = `n`
- Đây là bài **nhập môn quay lui**

---

### BÀI 2️⃣: SINH HOÁN VỊ 1..n

**Bài toán:** In ra mọi hoán vị của các số từ `1` đến `n`.

```cpp
int n, a[100];
bool used[100];

void backtrack(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j++) cout << a[j] << ' ';
        cout << '\n';
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            used[v] = true;   // apply: đánh dấu đã dùng
            a[i] = v;
            backtrack(i + 1);
            used[v] = false;  // undo: bỏ đánh dấu
        }
    }
}
```

**Giải thích:**

- `used[v]` đảm bảo mỗi số chỉ xuất hiện một lần
- **Bắt buộc phải undo**, nếu không kết quả sai

---

### BÀI 3️⃣: SINH TỔ HỢP CHẬP k CỦA n

**Bài toán:** Chọn `k` số từ `1..n` sao cho tăng dần.

```cpp
int n, k, a[100];

void backtrack(int i, int last) {
    if (i > k) {
        for (int j = 1; j <= k; j++) cout << a[j] << ' ';
        cout << '\n';
        return;
    }
    for (int v = last + 1; v <= n; v++) {
        a[i] = v;          // chọn v ở vị trí i
        backtrack(i + 1, v);
    }
}
```

**Giải thích:**

- Biến `last` giúp đảm bảo thứ tự tăng dần
- Không cần mảng `used`

---

### BÀI 4️⃣: SINH k-PHÂN

**Bài toán:** Sinh mọi dãy độ dài `n`, mỗi phần tử thuộc `[0, k-1]`.

```cpp
int n, k, a[100];

void backtrack(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j++) cout << a[j];
        cout << '\n';
        return;
    }
    for (int v = 0; v < k; v++) {
        a[i] = v;
        backtrack(i + 1);
    }
}
```

**Giải thích:**

- Tổng quát của sinh nhị phân
- Số nghiệm = `k^n`

---

### BÀI 5️⃣: SINH SỐ SIÊU NGUYÊN TỐ

**Định nghĩa:** Số mà **mọi tiền tố đều là số nguyên tố**.

```cpp
int n;
vector<int> start = {2,3,5,7};

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

void backtrack(int len, int val) {
    if (len == n) {
        cout << val << '\n';
        return;
    }
    for (int d = 1; d <= 9; d += 2) {
        int nxt = val * 10 + d;
        if (isPrime(nxt))      // cắt nhánh
            backtrack(len + 1, nxt);
    }
}
```

**Giải thích:**

- Chỉ thử chữ số lẻ
- Nếu tiền tố không nguyên tố → bỏ nhánh ngay

---

## V. BÀI QUAY LUI NÂNG CAO: ZERO SUM

**Bài toán:** Chèn `+`, `-` hoặc ghép số vào `1..n` sao cho tổng bằng `0`.

```cpp
int n;
string expr = "1";

long long eval(const string& s) {
    long long res = 0, cur = 0;
    char sign = '+';
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == '+' || s[i] == '-') {
            res += (sign == '+' ? cur : -cur);
            if (i < s.size()) sign = s[i];
            cur = 0;
        } else if (s[i] != ' ') {
            cur = cur * 10 + (s[i] - '0');
        }
    }
    return res;
}

void backtrack(int next) {
    if (next > n) {
        if (eval(expr) == 0)
            cout << expr << '\n';
        return;
    }
    for (char op : {' ', '+', '-'}) {
        expr.push_back(op);      // apply
        expr += to_string(next);
        backtrack(next + 1);
        expr.erase(expr.size() - to_string(next).size() - 1); // undo
    }
}
```

**Giải thích:**

- Mỗi vị trí có 3 lựa chọn
- `eval()` dùng để tính giá trị biểu thức

---

## VI. KINH NGHIỆM THI ĐẤU

- Luôn viết quay lui **đúng trước, nhanh sau**
- 90% lỗi là do **undo sai hoặc thiếu**
- Nên luyện theo thứ tự: nhị phân → tổ hợp → hoán vị → biểu thức

---

## VII. TỔNG KẾT

| Nội dung         | Mức độ |
| ---------------- | ------ |
| Quay lui cơ bản  | ⭐⭐     |
| Cắt nhánh        | ⭐⭐⭐    |
| Quay lui kết hợp | ⭐⭐⭐⭐   |

👉 Bản quyền thuộc về Trần Văn Nam

