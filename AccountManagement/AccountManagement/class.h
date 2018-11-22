#ifndef __CLASS__
#define __CLASS__

#include "head.h"

//���� Ŭ����
class Account
{
private:
	int ID = 0;
	int balance;
	char *name;
public:
	Account(const int userID, int userBalance, const char *userName);

	Account(const Account &copy);

	int IDCompare(int userID);

	virtual void NormalDeposit(int money);

	virtual void HighCreditDeposit(int money);

	virtual int ReturnInterRate();

	virtual int ReturnKind();

	void nDeposit(int money, int interRate);

	void cDeposit(int money, int specialRate);

	void Withdraw(int money);

	int ReturnBalance();

	void ShowAccount() const;

	~Account();
};

//���뿹�ݰ��� Ŭ����
class NormalAccount : public Account
{
private:
	int interRate = 1;   		// �Աݽ� �߻��ϴ� ������ %����
	int kind;
public:
	NormalAccount(const int k, const int userID, int userBalance, const char *userName);

	NormalAccount(const NormalAccount &copy);


	int ReturnInterRate();


	int ReturnKind();

	void NormalDeposit(int money);

};


//�ſ���� �ſ���� Ŭ����
class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;		//�⺻������ �߰��Ǵ� ������
public:
	HighCreditAccount(const int k, const int rating, const int userID, int userBalance, const char *userName);

	HighCreditAccount(const HighCreditAccount &copy);

	void HighCreditDeposit(int money);
};

//BoundCheckPointArray Ŭ����(��������)
class BoundCheckPointArray
{
private:
	Account *accountArry[100];
public:
	BoundCheckPointArray()
	{}

	void AddAccount(Account *account, int num);

	Account* ReturnAccount(int num);

	void ShowArry(int num) const;
};


//Handler Ŭ����
class AccountHandler
{
private:
	BoundCheckPointArray accountList;
	int accountNum;
public:
	AccountHandler();

	AccountHandler(const AccountHandler &copy);

	void AddAccount(Account *account);

	void HandlerDeposit(int ID, int money);

	void HandlerWithdraw(int ID, int money);

	void ShowAllAccountInfo() const;
};

//�Է±ݾ��� -�ΰ�� Ŭ����
class NegativeException
{
private:
	int money;
public:
	NegativeException(int n)
		: money(n)
	{}

	int NeException();
};

//��±ݾ��� �ܾ׺��� ū ��� Ŭ����
class ExcessException
{
private:
	int money;
	int balance;
public:
	ExcessException(int n,int b)
		: money(n), balance(b)
	{}

	int ExException();
};


#endif