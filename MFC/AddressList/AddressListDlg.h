
// AddressListDlg.h: 头文件
//

#pragma once
#include "CAddresEdit.h"
#include "CNameEdit.h"
#include "CSearch.h"
#include "CTel.h"

// CAddressListDlg 对话框
class CAddressListDlg : public CDialogEx
{
// 构造
public:
	CAddressListDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDRESSLIST_DIALOG };
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
    int m_nGender;
	int m_nColCount = 0;
	BOOL m_bC;
	BOOL m_bCode;
	BOOL m_bMfc;
	BOOL m_bReverse;
	CString m_strSearch;
	CString m_strTel;
	CListCtrl m_lisAddressList;
	CNameEdit m_cName;
	CAddresEdit m_cAddresEdit;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedSearch();
	CString m_strName;
	CString m_strAddress;
	CString GetGender();
	CString GetHobby();
	CSearch m_cearch;
	CTel m_cTel;
	int Serch();
	afx_msg void OnBnClickedButton1();
};
