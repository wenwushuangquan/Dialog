
// AddressListDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AddressList.h"
#include "AddressListDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddressListDlg 对话框



CAddressListDlg::CAddressListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDRESSLIST_DIALOG, pParent)
	, m_bC(FALSE)
	, m_bCode(FALSE)
	, m_bMfc(FALSE)
	, m_bReverse(FALSE)
	, m_strSearch(_T(""))
	, m_strTel(_T(""))
	, m_nGender(0)
  , m_strName(_T(""))
  , m_strAddress(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddressListDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Check(pDX, CHE_C, m_bC);
  DDX_Check(pDX, CHE_CODE, m_bCode);
  DDX_Check(pDX, CHE_MFC, m_bMfc);
  DDX_Check(pDX, CHE_REVERSE, m_bReverse);
  DDX_Text(pDX, EDT_SEARCH, m_strSearch);
  DDX_Text(pDX, EDT_TEL, m_strTel);
  DDX_Control(pDX, LIS_ADDRESSLIST, m_lisAddressList);
  DDX_Radio(pDX, RAD_MAN, m_nGender);
  DDX_Control(pDX, EDT_NAME, m_cName);
  DDX_Control(pDX, EDT_ADDRESS, m_cAddresEdit);
  DDX_Text(pDX, EDT_NAME, m_strName);
  DDX_Text(pDX, EDT_ADDRESS, m_strAddress);
  DDX_Control(pDX, EDT_SEARCH, m_cearch);
  DDX_Control(pDX, EDT_TEL, m_cTel);
}

