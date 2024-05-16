// #ifndef ROM_H
// #define ROM_H

// #include "smb.h"


// namespace LCH
// {
//     class rom
//     {
//     public:
//         rom();
//         void read(int n);

//     private:
//         unsigned char *buffer_; // 指向数据的指针
//         int size_;     // 数据大小
//         int position_; // 当前读取位置
//     };

// }

// #endif

// /*
// class MemoryFile {
// public:
//     MemoryFile(char* data, std::size_t size)
//         : buffer_(data), size_(size), position_(0) {}

//     // 读取数据到目标缓冲区
//     std::streamsize read(char* dest, std::streamsize count) {
//         if (position_ + count > size_) {
//             // 如果请求的数据超过剩余大小，则只读取剩余部分
//             count = size_ - position_;
//         }
//         if (count > 0) {
//             std::memcpy(dest, buffer_ + position_, count);
//             position_ += count;
//         }
//         return count;
//     }

//     // 重置读取位置到文件开始
//     void seekg(std::streampos pos) {
//         if (pos < size_ && pos >= 0) {
//             position_ = static_cast<std::size_t>(pos);
//         }
//     }

//     // 获取当前位置
//     std::streampos tellg() const {
//         return position_;
//     }

//     // 检查是否到达文件末尾
//     bool eof() const {
//         return position_ >= size_;
//     }

// private:
//     char* buffer_; // 指向数据的指针
//     std::size_t size_; // 数据大小
//     std::size_t position_; // 当前读取位置
// };

// // 示例用法
// int main() {
//     // 假设我们有一个静态数组和它的大小
//     const char file_data[] = "Hello, World!";
//     const std::size_t file_size = sizeof(file_data) - 1; // 不包括结束符'\0'

//     // 创建一个MemoryFile对象
//     MemoryFile memory_file(const_cast<char*>(file_data), file_size);

//     // 读取数据
//     char buffer[20];
//     std::streamsize bytes_read = memory_file.read(buffer, 13); // 读取前13个字节

//     // 输出读取到的数据
//     buffer[bytes_read] = '\0'; // 添加结束符
//     std::cout << "Read " << bytes_read << " bytes: " << buffer << std::endl;

//     // 尝试读取更多数据，但此时应该到达文件末尾
//     bytes_read = memory_file.read(buffer, 13);
//     std::cout << "Read " << bytes_read << " bytes (should be less than 13 or 0): " << buffer << std::endl;

//     return 0;
// }
// */