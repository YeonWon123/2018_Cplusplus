#pragma once
class CFigure
{
public:
	CFigure();
	~CFigure();

private:
	int m_centerX;
	int m_centerY;

public:
	virtual int Draw(); // �� Draw()�Լ��� virtual Draw �Լ��� �ȴ�.
	int Center();
};

