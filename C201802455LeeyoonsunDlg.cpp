
// C201802455LeeyoonsunDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "C201802455Leeyoonsun.h"
#include "C201802455LeeyoonsunDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

char turn;

char graph[3][3] = { {' ',' ',' '},{' ',' ',' '}, {' ',' ',' '} };
int round_num = 0;
int cnt = 0;
int O_cnt, X_cnt;
bool winner;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CC201802455LeeyoonsunDlg 대화 상자



CC201802455LeeyoonsunDlg::CC201802455LeeyoonsunDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_C201802455LEEYOONSUN_DIALOG, pParent)
	, x_score(0)
	, o_score(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC201802455LeeyoonsunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, b1);
	DDX_Control(pDX, IDC_BUTTON2, b2);
	DDX_Control(pDX, IDC_BUTTON3, b3);
	DDX_Control(pDX, IDC_BUTTON4, b4);
	DDX_Control(pDX, IDC_BUTTON5, b5);
	DDX_Control(pDX, IDC_BUTTON6, b6);
	DDX_Control(pDX, IDC_BUTTON7, b7);
	DDX_Control(pDX, IDC_BUTTON8, b8);
	DDX_Control(pDX, IDC_BUTTON9, b9);


	DDX_Text(pDX, IDC_EDIT1, o_score);
	DDX_Text(pDX, IDC_EDIT2, x_score);
}

BEGIN_MESSAGE_MAP(CC201802455LeeyoonsunDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CC201802455LeeyoonsunDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CC201802455LeeyoonsunDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CC201802455LeeyoonsunDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CC201802455LeeyoonsunDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CC201802455LeeyoonsunDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CC201802455LeeyoonsunDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CC201802455LeeyoonsunDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CC201802455LeeyoonsunDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CC201802455LeeyoonsunDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CC201802455LeeyoonsunDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTT_RESET, &CC201802455LeeyoonsunDlg::OnBnClickedButtReset)
	ON_BN_CLICKED(IDC_BUTT_NEWGAME, &CC201802455LeeyoonsunDlg::OnBnClickedButtNewgame)
END_MESSAGE_MAP()


// CC201802455LeeyoonsunDlg 메시지 처리기

BOOL CC201802455LeeyoonsunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CC201802455LeeyoonsunDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CC201802455LeeyoonsunDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CC201802455LeeyoonsunDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CC201802455LeeyoonsunDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void CC201802455LeeyoonsunDlg::win() {

	if (game() == 'D') {
		MessageBox("무승부 입니다.", "End");
		OnBnClickedButtReset();
		round_num += 1;
	}
	else if (game() == 'O') {
		MessageBox("'O'의 승리입니다.", "End");
		OnBnClickedButtReset();
		UpdateData(TRUE);
		o_score += 1;
		UpdateData(FALSE);
		round_num += 1;
	}
	else if (game() == 'X') {
		MessageBox("'X'의 승리입니다.", "End");
		OnBnClickedButtReset();
		UpdateData(TRUE);
		x_score += 1;
		UpdateData(FALSE);
		round_num += 1;

	}
	
	

	
	
	
}

char CC201802455LeeyoonsunDlg::game() {
	


	if (cnt <= 9) {

		if (((graph[0][2] == graph[1][1])&&(graph[1][1] == graph[2][0])) || ((graph[0][0] == graph[1][1] )&& (graph[1][1] == graph[2][2]))) {
			if (graph[1][1] == 'X') {
				return 'X';
			}
			else if (graph[1][1] == 'O') {
				return 'O';
			}
		}

		for (int i = 0; i < 3; i++) {
			O_cnt = 0;
			X_cnt = 0;
			for (int j = 0; j < 3; j++) {
				if (graph[i][j] == 'O') {
					O_cnt += 1;
				}
				else if (graph[i][j] == 'X') {
					X_cnt += 1;
				}
			}
			if (O_cnt == 3) {
				return 'O';
			}
			else if (X_cnt == 3) {
				return 'X';
			}
		}

		for (int k = 0; k < 3; k++) {
			O_cnt = 0;
			X_cnt = 0;
			for (int l = 0; l < 3; l++) {
				if (graph[l][k] == 'O') {
					O_cnt += 1;
				}
				else if (graph[l][k] == 'X') {
					X_cnt += 1;
				}
			}
			if (O_cnt == 3) {
				return 'O';

			}
			else if (X_cnt == 3) {
				return 'X';

			}
		}
		

	}
	if (cnt == 9) {
		return 'D';
	}
}

 
char CC201802455LeeyoonsunDlg::turn_cal(){
	
	cnt = cnt + round_num;

	if (cnt % 2) {
		turn = 'X';
	}
	else {
		turn = 'O';
	}
	cnt = cnt - round_num;

	return turn;
}


