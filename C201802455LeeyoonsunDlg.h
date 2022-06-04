
// C201802455LeeyoonsunDlg.h: 헤더 파일
//

#pragma once


// CC201802455LeeyoonsunDlg 대화 상자
class CC201802455LeeyoonsunDlg : public CDialogEx
{
// 생성입니다.
public:
	CC201802455LeeyoonsunDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_C201802455LEEYOONSUN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	char turn_cal(), game(); 
	void win();
	CButton b1,b2,b3,b4,b5,b6,b7,b8,b9;

	afx_msg void OnBnClickedButtReset();
	afx_msg void OnBnClickedButtNewgame();
	int o_score;
	int x_score;
};
