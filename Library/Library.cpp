#include "Header.h"
#include "Menu.h"
#include "LibraryManager.h"

int main()
{
	std::string appName = "Library";
	std::vector<std::string> menuItem = {
		{"Add a book to your library"},
		{"Remove a book from the library"},
		{"Search books by author"},
		{"Searching for a book by title"},
		{"Display all available books"},
		{"Program finish"}
	};
	auto menu = std::make_unique<Menu>(appName, menuItem);
	auto library = std::make_unique<LibraryManager>();
	library->loadData();

	bool stop = false;
	do {
		menu->displayAppName();
		menu->displayMenuItem();
		switch (menu->choiceProgram()) {
		case 1:
			library->addBook();
			break;
		case 2:
			library->delBook();
			break;
		case 3:
			library->searchByAuthor();
			break;
		case 4:
			library->bookSearch();
			break;
		case 5:
			library->displayBook();
			break;
		case 6:
			stop = true;
			break;
		}
		if (stop == true) {
			break;
		}
	} while (menu->allowProgram());
}

