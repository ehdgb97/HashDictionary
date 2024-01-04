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

// ���Ͽ� �ִ� ��Ʈ�� ����뵵.
std::vector<std::string> g_SetAll;	

//string Buckets[SIZE];  
vector<std::string> Buckets[SIZE];
unordered_map<std::string, std::string> Unorderd_Buckets;
int Hash(const std::string& Key);
void LoadWordsFromFile(std::vector<std::string>& container);


int main()
{
	/// �ð� ��� �Լ�
	Timer _profiler;
	LoadWordsFromFile(g_SetAll);

	// 1. unordered_map�� ���ڸ� �ִ´�.
	cout<<"unordered_map�� ���ڸ� �ֽ��ϴ�."<<endl;
	_profiler.Start();
	for (auto& word:g_SetAll)
	{
		Unorderd_Buckets.insert({ word, word });

	}
	_profiler.End();
	

	// 2. Buckets�� ���ڸ� �ִ´�.
	cout << "Chaining�� ���ڸ� �ֽ��ϴ�." << endl;

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
	/// ���Ͽ��� ��� ������ �о, set<string>�� �ִ´�.
	fstream file;
	string word,filename;
	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		container.push_back(word);
	}
	cout << "���� �ε� �Ϸ�!" << endl;
}


