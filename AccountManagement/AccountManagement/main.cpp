#include <iostream>
#include <cstring>

using namespace std;

class bank
{
private:
	int ID = 0;
	int balance;
	char *name;
public:
	bank(const int userID, int userBalance, const char *userName)
	{
		int len = strlen(userName) + 1;
		name = new char[len];
		strcpy(name, userName);
		balance = userBalance;
		ID = userID;
	}

	int IDCompare(int userID)
	{
		if (ID == userID)
			return 1;
		else
			return 0;
	}

	void Deposit(int money)
	{
		balance = balance + money;
	}

	void Withdraw(int money)
	{
		balance = balance - money;
	}

	void ShowAccount()
	{
		cout << "ID : " << ID << endl;
		cout << "�̸� : " << name << endl;
		cout << "�ܾ� : " << balance << endl;

	}

	~bank()
	{
		delete[]name;
		cout << "�Ҹ��� �۵�" << endl;
	}
};

void MakeAccountFunc(int AccountNum, bank **array)
{
	int ID, balance, len;
	char name[20];
	char *nameptr;
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> ID;
	cout << ID << endl;
	cout << "�̸� : ";
	cin >> name;
	cout << name << endl;
	cout << "�ܾ� : ";
	cin >> balance;
	cout << balance << endl;

	len = strlen(name) + 1;
	nameptr = new char[len];
	strcpy(nameptr, name);

	array[AccountNum] = new bank(ID, balance, nameptr);

}

void DepositFunc(int AccountNum, bank **array)
{
	int i = 0;
	int in;
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
		if (array[i]->IDCompare(inID) == 1)
		{
			array[i]->Deposit(in);
			i = 0;
			break;
		}
		else
		{
			i++;
			if (i > AccountNum)
			{
				i = 0;
				break;
			}
		}
	}

}

void WithdrawFunc(int AccountNum, bank **array)
{
	int i = 0;
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
		if (array[i]->IDCompare(outID) == 1)
		{
			array[i]->Withdraw(out);
			i = 0;
			break;
		}
		else
		{
			i++;
			if (i > AccountNum)
			{
				i = 0;
				break;
			}
		}
	}
}

void ShowAllFunc(int AccountNum, bank **array)
{
	int i = 0;
	cout << "[��ü ���]" << endl;
	while (1)
	{
		array[i]->ShowAccount();
		i++;
		if (i == AccountNum)
		{
			i = 0;
			break;
		}
	}
}

int main(void)
{
	int i = 0;
	int AccountNum = 0;
	int num = 0;
	bank *array[100];

	while (1)
	{
		cout << "---------Menu---------" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "----------------------" << endl;
		cin >> num;
		cout << "���� : " << num << endl;

		if (num == 1) //���� ����
		{
			MakeAccountFunc(AccountNum, array);
			AccountNum++;
		}
		else if (num == 2) //�Ա�
		{
			DepositFunc(AccountNum, array);
		}
		else if (num == 3) //���
		{
			WithdrawFunc(AccountNum, array);
		}
		else if (num == 4) //�������� ��ü ���
		{
			ShowAllFunc(AccountNum, array);
		}
		else if (num == 5) //���α׷� ����
			break;
		else
			cout << "�߸��� ���� �Է��޽��ϴ�." << endl;

	}

	if (AccountNum > 0)
	{
		while (1)
		{
			delete array[i];
			cout << "����Ʈ" << endl;
			i++;
			if (i >= AccountNum)
			{
				i = 0;
				break;
			}
			else if (i == 100)
			{
				i = 0;
				break;
			}
		}
	}

	return 0;
}


