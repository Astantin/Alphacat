#include<AI.h>
#include<easyx.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
void menu()
{
	IMAGE img, img1, img2, img3;
	loadimage(&img, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\��ͷ.png", 942, 795);
	loadimage(&img1, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\�˻�.png", 942, 795);
	loadimage(&img2, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\���.png", 942, 795);
	loadimage(&img3, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\�˳�.png", 942, 795);
	initgraph(942, 795);//������Ϸ����
	putimage(0, 0, &img);
	void Qipan_PVP();
	void Qipan_PVE(int i);
	int playcarton();
	MOUSEMSG m;
	while (1)
	{

		m = GetMouseMsg();

		if ((m.x <= 328 || m.x >= 579 || m.y <= 208 || m.y >= 306) && (m.x <= 330 || m.x >= 578 || m.y <= 360 || m.y >= 461) && (m.x <= 332 || m.x >= 581 || m.y <= 534 || m.y >= 634))//�˵�
		{
			putimage(0, 0, &img);
		}
		//
		//
		if (m.x >= 328 && m.x <= 579 && m.y >= 208 && m.y <= 306)//�˻�
		{
			putimage(0, 0, &img1);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Sleep(1000);
				int tp = playcarton();
				Qipan_PVE(tp);
			}			
		}
		//
		//
		if (m.x >= 330 && m.x <= 578 && m.y >= 360 && m.y <= 461)//����
		{
			putimage(0, 0, &img2);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Sleep(1000);
				Qipan_PVP();
			}
		}
		//
		//
		if (m.x >= 332 && m.x <= 581 && m.y >= 534 && m.y <= 634)//�˳�
		{
			putimage(0, 0, &img3);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
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
	loadimage(&img, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����.png", 942, 795);
	loadimage(&img0, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����0.png", 160, 60);
	loadimage(&img1, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����1.png", 160, 60);
	loadimage(&imgX, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\OS.png", 190, 190);
	putimage(0, 0, &img);
	MOUSEMSG m;
	int e = 0;
	int a[3][3]{};
	int Y = 20;
	while (1)
	{
		m = GetMouseMsg();

		if (!(m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795))//���ذ�ť
		{
			putimage(760, 735, &img1);
		}
		if (m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795)
		{
			putimage(760, 735, &img0);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
				menu();
			}
		}
		//
		//
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		if (m.x >= 37 && m.x <= 246 && m.y >= 86 && m.y <= 301)//��һ��
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][0] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(45, 95, &imgXS, NOTSRCERASE);
					putimage(45, 95, &imgX, SRCINVERT);
					a[0][0] = 1;
					outtextxy(755, Y, L"���1���ڣ�0,0���㣻");
					Y += 30;
				}
				else
				{
					putimage(45, 95, &imgOS, NOTSRCERASE);
					putimage(45, 95, &imgO, SRCINVERT);
					a[0][0] = -1;
					outtextxy(755, Y, L"���2���ڣ�0,0���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 250 && m.x <= 480 && m.y >= 88 && m.y <= 299)//�ڶ���
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][1] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(262, 97, &imgXS, NOTSRCERASE);
					putimage(262, 97, &imgX, SRCINVERT);
					a[0][1] = 1;
					outtextxy(755, Y, L"���1���ڣ�0,1���㣻");
					Y += 30;
				}
				else
				{
					putimage(262, 97, &imgOS, NOTSRCERASE);
					putimage(262, 97, &imgO, SRCINVERT);
					a[0][1] = -1;
					outtextxy(755, Y, L"���2���ڣ�0,1���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 482 && m.x <= 700 && m.y >= 86 && m.y <= 301)//������
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[0][2] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 95, &imgXS, NOTSRCERASE);
					putimage(490, 95, &imgX, SRCINVERT);
					a[0][2] = 1;
					outtextxy(755, Y, L"���1���ڣ�0,2���㣻");
					Y += 30;
				}
				else
				{
					putimage(490, 95, &imgOS, NOTSRCERASE);
					putimage(490, 95, &imgO, SRCINVERT);
					a[0][2] = -1;
					outtextxy(755, Y, L"���2���ڣ�0,2���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 37 && m.x <= 244 && m.y >= 301 && m.y <= 512)//���ĸ�
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][0] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(45, 310, &imgXS, NOTSRCERASE);
					putimage(45, 310, &imgX, SRCINVERT);
					a[1][0] = 1;
					outtextxy(755, Y, L"���1���ڣ�1,0���㣻");
					Y += 30;
				}
				else
				{
					putimage(45, 310, &imgOS, NOTSRCERASE);
					putimage(45, 310, &imgO, SRCINVERT);
					a[1][0] = -1;
					outtextxy(755, Y, L"���2���ڣ�1,0���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 246 && m.x <= 480 && m.y >= 301 && m.y <= 511)//�����
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][1] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(255, 310, &imgXS, NOTSRCERASE);
					putimage(255, 310, &imgX, SRCINVERT);
					a[1][1] = 1;
					outtextxy(755, Y, L"���1���ڣ�1,1���㣻");
					Y += 30;
				}
				else
				{
					putimage(255, 310, &imgOS, NOTSRCERASE);
					putimage(255, 310, &imgO, SRCINVERT);
					a[1][1] = -1;
					outtextxy(755, Y, L"���2���ڣ�1,1���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 482 && m.x <= 699 && m.y >= 301 && m.y <= 512)//������
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[1][2] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 310, &imgXS, NOTSRCERASE);
					putimage(490, 310, &imgX, SRCINVERT);
					a[1][2] = 1;
					outtextxy(755, Y, L"���1���ڣ�1,2���㣻");
					Y += 30;
				}
				else
				{
					putimage(490, 310, &imgOS, NOTSRCERASE);
					putimage(490, 310, &imgO, SRCINVERT);
					a[1][2] = -1;
					outtextxy(755, Y, L"���2���ڣ�1,2���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 38 && m.x <= 241 && m.y >= 511 && m.y <= 748)//���߸�
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][0] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(46, 520, &imgXS, NOTSRCERASE);
					putimage(46, 520, &imgX, SRCINVERT);
					a[2][0] = 1;
					outtextxy(755, Y, L"���1���ڣ�2,0���㣻");
					Y += 30;
				}
				else
				{
					putimage(46, 520, &imgOS, NOTSRCERASE);
					putimage(46, 520, &imgO, SRCINVERT);
					a[2][0] = -1;
					outtextxy(755, Y, L"���2���ڣ�2,0���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 245 && m.x <= 478 && m.y >= 510 && m.y <= 749)//�ڰ˸�
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][1] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(253, 520, &imgXS, NOTSRCERASE);
					putimage(253, 520, &imgX, SRCINVERT);
					a[2][1] = 1;
					outtextxy(755, Y, L"���1���ڣ�2,1���㣻");
					Y += 30;
				}
				else
				{
					putimage(253, 520, &imgOS, NOTSRCERASE);
					putimage(253, 520, &imgO, SRCINVERT);
					a[2][1] = -1;
					outtextxy(755, Y, L"���2���ڣ�2,1���㣻");
					Y += 30;
				}
			}
		}
		if (m.x >= 480 && m.x <= 700 && m.y >= 511 && m.y <= 748)//�ھŸ�
		{
			if (m.uMsg == WM_LBUTTONDOWN && a[2][2] == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				if (e++ % 2 == 0)
				{
					putimage(490, 520, &imgXS, NOTSRCERASE);
					putimage(490, 520, &imgX, SRCINVERT);
					a[2][2] = 1;
					outtextxy(755, Y, L"���1���ڣ�2,2���㣻");
					Y += 30;
				}
				else
				{
					putimage(490, 520, &imgOS, NOTSRCERASE);
					putimage(490, 520, &imgO, SRCINVERT);
					a[2][2] = -1;
					outtextxy(755, Y, L"���2���ڣ�2,2���㣻");
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
				outtextxy(755, Y, L"���1��ʤ��");
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (g == -1)
			{
				outtextxy(755, Y, L"���2��ʤ��");
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (g == 0)
			{
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(1000);
				outtextxy(755, Y, L"ƽ�֣�");			
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
	loadimage(&img, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����.png", 942, 795);
	loadimage(&img0, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����0.png", 160, 60);
	loadimage(&img1, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\����1.png", 160, 60);
	loadimage(&imgX, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\OS.png", 190, 190);
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
		PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
		Qipan_print(M, N, a, Y);
		Y += 30;
	}		//��һ��AI�����
	e++;
		while (1)
		{
			m = GetMouseMsg();
			if (!(m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795))//���ذ�ť
			{
				putimage(760, 735, &img1);
			}
			if (m.x >= 760 && m.x <= 920 && m.y >= 735 && m.y <= 795)
			{
				putimage(760, 735, &img0);
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\buttonOnClicked.wav"), NULL, SND_FILENAME | SND_ASYNC );
					menu();
				}
			}
			//
			//
			if (e % 2 == 0)//AI����
			{
				Sleep(1000);
				struct point P = *AI(a, 1);
				int i = P.x, j = P.y;
				PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Qipan_print(i, j, a, Y);
				Y += 30;
				e++;
			}
			else
			{
				if (m.x >= 37 && m.x <= 246 && m.y >= 86 && m.y <= 301)//��һ��
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][0] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(45, 95, &imgOS, NOTSRCERASE);
						putimage(45, 95, &imgO, SRCINVERT);
						a[0][0] = -1;
						outtextxy(755, Y, L"������ڣ�0,0���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 250 && m.x <= 480 && m.y >= 88 && m.y <= 299)//�ڶ���
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][1] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(262, 97, &imgOS, NOTSRCERASE);
						putimage(262, 97, &imgO, SRCINVERT);
						a[0][1] = -1;
						outtextxy(755, Y, L"������ڣ�0,1���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 482 && m.x <= 700 && m.y >= 86 && m.y <= 301)//������
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[0][2] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 95, &imgOS, NOTSRCERASE);
						putimage(490, 95, &imgO, SRCINVERT);
						a[0][2] = -1;
						outtextxy(755, Y, L"������ڣ�0,2���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 37 && m.x <= 244 && m.y >= 301 && m.y <= 512)//���ĸ�
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][0] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(45, 310, &imgOS, NOTSRCERASE);
						putimage(45, 310, &imgO, SRCINVERT);
						a[1][0] = -1;
						outtextxy(755, Y, L"������ڣ�1,0���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 246 && m.x <= 480 && m.y >= 301 && m.y <= 511)//�����
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][1] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(255, 310, &imgOS, NOTSRCERASE);
						putimage(255, 310, &imgO, SRCINVERT);
						a[1][1] = -1;
						outtextxy(755, Y, L"������ڣ�1,1���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 482 && m.x <= 699 && m.y >= 301 && m.y <= 512)//������
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[1][2] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 310, &imgOS, NOTSRCERASE);
						putimage(490, 310, &imgO, SRCINVERT);
						a[1][2] = -1;
						outtextxy(755, Y, L"������ڣ�1,2���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 38 && m.x <= 241 && m.y >= 511 && m.y <= 748)//���߸�
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][0] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(46, 520, &imgOS, NOTSRCERASE);
						putimage(46, 520, &imgO, SRCINVERT);
						a[2][0] = -1;
						outtextxy(755, Y, L"������ڣ�2,0���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 245 && m.x <= 478 && m.y >= 510 && m.y <= 749)//�ڰ˸�
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][1] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(253, 520, &imgOS, NOTSRCERASE);
						putimage(253, 520, &imgO, SRCINVERT);
						a[2][1] = -1;
						outtextxy(755, Y, L"������ڣ�2,1���㣻");
						e++;
						Y += 30;
					}
				}
				else if (m.x >= 480 && m.x <= 700 && m.y >= 511 && m.y <= 748)//�ھŸ�
				{
					if (m.uMsg == WM_LBUTTONDOWN && a[2][2] == 0)
					{
						PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\Luozi.wav"), NULL, SND_FILENAME | SND_ASYNC );
						putimage(490, 520, &imgOS, NOTSRCERASE);
						putimage(490, 520, &imgO, SRCINVERT);
						a[2][2] = -1;
						outtextxy(755, Y, L"������ڣ�2,2���㣻");
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
					outtextxy(755, Y, L"���Ի�ʤ��");
					PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else if (g == -1)
				{
					outtextxy(755, Y, L"��һ�ʤ��");
					PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else if (g == 0)
				{
					PlaySound(TEXT("D:\\C���Գ������\\��Ŀ\\Alphacat\\mucic\\defeat.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
					outtextxy(755, Y, L"ƽ�֣�");
					
				}
			}
		}
}
void Qipan_print(int x, int y,int a[3][3],int Y)//��������������AI������������
{
	IMAGE imgX, imgO, imgXS, imgOS;
	loadimage(&imgX, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\X.png", 190, 190);
	loadimage(&imgO, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\O.png", 190, 190);
	loadimage(&imgXS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\XS.png", 190, 190);
	loadimage(&imgOS, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\OS.png", 190, 190);
	if (x == 0 && y == 0)//��һ��
	{
		putimage(45, 95, &imgXS, NOTSRCERASE);
		putimage(45, 95, &imgX, SRCINVERT);
		a[0][0] = 1;
		outtextxy(755, Y, L"�������ڣ�0,0���㣻");
	}
	else if (x == 0 && y == 1)//�ڶ���
	{
		putimage(262, 97, &imgXS, NOTSRCERASE);
		putimage(262, 97, &imgX, SRCINVERT);
		a[0][1] = 1;
		outtextxy(755, Y, L"�������ڣ�0,1���㣻");
	}
	else if (x == 0 && y == 2)//������
	{
		putimage(490, 95, &imgXS, NOTSRCERASE);
		putimage(490, 95, &imgX, SRCINVERT);
		a[0][2] = 1;
		outtextxy(755, Y, L"�������ڣ�0,2���㣻");
	}
	else if (x == 1 && y == 0)//���ĸ�
	{
		putimage(45, 310, &imgXS, NOTSRCERASE);
		putimage(45, 310, &imgX, SRCINVERT);
		a[1][0] = 1;
		outtextxy(755, Y, L"�������ڣ�1,0���㣻");
	}
	else if (x == 1 && y == 1)//�����
	{
		putimage(255, 310, &imgXS, NOTSRCERASE);
		putimage(255, 310, &imgX, SRCINVERT);
		a[1][1] = 1;
		outtextxy(755, Y, L"�������ڣ�1,1���㣻");
	}
	else if (x == 1 && y == 2)//������
	{
		putimage(490, 310, &imgXS, NOTSRCERASE);
		putimage(490, 310, &imgX, SRCINVERT);
		a[1][2] = 1;
		outtextxy(755, Y, L"�������ڣ�1,2���㣻");
	}
	else if (x == 2 && y == 0)//���߸�
	{
		putimage(46, 520, &imgXS, NOTSRCERASE);
		putimage(46, 520, &imgX, SRCINVERT);
		a[2][0] = 1;
		outtextxy(755, Y, L"�������ڣ�2,0���㣻");
	}
	else if (x == 2 && y == 1)//�ڰ˸�
	{
		putimage(253, 520, &imgXS, NOTSRCERASE);
		putimage(253, 520, &imgX, SRCINVERT);
		a[2][1] = 1;
		outtextxy(755, Y, L"�������ڣ�2,1���㣻");
	}
	else if (x == 2 && y == 2)//�ھŸ�
	{
		putimage(490, 520, &imgXS, NOTSRCERASE);
		putimage(490, 520, &imgX, SRCINVERT);
		a[2][2] = 1;
		outtextxy(755, Y, L"�������ڣ�2,2���㣻");
	}
}
int playcarton()//��ʾ���ַ�
{
	IMAGE img, img1;
	loadimage(&img, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\������.png", 942, 795);
	loadimage(&img1, L"D:\\C���Գ������\\��Ŀ\\Alphacat\\img\\�����.png", 942, 795);
	srand(time(0));
	int a = rand() % 2;
	if (a == 1)
		putimage(0, 0, &img);
	else
		putimage(0, 0, &img1);
	Sleep(2000);
	return a;
}