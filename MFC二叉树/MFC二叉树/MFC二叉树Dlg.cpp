
// MFC������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC������.h"
#include "MFC������Dlg.h"
#include "afxdialogex.h"
#include "binaryTreeNode.h"
#include "define.h"
#include <iostream>
#include <stack>
#include<assert.h>
#include <queue>
#include <sstream>
#include <math.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC������Dlg �Ի���



CMFC������Dlg::CMFC������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC������Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_BUTTON4, treeWideth);
	DDX_Control(pDX, IDC_BUTTON2, exchangeTree);
	DDX_Control(pDX, IDC_BUTTON3, levelOrderTree);*/
}

BEGIN_MESSAGE_MAP(CMFC������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_BN_CLICKED(IDC_BUTTON4, &CMFC������Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC������Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC������Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC������Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CMFC������Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFC������Dlg::OnBnClickedButton17)*/
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC������Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC������Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC������Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC������Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC������Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC������Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC������Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFC������Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFC������Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFC������Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFC������Dlg::OnBnClickedButton21)
END_MESSAGE_MAP()


// CMFC������Dlg ��Ϣ�������

BOOL CMFC������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	
	
	createTree(a,b,tree,Size);
	tree->parent =new binaryTreeNode (0);
	tree->parent->Hpos=40;


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
//----------------------------------------------------------------------------------------------------------------------------

CString createString (int x) 
{
	CString s=(CString)"";
	for(int i=0;i<x;i++)
		s+=(CString)" ";
	return s;
}

void createTree (int a[],int b[],binaryTreeNode* & tree,int size)//������ ����a[]������ b[]��ӵ�е����������
{
	stack<binaryTreeNode*> binary;
	int temp;
	

	for(int i=0;i<size;i++)//����a�Ĵ�СΪѭ������
	{
		temp=a[i];

		tree= new binaryTreeNode (temp);


		if(b[i]==0)//û������
		{
			binary.push(tree);
			continue;
		}
		if(b[i]==1)//��������
		{
			tree->leftChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			binary.push(tree);
			continue;
		}
		if(b[i]==2)//����������
		{
			tree->rightChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			tree->leftChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			binary.push(tree);
			continue;
		}
		if(b[i]==3)//��������
		{
			tree->rightChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			binary.push(tree);
			continue;
		}
	}
}

void exchange (binaryTreeNode* & tree)//��������������һ���ڵ����������
{
	binaryTreeNode * temp;
	temp=tree->leftChild;
	tree->leftChild=tree->rightChild;
	tree->rightChild=temp;
}

void exchangeLeftToRight (binaryTreeNode* & tree)//�����������Ķ������������ҽ���
{
	if(tree)
	{
		exchangeLeftToRight (tree->rightChild);

		if(tree->rightChild!=NULL || tree->leftChild!=NULL)
			exchange(tree);

		exchangeLeftToRight (tree->rightChild);
	}
}
		

void levelOrder (binaryTreeNode* tree)
{
	CString x;
	queue<binaryTreeNode*> q;
	while (tree != NULL)
	{
        x.Format(_T("%3d"),tree->element);
		levelOrderOutput+=x;
	
		cout<<tree->element<<"   ";
		if(tree->leftChild != NULL)
			q.push(tree->leftChild);
		if(tree->rightChild != NULL)
			q.push(tree->rightChild);
		if(!q.empty())
		{
		tree=q.front();
		q.pop();
		}
		else
			tree=NULL;
	}
}

void getLocation (binaryTreeNode* tree,int x=20,int y=0)  //��ȡ���ݵĺ������������
{

	

	if(tree)
	{
		tree->Hpos=x;
		getLocation(tree->leftChild,tree->Hpos-(abs(tree->parent->Hpos-tree->Hpos))/2,y+1);
	
		tree->Zpos=y;
		getLocation(tree->rightChild,tree->Hpos+(abs(tree->parent->Hpos-tree->Hpos))/2,y+1);
	}

}


