# 📚 Quản Lý Danh Sách Sinh Viên

## 🎯 Mục tiêu

Xây dựng chương trình quản lý sinh viên bằng **Danh sách liên kết đơn (Singly Linked List)**.

---

# Cấu trúc dữ liệu

```cpp
struct SinhVien {
    int mssv;
    string name;
    double GPA;
};
```

> Làm tròn GPA:

```cpp
GPA = round(GPA * 100) / 100;
```

---

# 🟢 Chức năng

## 1. Quản lý sinh viên

**Mô tả**

Thêm, xóa và cập nhật thông tin sinh viên trong danh sách liên kết.

### Yêu cầu

- Thêm vào đầu
- Thêm vào cuối
- Thêm vào vị trí bất kỳ
- Xóa đầu
- Xóa cuối
- Xóa theo MSSV
- Cập nhật tên
- Cập nhật GPA

---

## 2. Tìm kiếm

**Mô tả**

Tìm sinh viên theo các tiêu chí.

### Yêu cầu

- Theo MSSV
- Theo tên
- Theo GPA
- Theo điều kiện

---

## 3. Hiển thị

**Mô tả**

In danh sách sinh viên ra màn hình.

### Yêu cầu

- Hiển thị toàn bộ
- Hiển thị theo GPA
- Hiển thị theo điều kiện

---

## 4. Sắp xếp

**Mô tả**

Sắp xếp danh sách theo nhiều tiêu chí.

### Yêu cầu

- Theo MSSV
- Theo tên
- Theo GPA

> Sử dụng `swap()` để hoán đổi dữ liệu.

### Nâng cao

- Sắp xếp theo tên cuối.
- Đổi liên kết node thay vì `swap()`.

---

## 5. Thống kê

- Đếm số lượng sinh viên
- GPA cao nhất
- GPA thấp nhất
- GPA trung bình

---

## 6. File

- Đọc dữ liệu
- Lưu dữ liệu
- Xuất dữ liệu theo điều kiện

---

## 7. Tách / Gộp

- Tách danh sách theo điều kiện
- Gộp hai danh sách

---

# 🔵 Bài tập bổ sung: Quản lý khoa

```cpp
struct Khoa{
    int maKhoa;
    string tenKhoa;
};
```

Có thể bổ sung:

```cpp
struct SinhVien{
    int mssv;
    string name;
    double GPA;
    Khoa khoa;
};
```

## Chức năng

- Quản lý khoa
- Tìm sinh viên theo khoa
- Thống kê theo khoa
- Sắp xếp theo khoa
- File theo khoa

---

# 🖥️ Hệ thống Menu

## Menu chính

```text
================ MENU CHÍNH ================

1. Quản lý sinh viên
2. ...
3. ...
0. Thoát

============================================
```

## Menu quản lý sinh viên

```text
============ QUẢN LÝ SINH VIÊN ============

1. Quản lý sinh viên
2. Tìm kiếm
3. Hiển thị
4. Sắp xếp
5. Thống kê
6. File
7. Tách / Gộp
8. Quản lý khoa

0. Quay lại

===========================================
```

## Menu Quản lý sinh viên

```text
1. Thêm vào đầu
2. Thêm vào cuối
3. Thêm theo vị trí
4. Xóa đầu
5. Xóa cuối
6. Xóa theo MSSV
7. Cập nhật

0. Quay lại
```

## Menu Tìm kiếm

```text
1. Theo MSSV
2. Theo tên
3. Theo GPA
4. Theo điều kiện

0. Quay lại
```

## Menu Hiển thị

```text
1. Toàn bộ
2. Theo GPA
3. Theo điều kiện

0. Quay lại
```

## Menu Sắp xếp

```text
1. Theo MSSV
2. Theo tên
3. Theo GPA
4. Theo tên cuối (Nâng cao)

0. Quay lại
```

## Menu Thống kê

```text
1. Đếm số lượng
2. GPA cao nhất
3. GPA thấp nhất
4. GPA trung bình

0. Quay lại
```

## Menu File

```text
1. Đọc file
2. Ghi file
3. Xuất theo điều kiện

0. Quay lại
```

## Menu Tách / Gộp

```text
1. Tách danh sách
2. Gộp danh sách

0. Quay lại
```

## Menu Quản lý khoa

```text
1. Quản lý khoa
2. Sinh viên theo khoa
3. Thống kê theo khoa
4. Sắp xếp theo khoa
5. File theo khoa

0. Quay lại
```

---

# 📌 Yêu cầu thực hiện

- Sử dụng Danh sách liên kết đơn.
- Mỗi chức năng cài đặt thành một hàm.
- Sử dụng menu `switch-case`.
- Xử lý các trường hợp:
  - Danh sách rỗng.
  - Không tìm thấy sinh viên.
  - Trùng MSSV.
- Khuyến khích chia chương trình thành các file:
  - `main.cpp`
  - `LinkedList.h/.cpp`
  - `Student.h/.cpp`
  - `File.h/.cpp`

---

# ⭐ Gợi ý mở rộng

- Tìm kiếm gần đúng theo tên.
- Lưu dữ liệu dạng CSV.
- Thêm kiểm tra dữ liệu đầu vào.
- Tối ưu thuật toán sắp xếp cho danh sách liên kết.
