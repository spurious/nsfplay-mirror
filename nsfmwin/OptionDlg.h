#pragma once
#include "afxcmn.h"


// COptionDlg �_�C�A���O

class COptionDlg : public CDialog
{
	DECLARE_DYNAMIC(COptionDlg)

public:
	COptionDlg(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~COptionDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_OPTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
  int m_priority;
  CSliderCtrl m_prioCtrl;
  virtual BOOL OnInitDialog();
  int m_length;
  int m_minloop;
  BOOL m_usealt;
};
