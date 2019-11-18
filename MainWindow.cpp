#include<iostream>
#include<string>
#include <iomanip>
#include "Book.h"

using namespace std;


void clearWindow() { system("cls"); }

void showWelcome() {
	string str = "";
	cout << setw(40) << "ͼ�����ϵͳ" << endl;
	cout << endl;
}

void showMenu() {
	string str = "";
	cout<< setw(40);

	cout << "��ѡ����" << endl;
	cout << endl;

	cout << setw(40) <<"1 �������" << endl;
	cout << endl;

	cout << setw(40) << "2 ���ȫ��" << endl;
	cout << endl;

	cout << setw(40) << "3 ɾ��ͼ��" << endl;
}

void waitUser(){
	int inputpage = 0;
	cout << "E: �������˵� q:�˳�" << endl;
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
		
	cout << "��������:       " ;
	cin >> name;
	cout << endl << "����ISBN:       ";
	cin >> isbn;
	cout << endl << "�������ߣ�      ";
	cin >> author;
	cout << endl << "����۸�      ";
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
	cout << "����Ҫɾ����ͼ���У�";
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
		cout << "�������ѡ�";
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