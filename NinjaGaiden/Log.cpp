#include"Log.h"

Log::Log()
{
}

Log::~Log()
{
}

void Log::ShowLog(char* _key, char* _value)
{
	char buffer[100];
	sprintf_s(buffer, "%s : %s\n",_key,_value );
	OutputDebugStringA(buffer);
}

void Log::ShowLog(char* value){
	char buffer[100];
	sprintf_s(buffer, "%s \n",value);
	OutputDebugStringA(buffer);
}

void Log::ShowLog(char* _key, int _value) {
	char buffer[100];
	sprintf_s(buffer, "Gia tri cua %s : %d \n", _key, _value);
	OutputDebugStringA(buffer);
}

void Log::ShowLog(char* _key, float _value) {
	char buffer[100];
	sprintf_s(buffer, "Gia tri cua %s : %f \n", _key, _value);
	OutputDebugStringA(buffer);
}

void Log::LogObject(char* _objectName, Object* _object) {
	char* objectName = _objectName;
	Object* object = _object;
	ShowLog(objectName);
	ShowLog("X", object->GetBody()->GetX());
	ShowLog("Y", object->GetBody()->GetY());
	ShowLog("Vx", object->GetBody()->GetVelocityX());
	ShowLog("Vy", object->GetBody()->GetVelocityY());
}
