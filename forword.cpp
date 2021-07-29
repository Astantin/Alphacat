#include<AI.h>
#include<easyx.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
void menu()
{
	IMAGE img, img1, img2, img3;
	loadimage(&img, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\开头.png", 942, 795);
	loadimage(&img1, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\人机.png", 942, 795);
	loadimage(&img2, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\玩家.png", 942, 795);
	loadimage(&img3, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\退出.png", 942, 795);
	initgraph(942, 795);//开辟游戏界面
	putimage(0, 0, &img);
	void Qipan_PVP();
	void Qipan_PVE(int i);
	int playcarton();
	MOUSEMSG m;
	while (1)
	{

		m = GetMouseMsg();

		if ((m.x <= 328 || m.x >= 579 || m.y <= 208 || m.y >= 306) && (m.x <= 330 || m.x >= 578 || m.y <= 360 || m.y >= 461) && (m.x <= 332 || m.x >= 581 || m.y <= 534 || m.y >= 634))//菜单
		{
			putimage(0, 0, &img);
		}
		//
		//
		if (m.x >= 328 && m.x <= 579 && m.y >= 208 && m.y <= 306)//人机
		{
			putimage(0, 0, &img1);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Sleep(1000);
				int tp = playcarton();
				Qipan_PVE(tp);
			}			
		}
		//
		//
		if (m.x >= 330 && m.x <= 578 && m.y >= 360 && m.y <= 461)//人人
		{
			putimage(0, 0, &img2);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Sleep(1000);
				Qipan_PVP();
			}
		}
		//
		//
		if (m.x >= 332 && m.x <= 581 && m.y >= 534 && m.y <= 634)//退出
		{
			putimage(0, 0, &img3);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Sleep(1000);
				exit(0);
			}
		}
	}
	closegraph();
}
//
//
//
void Qipan_PVP()
{
	IMAGE img, img0, img1, imgX, imgO, imgXS, imgOS;
	loadimage(&img, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景.png", 942, 795);
	loadimage(&img0, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景0.png", 160, 60);
	loadimage(&img1, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景1.png", 160, 60);
	loadimage(&imgX, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\OS.png", 190, 190);
	putimage(0, 0, &img);
	MOUSEMSG m;
	int e = 0;
	int a[3][3]{};
	int Y = 20;
	while (1)
	{
		m = GetMouseMsg();

		if (!(m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795))//返回按钮
		{
			putimage(760, 735, &img1);
		}
		if (m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795)
		{
			putimage(760, 735, &img0);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				menu();
			}
		}
		//
		//
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		if (m.x >= 37 && m.x <= 246 && m.y >= 86 && m.y <= 301)//第一格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][0] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(45, 95, &imgXS, NOTSRCERASE);
					putimage(45, 95, &imgX, SRCINVERT);
					a[0][0] = 1;
					outtextxy(755, Y, L"玩家1下在（0,0）点；");
					Y += 30;
				}
				else
				{
					putimage(45, 95, &imgOS, NOTSRCERASE);
					putimage(45, 95, &imgO, SRCINVERT);
					a[0][0] = -1;
					outtextxy(755, Y, L"玩家2下在（0,0）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 250 && m.x <= 480 && m.y >= 88 && m.y <= 299)//第二格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][1] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(262, 97, &imgXS, NOTSRCERASE);
					putimage(262, 97, &imgX, SRCINVERT);
					a[0][1] = 1;
					outtextxy(755, Y, L"玩家1下在（0,1）点；");
					Y += 30;
				}
				else
				{
					putimage(262, 97, &imgOS, NOTSRCERASE);
					putimage(262, 97, &imgO, SRCINVERT);
					a[0][1] = -1;
					outtextxy(755, Y, L"玩家2下在（0,1）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 482 && m.x <= 700 && m.y >= 86 && m.y <= 301)//第三格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][2] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 95, &imgXS, NOTSRCERASE);
					putimage(490, 95, &imgX, SRCINVERT);
					a[0][2] = 1;
					outtextxy(755, Y, L"玩家1下在（0,2）点；");
					Y += 30;
				}
				else
				{
					putimage(490, 95, &imgOS, NOTSRCERASE);
					putimage(490, 95, &imgO, SRCINVERT);
					a[0][2] = -1;
					outtextxy(755, Y, L"玩家2下在（0,2）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 37 && m.x <= 244 && m.y >= 301 && m.y <= 512)//第四格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][0] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(45, 310, &imgXS, NOTSRCERASE);
					putimage(45, 310, &imgX, SRCINVERT);
					a[1][0] = 1;
					outtextxy(755, Y, L"玩家1下在（1,0）点；");
					Y += 30;
				}
				else
				{
					putimage(45, 310, &imgOS, NOTSRCERASE);
					putimage(45, 310, &imgO, SRCINVERT);
					a[1][0] = -1;
					outtextxy(755, Y, L"玩家2下在（1,0）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 246 && m.x <= 480 && m.y >= 301 && m.y <= 511)//第五格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][1] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(255, 310, &imgXS, NOTSRCERASE);
					putimage(255, 310, &imgX, SRCINVERT);
					a[1][1] = 1;
					outtextxy(755, Y, L"玩家1下在（1,1）点；");
					Y += 30;
				}
				else
				{
					putimage(255, 310, &imgOS, NOTSRCERASE);
					putimage(255, 310, &imgO, SRCINVERT);
					a[1][1] = -1;
					outtextxy(755, Y, L"玩家2下在（1,1）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 482 && m.x <= 699 && m.y >= 301 && m.y <= 512)//第六格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][2] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 310, &imgXS, NOTSRCERASE);
					putimage(490, 310, &imgX, SRCINVERT);
					a[1][2] = 1;
					outtextxy(755, Y, L"玩家1下在（1,2）点；");
					Y += 30;
				}
				else
				{
					putimage(490, 310, &imgOS, NOTSRCERASE);
					putimage(490, 310, &imgO, SRCINVERT);
					a[1][2] = -1;
					outtextxy(755, Y, L"玩家2下在（1,2）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 38 && m.x <= 241 && m.y >= 511 && m.y <= 748)//第七格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][0] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(46, 520, &imgXS, NOTSRCERASE);
					putimage(46, 520, &imgX, SRCINVERT);
					a[2][0] = 1;
					outtextxy(755, Y, L"玩家1下在（2,0）点；");
					Y += 30;
				}
				else
				{
					putimage(46, 520, &imgOS, NOTSRCERASE);
					putimage(46, 520, &imgO, SRCINVERT);
					a[2][0] = -1;
					outtextxy(755, Y, L"玩家2下在（2,0）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 245 && m.x <= 478 && m.y >= 510 && m.y <= 749)//第八格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][1] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(253, 520, &imgXS, NOTSRCERASE);
					putimage(253, 520, &imgX, SRCINVERT);
					a[2][1] = 1;
					outtextxy(755, Y, L"玩家1下在（2,1）点；");
					Y += 30;
				}
				else
				{
					putimage(253, 520, &imgOS, NOTSRCERASE);
					putimage(253, 520, &imgO, SRCINVERT);
					a[2][1] = -1;
					outtextxy(755, Y, L"玩家2下在（2,1）点；");
					Y += 30;
				}
			}
		}
		if (m.x >= 480 && m.x <= 700 && m.y >= 511 && m.y <= 748)//第九格
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][2] == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 520, &imgXS, NOTSRCERASE);
					putimage(490, 520, &imgX, SRCINVERT);
					a[2][2] = 1;
					outtextxy(755, Y, L"玩家1下在（2,2）点；");
					Y += 30;
				}
				else
				{
					putimage(490, 520, &imgOS, NOTSRCERASE);
					putimage(490, 520, &imgO, SRCINVERT);
					a[2][2] = -1;
					outtextxy(755, Y, L"玩家2下在（2,2）点；");
					Y += 30;
				}
			}
		}
		int g = isend(a);
		if (g != 2)
		{
 			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					a[i][j] = 2;
			if (g == 1)
			{
				outtextxy(755, Y, L"玩家1获胜！");
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (g == -1)
			{
				outtextxy(755, Y, L"玩家2获胜！");
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (g == 0)
			{
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(1000);
				outtextxy(755, Y, L"平局！");			
			}
		}
	}
	closegraph();
}
//
//
//
void Qipan_PVE(int k)
{
	void Qipan_print(int x, int y, int a[3][3], int Y);
	IMAGE img, img0, img1, imgX, imgO, imgXS, imgOS;
	loadimage(&img, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景.png", 942, 795);
	loadimage(&img0, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景0.png", 160, 60);
	loadimage(&img1, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\背景1.png", 160, 60);
	loadimage(&imgX, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\OS.png", 190, 190);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	MOUSEMSG m;
	int e = 0;
	int a[3][3]{};
	int Y = 20;
	if (k == 1)
	{
		int M, N;
		srand(time(0));
		M = rand() % 3;
		N = rand() % 3;
		Sleep(500);
		PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
		Qipan_print(M, N, a, Y);
		Y += 30;
	}		//第一步AI随机下
	e++;
		while (1)
		{
			m = GetMouseMsg();
			if (!(m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795))//返回按钮
			{
				putimage(760, 735, &img1);
			}
			if (m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795)
			{
				putimage(760, 735, &img0);
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
					menu();
				}
			}
			//
			//
			if (e % 2 == 0)//AI下棋
			{
				Sleep(1000);
				struct point P = *AI(a, 1);
				int i = P.x, j = P.y;
				PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Qipan_print(i, j, a, Y);
				Y += 30;
				e++;
			}
			else
			{
				if (m.x >= 37 && m.x <= 246 && m.y >= 86 && m.y <= 301)//第一格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][0] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(45, 95, &imgOS, NOTSRCERASE);
						putimage(45, 95, &imgO, SRCINVERT);
						a[0][0] = -1;
						outtextxy(755, Y, L"玩家下在（0,0）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 250 && m.x <= 480 && m.y >= 88 && m.y <= 299)//第二格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][1] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(262, 97, &imgOS, NOTSRCERASE);
						putimage(262, 97, &imgO, SRCINVERT);
						a[0][1] = -1;
						outtextxy(755, Y, L"玩家下在（0,1）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 482 && m.x <= 700 && m.y >= 86 && m.y <= 301)//第三格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][2] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 95, &imgOS, NOTSRCERASE);
						putimage(490, 95, &imgO, SRCINVERT);
						a[0][2] = -1;
						outtextxy(755, Y, L"玩家下在（0,2）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 37 && m.x <= 244 && m.y >= 301 && m.y <= 512)//第四格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][0] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(45, 310, &imgOS, NOTSRCERASE);
						putimage(45, 310, &imgO, SRCINVERT);
						a[1][0] = -1;
						outtextxy(755, Y, L"玩家下在（1,0）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 246 && m.x <= 480 && m.y >= 301 && m.y <= 511)//第五格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][1] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(255, 310, &imgOS, NOTSRCERASE);
						putimage(255, 310, &imgO, SRCINVERT);
						a[1][1] = -1;
						outtextxy(755, Y, L"玩家下在（1,1）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 482 && m.x <= 699 && m.y >= 301 && m.y <= 512)//第六格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][2] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 310, &imgOS, NOTSRCERASE);
						putimage(490, 310, &imgO, SRCINVERT);
						a[1][2] = -1;
						outtextxy(755, Y, L"玩家下在（1,2）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 38 && m.x <= 241 && m.y >= 511 && m.y <= 748)//第七格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][0] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(46, 520, &imgOS, NOTSRCERASE);
						putimage(46, 520, &imgO, SRCINVERT);
						a[2][0] = -1;
						outtextxy(755, Y, L"玩家下在（2,0）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 245 && m.x <= 478 && m.y >= 510 && m.y <= 749)//第八格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][1] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(253, 520, &imgOS, NOTSRCERASE);
						putimage(253, 520, &imgO, SRCINVERT);
						a[2][1] = -1;
						outtextxy(755, Y, L"玩家下在（2,1）点；");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 480 && m.x <= 700 && m.y >= 511 && m.y <= 748)//第九格
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][2] == 0)
					{
						PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 520, &imgOS, NOTSRCERASE);
						putimage(490, 520, &imgO, SRCINVERT);
						a[2][2] = -1;
						outtextxy(755, Y, L"玩家下在（2,2）点；");
						e++;
						Y += 30;
					}
				}
			}
			int g = isend(a);
			if (g != 2)
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						a[i][j] = 2;
				
				if (g == 1)
				{
					outtextxy(755, Y, L"电脑获胜！");
					PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else if (g == -1)
				{
					outtextxy(755, Y, L"玩家获胜！");
					PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else if (g == 0)
				{
					PlaySound(TEXT("D:\\C语言程序设计\\项目\\Alphacat\\mucic\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
					outtextxy(755, Y, L"平局！");
					
				}
			}
		}
}
void Qipan_print(int x, int y,int a[3][3],int Y)//辅助函数，用于AI在棋盘上下棋
{
	IMAGE imgX, imgO, imgXS, imgOS;
	loadimage(&imgX, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\OS.png", 190, 190);
	if (x == 0 && y == 0)//第一格
	{
		putimage(45, 95, &imgXS, NOTSRCERASE);
		putimage(45, 95, &imgX, SRCINVERT);
		a[0][0] = 1;
		outtextxy(755, Y, L"电脑下在（0,0）点；");
	}
	else if (x == 0 && y == 1)//第二格
	{
		putimage(262, 97, &imgXS, NOTSRCERASE);
		putimage(262, 97, &imgX, SRCINVERT);
		a[0][1] = 1;
		outtextxy(755, Y, L"电脑下在（0,1）点；");
	}
	else if (x == 0 && y == 2)//第三格
	{
		putimage(490, 95, &imgXS, NOTSRCERASE);
		putimage(490, 95, &imgX, SRCINVERT);
		a[0][2] = 1;
		outtextxy(755, Y, L"电脑下在（0,2）点；");
	}
	else if (x == 1 && y == 0)//第四格
	{
		putimage(45, 310, &imgXS, NOTSRCERASE);
		putimage(45, 310, &imgX, SRCINVERT);
		a[1][0] = 1;
		outtextxy(755, Y, L"电脑下在（1,0）点；");
	}
	else if (x == 1 && y == 1)//第五格
	{
		putimage(255, 310, &imgXS, NOTSRCERASE);
		putimage(255, 310, &imgX, SRCINVERT);
		a[1][1] = 1;
		outtextxy(755, Y, L"电脑下在（1,1）点；");
	}
	else if (x == 1 && y == 2)//第六格
	{
		putimage(490, 310, &imgXS, NOTSRCERASE);
		putimage(490, 310, &imgX, SRCINVERT);
		a[1][2] = 1;
		outtextxy(755, Y, L"电脑下在（1,2）点；");
	}
	else if (x == 2 && y == 0)//第七格
	{
		putimage(46, 520, &imgXS, NOTSRCERASE);
		putimage(46, 520, &imgX, SRCINVERT);
		a[2][0] = 1;
		outtextxy(755, Y, L"电脑下在（2,0）点；");
	}
	else if (x == 2 && y == 1)//第八格
	{
		putimage(253, 520, &imgXS, NOTSRCERASE);
		putimage(253, 520, &imgX, SRCINVERT);
		a[2][1] = 1;
		outtextxy(755, Y, L"电脑下在（2,1）点；");
	}
	else if (x == 2 && y == 2)//第九格
	{
		putimage(490, 520, &imgXS, NOTSRCERASE);
		putimage(490, 520, &imgX, SRCINVERT);
		a[2][2] = 1;
		outtextxy(755, Y, L"电脑下在（2,2）点；");
	}
}
int playcarton()//提示先手方
{
	IMAGE img, img1;
	loadimage(&img, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\电脑先.png", 942, 795);
	loadimage(&img1, L"D:\\C语言程序设计\\项目\\Alphacat\\img\\玩家先.png", 942, 795);
	srand(time(0));
	int a = rand() % 2;
	if (a == 1)
		putimage(0, 0, &img);
	else
		putimage(0, 0, &img1);
	Sleep(2000);
	return a;
}