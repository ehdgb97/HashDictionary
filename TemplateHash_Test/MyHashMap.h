#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename Keytype,typename Valuetype>
class MyHashMap
{
	unsigned int m_size;
	vector<list<pair<Keytype, Valuetype>>> m_map;
public:

	MyHashMap():m_size(50000) { m_map.resize(m_size); }
	~MyHashMap() {};

	void Insert( const Keytype& _key, const Valuetype& _value);
	unsigned int GetHashIndex(const Keytype& _key);
	void Delete(const Keytype& _key);
	Valuetype Find(const Keytype& _key);

};
#pragma region  <typename Keytype, typename Valuetype>
template<typename Keytype, typename Valuetype>
inline void MyHashMap<Keytype, Valuetype>::Insert(const Keytype& _key, const Valuetype& _value)
{
	int index = GetHashIndex(_key);
	m_map[index].emplace_back(_key, _value);

}

template<typename Keytype, typename Valuetype>
inline unsigned int MyHashMap<Keytype, Valuetype>::GetHashIndex(const Keytype& _key)
{
	std::hash<Keytype> hasher;
	unsigned int index= hasher(_key)*65599 % m_size;
	return index;
}

template<typename Keytype, typename Valuetype>
inline void MyHashMap<Keytype, Valuetype>::Delete(const Keytype& _key)
{
	int index = GetHashIndex(_key);
	for (auto& Value : m_map[index])
		if (Value.first == _key)
			m_map[index].erase(Value);
}

template<typename Keytype, typename Valuetype>
inline Valuetype MyHashMap<Keytype, Valuetype>::Find(const Keytype& _key)
{
	int index= GetHashIndex(_key);
	for (auto& Value : m_map[index])
		if (Value.first== _key)
			return Value;
}

#pragma endregion 