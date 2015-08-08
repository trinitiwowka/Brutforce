#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <ctime> 
unsigned int start_time = clock(); // начальное время
								   // здесь должен быть фрагмент кода, время выполнения которого нужно измерить


using namespace std;
bool is_palindrom(string arg)
{
	register int first = 0;
	register int last = arg.size() - 1;
	if (arg.size() == 1 || arg.size() == 0)return false;
	while (first < last)
	{
		if (arg[first] != arg[last])return false;
		++first;
		--last;
	}
	return true;
}
void tolower(string&s)
{
	for (int i = 0; i < s.length(); ++i)s[i] = tolower(s[i]);
}
string ignore_space(string&s, string space)
{
	register string temp;
	for (int i = 0; i <space.size(); ++i)
	{
		if (s[0] == space[i])
		{
			temp = s[1];
			for (int i = 2; i < s.size(); ++i)
			{
				temp += s[i];
			}
			break;
		}
		if (s[s.size() - 1] == space[i])
		{
			temp = s[0];
			for (int i = 1; i < s.size() - 1; ++i)
			{
				temp += s[i];
			}
			break;
		}
	}
	return temp;
}
int main()
{
	unsigned int start_time = clock(); // начальное время
	setlocale(LC_ALL, "Russian");
	register string temp;
	ifstream file_in("1.txt");
	ofstream file_out("3.txt"/*, ios::app*/);
	register bool if_stream_bad = 1;
	 const string whitespace = { "/.,'\"%!~)(*_-=+" };
	 register __int64 counter = 0;

	vector <string> same_words;
	while (if_stream_bad)
	{
		if_stream_bad = bool(file_in >> temp);
		tolower(temp);

	////////////////////////	
		if (is_palindrom(ignore_space(temp, whitespace))) {
			if (find(same_words.begin(), same_words.end(), ignore_space(temp, whitespace)) == same_words.end())
			same_words.push_back(ignore_space(temp, whitespace));
		}
		counter++;
	}
	////////////////////////////
	for (vector<string>::iterator i = same_words.begin(); i < same_words.end(); ++i)
	{
		file_out << *i << endl;
	}
	///////////////////////////
	unsigned int end_time = clock(); // конечное время
	cout << "Runtime:" << (end_time - start_time) / 1000.0 << endl;
	cout << "All words:" << counter << endl;
	cin.get();
}