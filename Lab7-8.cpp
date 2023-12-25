#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
//Вариант 2 Библиотека

//Классы и инкапсуляция. Реализация таких классов, как Book, User и Loan
class Book 
{
private:
    char* book_author = nullptr;         //авторы книги
    char* book_title = nullptr;          //название книги
    int book_year;                       //год выпуска книги
    char* book_ISBN = nullptr;           //ISBN книги
    
public:
    Book(){ //конутруктор без параметров
        setAll("Авторы книги:", "Назывние книги:", 0, "ISBN книги:");
    }
    Book(const char* s_author, const char* s_title, int s_year, char* s_ISBN){ //конструктор с параметрами
        setAll(s_author, s_title, s_year, s_ISBN);
    }
    Book(const Book & book){ //конструктор копирования
        setAll(book.book_author, book.book_title, book.book_year, book.book_ISBN);
    }
    ~Book(){ //деструктор
        delete[] book_author;
        delete[] book_title;
        delete[] book_ISBN;   
    }

    //вывод на экран каждого поля
    void printAuthor() const {
        cout << "Авторы книги: " << book_author << endl;
    }
    void printTitle() const {
        cout << "Название книги: " << book_title << endl;
    }
    void printYear() const {
        cout << "Год выпуска книги: " << book_year << endl;
    }
    void printISBN() const {
        cout << "ISBN книги: " << book_ISBN << endl;
    }
    void printAll() const {
        cout << "Авторы книги: " << book_author << endl;
        cout << "Название книги: " << book_title << endl;
        cout << "Год выпуска книги " << book_year << endl;
        cout << "ISBN книги: " << book_ISBN << endl;

    }

    //редактирование каждого поля
    void setAuthor(const char* s_author) {
        delete[] book_author;
        book_author = new char[strlen(s_author) + 1];
        strcpy(book_author, s_author);
    }
    void setTitle(const char* s_title){
        delete[] book_title;
        book_title = new char[strlen(s_title) + 1];
        strcpy(book_title, s_title);
    }
    void setYear(int s_year){
        book_year = s_year;
    }
    void setISBN(const char* s_ISBN){
        delete[] book_ISBN;
        book_ISBN = new char[strlen(s_ISBN) + 1];
        strcpy(book_ISBN, s_ISBN);
    }
    void setAll(const char* s_author, const char* s_title, int s_year, const char* s_ISBN){
        setAuthor(s_author);
        setTitle(s_title);
        book_year = s_year;
        setISBN(s_ISBN);
    }

    //получение значений каждого поля
    const char* getAuthors() const {
        return book_author;
    }
    const char* getTitle() const {
        return book_title;
    }
    int getYear() const {
        return book_year;
    }
    const char* getISBN() const {
        return book_ISBN;
    }

    //Перегрузка функции в классе Book для поиска книг по разным критериям (название, автор, ISBN).
    // Поиск книги по названию
    bool searchByTitleAndPrint(const char* title) const {
        if (strcmp(book_title, title) == 0) {
            cout << "Найдена книга: " << endl;
            printAll();
            cout << "----------------" << endl;
            return true;
        }
        return false;
    }

    // Поиск книги по автору
    bool searchByAuthorAndPrint(const char* author) const {
        if (strcmp(book_author, author) == 0) {
            cout << "Найдена книга: " << endl;
            printAll();
            cout << "----------------" << endl;
            return true;
        }
        return false;
    }
    // Поиск книги по ISBN
    bool searchByISBNAndPrint(const char* isbn) const {
        if (strcmp(book_ISBN, isbn) == 0) {
            cout << "Найдена книга: " << endl;
            printAll();
            cout << "----------------" << endl;
            return true;
        }
        return false;
    }

    // Виртуальные функции для выведения деталей об издании
    virtual void displayDetails() {
        cout << "Год издания: " << book_year << endl;
    }
};

class User
{
private:
    char* user_name = nullptr;          //имя пользователя
    char* user_email = nullptr;         //email пользователя
    int user_age;                       //возраст пользователя
    int user_ID;                        //ID пользователя

