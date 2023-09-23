#include <iostream>
#include <utility>

using namespace std;

// Створення класу "Книга"
class Book {
public:
    string title;
    int numPages;
    double price;

    Book(string t, int np, double p) : title(t), numPages(np), price(p) {}

    virtual void displayInfo() {
        cout << "Книга: " << title << endl;
        cout << "Кількість сторінок: " << numPages << endl;
        cout << "Ціна: " << price << " грн" << endl;
    }
};

// "Бібліотека", який наслідує властивості класу "Книга"
class Library : public Book {
public:
    double discount;

    Library(string t, int np, double p, double d) : Book(std::move(t), np, p), discount(d) {}

    double calculateDiscountedPrice() {
        return price * (1 - discount / 100);
    }

    void displayInfo() override {
        cout << "Бібліотека: " << title << endl;
        cout << "Кількість сторінок: " << numPages << endl;
        cout << "Ціна: " << price << " грн" << endl;
        cout << "Знижка: " << discount << "%" << endl;
    }
};

int main() {
    string bookTitle, libraryTitle;
    int bookPages, libraryPages;
    double bookPrice, libraryPrice, discount;

    cout << "Введіть назву книги: ";
    getline(cin, bookTitle);
    cout << "Введіть кількість сторінок книги: ";
    cin >> bookPages;
    cout << "Введіть ціну книги: ";
    cin >> bookPrice;
    cout << "Введіть назву бібліотеки: ";
    cin.ignore();
    getline(cin, libraryTitle);
    cout << "Введіть кількість сторінок книги в бібліотеці: ";
    cin >> libraryPages;
    cout << "Введіть ціну в бібліотеці: ";
    cin >> libraryPrice;
    cout << "Введіть знижку для бібліотеки (у відсотках): ";
    cin >> discount;

    Book book(bookTitle, bookPages, bookPrice);
    Library library(libraryTitle, libraryPages, libraryPrice, discount);

    cout << "\nІнформація про книгу:" << endl;
    book.displayInfo();

    cout << "\nІнформація про бібліотеку:" << endl;
    library.displayInfo();

    double discountedPrice = library.calculateDiscountedPrice();
    cout << "\nЦіна книги в бібліотеці зі знижкою: " << discountedPrice << " грн" << endl;

    return 0;
}
