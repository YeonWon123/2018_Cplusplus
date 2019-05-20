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

	// friend �Լ��� public�̴� private�̴� �������.
	// friend const CMoney operator + (const CMoney &aMoney, const CMoney &bMoney);
	// friend void showMoney(const CMoney &aMount);
	//const CMoney operator +(CMoney& bMoney);
};
