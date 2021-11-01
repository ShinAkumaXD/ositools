#include <stdafx.h>
#include "Version.h"
#include <GameDefinitions/Base/Base.h>
#include <Extender/ScriptExtender.h>
#include <thread>

namespace dse
{
	STDString ToUTF8(WStringView s)
	{
		int size = WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0, NULL, NULL);
		STDString converted;
		converted.resize(size);
		WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size(), NULL, NULL);
		return converted;
	}

	STDWString FromUTF8(StringView s)
	{
		int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
		STDWString converted;
		converted.resize(size);
		MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
		return converted;
	}
}

std::string ToUTF8(std::wstring_view s)
{
	int size = WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0, NULL, NULL);
	std::string converted;
	converted.resize(size);
	WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size(), NULL, NULL);
	return converted;
}

std::wstring FromUTF8(std::string_view s)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
	std::wstring converted;
	converted.resize(size);
	MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
	return converted;
}

[[noreturn]]
void Fail(TCHAR const * reason)
{
#if defined(_DEBUG)
	DebugBreak();
#endif
	ERR(L"%s", reason);
	MessageBoxW(NULL, reason, L"Script Extender Error", MB_OK | MB_ICONERROR);
	TerminateProcess(GetCurrentProcess(), 1);
}

[[noreturn]]
void Fail(char const * reason)
{
#if defined(_DEBUG)
	DebugBreak();
#endif
	ERR("%s", reason);
	MessageBoxA(NULL, reason, "Script Extender Error", MB_OK | MB_ICONERROR);
	TerminateProcess(GetCurrentProcess(), 1);
}

void LogLuaError(std::string_view msg)
{
	dse::gExtender->LogLuaError(msg);
}

void LogOsirisError(std::string_view msg)
{
	dse::gExtender->LogOsirisError(msg);
}

void LogOsirisWarning(std::string_view msg)
{
	dse::gExtender->LogOsirisWarning(msg);
}

void LogOsirisMsg(std::string_view msg)
{
	dse::gExtender->LogOsirisMsg(msg);
}
