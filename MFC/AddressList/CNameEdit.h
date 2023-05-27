#pragma once


// CNameEdit

class CNameEdit : public CEdit
{
	DECLARE_DYNAMIC(CNameEdit)

public:
	CNameEdit();
	virtual ~CNameEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


