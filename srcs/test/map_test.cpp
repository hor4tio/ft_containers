
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdlib.h>
/**
  * Main de test pour les fonctions associé à Map
  * Permet d'effectuer le test avec notre code ou la STL
  * Il faut changer IS_STL par 0 ou 1
  * "clang++ -D IS_STL" permet de switch sans modifier le code
  */

#ifndef IS_STL
# define IS_STL 1
#endif


#if IS_STL
	#include <map>
	namespace ft = std;
#else
	#include "../map.hpp"
#endif

template <typename T, typename U>
std::ostream &operator<<(std::ostream &outputFile, const ft::map<T, U> &map)
{
	outputFile	<< "\033[1;36mSize\t" << map.size()
				<< "\033[0m" << std::endl
				<< "\033[1;36mContent ";
	if (map.empty())
		outputFile << "<empty>";
	else
	{

		typename ft::map<T, U>::const_iterator it = map.begin();
		while (true)
		{
			outputFile << it->first << "=" << it->second;
			if (++it != map.end())
				outputFile << ", ";
			else
				break;
		}
	}
	outputFile << "\033[0m";
	return outputFile;
}

static void mapInsert()
{
	ft::map<char, int> map1, map2;
	ft::map<int, int> map3;

	std::cout << "Map Basic insert :" << std::endl;
	map1.insert(ft::pair<char,int>('a', 30));
	map1.insert(ft::pair<char,int>('c', 70));
	map1.insert(ft::pair<char,int>('b', 20));
	map1.insert(ft::pair<char,int>('d', 10));
	map1.insert(ft::pair<char,int>('e', 50));
	map1.insert(ft::pair<char,int>('0', 101));
	map1.insert(ft::pair<char,int>('f', 40));
	map1.insert(ft::pair<char,int>('g', 60));
	map1.insert(ft::pair<char,int>('2', 100));
	
	std::cout << map1 << std::endl;

	std::cout << "Map Iterator insert :" << std::endl;
  	ft::map<char,int>::iterator it = map1.begin();
  	map1.insert(it, ft::pair<char,int>('Z', 300));
	map1.insert(it, ft::pair<char,int>('5', 400));
	std::cout << map1 << std::endl;

	std::cout << "Map First/Last insert :" << std::endl;
	map2.insert(map1.begin(), map1.find('e'));
	std::cout << map2 << std::endl;

	//srand(time(NULL));
	std::cout << "Map Random Basic insert :" << std::endl;
	for (int i = 0; i < 200; ++i)
		map3.insert(ft::pair<int,int>((rand() % 1000), i));
	std::cout << map3 << std::endl;
}

void mapOperatorInsert()
{
	ft::map<char, int> map;

	map['a'] = 30;
	map['c'] = 70;
	map['b'] = 20;
	map['f'] = 40;
	map['d'] = 10;
	map['e'] = 50;
	map['0'] = 101;
	map['g'] = 60;
	map['2'] = 100;

	std::cout << map << std::endl;
}

static void mapErase()
{
	ft::map<char, int> map1, map2;

	std::cout << "Map Erase :" << std::endl;
	map1.insert(ft::pair<char,int>('a', 30));
	map1.insert(ft::pair<char,int>('c', 70));
	map1.insert(ft::pair<char,int>('b', 20));
	map1.insert(ft::pair<char,int>('d', 10));
	map1.insert(ft::pair<char,int>('e', 50));
	map1.insert(ft::pair<char,int>('0', 101));
	map1.insert(ft::pair<char,int>('f', 40));
	map1.insert(ft::pair<char,int>('g', 60));
	map1.insert(ft::pair<char,int>('2', 100));
	std::cout << map1 << std::endl;

	ft::map<char,int>::iterator it = map1.find('b');
	map1.erase(it);
	std::cout << map1 << std::endl;

	map1.erase('c');
	std::cout << map1 << std::endl;

	it = map1.find('e');
	map1.erase(it, map1.end());
	std::cout << map1 << std::endl;
}

