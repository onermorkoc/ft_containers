# include "./Sources/Containers/vector.hpp"
# include "./Sources/Containers/stack.hpp"
# include "./Sources/Containers/map.hpp"
# include <vector>
# include <stack>
# include <map>
# include <iostream>

int main(void){

	std :: cout << "################################### => Vector <= ###################################" << std :: endl;

	ft::vector<int> v;

	for(int i = 0; i < 1000; i++){
		time(NULL);
		v.push_back(rand() % 1000);
	}
	
	std :: cout << "Size: " << v.size() << std :: endl;
	std :: cout << "Capacity: " << v.capacity() << std :: endl;
	std :: cout << "Bu dizi boş mu: " << v.empty() << std :: endl;
	std :: cout << "En baştaki eleman: " << v.front() << std :: endl;
	std :: cout << "En sondaki eleman: " << v.back() << std :: endl;
	std :: cout << "at(500) index değeri: " << v.at(500) << std :: endl;
	
	v.pop_back();
	std :: cout << "En sondaki elemanı sildim yeni size: " << v.size() << std :: endl;

	ft::vector<int>::iterator i = v.begin();
	int result = 0;
	while (i != v.end()){
		//std :: cout << "v[index]: " << *i << std :: endl;
		result += *i++;
	}

	std :: cout << "İçindeki elemanların toplam değeri: " << result << std :: endl;
	v.erase(v.begin() + 100, v.end() - 100);
	std :: cout << "Silme işleminden sonra 200 size olmalı: " << v.size() << std :: endl;

	v.resize(10);
	std :: cout << "Size yeniden boyutlandırdım yeni boyut 10 olmalı: " << v.size() << std :: endl;
	
	v.reserve(2000);
	std :: cout << "Kapasiteyi yeniden boyutlandırdım yeni boyut 2000 olmalı: " << v.capacity() << std :: endl;

	ft::vector<int> copy = v; // copy assignment operator test

	std :: cout << "################################### => Map <= ###################################" << std :: endl;

	ft :: map<int, int> m;

	int find = 0;
	for (int i = 0; i < 1000; i++){
		int number = rand();
		m.insert(ft::make_pair(number, number));
		if (i == 500)
			find = number;
	}

	std :: cout << "Size: " << m.size() << std :: endl;
	std :: cout << "42 sayısı mapte var mı: " << m.count(42) << std :: endl;

	ft::map<int, int>::iterator first = m.begin();

	while (first != m.end()){
		//std :: cout << "key: " << first->first << "second: " << first->second << std :: endl;
		first++;
	}
		
	std :: cout << "find(): " << m.find(find)->first << std :: endl;
	
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> eq = m.equal_range(42);
	std :: cout << "lower: " << eq.first->first << "upper: " << eq.first->first << std :: endl;

	std :: cout << "Map boş mu: " << m.empty() << std :: endl;
	m.clear();
	std :: cout << "Clear işlemınden sonra map boş mu: " << m.empty() << std :: endl;

	return (0);
}