void widethOrder (binaryTreeNode* tree,int wide[],int j=0)
{
	if(tree != NULL)
	{
		wide[j]++;
		widethOrder(tree->leftChild,wide,j+1);
		widethOrder(tree->rightChild,wide,j+1);
	}
	
}

int treeWide(binaryTreeNode* tree)
{
	
	for(int i=0;i<10;i++)
		thewideth[i]=0;

	if(tree == NULL)//����Ϊ��ʱ
		return 0;

	widethOrder(tree,thewideth,0);

	int max=1;
	for(int i=0;i<10;i++)
		if(max<thewideth[i])
			max=thewideth[i];
	return max;
}

void outPutTree (binaryTreeNode* tree)
{
		getLocation(tree);

//------------------------------------------------��α�������ele�����blank���飬���������ݺͶ�Ӧ�ĺ������ֵ
	binaryTreeNode *p=tree;
	queue<binaryTreeNode*> q;
	int i=0,j=0,h=0;
	stringstream ss;
	CString y;
	while (p != NULL)
	{
		if(j<thewideth[h])
		{
			blank[i][j]=p->Hpos;
		    y.Format(_T("%d"),p->element);
			ele[i][j]=y;
			y.Empty();
			j++;
		}
		else
		{
			i++;
			h++;
			j=0;
		
			blank[i][j]=p->Hpos;
			y.Format(_T("%d"),p->element);
			ele[i][j]=y;
			y.Empty();

			j=1;
		}

		if(p->leftChild != NULL)
			q.push(p->leftChild);
		if(p->rightChild != NULL)
			q.push(p->rightChild);
		if(!q.empty())
		{
		p=q.front();
		q.pop();
		}
		else
			p=NULL;
	}
//-------------------------------------------------------------------------ͨ��int�͵�blank����  д��string���͵�blankNumber����
	int tem;
	for(int i=0;i<10;i++)
		for(int j=0;j<thewideth[i];j++)
		{
			if(j==0)
			{
				tem=blank[i][j]-1;
				blankNumber[i][j]=createString(tem);
			}
			else
			{
				tem=blank[i][j]-blank[i][j-1];
				blankNumber[i][j]=createString(tem);
			}
		}


//------------------------------------------------------------------------------------------------��blankNumber��ele������	
	int k=0,g=0;
	CString x;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<2*thewideth[i];j++)
		{
			if(j%2==0)
			{
				theFinal[i]+=blankNumber[i][k];
				k++;
			}
			else
			{
				
				theFinal[i]+=ele[i][g];
				g++;
			}
		}
		k=0;
		g=0;
	}

	
}
		



void freeTree(binaryTreeNode* & tree)//�ͷ��� 
{
	if(tree->leftChild!=NULL) 
		freeTree(tree->leftChild);
	if(tree->rightChild!=NULL)
		freeTree(tree->rightChild);
	delete(tree);
}


//--------------------------------------------------------------------------------------------------------------------
void CMFC������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*void CMFC������Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	int index=-1;
	
	int wide=treeWide(tree);
    CString x;
    x.Format(_T("%d"),wide);


	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}




void CMFC������Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	int index=-1;
	levelOrder(tree);

	levelOrderOutput.Empty();

	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}


void CMFC������Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freeTree(tree);
	createTree(a,b,tree,Size);
	tree->parent =new binaryTreeNode (0);
	tree->parent->Hpos=40;;
	treeWide(tree);

	outPutTree(tree);
	
	int index=-1;

	for(int i=0;i<5;i++)
		theFinal[i].Empty();

	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);


}


void CMFC������Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freeTree(tree);
	createTree(a,b,tree,Size);
	
	tree->parent =new binaryTreeNode (0);
	tree->parent->Hpos=40;

	exchangeLeftToRight(tree);
	treeWide(tree);

	outPutTree(tree);

	int index=-1;

	for(int i=0;i<5;i++)
		theFinal[i].Empty();

	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}


void CMFC������Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	freeTree(tree);
	CDialogEx::OnCancel();
}*/