static void mapFind()
{
	ft::map<char, int> map1, map2;

	std::cout << "Map Basic insert :" << std::endl;
	map1.insert(ft::pair<char,int>('a', 30));
	map1.insert(ft::pair<char,int>('c', 70));
	map1.insert(ft::pair<char,int>('b', 20));
	map1.insert(ft::pair<char,int>('d', 10));
	map1.insert(ft::pair<char,int>('e', 50));
	map1.insert(ft::pair<char,int>('0', 101));
	map1.insert(ft::pair<char,int>('f', 40));
	map1.insert(ft::pair<char,int>('g', 60));
	map1.insert(ft::pair<char,int>('2', 100));
	std::cout << map1 << std::endl;

	std::cout << "Map Iterator insert :" << std::endl;
  	ft::map<char,int>::iterator it = map1.begin();
  	map1.insert(it, ft::pair<char,int>('Z', 300));
	map1.insert(it, ft::pair<char,int>('5', 400));
	std::cout << map1 << std::endl;

	std::cout << "Map First/Last insert :" << std::endl;
	map2.insert(map1.begin(), map1.find('e'));
	std::cout << map2 << std::endl;
}

static void mapClear()
{
	ft::map<char, int> map;

	std::cout << "Map Clear :" << std::endl;
	map.insert(ft::pair<char,int>('a', 30));
	map.insert(ft::pair<char,int>('c', 70));
	map.insert(ft::pair<char,int>('b', 20));
	map.insert(ft::pair<char,int>('d', 10));
	map.insert(ft::pair<char,int>('e', 50));
	map.insert(ft::pair<char,int>('0', 101));
	map.insert(ft::pair<char,int>('f', 40));
	map.insert(ft::pair<char,int>('g', 60));
	map.insert(ft::pair<char,int>('2', 100));

	map.clear();
	std::cout << map << std::endl;

	map.insert(ft::pair<char,int>('e', 50));
	map.insert(ft::pair<char,int>('c', 70));
	std::cout << map << std::endl;

	std::cout << "Map Find :" << std::endl;
	ft::map<char, int>::iterator it = map.find('e');
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find e" << std::endl;
	if (map.count('e') > 0)
		std::cout << "e find with map::count" << std::endl;
	else
		std::cout << "Unable to find e" << std::endl;

	std::cout << "Map Find didnt contains:" << std::endl;
	it = map.find('o');
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find o" << std::endl;
	if (map.count('o') > 0)
		std::cout << "o find with map::count" << std::endl;
	else
		std::cout << "Unable to find o" << std::endl;

	std::cout << "Map Find NULL:" << std::endl;
	it = map.find(0);
	if (it != map.end())
		std::cout << it->first << "=" << it->second << std::endl;
	else
		std::cout << "Unable to find NULL" << std::endl;
	if (map.count(0) > 0)
		std::cout << "0 find with map::count" << std::endl;
	else
		std::cout << "Unable to find 0" << std::endl;
}

static void mapEmpty()
{
	ft::map<char, int> map1, map2, map3;

	std::cout << "Map Empty :" << std::endl;
	std::cout << (map1.empty() ? "true" : "false") << std::endl;

	map1.insert(ft::pair<char,int>('a', 30));
	map1.insert(ft::pair<char,int>('c', 70));
	map1.insert(ft::pair<char,int>('b', 20));
	map1.insert(ft::pair<char,int>('d', 10));
	map1.insert(ft::pair<char,int>('e', 50));
	map1.insert(ft::pair<char,int>('0', 101));
	map1.insert(ft::pair<char,int>('f', 40));
	map1.insert(ft::pair<char,int>('g', 60));
	map1.insert(ft::pair<char,int>('2', 100));
	std::cout << map1 << std::endl;

	ft::map<char,int>::iterator it = map1.find('b');
	std::cout << it->first << "=" << it->second << std::endl;
	map1.clear();
	std::cout << map1 << std::endl;

	map1.insert(ft::pair<char,int>('e', 50));
	map1.insert(ft::pair<char,int>('c', 70));
	std::cout << map1 << std::endl;

	std::cout << (map1.empty() ? "true" : "false") << std::endl;

	map1.clear();

	std::cout << (map1.empty() ? "true" : "false") << std::endl;
}

