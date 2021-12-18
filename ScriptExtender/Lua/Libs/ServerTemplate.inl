#pragma once
#include <Lua/Shared/LuaSerializers.h>
#include <Lua/Shared/LuaMethodHelpers.h>
#include <Extender/ScriptExtender.h>

BEGIN_NS(esv::lua::tmpl)

GameObjectTemplate* GetRootTemplate(FixedString const& templateId)
{
	auto bank = GetStaticSymbols().GetGlobalTemplateBank();
	auto tmpl = bank->Templates.Find(templateId);
	if (tmpl) {
		return *tmpl;
	} else {
		return nullptr;
	}
}

GameObjectTemplate* GetCacheTemplate(FixedString const& templateId)
{
	auto cache = *GetStaticSymbols().esv__CacheTemplateManager;
	if (cache) {
		auto tmpl = cache->Templates.Find(templateId);
		if (tmpl) {
			return *tmpl;
		}
	}

	return nullptr;
}

GameObjectTemplate* GetLocalTemplate(FixedString const& templateId)
{
	auto level = GetStaticSymbols().GetCurrentServerLevel();
	if (level) {
		auto tmpl = level->LocalTemplateManager->Templates.Find(templateId);
		if (tmpl) {
			return *tmpl;
		}
	}

	return nullptr;
}

GameObjectTemplate* GetLocalCacheTemplate(FixedString const& templateId)
{
	auto level = GetStaticSymbols().GetCurrentServerLevel();
	if (level) {
		auto tmpl = level->LevelCacheTemplateManager->Templates.Find(templateId);
		if (tmpl) {
			return *tmpl;
		}
	}

	return nullptr;
}

GameObjectTemplate* GetTemplate(FixedString const& templateId)
{
	auto tmpl = GetRootTemplate(templateId);
	if (!tmpl) {
		tmpl = GetLocalTemplate(templateId);
		if (!tmpl) {
			tmpl = GetCacheTemplate(templateId);
			if (!tmpl) {
				tmpl = GetLocalCacheTemplate(templateId);
			}
		}
	}

	return tmpl;
}

void RegisterTemplateLib(lua_State* L)
{
	static const luaL_Reg lib[] = {
		{"GetRootTemplate", LuaWrapFunction(&GetRootTemplate)},
		{"GetLocalTemplate", LuaWrapFunction(&GetLocalTemplate)},
		{"GetCacheTemplate", LuaWrapFunction(&GetCacheTemplate)},
		{"GetLocalCacheTemplate", LuaWrapFunction(&GetLocalCacheTemplate)},
		{"GetTemplate", LuaWrapFunction(&GetTemplate)},
		{0,0}
	};

	RegisterLib(L, "Template", lib);
}

END_NS()
