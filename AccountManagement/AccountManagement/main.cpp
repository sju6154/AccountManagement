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
		cout << "이름 : " << name << endl;
		cout << "잔액 : " << balance << endl;

	}

	~bank()
	{
		delete[]name;
		cout << "소멸자 작동" << endl;
	}
};

void MakeAccountFunc(int AccountNum, bank **array)
{
	int ID, balance, len;
	char name[20];
	char *nameptr;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> ID;
	cout << ID << endl;
	cout << "이름 : ";
	cin >> name;
	cout << name << endl;
	cout << "잔액 : ";
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
	cout << "[입금]" << endl;
	cout << "계좌ID : ";
	cin >> inID;
	cout << inID << endl;
	cout << "입금액 : ";
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
	cout << "[출금]" << endl;
	cout << "계좌ID : ";
	cin >> outID;
	cout << outID << endl;
	cout << "출금액 : ";
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
	cout << "[전체 출력]" << endl;
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
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "----------------------" << endl;
		cin >> num;
		cout << "선택 : " << num << endl;

		if (num == 1) //계좌 개설
		{
			MakeAccountFunc(AccountNum, array);
			AccountNum++;
		}
		else if (num == 2) //입금
		{
			DepositFunc(AccountNum, array);
		}
		else if (num == 3) //출금
		{
			WithdrawFunc(AccountNum, array);
		}
		else if (num == 4) //계좌정보 전체 출력
		{
			ShowAllFunc(AccountNum, array);
		}
		else if (num == 5) //프로그램 종료
			break;
		else
			cout << "잘못된 값을 입력햇습니다." << endl;

	}

	if (AccountNum > 0)
	{
		while (1)
		{
			delete array[i];
			cout << "딜리트" << endl;
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


