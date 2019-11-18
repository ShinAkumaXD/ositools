#pragma once

#include <iostream>
#include <string>

std::string ToUTF8(std::wstring const & s);
std::wstring FromUTF8(std::string const & s);

template <typename... Args>
void Debug(wchar_t const * fmt, Args... args)
{
	wchar_t buf[1024];
	int length = swprintf_s(buf, 1024 - 4, fmt, args...);
	buf[length++] = '\r';
	buf[length++] = '\n';
	buf[length++] = 0;
	OutputDebugStringW(buf);
	std::wcout << buf;
}

template <typename... Args>
void Debug(char const * fmt, Args... args)
{
	char buf[1024];
	int length = sprintf_s(buf, 1024 - 4, fmt, args...);
	buf[length++] = '\r';
	buf[length++] = '\n';
	buf[length++] = 0;
	OutputDebugStringA(buf);
	std::cout << buf;
}

inline void DebugRaw(char const * msg)
{
	OutputDebugStringA(msg);
	std::cout << msg << std::endl;
}

[[noreturn]]
void Fail(TCHAR const * reason);

[[noreturn]]
void Fail(char const * reason);

void CreateConsole(HMODULE hModule);
