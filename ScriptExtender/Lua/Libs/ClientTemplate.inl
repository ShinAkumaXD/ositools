#pragma once
#include <Lua/Shared/LuaSerializers.h>
#include <Lua/Shared/LuaMethodHelpers.h>
#include <Extender/ScriptExtender.h>

BEGIN_NS(ecl::lua::tmpl)

GameObjectTemplate* GetRootTemplate(FixedString templateId)
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
	auto cache = *GetStaticSymbols().ecl__CacheTemplateManager;
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
	auto level = GetStaticSymbols().GetCurrentClientLevel();
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
	auto level = GetStaticSymbols().GetCurrentClientLevel();
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

void RegisterTemplateLib()
{
	DECLARE_MODULE(Template, Client)
	BEGIN_MODULE()
	MODULE_FUNCTION(GetRootTemplate)
	MODULE_FUNCTION(GetLocalTemplate)
	MODULE_FUNCTION(GetCacheTemplate)
	MODULE_FUNCTION(GetCacheTemplate)
	MODULE_FUNCTION(GetLocalCacheTemplate)
	MODULE_FUNCTION(GetTemplate)
	END_MODULE()
}

END_NS()
