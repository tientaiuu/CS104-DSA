#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


template <typename T>
class HashTable {
private:
    struct Node {
        T key;
        Node* next;
        Node(T k) : key(k), next(nullptr) {}
    };

    // Hàm băm
    size_t hashFunction(T key) {
        double A = (std::sqrt(5) - 1) / 2;
        return static_cast<size_t>(floor(tableSize * (key * A - floor(key * A))));
    }

    Node** table;
    size_t tableSize;
    std::ofstream outputFile;
    size_t deletedCollisions;
    bool collisionDetected; // Cờ biểu thị xung đột trong quá trình insert
    bool searchCollisionDetected; // Cờ biểu thị xung đột trong quá trình search

public:
    HashTable(size_t m, std::string& outputFileName);       // constructor 
    ~HashTable();                                           // destructor
    void insert(T key);                                     // insert function
    void search(T key);                                     // search function
};

// Constructor
template <typename T>
HashTable<T>::HashTable(size_t m, std::string& outputFileName) : table(new Node* [m]()), tableSize(m), deletedCollisions(0), collisionDetected(false), searchCollisionDetected(false) {
    // Mở file output và in ra thông báo khởi tạo thành công
    outputFile.open(outputFileName);
    if (outputFile.is_open()) {
        outputFile << "[constructor] - khoi tao thanh cong" << std::endl;
        outputFile << "+ m = " << m << std::endl;
        outputFile << "+ output file = " << outputFileName << std::endl;
    }
    else {
        // In ra thông báo nếu không thể mở file
        std::cerr << "khoi tao that bai - khong the mo file" << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Destructor
template <typename T>
HashTable<T>::~HashTable() {
    size_t deleted = 0;

    for (size_t i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        Node* previous = nullptr;

        while (current != nullptr) {
            Node* next = current->next;

            // Kiểm tra xem có phần tử nào khác với nó trong linked list không
            bool collisionDetected = false;
            Node* other = table[i];
            while (other != nullptr) {
                if (current != other && current->key == other->key) {
                    collisionDetected = true;
                    break;
                }
                other = other->next;
            }

            // Nếu xung đột và chưa xóa, tăng giá trị deleted
            if (collisionDetected && current != nullptr) {
                delete current;
                ++deleted;
                if (previous != nullptr) {
                    previous->next = next;
                }
                else {
                    table[i] = next;
                }
            }
            else {
                previous = current;
            }

            current = next;
        }
    }

    delete[] table;

    outputFile << "[destructor] - huy bo thanh cong" << std::endl;
    outputFile << "+ so phan tu xung dot da delete = " << deleted << std::endl;
    outputFile << "+ da delete bang T" << std::endl;

    outputFile.close();
}

template <typename T>
void HashTable<T>::insert(T key) {
    // Tính toán index của key trong bảng băm
    size_t index = hashFunction(key);
    Node* newNode = new Node(key);

    // Kiểm tra xung đột
    if (table[index] != nullptr) {
        collisionDetected = true;
        newNode->next = table[index];
    }

    // Thêm newNode vào linked list tại vị trí index
    table[index] = newNode;

    outputFile << "[insert " << key << "] - thanh cong" << std::endl;
    outputFile << "+ key = " << key << std::endl;
    outputFile << "+ hash value = " << index << std::endl;
    outputFile << "+ xung dot = [" << (collisionDetected ? "co" : "khong") << "]" << std::endl;

    // Reset cờ
    collisionDetected = false;
}

template <typename T>
void HashTable<T>::search(T key) {

    // Tính toán index của key trong bảng băm
    size_t index = hashFunction(key);

    // Duyệt qua linked list tại vị trí index
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            // Kiểm tra xung đột trong quá trình search
            outputFile << "[search " << key << "] - tim thay" << std::endl;
            outputFile << "+ key = " << key << std::endl;
            outputFile << "+ hash value = " << index << std::endl;

            if (searchCollisionDetected) {
                outputFile << "+ xung dot = [co]" << std::endl;
            }
            else {
                outputFile << "+ xung dot = [khong]" << std::endl;
            }
            // Reset cờ 
            searchCollisionDetected = false;

            return;
        }
        current = current->next;
    }

    // Đặt cờ
    searchCollisionDetected = true;

    outputFile << "[search " << key << "] - khong tim thay" << std::endl;
    outputFile << "+ key = " << key << std::endl;
    outputFile << "+ hash value = " << index << std::endl;
    outputFile << "+ xung dot = [co]" << std::endl;
}

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        std::cout << "Khong co tham so dong lenh\n";
        return 0;
    }

    const std::string inputFileName(argv[1]);
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Khong the mo file kiem thu '" << inputFileName << "'" << std::endl;
        return 0;
    }

    std::string outputFileName;
    int m, numInsert, numSearch, key;

    // Đọc các tham số đầu vào từ tệp kiểm thử
    inputFile >> outputFileName >> m >> numInsert;

    // Tạo đối tượng HashTable
    HashTable<int> hashTable(m, outputFileName);

    // Chèn các khóa vào bảng băm
    for (int i = 0; i < numInsert; i++) {
        inputFile >> key;
        hashTable.insert(key);
    }

    // Tìm kiếm các khóa
    inputFile >> numSearch;
    for (int i = 0; i < numSearch; i++) {
        inputFile >> key;
        hashTable.search(key);
    }

    return 0;
}