#include "CDialogAppTest.h"
#include "CDialogTest.h"

CDialogAppTest g_App;

BOOL CDialogAppTest::InitInstance()
{
  CDialogTest Dlg;
  Dlg.DoModal();
  return 0;
}
