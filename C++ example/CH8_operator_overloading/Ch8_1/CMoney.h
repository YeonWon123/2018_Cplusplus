#pragma once
class CMoney
{
public:
	CMoney();
	CMoney(int nDollar, int nCent);
	~CMoney();

private:
	int m_nDollar;
	int m_nCent;

public:
	void SetDollar(int nDollar);
	void SetCent(int nCent);
	int GetDollar() const;
	int GetCent() const;

	// friend 함수는 public이던 private이던 상관없다.
	// friend const CMoney operator + (const CMoney &aMoney, const CMoney &bMoney);
	// friend void showMoney(const CMoney &aMount);
	//const CMoney operator +(CMoney& bMoney);
};
