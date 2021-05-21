#pragma once

#include<iostream>
#include<stack>
#include<windows.h>
#include<cmath>
#include<fstream>

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
	virtual void Hide(Graphics^ gr) = 0;

};

class TPoint : public TRoot
{
protected:
	int x, y;
public:
	TPoint(int _x = 0, int _y = 0) { x = _x; y = _y; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void Show(Graphics^ gr) override
	{
		gr->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
		Visible = true;
	}
	void Hide(Graphics^ gr) override
	{
		gr->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
		Visible = false;
	}
};

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
	TChart()
	{
		pFirst = NULL; pLast = NULL;
	}
	~TChart()
	{
		if (pFirst)
			delete pFirst;
		if (pLast)
			delete pLast;
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
	void Show(Graphics^ gr) override 
	{
		TLine CurrLine;
		TRoot* pr;
		TPoint* pp;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		while (!st.empty())
		{
			st.pop();
		}
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
			if (!CurrLine.pLp)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp)
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
			if (CurrLine.pFp && CurrLine.pLp)
			{
				gr->DrawLine(Pens::Black, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				pp = CurrLine.pLp;
				if (!st.empty())
				{
					CurrLine = st.top();
					st.pop();
					if (!CurrLine.pFp)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					st.push(CurrLine);
				}
			}
		}
	}
	void Hide(Graphics^ gr) override 
	{
		TLine CurrLine;
		TRoot* pr;
		TPoint* pp;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		while (!st.empty())
		{
			st.pop();
		}
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
					pp->Hide(gr);
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (!CurrLine.pLp)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp)
				{
					CurrLine.pLp = pp;
					pp->Hide(gr);
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					st.push(CurrLine);
				}
			}
			if (CurrLine.pFp && CurrLine.pLp)
			{
				gr->DrawLine(Pens::White, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				pp = CurrLine.pLp;
				if (!st.empty())
				{
					CurrLine = st.top();
					st.pop();
					if (!CurrLine.pFp)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					st.push(CurrLine);
				}
			}
		}
	}
    void TChart::InsLine(TChart* line) //bool
	{
		TPoint* first = dynamic_cast<TPoint*>(line->GetFirst());
		TPoint* last = dynamic_cast<TPoint*>(line->GetLast());
		TLine CurrLine;
		TRoot* pr;
		TPoint* pp;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		while (!st.empty())
		{
			st.pop();
		}
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
					if (abs(pp->GetX() - first->GetX()) < 2 && abs(pp->GetY() - first->GetY()) < 2)
					{
						CurrLine.pChart->SetFirst(line);
						TRoot* tmp = line->GetFirst();
						line->SetFirst(line->GetLast());
						line->SetLast(tmp);
					//	return true;
					}
					else if (abs(pp->GetX() - last->GetX()) < 2 && abs(pp->GetY() - last->GetY()) < 2)
					{
						CurrLine.pChart->SetFirst(line);
					//	return true;
					}
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (!CurrLine.pLp)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp)
				{
					CurrLine.pLp = pp;
					if ((abs(pp->GetX() - first->GetX()) < 2 && abs(pp->GetY() - first->GetY()) < 2))
					{
						CurrLine.pChart->SetLast(line);
						TRoot* tmp = line->GetFirst();
						line->SetFirst(line->GetLast());
						line->SetLast(tmp);
						//return true;
					}
					else if (abs(pp->GetX() - last->GetX()) < 2 && abs(pp->GetY() - last->GetY()) < 2)
					{
						CurrLine.pChart->SetLast(line);
						//return true;
					}
				}
				else
				{
					st.push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					st.push(CurrLine);
				}
			}
			if (CurrLine.pFp && CurrLine.pLp)
			{
				pp = CurrLine.pLp;

				if (!st.empty())
				{
					CurrLine = st.top();
					st.pop();

					if (!CurrLine.pFp)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					st.push(CurrLine);
				}
			}
		}
	//	return false;
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
