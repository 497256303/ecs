
// MFC二叉树Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC二叉树.h"
#include "MFC二叉树Dlg.h"
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC二叉树Dlg 对话框



CMFC二叉树Dlg::CMFC二叉树Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC二叉树Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC二叉树Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_BUTTON4, treeWideth);
	DDX_Control(pDX, IDC_BUTTON2, exchangeTree);
	DDX_Control(pDX, IDC_BUTTON3, levelOrderTree);*/
}

BEGIN_MESSAGE_MAP(CMFC二叉树Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_BN_CLICKED(IDC_BUTTON4, &CMFC二叉树Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC二叉树Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC二叉树Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC二叉树Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CMFC二叉树Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFC二叉树Dlg::OnBnClickedButton17)*/
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC二叉树Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC二叉树Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC二叉树Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC二叉树Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC二叉树Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC二叉树Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC二叉树Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFC二叉树Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFC二叉树Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFC二叉树Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFC二叉树Dlg::OnBnClickedButton21)
END_MESSAGE_MAP()


// CMFC二叉树Dlg 消息处理程序

BOOL CMFC二叉树Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	
	
	createTree(a,b,tree,Size);
	tree->parent =new binaryTreeNode (0);
	tree->parent->Hpos=40;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
//----------------------------------------------------------------------------------------------------------------------------

CString createString (int x) 
{
	CString s=(CString)"";
	for(int i=0;i<x;i++)
		s+=(CString)" ";
	return s;
}

void createTree (int a[],int b[],binaryTreeNode* & tree,int size)//生成树 其中a[]存数据 b[]存拥有的子树的情况
{
	stack<binaryTreeNode*> binary;
	int temp;
	

	for(int i=0;i<size;i++)//数组a的大小为循环条件
	{
		temp=a[i];

		tree= new binaryTreeNode (temp);


		if(b[i]==0)//没有子树
		{
			binary.push(tree);
			continue;
		}
		if(b[i]==1)//有左子树
		{
			tree->leftChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			binary.push(tree);
			continue;
		}
		if(b[i]==2)//有左右子树
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
		if(b[i]==3)//有右子树
		{
			tree->rightChild=binary.top();
			binary.top()->parent=tree;
			binary.pop();
			binary.push(tree);
			continue;
		}
	}
}

void exchange (binaryTreeNode* & tree)//用来交换二叉树一个节点的左右子树
{
	binaryTreeNode * temp;
	temp=tree->leftChild;
	tree->leftChild=tree->rightChild;
	tree->rightChild=temp;
}

void exchangeLeftToRight (binaryTreeNode* & tree)//用来对整个的二叉树进行左右交换
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

void getLocation (binaryTreeNode* tree,int x=20,int y=0)  //获取数据的横坐标和纵坐标
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

	if(tree == NULL)//当树为空时
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

//------------------------------------------------层次遍历构建ele数组和blank数组，用来存数据和对应的横坐标的值
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
//-------------------------------------------------------------------------通过int型的blank数组  写出string类型的blankNumber数组
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


//------------------------------------------------------------------------------------------------把blankNumber和ele合起来	
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
		



void freeTree(binaryTreeNode* & tree)//释放树 
{
	if(tree->leftChild!=NULL) 
		freeTree(tree->leftChild);
	if(tree->rightChild!=NULL)
		freeTree(tree->rightChild);
	delete(tree);
}


//--------------------------------------------------------------------------------------------------------------------
void CMFC二叉树Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC二叉树Dlg::OnPaint()
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
HCURSOR CMFC二叉树Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*void CMFC二叉树Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	
	int index=-1;
	
	int wide=treeWide(tree);
    CString x;
    x.Format(_T("%d"),wide);


	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}




void CMFC二叉树Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	
	int index=-1;
	levelOrder(tree);

	levelOrderOutput.Empty();

	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}


void CMFC二叉树Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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


void CMFC二叉树Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
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


void CMFC二叉树Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	freeTree(tree);
	CDialogEx::OnCancel();
}*/


//线索二叉树 
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
	//先序 --创建树
	Thread_BiTree(const char* arr, size_t Size)
		:_pRoot(NULL)
		, Prev(NULL)
	{
		size_t index = 0;
		_CreatTree(_pRoot, arr, Size, index);//创建二叉树
	}
protected:
	void  _CreatTree(BiTreeNode*& Root, const char* arr, size_t size, size_t& index)
	{
		if (arr == NULL || size == 0)
		{
			cout << "输入有误 " << endl;
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
	//先序--线索化二叉树
	void PreOrderThreading()
	{
		_PreOrderThreading(this->_pRoot);
	}
	//先序--遍历 线索二叉树
	void PreOrder()
	{
		_PreOrder(this->_pRoot);
	}
protected:
	//先序--线索化二叉树--C  
	//思路：先看左子树， 找下一个节点的时候，在检测上一个节点的右节点
	void _PreOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		if (Root->pLeft == NULL) //没有左子树
		{
			Root->pLeft = Prev;   //前驱
			Root->Ltag = Thread;
		}
		if (Prev != NULL && Prev->pRight == NULL) // 上一个节点有没有  右子树
		{  //Prev第一次进来 为空  
			Prev->pRight = Root;   //后继
			Prev->Rtag = Thread;
		}
		Prev = Root;//前驱  ， 每次记住上次的节点

					//判断Root是否有左右孩子
		if (Root->Ltag == Link)
			_PreOrderThreading(Root->pLeft);
		if (Root->Rtag == Link)
			_PreOrderThreading(Root->pRight);
	}
	//先序--遍历 线索二叉树--C
	void _PreOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur != NULL)
		{
			while (pCur->pLeft != NULL && pCur->Ltag == Link)//找到最左边的节点,左标记一直为Link
			{
				cout << pCur->_data << ' ';
				pCur = pCur->pLeft;
			}
			//到这来，左边的的节点还没有访问
			cout << pCur->_data << ' ';

			if (pCur->Ltag == Thread)//遇到线索 就看右节点
			{
				pCur = pCur->pRight;
			}
			while (pCur != NULL)//循环右节点
			{
				if (pCur->pLeft != NULL && pCur->Ltag == Link)//遇到左节点存在 ， 则访问
				{
					break;
				}
				cout << pCur->_data << ' ';
				pCur = pCur->pRight;
			}
		}
	}

