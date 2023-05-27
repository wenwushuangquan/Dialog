#pragma once


// CName

class CName : public CEdit
{
	DECLARE_DYNAMIC(CName)

public:
	CName();
	virtual ~CName();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
  void ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon);
};


