#pragma once
#include <string>
class HashData
{
private:
	std::string m_string;
	int m_int;
	float m_float;
	double m_double;


public:
	HashData();
	void SetData(std::string s, int i, float f, double d);
	~HashData();
	const std::string Getstring() const { return m_string; }
	const int Getm_int() const { return m_int; }

};