public:
	//中序--线索化二叉树
	void InOrderThreading()
	{
		_InOrderThreading(_pRoot);
	}
	//中序--遍历线索二叉树
	void InOrder()
	{
		_InOrder(this->_pRoot);
	}
protected:
	//中序--线索化二叉树--C
	//思路:按 左-根-右的顺序   先找到最左边的节点-> 和先序线索一样 ,先链接左子树，执行到下一个节点在看上次节点的右子树 -> 右子树
	void _InOrderThreading(BiTreeNode*& Root)
	{
		if (Root == NULL)
		{
			return;
		}
		_InOrderThreading(Root->pLeft);    // 左

		if (Root->pLeft == NULL)	//根
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
		_InOrderThreading(Root->pRight);   //右
	}
	//中序--遍历二叉树--C
	//思路：找到中序开始的节点（最左边的节点）-> (后继 )它的根节点，若没有则找右节点
	void _InOrder(BiTreeNode* Root)
	{
		if (Root == NULL)
		{
			return;
		}
		BiTreeNode* pCur = Root;
		while (pCur)
		{
			while (pCur->Ltag == Link) //找最左边的节点
			{
				pCur = pCur->pLeft;
			}
			cout << pCur->_data << ' ';

			while (pCur && pCur->Rtag == Thread)//找中序后继节点
			{
				pCur = pCur->pRight;
				cout << pCur->_data << ' ';
			}
			//没有后继，有右子树   
			pCur = pCur->pRight;
		}
	}
public:
	//后序--线索二叉树
	void PostOrderThreading()
	{
		_PostOrderThreading(_pRoot);
	}
protected:
	//后序--线索二叉数--C
	//思路：左-右-根  和前面的一样
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
	BiTreeNode* Prev;  //记录
};


/*void CMFC二叉树Dlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
}*/

void CMFC二叉树Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "            1\r\n   2                 3\r\n 4    5           6   7\r\n    8    9\r\n       10  11";
	SetDlgItemText(IDC_EDIT1, s);
}


void CMFC二叉树Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFC二叉树Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "1 2 4 5 8 9 10 11 3 6 7";
	SetDlgItemText(IDC_EDIT2, s);
}


void CMFC二叉树Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "4 2 8 5 10 9 11 1 6 3 7";
	SetDlgItemText(IDC_EDIT3, s);
}


void CMFC二叉树Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "4 8 10 11 9 5 2 6 7 3 1";
	SetDlgItemText(IDC_EDIT4, s);
}


void CMFC二叉树Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "6";
	SetDlgItemText(IDC_EDIT5, s);
}



void CMFC二叉树Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "结点\t左标志\t前驱\t右标志\t后驱\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\t2\t1\t5\r\n5\t0\t8\t0\t9\r\n6\t1\t3\t1\t7\r\n7\t1\t6\t1\tNII\r\n8\t1\t5\t1\t9\r\n9\t0\t10\t0\t11\r\n10\t1\t9\t1\t11\r\n11\t1\t10\t1\t3";
	SetDlgItemText(IDC_EDIT6, s);
}


void CMFC二叉树Dlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "结点\t左标志\t前驱\t右标志\t后驱\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\tNIL\t1\t2\r\n5\t0\t8\t0\t9\r\n6\t1\t1\t1\t3\r\n7\t1\t3\t1\tNII\r\n8\t1\t2\t1\t5\r\n9\t0\t10\t0\t11\r\n10\t1\t5\t1\t9\r\n11\t1\t9\t1\t1";
	SetDlgItemText(IDC_EDIT7, s);
}


void CMFC二叉树Dlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "结点\t左标志\t前驱\t右标志\t后驱\r\n1\t0\t2\t0\t3\r\n2\t0\t4\t0\t5\r\n3\t0\t6\t0\t7\r\n4\t1\tNIL\t1\t8\r\n5\t0\t8\t0\t9\r\n6\t1\t2\t1\t7\r\n7\t1\t6\t1\t3\r\n8\t1\t4\t1\t10\r\n9\t0\t10\t0\t11\r\n10\t1\t8\t1\t11\r\n11\t1\t10\t1\t9";
	SetDlgItemText(IDC_EDIT8, s);
}


void CMFC二叉树Dlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "1 2 4 5 8 9 10 11 3 6 7";
	SetDlgItemText(IDC_EDIT9, s);
}


void CMFC二叉树Dlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	s = "4 2 8 5 10 9 11 1 6 3 7";
	SetDlgItemText(IDC_EDIT10, s);
}
