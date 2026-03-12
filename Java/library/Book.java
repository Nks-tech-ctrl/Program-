package library;

public class Book {

    int bookId;
    String title;
    String author;

    public void setData(int id, String t, String a) {
        bookId = id;
        title = t;
        author = a;
    }

    public void display() {
        System.out.println("Book ID: " + bookId);
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
    }
}