template<class InputIterator>
static void printIteratorTest(std::string itName, InputIterator begin, InputIterator last)
{
	std::cout << itName << " = " << begin->first << std::endl;
	std::cout << "++" << itName << " = " << (++begin)->first << std::endl;
	std::cout << itName << "++ = " << (begin++)->first << std::endl;
	std::cout << "--" << itName << " = " << (--begin)->second << std::endl;
	std::cout << itName << "-- = " << (begin--)->second << std::endl;
	std::cout << " ++(++" << itName << ") = " << (++(++begin))->first << std::endl;
	//std::cout << itName << "[3] = " << begin[3] << std::endl; // A voir si demander
	std::cout << itName << " to last >";
	while (begin != last)
		std::cout << " " << (begin++)->first;
	std::cout << std::endl;

	std::cout << itName << "last == " << itName << "last = " << (last == last) << std::endl;
	std::cout << itName << "last != " << itName << "last = " << (last != last) << std::endl;
}

static void iteratorTest()
{
	ft::map<char, int> map;
	map.insert(ft::pair<char,int>('a', 30));
	map.insert(ft::pair<char,int>('c', 70));
	map.insert(ft::pair<char,int>('b', 20));
	map.insert(ft::pair<char,int>('d', 10));
	map.insert(ft::pair<char,int>('e', 50));
	map.insert(ft::pair<char,int>('0', 101));
	map.insert(ft::pair<char,int>('f', 40));
	map.insert(ft::pair<char,int>('g', 60));
	map.insert(ft::pair<char,int>('2', 100));

	std::cout << map << std::endl;
	std::cout << "Iterator test :" << std::endl;
	std::cout << "*vector.begin() = " << map.begin()->first << std::endl;
	printIteratorTest("it", map.begin(), map.end());

	ft::map<char, int>::reverse_iterator rIt = map.rbegin();
	(void)rIt;
	std::cout << "Reverse Iterator test :" << std::endl;
	std::cout << "*vector.rbegin() = " << map.rbegin()->first << std::endl;
	printIteratorTest("reverseIt", map.rbegin(), map.rend());

	/*const ft::map<char, int> constMap(map);
	ft::map<char, int>::const_iterator itConst(constMap.begin());
	(void)itConst;
	std::cout << "Iterator const test :" << std::endl;
	std::cout << "*constVector.begin() = " << constMap.begin()->second << std::endl;
	printIteratorTest("itConst", constMap.begin(), constMap.end());*/

	/*std::cout << "Reverse Iterator const test :" << std::endl;
	std::cout << "*constVector.rbegin() = " << *constVector.rbegin() << std::endl;
	std::cout << "*constVector.rend() - 1 = " << *(constVector.rend() - 1) << std::endl;
	printIteratorTest("reverseitConst", constVector.rbegin(), constVector.rend());

	const ft::vector<int>::const_reverse_iterator constIt = vector.rbegin();
	(void)constIt;*/
}

int main()
{
	mapInsert();

	std::cout << std::endl;
	(void)&mapOperatorInsert;
	mapOperatorInsert();

	std::cout << std::endl;
	(void)&mapErase;
	// mapErase();

	std::cout << std::endl;
	(void)&mapClear;
	mapClear();

	std::cout << std::endl;
	(void)&mapEmpty;
	mapEmpty();

	std::cout << std::endl;
	(void)&mapFind;
	mapFind();

	std::cout << std::endl;
	(void)&iteratorTest;
	iteratorTest();
}
