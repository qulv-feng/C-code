#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	char ch;
//	cin >> ch;
//	cout << "  " << ch<< "  " << endl;
//	cout << " " << ch << ch << ch << " " << endl;
//	cout << ch << ch << ch << ch << ch << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	short b = 0;
//	cout << sizeof(int) << " " << sizeof(short) << endl;
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world,hello everyone";
//	string s2;
//	s2 = s1.substr();
//	cout << s2 << endl;
//	s2 = s1.substr(2, 3);
//	cout << s2 << endl;
//	s2 = s1.substr(2);
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world,hello everyone";
//	int ret = s1.find("bit", 2);
//	if (ret == string::npos)
//		printf("No this this string\n");
//	else
//	{
//		string s2 = s1.substr(ret, 3);
//		cout << s2 << endl;
//	}
//	return 0;
//}


//int main()
//{
//	string s1 = "1213213hello";
//	size_t pos = 0;
//	int ret = stoi(s1,&pos);
//	cout << ret << endl;
//	cout << pos << endl;
//	return 0;
//}
//
//int main()
//{
//	double f = 0;
//	string s = "1324.213dsfr";
//	f = stod(s);
//	cout << f << endl;
//	return 0;
//}
//
//int main()
//{
//	double pi = 3.1415926;
//	string s = to_string(pi);
//	cout << "pi is " + s << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	int num = s.size();
//	size_t ret = s.find(' ', 0);
//	while (ret != string::npos)
//	{
//		num--;
//		ret = s.find(' ', ret+1);
//	}
//	cout << num << endl;
//	return 0;
//}


#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	string s1;
	string s2;
	while (num)
	{
		cin >> s1 >> s2;
		if (s1 == s2)
			printf("Tie\n");
		else if (s1 > s2)
			printf("Player1\n");
		else
			printf("Player2\n");
		num--;
	}
	return 0;
}