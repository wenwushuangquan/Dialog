
// DialogDlg.h: 头文件
//

#pragma once
#define WM_MYMSG (WM_USER + 1)
#include "CMyEdit.h"


// CDialogDlg 对话框
class CDialogDlg : public CDialogEx
{
// 构造
public:
	CDialogDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDropdownButton1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg LRESULT OnMyMSG(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedOk();
	CMyEdit m_edt;
	afx_msg void OnBnClickedTest5();
	CString m_strText;
	afx_msg void OnBnClickedSet();
	afx_msg void OnBnClickedCstring();
};
