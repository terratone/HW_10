//  Создайте иерархию классов по работе с файлами. Базовый
//  класс умеет открывать файл и отображать его содержимое в консоль,
//  первый класс потомка открывает файл и отображает содержимое в виде ASCII-кодов символов,
//  расположенных в файле, второй класс потомка открывает
//  и показывает его содержимое в двоичном виде и т.д.
//  Для отображения содержимого файла в базовом классе
//  определена виртуальная функция
//  void Display(const char* path);
//  path — путь к файлу.
//  Потомки создают свою реализацию виртуальной функции.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Базовый класс для работы с файлами
class FileHandler {
public:
    // Открыть файл
    void Open(const char* path) {
        fileStream.open(path);
    }

    // Виртуальная функция для отображения содержимого файла
    virtual void Display(const char* path) {
        Open(path);
        string content;
        while (getline(fileStream, content)) {
            cout << content << endl;
        }
    }

protected:
    std::ifstream fileStream;
};

// Первый класс-потомок
class AsciiFileHandler : public FileHandler {
public:
    // Переопределение функции Display для отображения содержимого в виде ASCII-кодов
    void Display(const char* path) override {
        Open(path);
        char ch;
        while (fileStream.get(ch)) {
            cout << static_cast<int>(ch) << " ";
        }
        cout << endl;
    }
};

// Второй класс-потомок
class BinaryFileHandler : public FileHandler {
public:
    // Переопределение функции Display для отображения содержимого в двоичном виде
    void Display(const char* path) override {
        Open(path);
        char byte;
        while (fileStream.get(byte)) {
            for (int i = 7; i >= 0; i--) {
                std::cout << ((byte >> i) & 1);
            }
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    FileHandler baseHandler;
    AsciiFileHandler asciiHandler;
    BinaryFileHandler binaryHandler;

    // Отображение содержимого файла с помощью базового класса
    baseHandler.Display("sample.txt");

    // Отображение содержимого файла в виде ASCII-кодов
    asciiHandler.Display("sample.txt");

    // Отображение содержимого в двоичном виде
    binaryHandler.Display("sample.txt");

    return 0;
}