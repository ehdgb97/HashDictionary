#pragma once

#include <windows.h>

/// <summary>
/// ���� �ð��� ��� Ŭ����
/// �ڷᱸ��&�˰��� ������ ���ؼ� �����.
///
/// 2020.10.23 LeHide
/// </summary>
class Timer
{
public:
	Timer();


	void Start();
	void End();

	double GetElaspedTime();

private:
	// ����ð��� �� ����.
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;
};

