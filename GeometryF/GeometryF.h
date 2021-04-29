#pragma once
//#include <stdlib.h>
//#include<stdio.h>
#include<iostream>
#include<stack>
//#include<cstdlib>
//#include "windows.h"
//#include "../GeometryF/MyForm.h"

//#include <Windows.h>

using namespace System::Drawing;

class TRoot
{
protected:
	bool Visible, Active;
public:
	TRoot()
	{
		Visible = false;
		Active = false;
	}
	virtual void Show(Graphics^ gr) = 0;
	//virtual void Hide(Graphics^ gr) = 0;

};

class TPoint : public TRoot
{
protected:
	int x, y;
public:
	TPoint(int _x = 0, int _y = 0) { x = _x; y = _y; }
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	//virtual
	void Show(Graphics^ gr) override
	{
		gr->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
		Visible = true;
	}
	//virtual
	/*void Hide(Graphics^ gr) override
	{
		gr->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
		Visible = false;
	}*/
};

/*
TList <TRoot*> l;
l.InsFirst(new TPoint);
l.InsFirst(new TLine);
l.getCurr()->Show();
*/

class TChart;

struct TLine
{
	TChart* pChart;
	TPoint* pFp, * pLp;
};


class TChart : public TRoot
{
protected:
	TRoot* pFirst, * pLast;
	std:: stack <TLine> st;
public:
	//void Hide(Graphics^ gr) override;
	TChart()
	{
		pFirst = NULL; pLast = NULL;
	}
	int GetSize()
	{
		int res = 0;
		if (pLast)
			res++;
		if (pFirst)
			res++;
		return res;
	}
	void SetFirst(TRoot* p) 
	{
		TPoint* pPoint = dynamic_cast<TPoint*>(p);
		TChart* pChart = dynamic_cast<TChart*>(p);
		if (pPoint || pChart)
			pFirst =p;
	}
	TRoot* GetFirst()
	{
		return pFirst;
	}
	void SetLast(TRoot* p) 
	{
		TPoint* pPoint = dynamic_cast<TPoint*>(p);
		TChart* pChart = dynamic_cast<TChart*>(p);
		if (pPoint || pChart)
			pLast = p;
	}
	TRoot* GetLast()
	{
		return pLast;
	}
	void Show(Graphics^ gr) override //не рекурсия
	{
		TLine CurrLine;
		TRoot * pr;
		TPoint* pp;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		st.push(CurrLine);
		while (!st.empty())
		{
			CurrLine = st.top();
			st.pop();
			while (!CurrLine.pFp)
			{
				pr = CurrLine.pChart->GetFirst();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp)
				{
					CurrLine.pFp = pp;
					pp->Show(gr);
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (CurrLine.pLp == NULL)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pLp = pp;
					pp->Show(gr);
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					st.push(CurrLine);
				}
			}
			if ((CurrLine.pFp != NULL) && (CurrLine.pFp != NULL))
			{
				gr->DrawLine(Pens::Black, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				pp = CurrLine.pLp;
				if (!st.empty())
				{
					CurrLine = st.top();
					st.pop();
					if (CurrLine.pFp == NULL)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
				}
				st.push(CurrLine);
			}
		}
	}
	TRoot* ShowRec(Graphics^ gr, TRoot(*p))
	{
		TPoint* pF, * pL;
		TChart* pCh;
		TRoot* pR;
		pF = dynamic_cast<TPoint*>(p);
		if (pF != NULL)
		{
			pF->Show(gr);
			return pF;
		}
		else
		{
			pCh = dynamic_cast<TChart*>(p);
			pR = ShowRec(gr, pCh->GetFirst());
			pF = dynamic_cast<TPoint*>(pR);
			pR = ShowRec(gr, pCh->GetLast());
			pL = dynamic_cast<TPoint*>(pR);
			if (pF && pL)
			{
				gr->DrawLine(Pens::Black, pF->GetX(), pF->GetY(), pL->GetX(), pL->GetY());
				return pL;
			}
		}
	}
};
