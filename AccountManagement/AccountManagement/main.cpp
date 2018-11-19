#include <iostream>
#include <cstring>

using namespace std;

struct bank
{
	int ID;
	int balance;
	char name[20];
};

void MakeAccount(bank *account)
{
	int i = 0;
	while (1)
	{
		if (account[i].ID == 0)
		{
			cout << "[계좌개설]" << endl;
			cout << "계좌ID : ";
			cin >> account[i].ID;
			cout << account[i].ID << endl;
			cout << "이름 : ";
			cin >> account[i].name;
			cout << account[i].name << endl;
			cout << "잔액 : ";
			cin >> account[i].balance;
			cout << account[i].balance << endl;
			i = 0;
			break;
		}
		else i++;
	}
}



int main(void)
{
	int i = 0;
	int num = 0;
	bank array[100];
	for (i = 0; i < 100; i++)
	{
		array[i].ID = 0;
	}
	i = 0;
	while (1)
	{
		cout << "---------Menu---------" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;

		cin >> num;
		cout << "선택 : " << num << endl;

		if (num == 1)
		{

			MakeAccount(array);

		}
		else if (num == 2)
		{
			int in = 0;
			int inID;
			cout << "[입금]" << endl;
			cout << "계좌ID : ";
			cin >> inID;
			cout << inID << endl;
			cout << "입금액 : ";
			cin >> in;
			cout << in << endl;
			while (1)
			{
				if (array[i].ID == inID)
				{
					array[i].balance = array[i].balance + in;
					i = 0;
					break;
				}
				else i++;
			}

		}
		else if (num == 3)
		{
			int out = 0;
			int outID;
			cout << "[출금]" << endl;
			cout << "계좌ID : ";
			cin >> outID;
			cout << outID << endl;
			cout << "출금액 : ";
			cin >> out;
			cout << out << endl;
			while (1)
			{
				if (array[i].ID == outID)
				{
					array[i].balance = array[i].balance - out;
					i = 0;
					break;
				}
				else i++;
			}
		}
		else if (num == 4)
		{
			for (i = 0; i < 100; i++)
			{
				if (array[i].ID != 0)
				{
					cout << "[전체 출력]" << endl;
					cout << "ID : " << array[i].ID << endl;
					cout << "이름 : " << array[i].name << endl;
					cout << "잔액 : " << array[i].balance << endl;
				}
			}
		}
		else if (num == 5)
			break;
		else
			cout << "잘못된 값을 입력햇습니다." << endl;
	}

	return 0;
}