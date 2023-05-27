#pragma once


// CRepeat

class CRepeat : public CEdit
{
	DECLARE_DYNAMIC(CRepeat)

public:
	CRepeat();
	virtual ~CRepeat();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


