#include <Lua/Shared/LuaSerializers.h>
#include <Lua/Shared/LuaMethodHelpers.h>
#include <ScriptHelpers.h>

BEGIN_NS(lua::loca)

STDString GetTranslatedString(lua_State* L, char const* translatedStringKey, std::optional<char const*> fallbackText)
{
	STDWString translated;
	if (script::GetTranslatedString(translatedStringKey, translated)) {
		return ToUTF8(translated);
	} else {
		return fallbackText ? *fallbackText : "";
	}
}

std::tuple<STDString, FixedString> GetTranslatedStringFromKey(lua_State* L, FixedString key)
{
	TranslatedString translated;
	if (script::GetTranslatedStringFromKey(key, translated)) {
		return { ToUTF8(translated.Handle.ReferenceString), translated.Handle.Handle };
	} else {
		return {};
	}
}

unsigned NextDynamicStringHandleId{ 1 };

std::optional<STDString> CreateTranslatedString(lua_State* L, char const* keyStr, char const* value)
{
	FixedString key(keyStr);

	STDString handleStr = "ExtStr_";
	handleStr += std::to_string(NextDynamicStringHandleId++);
	FixedString handle(handleStr.c_str());

	if (script::CreateTranslatedStringKey(key, handle)) {
		STDWString str(FromUTF8(value));
		if (script::CreateTranslatedString(handle, str)) {
			return handleStr;
		}
	}

	return {};
}

bool CreateTranslatedStringKey(lua_State* L, char const* keyStr, char const* handleStr)
{
	FixedString key(keyStr);
	FixedString handle(handleStr);
	return script::CreateTranslatedStringKey(key, handle);
}

bool CreateTranslatedStringHandle(lua_State* L, char const* handleStr, char const* value)
{
	FixedString handle(handleStr);

	STDWString str(FromUTF8(value));
	return script::CreateTranslatedString(handle, str);
}

void RegisterLocalizationLib(lua_State* L)
{
	static const luaL_Reg lib[] = {
		{"GetTranslatedString", LuaWrapFunction(&GetTranslatedString)},
		{"GetTranslatedStringFromKey", LuaWrapFunction(&GetTranslatedStringFromKey)},
		{"CreateTranslatedString", LuaWrapFunction(&CreateTranslatedString)},
		{"CreateTranslatedStringKey", LuaWrapFunction(&CreateTranslatedStringKey)},
		{"CreateTranslatedStringHandle", LuaWrapFunction(&CreateTranslatedStringHandle)},
		{0,0}
	};

	RegisterLib(L, "L10N", lib);
}

END_NS()
