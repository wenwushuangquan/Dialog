#pragma once

// CEamil

class CEamil : public CEdit
{
	DECLARE_DYNAMIC(CEamil)

public:
	CEamil();
	virtual ~CEamil();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