void CC201802455LeeyoonsunDlg::OnBnClickedButton1()
{
	turn = turn_cal();
	if (graph[0][0] = ' '){
		if (turn == 'X') {
			graph[0][0] = 'X';
			b1.SetWindowTextA("X");
		}		
		else {
			graph[0][0] = 'O';
			b1.SetWindowTextA("O");
		}
	}
	cnt++;
	win();
}


void CC201802455LeeyoonsunDlg::OnBnClickedButton2()
{
	turn = turn_cal();
	if(graph[0][1] = ' ') {
		if (turn == 'X') {
			graph[0][1] = 'X';
			b2.SetWindowTextA("X");
		}
		else {
			graph[0][1] = 'O';
			b2.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

}


void CC201802455LeeyoonsunDlg::OnBnClickedButton3()
{
	turn = turn_cal();
	if (graph[0][2] = ' ') {
		if (turn == 'X') {
			graph[0][2] = 'X';
			b3.SetWindowTextA("X");
		}
		else {
			graph[0][2] = 'O';
			b3.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton4()
{
	turn = turn_cal();

	if (graph[1][0] = ' ') {
		if (turn == 'X') {
			graph[1][0] = 'X';
			b4.SetWindowTextA("X");
		}
		else {
			graph[1][0] = 'O';
			b4.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton5()
{
	turn = turn_cal();
	if (graph[1][1] = ' ') {
		if (turn == 'X') {
			graph[1][1] = 'X';
			b5.SetWindowTextA("X");
		}
		else {
			graph[1][1] = 'O';
			b5.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton6()
{
	turn = turn_cal();
	if (graph[1][2] = ' ') {
		if (turn == 'X') {
			graph[1][2] = 'X';
			b6.SetWindowTextA("X");
		}
		else {
			graph[1][2] = 'O';
			b6.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton7()
{
	turn = turn_cal();
	if (graph[2][0] = ' ') {
		if (turn == 'X') {
			graph[2][0] = 'X';
			b7.SetWindowTextA("X");
		}
		else {
			graph[2][0] = 'O';
			b7.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton8()
{
	turn = turn_cal();
	if (graph[2][1] = ' ') {
		if (turn == 'X') {
			graph[2][1] = 'X';
			b8.SetWindowTextA("X");
		}
		else {
			graph[2][1] = 'O';
			b8.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CC201802455LeeyoonsunDlg::OnBnClickedButton9()
{
	turn = turn_cal();
	if (graph[2][2] = ' ') {
		if (turn == 'X') {
			graph[2][2] = 'X';
			b9.SetWindowTextA("X");
		}
		else {
			graph[2][2] = 'O';
			b9.SetWindowTextA("O");
		}
	}
	cnt++;
	win();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


	


void CC201802455LeeyoonsunDlg::OnBnClickedButtReset()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			graph[i][j] = ' ';
		}
	}

	UpdateData(TRUE);
	b1.SetWindowTextA(" ");
	b2.SetWindowTextA(" ");
	b3.SetWindowTextA(" ");
	b4.SetWindowTextA(" ");
	b5.SetWindowTextA(" ");
	b6.SetWindowTextA(" ");
	b7.SetWindowTextA(" ");
	b8.SetWindowTextA(" ");
	b9.SetWindowTextA(" ");
	UpdateData(FALSE);

	cnt = 0;

}


void CC201802455LeeyoonsunDlg::OnBnClickedButtNewgame()
{
	OnBnClickedButtReset();
	UpdateData(TRUE);
	x_score = 0;
	o_score = 0;
	UpdateData(FALSE);
}