#include<iostream>
#include<string>
#include <iomanip>
#include "Book.h"

using namespace std;


void clearWindow() { system("cls"); }

void showWelcome() {
	string str = "";
	cout << setw(40) << "图书管理系统" << endl;
	cout << endl;
}

void showMenu() {
	string str = "";
	cout<< setw(40);

	cout << "请选择功能" << endl;
	cout << endl;

	cout << setw(40) <<"1 添加新书" << endl;
	cout << endl;

	cout << setw(40) << "2 浏览全部" << endl;
	cout << endl;

	cout << setw(40) << "3 删除图书" << endl;
}

void waitUser(){
	int inputpage = 0;
	cout << "E: 返回主菜单 q:退出" << endl;
	char c;
	cin >> c;
	if (c=='q')
	{
		system("exit");
	}
}

void showMainWindow() {
	string str = "";
	cout << setw(60) << setfill('*') << str << endl;
	system("title MainWindow");
	showWelcome();
	showMenu();
}


void guideInput() {
	string name;
	string isbn;
	string author;
	string price;
		
	cout << "输入书名:       " ;
	cin >> name;
	cout << endl << "输入ISBN:       ";
	cin >> isbn;
	cout << endl << "输入作者：      ";
	cin >> author;
	cout << endl << "输入价格：      ";
	cin >> price;

	Book b(name,isbn,author,price);
	b.WriteToFile();
	cout << "Write Finish" << endl;
	waitUser();
}
void viewData() {

	Book b;
	b.getFromFile();
	waitUser();
}

void deleteBookFromFile() {
	cout << "输入要删除的图书行：";
	Book b;
	int lineid;
	cin >> lineid;
	b.deleteData(lineid);
	cout << endl;
	cout << "Delete Finished" << endl;
	waitUser();
}
void mainloop() {
	while (1)
	{
		showMainWindow();
		cout << "输入操作选项：";
		int c;
		cin >> c;
		cout << endl;
		switch (c)
		{
		case 1:
			clearWindow();
			guideInput();
			break;
		case 2:
			clearWindow();
			viewData();
			break;
		case 3:
			clearWindow();
			deleteBookFromFile();
			break;
		}

	}

}