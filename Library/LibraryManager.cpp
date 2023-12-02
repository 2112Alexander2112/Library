#include "Header.h"
#include "LibraryManager.h"

void LibraryManager::loadData()
{
	std::ifstream fin;
	fin.open("Library.txt");
	while (!fin.eof()) {
		int id;
		std::string title;
		std::string author;
		std::string publishingHouse;
		std::string size;

		fin >> id;
		fin.ignore();
		std::getline(fin, title);
		std::getline(fin, author);
		std::getline(fin, publishingHouse);
		std::getline(fin, size);

		BookModel book(id, title, author, publishingHouse, size);
		library.push_back(book);
	}
	library.pop_back();
	fin.close();
}

void LibraryManager::saveData()
{
	std::ofstream fout;
	fout.open("Library.txt");
	for (int i = 0; i < library.size(); i++) {
		BookModel temp = library[i];
		fout << temp.getId() << std::endl;
		fout << temp.getTitle() << std::endl;
		fout << temp.getAuthor() << std::endl;
		fout << temp.getPublishingHouse() << std::endl;
		fout << temp.getSize() << std::endl;
	}
	fout.close();
}

void LibraryManager::addBook()
{
	int id;
	std::string title;
	std::string author;
	std::string publishingHouse;
	std::string size;

	id = library.back().getId() + 1;
	std::cin.ignore();
	std::cout << "\n> Name the book: ";
	std::getline(std::cin, title);
	std::cout << "\n> Enter the author of the book: ";
	std::getline(std::cin, author);
	std::cout << "\n> Name the publishing house : ";
	std::getline(std::cin, publishingHouse);
	std::cout << "\n> Enter the number of pages in the book: ";
	std::getline(std::cin, size);

	BookModel book(id, title, author, publishingHouse, size);
	library.push_back(book);
	saveData();
}

void LibraryManager::delBook()
{
	std::string title;
	std::cout << "\n> Specify the title of the book to be deleted: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	auto itro = std::find_if(library.begin(), library.end(), [title](const BookModel& book) {
		return (book.getTitle() == title);
		});
	if (itro == library.end()) {
		std::cout << "\n> Task with Title = " << title << " not fount!\n";
	}
	else {
		library.erase(itro);
		saveData();
	}
}

void LibraryManager::searchByAuthor()
{
	std::string author;
	std::cout << "\n> Enter the author of the book you want to see: ";
	std::cin.ignore();
	std::getline(std::cin, author);

	std::for_each(library.begin(), library.end(), [author](const BookModel& book) {
		if (book.getAuthor() == author) {
			std::cout << std::endl;
			book.display();
		}
		});
}

void LibraryManager::bookSearch()
{
	std::string title;
	std::cout << "\n> Enter book title: ";
	std::getline(std::cin, title);
	
	std::for_each(library.begin(), library.end(), [title](const BookModel& book) {
		if (book.getTitle() == title) {
			std::cout << std::endl;
			book.display();
		}
		});
}

void LibraryManager::displayBook() const
{
	std::cout << "\n> Number of books: " << library.size() << "\n";
	for (int i = 0; i < library.size(); i++) {
		std::cout << std::endl;
		library[i].display();
	}
}
