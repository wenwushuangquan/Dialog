#include "CSelfDialog.h"

CSelfDialog::CSelfDialog(CWnd* pParent):
  CDialogEx(DLG_TEST , pParent)
{
}

BEGIN_MESSAGE_MAP(CSelfDialog, CDialogEx)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(BTN_TEST1, &CSelfDialog::OnBnClickedButton1)
END_MESSAGE_MAP()

void CSelfDialog::OnBnClickedButton1()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  AfxMessageBox(_T("����3"));
}