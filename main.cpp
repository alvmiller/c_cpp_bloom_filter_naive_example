#include <bits/stdc++.h>

using namespace std;

/*
Bloom Filter C

https://en.wikipedia.org/wiki/Bloom_filter
https://www.geeksforgeeks.org/python/bloom-filters-introduction-and-python-implementation/
https://redis.io/docs/latest/develop/data-types/probabilistic/bloom-filter/
https://systemdesign.one/bloom-filters-explained/
https://medium.com/@sylvain.tiset/bloom-filters-101-the-power-of-probabilistic-data-structures-ef1b4a422b0b
https://www.andreinc.net/2022/03/01/on-implementing-bloom-filters-in-c
https://github.com/nomemory/bloomfilters-c
https://github.com/barrust/bloom
https://github.com/jvirkki/libbloom
https://medium.com/@himanshubarak/bloom-filter-the-data-structure-built-for-speed-search-2a9361136d2
https://save-buffer.github.io/bloom_filter.html
https://github.com/ArashPartow/bloom
https://daankolthof.com/2019/05/06/implementing-a-simple-high-performance-bloom-filter-in-c/
https://github.com/daankolthof/bloomfilter
https://michaelschmatz.com/posts/how-to-write-a-bloom-filter-cpp/
https://github.com/PeterRK/PageBloomFilter

https://www.geeksforgeeks.org/python/bloom-filters-introduction-and-python-implementation/
https://medium.com/@himanshubarak/bloom-filter-the-data-structure-built-for-speed-search-2a9361136d2
*/

int h1(string s, int arrSize)
{
	long long int hash = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		hash = (hash + ((int)s[i]));
		hash = hash % arrSize;
	}
	return hash;
}

int h2(string s, int arrSize)
{
	long long int hash = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		hash = hash + pow(19, i) * s[i];
		hash = hash % arrSize;
	}
	return hash % arrSize;
}

int h3(string s, int arrSize)
{
	long long int hash = 7;
	for (int i = 0; i < s.size(); ++i)
	{
		hash = (hash * 31 + s[i]) % arrSize;
	}
	return hash % arrSize;
}

int h4(string s, int arrSize)
{
	long long int hash = 3;
	int p = 7;
	for (int i = 0; i < s.size(); ++i) {
		hash += hash * 7 + s[0] * pow(p, i);
		hash = hash % arrSize;
	}
	return hash;
}

bool lookup(bool* bitarray, int arrSize, string s)
{
	int a = h1(s, arrSize);
	int b = h2(s, arrSize);
	int c = h3(s, arrSize);
	int d = h4(s, arrSize);

	if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
		return true;
	else
		return false;
}

void insert(bool* bitarray, int arrSize, string s)
{
	if (lookup(bitarray, arrSize, s))
		cout << s << " (Maybe) has been already inserted" << endl;
	else
	{
		int a = h1(s, arrSize);
		int b = h2(s, arrSize);
		int c = h3(s, arrSize);
		int d = h4(s, arrSize);

		bitarray[a] = true;
		bitarray[b] = true;
		bitarray[c] = true;
		bitarray[d] = true;

		cout << s << " inserted" << endl;
	}
}

int main()
{
	bool bitarray[100] = { false };
	int arrSize = 100;
	string sarray[6] = { "aaa", "aaas",  "aaabb",
	                     "aaabbcc", "nnnnn", "aaa"};
	for (int i = 0; i < 6; ++i) {
		insert(bitarray, arrSize, sarray[i]);
	}

	return 0;
}