//���������� 
typedef enum
{
	Link,
	Thread
} PointTag;

typedef	struct  BinaryTreeNode
{
	BinaryTreeNode(const char data)
		:_data(data)
		, pLeft(NULL)
		, pRight(NULL)
		, Ltag(Link)
		, Rtag(Link)
	{}
	char _data;
	struct  BinaryTreeNode *pLeft, *pRight;
	PointTag  Ltag, Rtag;
}BiTreeNode;

class Thread_BiTree
{
public:
	//���� --������
	Thread_BiTree(const char* arr, size_t Size)
		:_pRoot(NULL)
		, Prev(NULL)
	{
		size_t index = 0;
		_CreatTree(_pRoot, arr, Size, index);//����������
	}
protected:
	void  _CreatTree(BiTreeNode*& Root, const char* arr, size_t size, size_t& index)
	{
		if (arr == NULL || size == 0)
		{
			cout << "�������� " << endl;
			return;
		}
		if (index < size && arr[index] != '#')
		{
			Root = new BiTreeNode(arr[index]);
			_CreatTree(Root->pLeft, arr, size, ++index);
			_CreatTree(Root->pRight, arr, size, ++index);
		}
	}
public:
	//����--������������
	void PreOrderThreading()
	{
		_PreOrderThreading(this->_pRoot);
	}
	//����--���� ����������
	void PreOrder()
	{
		_PreOrder(this->_pRoot);
	}
protected:
	//����--������������--C  
	//˼·���ȿ��������� ����һ���ڵ��ʱ���ڼ����һ���ڵ���ҽڵ�
	void _PreOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		if (Root->pLeft == NULL) //û��������
		{
			Root->pLeft = Prev;   //ǰ��
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL) // ��һ���ڵ���û��  ������
		{  //Prev��һ�ν��� Ϊ��  
			Prev->pRight = Root;   //���
			Prev->Rtag = Thread;
		}
		Prev = Root;//ǰ��  �� ÿ�μ�ס�ϴεĽڵ�

					//�ж�Root�Ƿ������Һ���
		if (Root->Ltag == Link)
			_PreOrderThreading(Root->pLeft);
		if (Root->Rtag == Link)
			_PreOrderThreading(Root->pRight);
	}
	//����--���� ����������--C
	void _PreOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur != NULL)
		{
			while (pCur->pLeft != NULL && pCur->Ltag == Link)//�ҵ�����ߵĽڵ�,����һֱΪLink
			{
				cout << pCur->_data << ' ';
				pCur = pCur->pLeft;
			}
			//����������ߵĵĽڵ㻹û�з���
			cout << pCur->_data << ' ';

			if (pCur->Ltag == Thread)//�������� �Ϳ��ҽڵ�
			{
				pCur = pCur->pRight;
			}
			while (pCur != NULL)//ѭ���ҽڵ�
			{
				if (pCur->pLeft != NULL && pCur->Ltag == Link)//������ڵ���� �� �����
				{
					break;
				}
				cout << pCur->_data << ' ';
				pCur = pCur->pRight;
			}
		}
	}

public:
	//����--������������
	void InOrderThreading()
	{
		_InOrderThreading(_pRoot);
	}
	//����--��������������
	void InOrder()
	{
		_InOrder(this->_pRoot);
	}
