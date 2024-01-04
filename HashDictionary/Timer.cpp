#include "Timer.h"
#include <iostream>


Timer::Timer()
{
	QueryPerformanceFrequency(&Frequency);
}

// ����
void Timer::Start()
{
	QueryPerformanceCounter(&BeginTime);
}

void Timer::End()
{
	// ��
	QueryPerformanceCounter(&Endtime);
	__int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	double duringtimeSec = (double)elapsed / (double)Frequency.QuadPart;

	std::cout << std::endl << "����ð� : " << duringtimeSec * 1000 << "ms" << std::endl << std::endl;
}

double Timer::GetElaspedTime()
{
	__int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	double duringtimeSec = (double)elapsed / (double)Frequency.QuadPart;

	std::cout << "����ð� : " << duringtimeSec * 1000 << "ms" << std::endl << std::endl;

	return duringtimeSec;
}
