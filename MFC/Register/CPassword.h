#pragma once

#include "CEamil.h"

// CPassword

class CPassword : public CEdit
{
	DECLARE_DYNAMIC(CPassword)

public:
	CPassword();
	virtual ~CPassword();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


