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
private:
    int get_book_index(Book book){
        auto it = find(this->shelf.begin(), this->shelf.end(), book);

        if(it != this->shelf.end()){
            return it - this->shelf.begin();
        }
        return -1;
    }
public:
    vector<Book> shelf = {Book("Book 1", "God"), Book("Book2", "Tw")};

    Shelf(){}

    Shelf(vector<Book> shelf){
        this->shelf = shelf;
    }

    void show_book(){
        for (int i=0; i<this->shelf.size();i++){
            cout << "Book NO." << i+1 << "). ";
            this->shelf[i].info();
            cout << endl;
        }
    }

    void add_book(Book new_book){
        this->shelf.push_back(new_book);
    }

    void remove_book(Book book){
        int ind;
        this->shelf.erase(this->shelf.begin());
    }


};

int main(){
    Book something = Book("No Name", "God");

    Shelf shelf1 = Shelf();
    shelf1.show_book();

}