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
			cout << "[���°���]" << endl;
			cout << "����ID : ";
			cin >> account[i].ID;
			cout << account[i].ID << endl;
			cout << "�̸� : ";
			cin >> account[i].name;
			cout << account[i].name << endl;
			cout << "�ܾ� : ";
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
		cout << "1. ���� ����" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;

		cin >> num;
		cout << "���� : " << num << endl;

		if (num == 1)
		{

			MakeAccount(array);

		}
		else if (num == 2)
		{
			int in = 0;
			int inID;
			cout << "[�Ա�]" << endl;
			cout << "����ID : ";
			cin >> inID;
			cout << inID << endl;
			cout << "�Աݾ� : ";
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
			cout << "[���]" << endl;
			cout << "����ID : ";
			cin >> outID;
			cout << outID << endl;
			cout << "��ݾ� : ";
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
					cout << "[��ü ���]" << endl;
					cout << "ID : " << array[i].ID << endl;
					cout << "�̸� : " << array[i].name << endl;
					cout << "�ܾ� : " << array[i].balance << endl;
				}
			}
		}
		else if (num == 5)
			break;
		else
			cout << "�߸��� ���� �Է��޽��ϴ�." << endl;
	}

	return 0;
}