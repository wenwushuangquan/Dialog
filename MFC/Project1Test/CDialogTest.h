#pragma once
#include "FrameDialog.h"

class CDialogTest:public CDialogEx
{
  // ����
public:
  CDialogTest(CWnd* pParent = nullptr);
  // �Ի�������
#ifdef AFX_DESIGN_TIME
  enum { IDD = DLG_TEST };
#endif
  DECLARE_MESSAGE_MAP()
    afx_msg void OnBnClickedOk();
  afx_msg void OnBnClickedCancel();
  afx_msg void OnBnClickedButton1();
  afx_msg void OnBnClickedButton3();
  afx_msg void OnBnClickedButton2();
};

