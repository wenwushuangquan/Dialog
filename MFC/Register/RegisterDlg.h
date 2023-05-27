
// RegisterDlg.h: 头文件
//

#pragma once
#include "CName.h"
#include "CEamil.h"
#include "CPassWord.h"
#include "CRepeat.h"


// CRegisterDlg 对话框
class CRegisterDlg : public CDialogEx
{
// 构造
public:
	CRegisterDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER_DIALOG };
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
	afx_msg void OnBnClickedRegister();
	CName m_name;
	CEamil m_email;
	CPassword m_password;
	CRepeat m_repeat;
	CString m_strName;
	CString m_strEamil;
	CString m_strTEL;
	CString m_strPassWord;
	CString m_strRepeat;
	afx_msg void OnBnClickedOk();
	bool ONEamil();
	bool OnPassWord();
	int m_nFlag;
	void SpecialCharacter();
	void CapitalLetter();
	void LowerCase();
	bool OnRepeat();
	bool OnTEL();
};
