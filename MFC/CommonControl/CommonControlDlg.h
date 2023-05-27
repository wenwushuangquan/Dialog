
// CommonControlDlg.h: 头文件
//

#pragma once


// CCommonControlDlg 对话框
class CCommonControlDlg : public CDialogEx
{
// 构造
public:
	CCommonControlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMMONCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedAdd();
  afx_msg void OnBnClickedSelected();
  afx_msg void OnBnClickedDelete();
  afx_msg void OnBnClickedTest();
  CString m_strName;
  CComboBox m_comFrom;
  int m_nGender;
  BOOL m_bCode;
  BOOL m_bDebug;
  BOOL m_bReverse;
  afx_msg void OnBnClickedModiy();
  CListCtrl m_lisTest;
  int m_nItemIdx = 0;
};
