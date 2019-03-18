#ifndef LOG_H
#define LOG_H
#include<stdio.h>
#include<Windows.h>
#include"Object.h"
class Log
{
public:
	Log();
	~Log();
	void ShowLog(char* _key, char* _value);
	void ShowLog(char * value);
	void ShowLog(char * _key, int _value);
	void ShowLog(char * _key, float _value);
	void LogObject(char * _objectName, Object * _object);
};


#endif // !LOG_H
