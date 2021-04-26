#pragma once
#ifndef VALIDDATA_H
#define VALIDDATA_H
#include <iostream>
#include <Windows.h>

using namespace std;

string getSystemTime();
bool ONE_or_TWO(string data);
bool valid_date(string data);
bool valid_name(string data);
bool valid_password(string data1, string data2);
bool valid_zeroLen(string data);
bool valid_numbers(string data);
bool valid_not_numbers(string data);

#endif 