protected:
	//����--������������--C
	//˼·:�� ��-��-�ҵ�˳��   ���ҵ�����ߵĽڵ�-> ����������һ�� ,��������������ִ�е���һ���ڵ��ڿ��ϴνڵ�������� -> ������
	void _InOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_InOrderThreading(Root->pLeft);    // ��

		if (Root->pLeft == NULL)	//��
		{
			Root->Ltag = Thread;
			Root->pLeft = Prev;
		}
		if (Prev != NULL && Prev->pRight == NULL)
		{
			Prev->pRight = Root;
			Prev->Rtag = Thread;
		}
		Prev = Root;
		_InOrderThreading(Root->pRight);   //��
	}
	//����--����������--C
	//˼·���ҵ�����ʼ�Ľڵ㣨����ߵĽڵ㣩-> (��� )���ĸ��ڵ㣬��û�������ҽڵ�
	void _InOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur)
		{
			while (pCur->Ltag == Link) //������ߵĽڵ�
			{
				pCur = pCur->pLeft;
			}
			cout << pCur->_data << ' ';

			while (pCur && pCur->Rtag == Thread)//�������̽ڵ�
			{
				pCur = pCur->pRight;
				cout << pCur->_data << ' ';
			}
			//û�к�̣���������   
			pCur = pCur->pRight;
		}
	}
public:
	//����--����������
	void PostOrderThreading()
	{
		_PostOrderThreading(_pRoot);
	}
protected:
	//����--����������--C
	//˼·����-��-��  ��ǰ���һ��
	void _PostOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_PostOrderThreading(Root->pLeft);
		_PostOrderThreading(Root->pRight);

		if (Root->pLeft == NULL)
		{
			Root->pLeft = Prev;
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL)
		{
			Prev->pRight = Root;
			Prev->Rtag = Thread;
		}
		Prev = Root;
	}
private:
	BiTreeNode* _pRoot;
	BiTreeNode* Prev;  //��¼
};


/*void CMFC������Dlg::OnBnClickedButton17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}*/

void CMFC������Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "            1\r\n   2                 3\r\n 4    5           6   7\r\n    8    9\r\n       10  11";
	SetDlgItemText(IDC_EDIT1, s);
}


void CMFC������Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFC������Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "1 2 4 5 8 9 10 11 3 6 7";
	SetDlgItemText(IDC_EDIT2, s);
}


void CMFC������Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "4 2 8 5 10 9 11 1 6 3 7";
	SetDlgItemText(IDC_EDIT3, s);
}


void CMFC������Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "4 8 10 11 9 5 2 6 7 3 1";
	SetDlgItemText(IDC_EDIT4, s);
}


void CMFC������Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "6";
	SetDlgItemText(IDC_EDIT5, s);
}



void CMFC������Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "���\t���־\tǰ��\t�ұ�־\t����\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\t2\t1\t5\r\n5\t0\t8\t0\t9\r\n6\t1\t3\t1\t7\r\n7\t1\t6\t1\tNII\r\n8\t1\t5\t1\t9\r\n9\t0\t10\t0\t11\r\n10\t1\t9\t1\t11\r\n11\t1\t10\t1\t3";
	SetDlgItemText(IDC_EDIT6, s);
}


void CMFC������Dlg::OnBnClickedButton20()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "���\t���־\tǰ��\t�ұ�־\t����\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\tNIL\t1\t2\r\n5\t0\t8\t0\t9\r\n6\t1\t1\t1\t3\r\n7\t1\t3\t1\tNII\r\n8\t1\t2\t1\t5\r\n9\t0\t10\t0\t11\r\n10\t1\t5\t1\t9\r\n11\t1\t9\t1\t1";
	SetDlgItemText(IDC_EDIT7, s);
}


void CMFC������Dlg::OnBnClickedButton18()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "���\t���־\tǰ��\t�ұ�־\t����\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\tNIL\t1\t8\r\n5\t0\t8\t0\t9\r\n6\t1\t2\t1\t7\r\n7\t1\t6\t1\t3\r\n8\t1\t4\t1\t10\r\n9\t0\t10\t0\t11\r\n10\t1\t8\t1\t11\r\n11\t1\t10\t1\t9";
	SetDlgItemText(IDC_EDIT8, s);
}


void CMFC������Dlg::OnBnClickedButton19()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "1 2 4 5 8 9 10 11 3 6 7";
	SetDlgItemText(IDC_EDIT9, s);
}


void CMFC������Dlg::OnBnClickedButton21()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	s = "4 2 8 5 10 9 11 1 6 3 7";
	SetDlgItemText(IDC_EDIT10, s);
}
