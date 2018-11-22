#include "head.h"

//Ŭ���� �Լ�
//Account
Account::Account(const int userID, int userBalance, const char *userName)
{
	int len = strlen(userName) + 1;
	name = new char[len];
	strcpy(name, userName);
	balance = userBalance;
	ID = userID;
}

Account::Account(const Account &copy)
	:ID(copy.ID), balance(copy.balance)
{
	//���� ����(deep copy)
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::IDCompare(int userID)
{
	if (ID == userID)
		return 1;
	else
		return 0;
}

void Account::NormalDeposit(int money)
{}

void Account::HighCreditDeposit(int money)
{}

int Account::ReturnInterRate()
{
	return 0;
}

int Account::ReturnKind()
{
	return 0;
}

void Account::nDeposit(int money, int interRate)
{
	balance = balance + money + (money / 100 * interRate);
}

void Account::cDeposit(int money, int specialRate)
{
	balance = balance + money + (money / 100 * ReturnInterRate()) + (money / 100 * specialRate);
}

void Account::Withdraw(int money)
{	
	balance = balance - money;	
}

int Account::ReturnBalance()
{
	return balance;
}

void Account::ShowAccount() const
{
	cout << "ID : " << ID << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << balance << endl;
}

Account::~Account()
{
	delete[]name;
	cout << "�Ҹ��� �۵�" << endl;
}

//NormalAccount�Լ�
NormalAccount::NormalAccount(const int k, int rating, const int userID, int userBalance, const char *userName)
	: Account(userID, userBalance, userName), kind(k), interRate(rating)
{}

NormalAccount::NormalAccount(const NormalAccount &copy)
	: interRate(copy.interRate), kind(copy.kind), Account(copy)
{
	//���� ����(deep copy)
}

int NormalAccount::ReturnInterRate()
{
	return interRate;
}

int NormalAccount::ReturnKind()
{
	return kind;
}

void NormalAccount::NormalDeposit(int money)
{
	nDeposit(money, interRate);
}

//HighCreditAccount�Լ�
HighCreditAccount::HighCreditAccount(const int k, const int rating, const int userID, int userBalance, const char *userName)
	: NormalAccount(k, rating, userID, userBalance, userName), specialRate(rating)
{}

HighCreditAccount::HighCreditAccount(const HighCreditAccount &copy)
	: specialRate(copy.specialRate), NormalAccount(copy)
{
	//���� ����(deep copy)
}

void HighCreditAccount::HighCreditDeposit(int money)
{
	cDeposit(money, specialRate);
}


//BoundCheckPointArray Ŭ���� �Լ�
BoundCheckPointArray::BoundCheckPointArray()
{
	accountArry = new Account*[100];
}

void BoundCheckPointArray::AddAccount(int kind, int rating, int ID, int balance, char *nameptr, int num)
{
	if (kind == NORMAL)
		accountArry[num] = new NormalAccount(kind, rating, ID, balance, nameptr);
	else if(kind == CREDIT)
		accountArry[num] = new HighCreditAccount(kind, rating, ID, balance, nameptr);
}
Account* BoundCheckPointArray::ReturnAccount(int num)
{
	return accountArry[num];
}

void BoundCheckPointArray::ShowArry(int num) const
{
	for (int i = 0; i < num; i++)
	{
		accountArry[i]->ShowAccount();
	}
}

BoundCheckPointArray::~BoundCheckPointArray()
{
		delete[]accountArry;
			cout << "accountArry �Ҹ�" << endl;
}

//AccountHandler Ŭ���� �Լ�
AccountHandler::AccountHandler() : accountNum(0)
{}

AccountHandler::AccountHandler(const AccountHandler &copy)
	: accountNum(copy.accountNum)
{}

void AccountHandler::AddAccount(int kind, int rating, int ID, int balance, char *nameptr)
{
	accountList.AddAccount(kind, rating, ID, balance, nameptr, accountNum);
	accountNum++;
}

void AccountHandler::HandlerDeposit(int ID, int money)
{
	int i = 0;
	while (1)
	{
		if (accountList.ReturnAccount(i)->IDCompare(ID) == 1)
		{
			if (accountList.ReturnAccount(i)->ReturnKind() == 1)
			{
				accountList.ReturnAccount(i)->NormalDeposit(money);
				break;
			}
			else if (accountList.ReturnAccount(i)->ReturnKind() == 2)
			{
				accountList.ReturnAccount(i)->HighCreditDeposit(money);
				break;
			}
		}
		else if (i > accountNum)
			break;
		else i++;
	}
}

void AccountHandler::HandlerWithdraw(int ID, int money)
{
	int i = 0;
	int withdrawID=ID;
	int withdrawMoney=money;

	while (1)
	{
		if (accountList.ReturnAccount(i)->IDCompare(ID) == 1)
		{
			ExcessException ee(withdrawMoney, accountList.ReturnAccount(i)->ReturnBalance());
			if (ee.ExException() == 1)
			{
				accountList.ReturnAccount(i)->Withdraw(money);
				break;
			}
			else
			{
				cout << "��ݾ��� �ٽ� �Է� �ϼ���." << endl;
				cin >> withdrawMoney;
				HandlerWithdraw(withdrawID, withdrawMoney);
				break;
			}
		}
		else if (i > accountNum)
			break;
		else i++;
	}
}

void AccountHandler::ShowAllAccountInfo() const
{
	accountList.ShowArry(accountNum);
}

// -���� Ŭ���� �Լ�
int NegativeException::NeException()
{
	try
	{
		if (money < 0)
			throw money;
		return 1;
	}
	catch (int expn)
	{
		cout << "�߸��� ��(" << expn << ")�� �Է� �߽��ϴ�." << endl;
	}
}


// �ʰ����� Ŭ���� �Լ�
int ExcessException::ExException()
{
	try
	{
		if (money > balance)
			throw balance;
		return 1;
	}
	catch (int expn)
	{
		cout << "�ܾ�("<< expn <<")�� �����մϴ�." << endl;
	}
}



//���°��� �Լ�
void MakeAccountFunc(AccountHandler *account)
{
	int ID, balance, len, rating;
	char kind;
	char crating;
	char name[20];
	char *nameptr;
	cout << "[���°���]" << endl;
	cout << "���� ����(N or C) : ";
	cin >> kind;
	cout << kind << endl;
	if (kind == 'C')
	{
		cout << "�ſ���(A or B or C) : ";
		cin >> crating;
		cout << crating << endl;
	}
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

	if (kind == 'N')
	{
		rating = 0;
		account->AddAccount(NORMAL, rating, ID, balance, nameptr);
	}
	else if (kind == 'C')
	{
		if (crating == 'A') rating = LEVEL_A;
		else if (crating == 'B')rating = LEVEL_B;
		else if (crating == 'C')rating = LEVEL_C;

		account->AddAccount(CREDIT, rating, ID, balance, nameptr);
	}
	delete nameptr;
	cout << "delete nameptr" << endl;
}


//�Ա� �Լ�
void DepositFunc(AccountHandler *account)
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

	NegativeException ne(in);
	if(ne.NeException()==1)
		account->HandlerDeposit(inID, in);
	else
	{
		cout << "�ٽ� �Է� �ϼ���." << endl;
		DepositFunc(account);
	}
}

//��� �Լ�
void WithdrawFunc(AccountHandler *account)
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

	NegativeException ne(out);
	if (ne.NeException() == 1)
		account->HandlerWithdraw(outID, out);		
	else
	{
		cout << "�ٽ� �Է� �ϼ���." << endl;
		WithdrawFunc(account);
	}
}

