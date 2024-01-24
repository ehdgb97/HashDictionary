#include <iostream>
#include<string>
#include<vector>
#include <fstream>
#include <conio.h>
#include <set>
#include<functional>
#include <unordered_map>
#include "Timer.h"
#include "HashData.h"
#include "MyHashMap.h"
using namespace std;
// 파일에 있는 스트링 저장용도.
std::vector<std::string> g_string_Container;
void LoadWordsFromFile(std::vector<std::string>& container);
template<typename T>
int increase(T t)
{
	return t + 1;
}
int main()
{
	Timer _profiler;
	MyHashMap<string, HashData> myHashMap_string;
	MyHashMap<int, HashData> myHashMap_int;
	unordered_map<string, HashData> unorderedMap;
	LoadWordsFromFile(g_string_Container);
	int I=0;
	float F=0;
	double D=0;

	_profiler.Start();
	for (auto& S : g_string_Container)
	{
		HashData data;
		data.SetData(S, I, F, D);
		I++;
		F++;
		D++;
		myHashMap_int.Insert(data.Getm_int(), data);
	}
	_profiler.End();


	_profiler.Start();
	for (auto& S : g_string_Container)
	{
		HashData data;
		data.SetData(S, I, F, D);
		I++;
		F++;
		D++;
		myHashMap_string.Insert(data.Getstring(), data);
	}
	_profiler.End();
	_profiler.Start();

	for (auto& S : g_string_Container)
	{
		HashData data;
		data.SetData(S, I, F, D);
		I++;
		F++;
		D++;
		unorderedMap.insert(make_pair(data.Getstring(), data));
	}
	_profiler.End();

}


void LoadWordsFromFile(std::vector<std::string>& container)
{
	/// 파일에서 모든 내용을 읽어서, set<string>에 넣는다.
	fstream file;
	string word, filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		container.push_back(word);
	}
	cout << "파일 로드 완료!" << endl;
}
