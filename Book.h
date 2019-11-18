#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Book
{
public:
	Book() {}
	Book(const string name, const string isbn, const string author, const string price) :
		m_name(name),m_isbn(isbn),m_author(author),m_price(price)
	{}


	
	string& getName() { return this->m_name; }
	void setName(const string &name) {	m_name = name;}
	string& getIsbn() { return m_isbn; }
	void setIsbn(const string &isbn) { m_isbn = isbn; }
	string& getAuthor() { return m_author; }
	void setAuthor(const string &author) { m_author = author; }
	string& getPrice() { return m_price; }
	void setPrice(const string &price) { m_price = price; }

	void WriteToFile();
	void getFromFile();
	void deleteData(int lineNumber);
private:
	string m_name;
	string m_isbn;
	string m_author;
	string m_price;


};

