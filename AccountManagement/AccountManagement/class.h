#ifndef __CLASS__
#define __CLASS__

#include "head.h"

//계좌 클래스
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

//보통예금계좌 클래스
class NormalAccount : public Account
{
private:
	int interRate;   		// 입금시 발생하는 이자율 %단위
	int kind;
public:
	NormalAccount(const int k,int rating, const int userID, int userBalance, const char *userName);

	NormalAccount(const NormalAccount &copy);


	int ReturnInterRate();


	int ReturnKind();

	void NormalDeposit(int money);

};


//신용계좌 신용계좌 클래스
class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;		//기본이율에 추가되는 이자율
public:
	HighCreditAccount(const int k, const int rating, const int userID, int userBalance, const char *userName);

	HighCreditAccount(const HighCreditAccount &copy);

	void HighCreditDeposit(int money);
};

//BoundCheckPointArray 클래스(계좌저장)
class BoundCheckPointArray
{
private:
	Account **accountArry;
public:
	BoundCheckPointArray();

	void AddAccount(int kind, int rating, int ID, int balance, char *nameptr, int num);

	Account* ReturnAccount(int num);

	void ShowArry(int num) const;

	~BoundCheckPointArray();
};


//Handler 클래스
class AccountHandler
{
private:
	int accountNum = 0;
	BoundCheckPointArray accountList;
public:
	AccountHandler();

	AccountHandler(const AccountHandler &copy);

	void AddAccount(int kind, int rating, int ID, int balance, char *nameptr);

	void HandlerDeposit(int ID, int money);

	void HandlerWithdraw(int ID, int money);

	void ShowAllAccountInfo() const;
};

//입력금액이 -인경우 클래스
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

//출력금액이 잔액보다 큰 경우 클래스
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