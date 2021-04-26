#include "validData.h"
#include <string>
//string to_string(int n)
//{
//		ostringstream ss;
//		ss << n;
//		return ss.str();
//}

string getSystemTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	int year, month, day;

	string date;

	day = st.wDay;
	month = st.wMonth;
	year = st.wYear;

	if (day < 10)
	{
		date = "0" + to_string(day) + ".";
	}
	else
	{
		date = to_string(day) + ".";
	}

	if (month < 10)
	{
		date += "0" + to_string(month) + ".";
	}
	else
	{
		date += to_string(month) + ".";
	}

	date += to_string(year);

	return date;
}

bool ONE_or_TWO(string data)
{
	if (data == "1" || data == "2")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool valid_date(string data)
{
	SYSTEMTIME st;
	GetSystemTime(&st); // текщее время

	size_t found = data.find_first_not_of("1234567890.");
	if (found != string::npos) {
		cout << " Неверный формат даты:";
		return false;
	}

	bool isLeap = false;
	string day = data;
	string mounth = data;
	string year = data;
	int sysyear = st.wYear;

	day = day.substr(0, 2);
	
	if (mounth.find_first_of(".") == 2)
	{
		mounth = mounth.substr(3, 2);
		if (year.find_last_of(".") == 5)
		{
			year = year.substr(6, 4);
			if (atoi(year.c_str()) <= sysyear)
			{
				if (atoi(year.c_str()) % 4 == 0) {
					isLeap = true;
				}
				if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31) {
					cout << " Неверный формат даты:";
					return false;
				}
				if (atoi(mounth.c_str()) < 1 || atoi(mounth.c_str()) > 12) {
					cout << " Неверный формат даты:";
					return false;
				}
				if (atoi(mounth.c_str()) == 2 && atoi(day.c_str()) > 29 && isLeap == true) {
					cout << " Неверный формат даты:";
					return false;
				}
				if (atoi(mounth.c_str()) == 2 && atoi(day.c_str()) > 28 && isLeap == false) {
					cout << " Неверный формат даты:";
					return false;
				}
				if (atoi(mounth.c_str()) == 4 || atoi(mounth.c_str()) == 6 || atoi(mounth.c_str()) == 9 || atoi(mounth.c_str()) == 11) {
					if (atoi(day.c_str()) > 30) {
						cout << " Неверный формат даты:";
						return false;
					}
				}
				return true;
			}
			else
			{
				cout << " Неверный формат даты:";
				return false;
			}
		}
		else
		{
			cout << " Неверный формат даты:";
			return false;
		}
	}
	else
	{
		cout << " Неверный формат даты:";
		return false;
	}
}

bool valid_name(string data)
{
	if (data.length() == 0)
	{
		return false;
	}

	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9'};
	for (size_t i = 0; i < data.length(); i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (data[i] == numbers[j] || data[i] == ' ')
			{
				cout << " Не верный формат, повторите операцию:";
				return false;
			}
		}
	}
	return true;
}

bool valid_password(string data1, string data2)
{
	if (data1.length() < 8 && data2.length() < 8)
	{
		cout << " Минимум 8 символов, повторите операцию:";
		return false;
	}
	else if (data1 != data2)
	{
		cout << " Пороли не совпали, повторите операцию:";
		return false;
	}
	size_t found = data1.find_first_of(" ");
	if (found != string::npos) {
		cout << " Неверный формат:";
		return false;
	}
	return true;
}

bool valid_zeroLen(string data)
{
	if (data.length() == 0)
	{
		return false;
	}
	size_t found = data.find_first_of(" ");
	if (found != string::npos) {
		cout << " Неверный формат:";
		return false;
	}
	return true;
}

bool valid_numbers(string data)
{
	if (data.length() == 0)
	{
		return false;
	}

	size_t found = data.find_first_not_of("1234567890+-");
	if (found != string::npos) {
		cout << " Неверный формат:";
		return false;
	}
	return true;
}

bool valid_not_numbers(string data)
{
	if (data.length() == 0)
	{
		return false;
	}

	size_t found = data.find_first_of("1234567890+-.");
	if (found != string::npos) {
		cout << " Неверный формат:";
		return false;
	}
	return true;
}
