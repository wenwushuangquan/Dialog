#pragma once
#include "SelfFrame.h"
#include "resource.h"

class CSelfDialog :public CDialogEx
{
public:
  CSelfDialog(CWnd* pParent = nullptr);

protected:
  DECLARE_MESSAGE_MAP()

public:
  afx_msg void OnBnClickedButton1();

  // 对话框数据
#ifdef AFX_DESIGN_TIME
  enum { IDD = DLG_TEST };
#endif
};

