//  Описать базовый класс «Строка».
//  Методы:
//  1) конструктор без параметров;
//  2) конструктор, принимающий в качестве параметра C - строку(заканчивается нулевым байтом);
//  3) конструктор копирования;
//  4) оператор присваивания;
//  5) получение длины строки;
//  6) очистка строки(сделать строку пустой);
//  7) деструктор;
//  8) конкатенация строк(перегрузить операторы + и += );
//  9) проверка на равенство(= = ) и на неравенство(!= ).


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    // Конструктор без параметров
    String() {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }

    // Конструктор, принимающий C-строку
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Оператор присваивания
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    // Получение длины строки
    int getLength() const {
        return length;
    }

    // Очистка строки
    void clear() {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Конкатенация строк (оператор +)
    String operator+(const String& other) {
        String newString;
        newString.length = length + other.length;
        newString.str = new char[newString.length + 1];
        std::strcpy(newString.str, str);
        std::strcat(newString.str, other.str);
        return newString;
    }

    // Оператор +=
    String& operator+=(const String& other) {
        int oldLength = length;
        length += other.length;
        char* temp = new char[length + 1];
        std::strcpy(temp, str);
        std::strcat(temp, other.str);
        delete[] str;
        str = temp;
        return *this;
    }

    // Оператор ==
    bool operator==(const String& other) {
        return (std::strcmp(str, other.str) == 0);
    }

    // Оператор !=
    bool operator!=(const String& other) {
        return !(*this == other);
    }

    // Функция вывода объекта на экран
    void print() {
        std::cout << str << std::endl;
    }
};

int main() {
    String s1("Hello");
    String s2(" World");

    // Примеры использования
    String s3 = s1 + s2;
    s3.print();

    s1 += s2;
    s1.print();

    std::cout << "Length of s1: " << s1.getLength() << std::endl;

    if (s1 == s3) {
        std::cout << "s1 is equal to s3" << std::endl;
    }
    else {
        std::cout << "s1 is not equal to s3" << std::endl;
    }

    s3.clear();
    s3.print();

    return 0;
}