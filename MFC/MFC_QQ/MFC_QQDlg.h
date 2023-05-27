
// MFC_QQDlg.h: 头文件
//

#pragma once
#include "CPassWord.h"


// CMFCQQDlg 对话框
class CMFCQQDlg : public CDialogEx
{
// 构造
public:
	CMFCQQDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_QQ_DIALOG };
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
	CPassWord m_passWord;

    // 气泡的提示,Unicode版本
	void ShowBalloonTip(HWND hWnd, LPCTSTR lpszText, LPCTSTR lpszTittle, int nTTIcon);
	afx_msg void OnBnClickedLogoin();
	CString m_strPassWord;
	// 筛选有大小写和特殊字符
	bool Filter();
private:
  // 特殊字符的筛选
  void SpecialCharacter();
public:
  // 标志变量，数值小于等于需求的总量
  int m_nFlag;
private:
  // 大写字符
  void CapitalLetter();
  // 小写字符
  void LowerCase();
};
