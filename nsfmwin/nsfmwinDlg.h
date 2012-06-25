// nsfmwinDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "OptionDlg.h"
#include <set>

// CnsfmwinDlg �_�C�A���O
class CnsfmwinDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CnsfmwinDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_NSFMWIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

// ����
protected:
	HICON m_hIcon;
  CWinThread *m_pThread;
  void StartFileFindThread();

public:
  BOOL m_bStopflag;
  BOOL m_bBtnMode;
  std::set<CString> m_setTarget;
  int m_nPriority, m_nSearchLen, m_nMinLoop, m_nUseAlt;
  int m_nListCx;
  void EnableDlgItem(BOOL bEnable);

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnDropFiles(HDROP hDropInfo);
  CListBox m_listbox;
  afx_msg void OnBnClickedDelete();
  afx_msg void OnBnClickedUp();
  afx_msg void OnBnClickedDown();
  afx_msg void OnBnClickedStart();
  CProgressCtrl m_progress2;
  CButton m_start;
  CButton m_delete;
  CButton m_up;
  CButton m_down;
  CProgressCtrl m_progress1;
  CStatic m_track;
  CStatic m_file;
  CStatic m_total;
  CProgressCtrl m_progress0;
  afx_msg void OnBnClickedOption();
  afx_msg void OnDestroy();
  CButton m_option;
};
