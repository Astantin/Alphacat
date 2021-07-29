#include<forword.h>
#include<easyx.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include<process.h>
void BGM(void*)
{
	while (1)
	{
		mciSendString(L"open D:\\C语言程序设计\\项目\\Alphacat\\mucic\\bkmusic.wav alias A", NULL, 0, NULL);
		mciSendString(L"play A wait", NULL, 0, NULL);
	}
}
int main()
{
	_beginthread(BGM, 0, NULL);
	menu();
	return 0;
}