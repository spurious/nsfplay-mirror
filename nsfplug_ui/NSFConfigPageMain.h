#if !defined(AFX_NSFCONFIGPAGEMAIN_H__5E143C23_5F61_4023_8A4E_D3F1048B1CF2__INCLUDED_)
#define AFX_NSFCONFIGPAGEMAIN_H__5E143C23_5F61_4023_8A4E_D3F1048B1CF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NSFConfigPageMain.h : �w�b�_�[ �t�@�C��
//
#include "NSFDialog.h"
#include "afxwin.h"
#include "afxcmn.h"

/////////////////////////////////////////////////////////////////////////////
// NSFConfigPageMain �_�C�A���O

class NSFConfigPageMain : public CPropertyPage, public NSFDialog
{
	DECLARE_DYNCREATE(NSFConfigPageMain)

// �R���X�g���N�V����
public:
	NSFConfigPageMain();
	~NSFConfigPageMain();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(NSFConfigPageMain)
	enum { IDD = IDD_BASIC };
	BOOL	m_bAutoStop;
	UINT	m_nStopSec;
	UINT	m_nFadeTime;
	UINT	m_nPlayTime;
	int		m_nPlayFreq;
	BOOL	m_bAutoDetect;
	UINT	m_nDetectTime;
	BOOL	m_bUpdatePlaylist;
	UINT	m_nLoopNum;
	BOOL	m_bMaskInit;
	CString	m_format;
	//}}AFX_DATA

// ���[�U�[�ǉ�
  void UpdateNSFPlayerConfig(bool b);

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(NSFConfigPageMain)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(NSFConfigPageMain)
	afx_msg void OnSelchangePlayfreq();
	afx_msg void OnChangeStopsec();
	afx_msg void OnChangePlaytime();
	afx_msg void OnChangeFadetime();
	afx_msg void OnAutostop();
	afx_msg void OnAutodetect();
	afx_msg void OnChangeDetecttime();
	afx_msg void OnUpdatePlaylist();
	afx_msg void OnChangeLoopnum();
	afx_msg void OnMaskinit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
  BOOL m_bUseAlt;
  afx_msg void OnBnClickedUsealt();
  BOOL m_bVsync;
  BOOL m_bPrefPal;
  BOOL m_bStereo;
  afx_msg void OnBnClickedVsync();
  BOOL m_bFastSeek;
  CSliderCtrl m_limitCtrl;
  CSliderCtrl m_threshCtrl;
  CSliderCtrl m_velocityCtrl;
  int m_nLimit;
  int m_nThreshold;
  int m_nVelocity;
  virtual BOOL OnInitDialog();
  CSliderCtrl m_hpfCtrl;
  int m_nHpfValue;
  CSliderCtrl m_lpfCtrl;
  int m_nLpfValue;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_NSFCONFIGPAGEMAIN_H__5E143C23_5F61_4023_8A4E_D3F1048B1CF2__INCLUDED_)
