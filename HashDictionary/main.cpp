#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Timer.h"
#include <conio.h>
#include <set>
#include<functional>
#include <unordered_map>

#pragma warning(disable : 4996)

using namespace std;
#define SIZE 195000

// 파일에 있는 스트링 저장용도.
std::vector<std::string> g_SetAll;	

//string Buckets[SIZE];  
vector<std::string> Buckets[SIZE];
unordered_map<std::string, std::string> Unorderd_Buckets;
int Hash(const std::string& Key);
void LoadWordsFromFile(std::vector<std::string>& container);


int main()
{
	/// 시간 재는 함수
	Timer _profiler;
	LoadWordsFromFile(g_SetAll);

	// 1. unordered_map에 문자를 넣는다.
	cout<<"unordered_map에 문자를 넣습니다."<<endl;
	_profiler.Start();
	for (auto& word:g_SetAll)
	{
		Unorderd_Buckets.insert({ word, word });

	}
	_profiler.End();
	

	// 2. Buckets에 문자를 넣는다.
	cout << "Chaining에 문자를 넣습니다." << endl;

	_profiler.Start();
	for (auto& word : g_SetAll)
	{
		int index = Hash(word);
		Buckets[index].push_back(word);
	}
	_profiler.End();

	return 0;
}


int Hash(const string& Key)
{
	int index = 0;
	for (int i = 0; i < Key.length(); i++)
	{
		index = index + (Key[i]-'a')* i;
	}
	index += Key.length() * 1000;

	index = index % SIZE;
	if (index<0)
		index = -index;
	
	return index;

}

void LoadWordsFromFile(std::vector<std::string>& container)
{
	/// 파일에서 모든 내용을 읽어서, set<string>에 넣는다.
	fstream file;
	string word,filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		container.push_back(word);
	}
	cout << "파일 로드 완료!" << endl;
}


