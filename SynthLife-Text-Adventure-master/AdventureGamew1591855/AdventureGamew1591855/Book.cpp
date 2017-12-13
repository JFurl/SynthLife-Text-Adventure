#include "stdafx.h"
#include "Book.h"

Book::Book() {

}

Book::Book(string n, string d):Object(n,d) {

}

string Book::type() {
	return "BOOK";
}

string Book::examine() {
	return getDescription();
}

string Book::open() {
	return "You shake the book. Only has pages in it...";
}