    const static int max_borrowed_books = 10;
    char* borrowedBooks[max_borrowed_books];     // Список заимствованных книг пользователя
    int numBorrowedBooks;                        // Текущее количество заимствованных книг

public: 
    User(){ //конструктор без параметров
        setAll("Имя пользователя:", "email пользователя", 0, 0);
    }
    User(const char* s_name, const char* s_email, int s_age, int s_ID ){ //конструктор с параметрами
        setAll(s_name, s_email, s_age, s_ID);
    }
    User(const User & user){ //конструктор копирования
        setAll(user.user_name, user.user_email, user.user_age, user.user_ID);
    }
    ~User(){ //деструктор
        delete[] user_name;
        delete[] user_email;
        for (int i = 0; i < numBorrowedBooks; ++i) {
            delete[] borrowedBooks[i];
        }
        // delete[] borrowedBooks;
    }

    //вывод на экран каждого поля
    void printName() const {
        cout << "Имя пользователя: " << user_name << endl;
    }
    void printEmail() const {
        cout << "Email пользователя: " << user_email << endl;
    }
    void printAge() const {
        cout << "Возраст пользователя: " << user_age << endl;
    }
    void printID() const {
        cout << "ID пользователя: " << user_ID << endl;
    }
    void printAll() const {
        cout << "Имя пользователя: " << user_name << endl;
        cout << "Email пользователя: " << user_email << endl;
        cout << "Возраст пользователя: " << user_age << endl;
        cout << "ID пользователя: " << user_ID << endl;
    }

    //редактирование каждого поля
    void setName(const char* s_name) {
        delete[] user_name;
        user_name = new char[strlen(s_name) + 1];
        strcpy(user_name, s_name);
    }
    void setEmail(const char* s_email) {
        delete[] user_email;
        user_email = new char[strlen(s_email) + 1];
        strcpy(user_email, s_email);
    }
    void setAge(int s_age){
        user_age = s_age;
    }
    void setID(int s_ID){
        user_ID = s_ID;
    }
    void setAll(const char* s_name, const char* s_email, int s_age, int s_ID){
        setName(s_name);
        setEmail(s_email);
        user_age = s_age;
        user_ID = s_ID;
    }

    //получение значений каждого поля
    const char* getName() const {
        return user_name;
    }
    const char* getEmail() const {
        return user_email;
    }
    int getAge() const {
        return user_age;
    }
    int getID() const {
        return user_ID;
    }

    // Виртуальные функции для обработки различных действий пользователя
    virtual void takeBook(const char* user_ID, const char* book_ISBN) {
        cout << "Пользователь " << user_ID << " взял книгу с  ISBN " << book_ISBN << endl << endl;
    }
    virtual void returnBook(const char* user_ID, const char* book_ISBN) {
        cout << "Пользователь " << user_ID << " вернул книгу с ISBN " << book_ISBN << endl;
    }

    // Перегрузка оператора "<<" для добавления новой книги в список заимствованных
    User& operator<<(const char* book_ISBN) {
        if (numBorrowedBooks < max_borrowed_books) {
            borrowedBooks[numBorrowedBooks] = new char[strlen(book_ISBN) + 1];
            strcpy(borrowedBooks[numBorrowedBooks], book_ISBN);
            numBorrowedBooks++;
            cout << "Пользователь " << user_ID << " добавил книгу с ISBN " << book_ISBN << " в список заимствованных книг." << endl;
        } else {
            cout << "Невозможно добавить больше книг" << endl;
        }
        return *this;
    }
};

class Loan
{
private:
    char* loan_number = nullptr;            //номер залога
    char* loan_deal = nullptr;              //результат залога
public:
    Loan(){ //конструктор без параметров
        setAll("ID залога:", "Результат залога:");
    }
    Loan(const char* s_number, const char* s_deal){ //конструктор с параметрами
        setAll(s_number, s_deal);
    }
    Loan(const Loan & loan){ //конструктор копирования
        setAll(loan.loan_number, loan.loan_deal);
    }
    ~Loan(){ //деструктор
        delete[] loan_number;
        delete[] loan_deal;
    }

