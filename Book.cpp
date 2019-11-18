#include "Book.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void Book::WriteToFile()
{
	ofstream ofs;
	ofs.open("book.txt", ios::app);
	try
	{
		ofs << m_name.c_str() << " " << m_isbn.c_str() << " "
			<< m_author.c_str() << " " << m_price.c_str() << endl;
	}
	catch (...)
	{
		throw "file error occurred";
		ofs.close();
	}
	ofs.close();
}
void Book::getFromFile() 
{


	ifstream ifs;
	ifs.open("book.txt", ios::in);
	try
	{
		string temp;
		while (getline(ifs, temp)) {
			cout << temp << endl;
		}
	}
	catch (...)
	{
		throw "file error occurred!";
		ifs.close();
	}
	ifs.close();
}
void Book::deleteData(int lineNumber) 
{
	fstream tempfile("temp.txt",fstream::in | fstream::out | fstream::trunc);
	if (!tempfile) cerr << "no tempfile\n";
	fstream file("book.txt", fstream::in | fstream::out);
	
	string temp;
	try
	{
		int i = 1;
	
		while (getline(file,temp))
		{
			if (i++ == lineNumber)
			{
				continue;
			}
			tempfile << temp << endl;
		}

	}
	catch (const std::exception&)
	{
		throw "file error occurred!";
		file.close();
		tempfile.close();
	}

	file.close();
	file.open("book.txt",ios::out);
	tempfile.seekg(0, ios::beg);
	while (getline(tempfile,temp))
	{
		file << temp << endl;
	}
	file.close();
	tempfile.close();
	remove("temp.txt");
}