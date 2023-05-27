#pragma once


// CPassWord

class CPassWord : public CEdit
{
	DECLARE_DYNAMIC(CPassWord)

public:
	CPassWord();
	virtual ~CPassWord();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	void ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon);
};