    //вывод на экран каждого поля
    void printNumber() const {
        cout << "Номер залога: " << loan_number << endl;
    }
    void printDeal() const {
        cout << "Результат залога: " << loan_deal << endl;
    }
    void printAll() const {
        cout << "Номер залога: " << loan_number << endl;
        cout << "Результат залога: " << loan_deal << endl;
    }

    //редактирование каждого поля
    void setNumber(const char* s_number) {
        delete[] loan_number;
        loan_number = new char[strlen(s_number) + 1];
        strcpy(loan_number, s_number);
    }
    void setDeal(const char* s_deal) {
        delete[] loan_deal;
        loan_deal = new char[strlen(s_deal) + 1];
        strcpy(loan_deal, s_deal);
    }
     void setAll(const char* s_number, const char* s_deal){
        setNumber(s_number);
        setDeal(s_deal);
    }

    //получение значений каждого поля
    const char* getNumber() const {
        return loan_number;
    }
    const char* getDeal() const {
        return loan_deal;
    }

};

//Наследование. Создание специализированного типа journal и dictionary, производных от класса Book.
class Journal : public Book {
private:
    char* journal_series = nullptr;

public:
    void printSeries() const {
        cout << "Серия журнала " << journal_series << endl;
    }
    const char* getSeries() const {
        return journal_series;
    }
    void setSeries(const char* s_series) {
        delete[] journal_series;
        journal_series = new char[strlen(s_series) + 1];
        strcpy(journal_series, s_series);
    }
    void displayDetails() override {
        cout << "Серия журнала" << journal_series << endl;
    }
};

class Dictionaty : public Book {
private:
    char* dictionary_language = nullptr;

public:
    void printLanguage() const {
        cout << "Серия журнала " << dictionary_language << endl;
    }
    const char* getLanguage() const {
        return dictionary_language;
    }
    void setLanguage(const char* s_language) {
        delete[] dictionary_language;
        dictionary_language = new char[strlen(s_language) + 1];
        strcpy(dictionary_language, s_language);
    }
    void displayDetails() override {
        cout << "Язык словаря: " << dictionary_language << endl;
    }
};

