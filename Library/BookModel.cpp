#include "Header.h"
#include "BookModel.h"

BookModel::BookModel() : id(0), title("---"), author("---"), publishingHouse("---"), size("---")
{
}

BookModel::BookModel(int id, std::string title, std::string author, std::string publishingHouse, std::string size)
	: id(id), title(title), author(author), publishingHouse(publishingHouse), size(size)
{
}

int BookModel::getId() const
{
	return id;
}

std::string BookModel::getTitle() const
{
	return title;
}

std::string BookModel::getAuthor() const
{
	return author;
}

std::string BookModel::getPublishingHouse() const
{
	return publishingHouse;
}

std::string BookModel::getSize() const
{
	return size;
}

void BookModel::display() const
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Publishing House: " << publishingHouse << std::endl;
	std::cout << "Number of pages: " <<  size << std::endl;
	std::cout << std::endl;
}
