// nsfmwin.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
//

#include "stdafx.h"
#include "nsfmwin.h"
#include "nsfmwinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CnsfmwinApp

BEGIN_MESSAGE_MAP(CnsfmwinApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CnsfmwinApp �R���X�g���N�V����

CnsfmwinApp::CnsfmwinApp()
{
	EnableHtmlHelp();

	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� CnsfmwinApp �I�u�W�F�N�g�ł��B

CnsfmwinApp theApp;


// CnsfmwinApp ������

BOOL CnsfmwinApp::InitInstance()
{
	// �A�v���P�[�V�����@�}�j�t�F�X�g���@visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll �o�[�W���� 6�@�ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �Ɂ@InitCommonControls() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();


	CnsfmwinDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �_�C�A���O�� <�L�����Z��> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}

	// �_�C�A���O�͕����܂����B�A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n���Ȃ���
	// �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}