// Класс для пользовательского интерфейса
class LibraryInterface {
public:
    void showMainMenu() {
    cout << "Добро пожаловать в библиотеку! " << endl << "Выберите один из вариантов ниже" << endl;
    cout << "1. Поиск книги по названию" << endl;
    cout << "2. Поиск книги по автору" << endl;
    cout << "3. Поиск книги по ISBN" << endl;
    cout << "4. Добавить книгу" << endl;
    cout << "5. Добавить пользователя" << endl;
    cout << "6. Взять книгу " << endl;
    cout << "7. Вернуть книгу" << endl;
    cout << "8. Другое..." << endl;
    }
    //1 Метод для поиска книги по названию
    void searchBookByTitle(const char* title, const Book* books, int numBooks) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].searchByTitleAndPrint(title)){
                return;
            }
        }
            cout << "Книги с таким названием не найдены." << endl << endl;
        }
    
    //2 Метод для поиска книги по автору
    void searchBookByAuthor(const char* author, const Book* books, int numBooks) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].searchByAuthorAndPrint(author)) {
                return;
            }
        }
            cout << "Книги этого автора не найдены." << endl << endl;
    }

    //3 Метод для поиска книги по ISBN
    void searchBookByISBN(const char* isbn, const Book* books, int numBooks) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].searchByISBNAndPrint(isbn)) {
                return;
            }
        }
            cout << "Книги с таким ISBN не найдены." << endl << endl;
    }

    //4 Метод для добавление книг в библиотеку 
    void addBooks() {
    cout << "Введите количество книг:" << endl;
    int count;
    cin >> count;
    Book* books = new Book[count];
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". книга" << endl;

        cout << "Введите автора книги:" << endl;
        char* authors = new char[32];
        cin >> authors;
        books[i].setAuthor(authors);
        delete[] authors;

        cout << "Введите название книги:" << endl;
        char* title = new char[64];
        cin >> title;
        books[i].setTitle(title);
        delete[] title;

        cout << "Введите год издания книги:" << endl;
        int year;
        cin >> year;
        books[i].setYear(year);

        cout << "Введите ISBN книги:" << endl << endl;
        char* ISBN = new char[64];
        cin >> ISBN;
        books[i].setISBN(ISBN);
        delete[] ISBN;
    }
    }

    //5 Метод для добавления пользователя
    void addUser(){
    cout << "Введите количество пользователей:" << endl;
    int count;
    cin >> count;
    User* users = new User[count];
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". пользователь" << endl;

        cout << "Введите имя пользователя:" << endl;
        char* name = new char[32];
        cin >> name;
        users[i].setName(name);
        delete[] name;

        cout << "Введите email пользователя:" << endl;
        char* email = new char[64];
        cin >> email;
        users[i].setEmail(email);
        delete[] email;

        cout << "Введите возраст пользователя:" << endl;
        int age;
        cin >> age;
        users[i].setAge(age);

        cout << "Введите ID пользователя:" << endl << endl;
        int ID;
        cin >> ID;
        users[i].setID(ID);
    }
    }

    //6 метод взятия книги из библиотеки 
    void takeBookFromUser(User& user) {
        char inputISBN[14];         // Строка для ввода ISBN
        char inputID[100];          // Строка для ввода ID пользователя
        cout << "Введите ваше ID: ";
        cin >> inputID;
        cout << "Введите ISBN книги, которую хотите взять: ";
        cin >> inputISBN;
        user.takeBook(inputID, inputISBN);
    }
    //7 метод для возврата книги из библиотеки 
    void returnBookFromUser(User& user) {
        char inputISBN[14];          // Строка для ввода ISBN
        char inputID[100];           // Строка для ввода ID пользователя
        cout << "Введите ваше ID: ";
        cin >> inputID;
        cout << "Введите ISBN книги, которую хотите взять: ";
        cin >> inputISBN;
        user.returnBook(inputID, inputISBN);
    }

    //8
    void outputToFile(const char* filename) {
    FILE* outfile = fopen(filename, "w");
    if (!outfile) {
        cerr << "Error: Невозможно открыть файл" << endl;
        return;
    }
    // Создаем объект книги
    Book book("J.K. Rowling", "Harry Potter", 1997, "9788700631625");
    fprintf(outfile, "%s\n", book.getAuthors());
    fprintf(outfile, "%s\n", book.getTitle());
    fprintf(outfile, "%d\n", book.getYear());
    fprintf(outfile, "%s\n", book.getISBN());

    fclose(outfile);
    }


    void inputFromFile(const char* filename) {
    FILE* infile = fopen(filename, "r");
    if (!infile) {
        cerr << "Error: Невозможно открыть файл" << endl;
        return;
    }
    char author[100], title[100], isbn[14];
    int year;
    // Считываем данные из файла и создаем объекты книг
    while (fscanf(infile, "%s %s %d %s", author, title, &year, isbn) != EOF) {
        // Создаем объект книги на основе прочитанных данных
        Book book(author, title, year, isbn);
        // Делаем что-то с объектом книги, например, добавляем его в массив книг
    }
    fclose(infile);
}
};


int main(){
    int numBooks;
    cin >> numBooks;
    Book books[numBooks];
    LibraryInterface interface;
    User currentUser;
    int choice;

    do {
        interface.showMainMenu();
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();  // Игнорируем символ новой строки во входном потоке

        switch (choice) {
            case 1:
                char author[100];
                cout << "Введите автора: ";
                cin.getline(author, 100);
                interface.searchBookByAuthor(author, books, numBooks);
                break;
            case 2:
                char title[100];
                cout << "Введите название книги: ";
                cin.getline(title, 100);
                interface.searchBookByTitle(title, books, numBooks);
                break;
            case 3:
                char isbn[100];
                cout << "Введите ISBN: ";
                cin.getline(isbn, 100);
                interface.searchBookByISBN(isbn, books, numBooks);
                break;
            case 4:
                interface.addBooks();
                break;
            case 5:
                interface.addUser();
                break;
            case 6:
                interface.takeBookFromUser(currentUser);
                break;
            case 7:
                interface.returnBookFromUser(currentUser);
                break;
            case 8:
                interface.outputToFile("library.txt");
                interface.inputFromFile("library.txt");
                break;
            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } 
    while (choice != 8);
    return 0;
}
