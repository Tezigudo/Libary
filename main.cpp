#include <iostream>
#include <vector>
// #include <tuple>
#include <time.h>

using namespace std;

class Book{
// private:
//     string author;
//TODO: make a getter setter later
public:
    string name;
    string author;
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
    vector<Book> shelf = {Book("Book1", "God"), Book("Book2", "Tw")};

    Shelf(){}

    Shelf(vector<Book> shelf){
        this->shelf = shelf;
    }

    int get_book_index(Book book){
        for(int i=0;i<this->shelf.size();i++){
            
            if (&this->shelf[i] == &book){ //check if equal by pointer
                return i;
            }
        }

        return -1;
    }

    int get_book_index(string name, string author){
        for (auto itr = this->shelf.begin();itr!=this->shelf.end();itr++){
            if ((*itr).name == name && (*itr).author == author){
                return itr - this->shelf.begin();
            }
        }
        return -1;
    }

    void show_book(){
        cout << "Now book in the shelf are: " << endl;
        for (int i=0; i<this->shelf.size();i++){
            cout << "Book NO." << i+1 << "). ";
            this->shelf[i].info();
            cout << endl;
        }
    }

    void add_book(Book new_book){
        this->shelf.push_back(new_book);
        new_book.info();
        cout << " has added to shelf" << endl;
        cout << endl;
    }

    void remove_book(string name, string author){
        int ind;
        this->shelf.erase(this->shelf.begin()+this->get_book_index(name, author));
        cout << "Book Name: " << name << " _Autrhor: "<< author << " has removed to shelf" << endl;
        cout << endl;
    }


};

int get_option(){
    while (1){
    cout << "Welcome to Tezigudo Libary" << endl << endl;
    cout << "Please select a menu"<< endl;
    cout << "1.) show all book" << endl;
    cout << "2.) Add book" << endl;
    cout << "3.) Borrow book" << endl;
    cout << "4.) Exit Program" << endl << endl;
    cout << "Enter choice(1-4): ";
    int choice;
    cin >> choice;
    if(0 < choice && choice < 5){
        return choice;
    }else{
        cout << endl;
        cout << "Please Enter a valid choice" << endl;;
    }
    };

};

// tuple<string, string> get_name_and_author(){
//     string name, author;
//     cout << "Please enter book's name: ";
//     cin >> name;
//     cout << "Please enter book's author: ";
//     cin >> author;
//     return make_tuple(name, author);

// }


int main(){
    // * test zone
    // Book something = Book("No Name", "God");

    // Shelf shelf1 = Shelf();
    // shelf1.show_book();

    // cout << shelf1.get_book_index("Book2", "Tw") << endl;
    // cout << shelf1.get_book_index("No Name", "God") << endl;
    // shelf1.add_book(something);
    // cout << shelf1.get_book_index("No Name", "God") << endl;
    // shelf1.show_book();

    // * proj zone
    Shelf lib = Shelf();
    int choice = get_option();
    switch (choice){
    case 1: {
        lib.show_book();
        break;
    }
    case 2: {
        cout << endl;
        cout << "Please enter information of book you want to add into shelf" << endl;
        string name, author;
        // tie(name, author) = get_name_and_author();

        cout << "Please enter book's name: ";
        cin >> name;
        cout << "Please enter book's author: ";
        cin >> author;

        Book new_book = Book(name, author);
        lib.add_book(new_book);
        break;
    }
    case 3:{
        cout << "Please enter information of book you want to borrow" << endl;
        string name, author;
        cout << "Please enter book's name: ";
        cin >> name;
        cout << "Please enter book's author: ";
        cin >> author;
        break;
    }
    case 4:{
        cout << "Invalid Option" << endl;
    }
    }

}