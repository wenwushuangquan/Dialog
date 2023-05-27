#pragma once


// CAddresEdit

class CAddresEdit : public CEdit
{
	DECLARE_DYNAMIC(CAddresEdit)

public:
	CAddresEdit();
	virtual ~CAddresEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


