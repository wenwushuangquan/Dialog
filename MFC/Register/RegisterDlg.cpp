
// RegisterDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Register.h"
#include "RegisterDlg.h"
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


// CRegisterDlg 对话框



CRegisterDlg::CRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGISTER_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strEamil(_T(""))
	, m_strTEL(_T(""))
	, m_strPassWord(_T(""))
	, m_strRepeat(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, EDT_NAME, m_name);
	DDX_Control(pDX, EDT_EMAIL, m_email);
	DDX_Control(pDX, EDT_PASSWORD, m_password);
	DDX_Control(pDX, EDT_REPEAT, m_repeat);
	DDX_Text(pDX, EDT_NAME, m_strName);
	DDX_Text(pDX, EDT_EMAIL, m_strEamil);
	DDX_Text(pDX, EDT_TEL, m_strTEL);
	DDX_Text(pDX, EDT_PASSWORD, m_strPassWord);
	DDX_Text(pDX, EDT_REPEAT, m_strRepeat);
}

BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_REGISTER, &CRegisterDlg::OnBnClickedRegister)
  ON_BN_CLICKED(IDOK, &CRegisterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序

BOOL CRegisterDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRegisterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRegisterDlg::OnPaint()
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
HCURSOR CRegisterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegisterDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
  UpdateData();
  int nFlagCount = 0;
  if (!ONEamil())
  {
    AfxMessageBox(TEXT("邮箱必须包括@与.组成"));
  }
  else
  {
	nFlagCount += 1;
  }

  if (!OnTEL())
  {
    AfxMessageBox(TEXT("手机号必须是11位"));
  }
  else
  {
    nFlagCount += 1;
  }

  if (!OnPassWord())
  {
	AfxMessageBox(TEXT("密码必须有大小写和特殊字符"));
  }
  else
  {
    nFlagCount += 1;
  }

  if (!OnRepeat())
  {
	AfxMessageBox(TEXT("重复密码必须和密码一样"));
  }
  else
  {
    nFlagCount += 1;
  }


  if (nFlagCount == 4)
  {
    AfxMessageBox(TEXT("注册成功！"));
	CString strFmt;
	strFmt += TEXT("昵称：");
	strFmt += m_strName;
	strFmt += TEXT("\t\t邮箱：");
	strFmt += m_strEamil;
    strFmt += TEXT("\t\t手机号：");
	strFmt += m_strTEL;
    strFmt += TEXT("\t密码：");
	strFmt += m_strPassWord;
	AfxMessageBox(strFmt);
  }

}


void CRegisterDlg::OnBnClickedOk()
{
  // TODO: 在此添加控件通知处理程序代码
  CDialogEx::OnOK();
}


bool CRegisterDlg::ONEamil()
{
  // TODO: 在此处添加实现代码.
  INT nAt= m_strEamil.Find('@', 0);
  INT nPoint = m_strEamil.Find('.', 0);
  if (nAt > 0 && nPoint > 0)
  {
	return true;
  }
  else
  {
    return false;
  }
}


bool CRegisterDlg::OnPassWord()
{
  // TODO: 在此处添加实现代码.
    m_nFlag = 0;
    SpecialCharacter();
    CapitalLetter();
    LowerCase();
    if (m_nFlag == 3)
    {
      return true;
    }

    return false;
}

void CRegisterDlg::SpecialCharacter()
{
  // TODO: 在此处添加实现代码.
  char cTmp = '!';
  while (true)
  {
    if (
      (('0' <= cTmp) && (cTmp <= '9')) ||
      (('a' <= cTmp) && (cTmp <= 'z')) ||
      (('A' <= cTmp) && (cTmp <= 'Z'))
      )
    {
      cTmp++;
      continue;
    }
    int nFind = m_strPassWord.Find(cTmp, 0);
    if (nFind >= 0)
    {
      m_nFlag += 1;
      break;
    }
    else
    {
      cTmp++;
      if (cTmp == '~' + 1)
      {
        break;
      }
    }
  }
}


void CRegisterDlg::CapitalLetter()
{
  CHAR c = 'A';
  for (; c <= 'Z'; ++c)
  {
    int nFindRtn = m_strPassWord.Find(c, 0);
    if (nFindRtn >= 0)
    {
      m_nFlag += 1;
      break;
    }
  }
}


void CRegisterDlg::LowerCase()
{
  CHAR c = 'a';
  for (; c <= 'z'; ++c)
  {
    int nFindRtn = m_strPassWord.Find(c, 0);
    if (nFindRtn >= 0)
    {
      m_nFlag += 1;
      break;
    }
  }
}


bool CRegisterDlg::OnRepeat()
{
  // TODO: 在此处添加实现代码.
  if (m_strPassWord == m_strRepeat)
  {
	return true;
  }
  return false;
}


bool CRegisterDlg::OnTEL()
{
  // TODO: 在此处添加实现代码.
  if (m_strTEL.GetLength() == 11)
  {
	return true;
  }
  else
  {
    return false;
  }
}
