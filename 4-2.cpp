#include<iostream>
#include<string>
using namespace std;

struct Person
{
    string name = "John";
    string surname = "Doe";
};

struct Book
{
    string title = "Unknown";
    Person author;
    int year = 0;
    int pages = 0;

    void displayBook()
    {
        cout << "Title: " << title << "\n" << "Author: " << author.name << " " << author.surname << "\n" << "Year: " << year << "\n" << "Pages: " << pages << "\n";
    }
};

Book createBook(string title, string name, string surname, int year, int pages)
{
    Person author{name, surname};
    Book book{title, author, year, pages};
    return book;
}

int main()
{
    Book book1 = createBook("The Fall of the House of Usher", "Edgar Allan", "Poe", 1839, 20);
    Book book2 = createBook("Das Kapital", "Carl", "Marx", 1867, 800);
    Book book3;
    Book books[3] = {book1, book2, book3};
    for(int i = 0; i < 3; i++)
    {
        books[i].displayBook();
    }
}