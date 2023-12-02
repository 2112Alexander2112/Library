#pragma once
class BookModel
{
	int id;
	std::string title;
	std::string author;
	std::string publishingHouse;
	std::string size;
public:
	BookModel();
	BookModel(int id, std::string title, std::string author, std::string publishingHouse, std::string size);
	int getId() const;
	std::string getTitle() const;
	std::string getAuthor() const;
	std::string getPublishingHouse() const;
	std::string getSize() const;
	void display() const;
};

