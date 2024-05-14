#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;
template<typename T>
class compare {
public:
	bool operator()(const T& a, const T& b)
	{
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first > b.first;
	}
};

int main() {
	ifstream fin("input.txt");
	if (!fin) {
		std::cout << "Eroare la citirea fisierulu!";
		return 1;
	}
	string s;
	if (!getline(fin, s)) {
		cout<<"error la citirea din fisier: input.txt";
		return 1;
	}
	transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });
	map<string, int> m;
	int i = 0;
	while(true) {
		size_t k1 = s.find_first_not_of(",.?! ",i);
		if (k1 == std::string::npos)
			break;
		size_t k2 = s.find_first_of(",.?! ", k1);
		m[s.substr(k1, k2-k1)]++;
		i = k2 + 1;
	}
	priority_queue<pair<string, int>,vector<pair<string,int>>,compare<pair<string,int>>> q;

	for (auto& i : m)
		q.push(i);

	while (!q.empty()) {
		auto a = q.top();
		q.pop();
		cout << a.first << " => " << a.second << '\n';
	}
	return 0;
}