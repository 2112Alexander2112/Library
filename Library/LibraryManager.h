#pragma once
#include "BookModel.h"

class LibraryManager
{
	std::vector<BookModel> library;
public:
	void loadData();
	void saveData();
	void addBook();
	void delBook();
	void searchByAuthor();
	void bookSearch();
	void displayBook() const;

};

