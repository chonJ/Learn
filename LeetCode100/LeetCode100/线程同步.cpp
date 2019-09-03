
#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <algorithm>

std::mutex mtx;
std::condition_variable cvar;
char g_ch = 0;

void print_fun(char ch)
{
	int cyle_cnt = 10;
	char ch_ = ch - 'A';

	for (int i = 0; i < cyle_cnt; i++)
	{
		std::unique_lock<std::mutex>ulk(mtx);
		cvar.wait(ulk, [ch_] {return ch_ == g_ch; });
		std::cout << (char)(ch_ + 'A');
		g_ch = (ch_ + 1) % 3;
		ulk.unlock();

		cvar.notify_all();
	}
}

int main_xianchengtongbu()
{
	std::vector<std::thread> threads;
	threads.push_back(std::thread(print_fun, 'A'));
	threads.push_back(std::thread(print_fun, 'B'));
	threads.push_back(std::thread(print_fun, 'C'));

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	std::cout << std::endl;

	system("pause");

	return 0;
}
/*
————————————————
版权声明：本文为CSDN博主「noBle_Ora」的原创文章，遵循CC 4.0 by - sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https ://blog.csdn.net/noBle_Ora/article/details/60464695
*/