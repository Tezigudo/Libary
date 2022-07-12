#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Book{
private:
    string author;
public:
    string name;
    Book(string name, string author){
        this->name = name;
        this->author = author;
    }

    void get_author(){
        cout << "author of this book is " << this->author << endl;
    }

    void information(){
        printf("This book name: %8s\nThis book author: %3s", this->name.c_str(), this->author.c_str());
        cout << endl;
    }

    void info(){
        cout << this->name.c_str() << " by " << this->author.c_str();
    }


};

class Shelf {
public:
    vector<Book> shelf = {Book("Book 1", "God"), Book("Book2", "Tw")};

    Shelf(){}

    Shelf(vector<Book> shelf){
        this->shelf = shelf;
    }

    void show_book(){
        for (int i=0; i<this->shelf.size();i++){
            cout << "Book NO." << i+1 << "). " << this->shelf[i].info() << endl;
        }
    }


};

int main(){
    Book something = Book("No Name", "God");

    Shelf shelf1 = Shelf();
    shelf1.show_book();

}