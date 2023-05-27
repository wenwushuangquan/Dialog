#pragma once


// CTel

class CTel : public CEdit
{
	DECLARE_DYNAMIC(CTel)

public:
	CTel();
	virtual ~CTel();

protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


