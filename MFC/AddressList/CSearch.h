#pragma once


// CSearch

class CSearch : public CEdit
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch();
	virtual ~CSearch();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


