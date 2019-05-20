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
	virtual int Draw(); // 이 Draw()함수는 virtual Draw 함수가 된다.
	int Center();
};

