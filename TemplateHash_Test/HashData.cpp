#include "HashData.h"

HashData::HashData()
{
}

void HashData::SetData(std::string s, int i, float f, double d)
{
	m_string = s;
	m_int = i;
	m_float = f;
	m_double = d;
}

HashData::~HashData()
{
}