BEGIN_MESSAGE_MAP(CAddressListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(BTN_ADD, &CAddressListDlg::OnBnClickedAdd)
  ON_BN_CLICKED(BTN_DELETE, &CAddressListDlg::OnBnClickedDelete)
  ON_BN_CLICKED(BTN_MODIFY, &CAddressListDlg::OnBnClickedModify)
  ON_BN_CLICKED(BTN_SEARCH, &CAddressListDlg::OnBnClickedSearch)
  ON_BN_CLICKED(IDC_BUTTON1, &CAddressListDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddressListDlg 消息处理程序

BOOL CAddressListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

    // TODO: 在此添加额外的初始化代码
	int nColIdx = 0;
    m_lisAddressList.InsertColumn(nColIdx++, TEXT("姓名"));
    m_lisAddressList.InsertColumn(nColIdx++, TEXT("性别"));
    m_lisAddressList.InsertColumn(nColIdx++, TEXT("喜好"));
	m_lisAddressList.InsertColumn(nColIdx++, TEXT("手机"));
	m_lisAddressList.InsertColumn(nColIdx++, TEXT("地址"));

	m_lisAddressList.SetExtendedStyle(m_lisAddressList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    //设置宽度
    for (int i = 0; i < nColIdx; ++i)
    {
      BOOL bRtn = m_lisAddressList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
    }



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAddressListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAddressListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAddressListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAddressListDlg::OnBnClickedAdd()
{
  // TODO: 在此添加控件通知处理程序代码
  int nIdx = 0;
  UpdateData();
  CString str_Gender = GetGender();
  CString str_Hobby = GetHobby();
  m_lisAddressList.InsertItem( m_nColCount, m_strName);
  m_lisAddressList.SetItemText(m_nColCount, ++nIdx, str_Gender);
  m_lisAddressList.SetItemText(m_nColCount, ++nIdx, str_Hobby);
  m_lisAddressList.SetItemText(m_nColCount, ++nIdx, m_strTel);
  m_lisAddressList.SetItemText(m_nColCount++, ++nIdx, m_strAddress);


  CHeaderCtrl* pHeadCtrl = m_lisAddressList.GetHeaderCtrl();
  int nColIdx = pHeadCtrl->GetItemCount();
  for (int i = 0; i < nColIdx; ++i)
  {
    BOOL bRtn = m_lisAddressList.SetColumnWidth(i, LVSCW_AUTOSIZE);
  }
}


void CAddressListDlg::OnBnClickedDelete()
{
  // TODO: 在此添加控件通知处理程序代码
  int nIdx = m_lisAddressList.GetSelectionMark();
  m_lisAddressList.DeleteItem(nIdx);
}


void CAddressListDlg::OnBnClickedModify()
{
  // TODO: 在此添加控件通知处理程序代码
  int nSelIdx = m_lisAddressList.GetSelectionMark();
  int nIdx = 0;
  UpdateData();
  CString str_Gender = GetGender();
  CString str_Hobby = GetHobby();
  //修改时，如果使用InsertItem()函数作为第一项，就会在原有的数据上插入一条，不符合修改的要求，所以，只能使用SetItemText()函数，并且设为后置加加
 // m_lisAddressList.InsertItem( nSelIdx, m_strName);
  m_lisAddressList.SetItemText(nSelIdx, nIdx++, m_strName);
  m_lisAddressList.SetItemText(nSelIdx, nIdx++, str_Gender);
  m_lisAddressList.SetItemText(nSelIdx, nIdx++, str_Hobby);
  m_lisAddressList.SetItemText(nSelIdx, nIdx++, m_strTel);
  m_lisAddressList.SetItemText(nSelIdx, nIdx++, m_strAddress);


  CHeaderCtrl* pHeadCtrl = m_lisAddressList.GetHeaderCtrl();
  int nColIdx = pHeadCtrl->GetItemCount();
  for (int i = 0; i < nColIdx; ++i)
  {
    BOOL bRtn = m_lisAddressList.SetColumnWidth(i, LVSCW_AUTOSIZE);
  }

}


void CAddressListDlg::OnBnClickedSearch()
{
  // TODO: 在此添加控件通知处理程序代码
  int n = Serch();
  CString strFmt;
  strFmt.Format(TEXT("%d"), ++n);
  AfxMessageBox(strFmt);
}


CString CAddressListDlg::GetGender()
{
  // TODO: 在此处添加实现代码.
  UpdateData();
  CString str_Rtn;
  switch (m_nGender)
  {
  case 0:
	str_Rtn = TEXT("男");
	break;
  case 1:
    str_Rtn = TEXT("女");
    break;
  case 2:
    str_Rtn = TEXT("未知");
    break;
  default:
	break;
  }
  return str_Rtn;
}


CString CAddressListDlg::GetHobby()
{
  // TODO: 在此处添加实现代码.
  CString str_Rtn;
  if (m_bReverse)
  {
    str_Rtn = TEXT(" 逆向");
  }
  if (m_bCode)
  {
    str_Rtn += TEXT(" 编程");
  }
  if (m_bC)
  {
	str_Rtn += TEXT(" C++");
  }
  if (m_bMfc)
  {
    str_Rtn += TEXT(" MFC");
  }
  return str_Rtn;
}

enum
{
  EM_NAME = 0,
  EM_TEL,
  EM_ADD,
  EM_GENDER,
  EM_HOBBY
};
int CAddressListDlg::Serch()
{
  // TODO: 在此处添加实现代码.
  UpdateData();
  for (int i = 0; i < m_nColCount; ++i)
  {
    if (m_lisAddressList.GetItemText(i, EM_NAME) == m_strSearch)
    {
      return i;
    }
    if (m_lisAddressList.GetItemText(i, EM_ADD) == m_strSearch)
    {
      return i;
    }
  }
  return -2;
}

#define MAN TEXT("男")
#define WOMEN TEXT("女")

void CAddressListDlg::OnBnClickedButton1()
{
  // TODO: 在此添加控件通知处理程序代码
  
  int nRowIndex = 0;  //行（一组数据中单个数据）
  int nColumnIndex = 0;  //列（一组数据）
  m_lisAddressList.InsertItem(nColumnIndex, _T("wenqi"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("12345678901"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("nicaicaicai"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, WOMEN);
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("Debug Reverse Sleep Talking "));

  nRowIndex = 0;
  m_lisAddressList.InsertItem(++nColumnIndex, _T("lulu"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("34543244345"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("hthththtr"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, WOMEN);
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("Sleep"));

  nRowIndex = 0;
  m_lisAddressList.InsertItem(++nColumnIndex, _T("wuwu"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("54656465464"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("yhytmtu"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, MAN);
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("Debug Reverse "));

  nRowIndex = 0;
  m_lisAddressList.InsertItem(++nColumnIndex, _T("mamm"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("45654665654"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("egregrege"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, WOMEN);
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("Sleep Talking "));

  nRowIndex = 0;
  m_lisAddressList.InsertItem(++nColumnIndex, _T("babab"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("34545435353"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("ynytnytntf"));
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, MAN);
  m_lisAddressList.SetItemText(nColumnIndex, ++nRowIndex, _T("Sleep Talking "));

  //自动设置内容宽度
  CHeaderCtrl* pHdrCtr = m_lisAddressList.GetHeaderCtrl();
  for (int i = 0; i < pHdrCtr->GetItemCount(); ++i)
  {
    m_lisAddressList.SetColumnWidth(i, LVSCW_AUTOSIZE);
  }
  m_nColCount = m_lisAddressList.GetItemCount();
}
