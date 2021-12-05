local _I = Ext._Internal

_I._PublishedEvents = {
	"GameStateChanged",
	"GetSkillDamage",
	"GetSkillAPCost",
	"ComputeCharacterHit",
	"CalculateTurnOrder", -- FIXME
	"GetHitChance",
	"StatusGetEnterChance",
	"StatusHitEnter",
	"BeforeCharacterApplyDamage",
	"TreasureItemGenerated",
	"BeforeCraftingExecuteCombination",
	"AfterCraftingExecuteCombination",
	"BeforeShootProjectile",
	"ShootProjectile",
	"ProjectileHit",
	"GroundHit",
	"OnExecutePropertyDataOnTarget",
	"OnExecutePropertyDataOnPosition"
}

Ext.IsClient = function ()
	return false
end

Ext.IsServer = function ()
	return true
end

Ext._GetModPersistentVars = function (modTable)
	local tab = Mods[modTable]
	if tab ~= nil then
		local persistent = tab.PersistentVars
		if persistent ~= nil then
			return Ext.Json.Stringify(persistent)
		end
	end
end

Ext._RestoreModPersistentVars = function (modTable, vars)
	local tab = Mods[modTable]
	if tab ~= nil then
		tab.PersistentVars = Ext.Json.Parse(vars)
	end
end

_I._RegisterEvents()

Ext.Events.OnExecutePropertyDataOnTarget:Subscribe(function (e)
	local prop = e.Property
	local propType = Ext._SkillPropertyTypes[prop.Action]
	if propType ~= nil and propType.ExecuteOnTarget ~= nil then
		propType.ExecuteOnTarget(e.Property, e.Attacker, e.Target, e.ImpactOrigin, e.IsFromItem, e.Skill, e.Hit)
	end
end)

Ext.Events.OnExecutePropertyDataOnPosition:Subscribe(function (e)
	local prop = e.Property
	local propType = Ext._SkillPropertyTypes[prop.Action]
	if propType ~= nil and propType.ExecuteOnPosition ~= nil then
		propType.ExecuteOnPosition(e.Property, e.Attacker, e.Position, e.AreaRadius, e.IsFromItem, e.Skill, e.Hit)
	end
end)

_C = function ()
	return Ext.GetCharacter(CharacterGetHostCharacter())
end

_W = function ()
	return Ext.GetItem(CharacterGetEquippedWeapon(CharacterGetHostCharacter()))
end

-- Backwards compatibility with old Osiris APIs
Ext.RegisterOsirisListener = CallDeprecated(Ext.Osiris.RegisterListener, "RegisterOsirisListener", "Osiris.RegisterListener")
Ext.OsirisIsCallable = CallDeprecated(Ext.Osiris.IsCallable, "OsirisIsCallable", "Osiris.IsCallable")
Ext.NewCall = CallDeprecated(Ext.Osiris.NewCall, "NewCall", "Osiris.NewCall")
Ext.NewQuery = CallDeprecated(Ext.Osiris.NewQuery, "NewQuery", "Osiris.NewQuery")
Ext.NewEvent = CallDeprecated(Ext.Osiris.NewEvent, "NewEvent", "Osiris.NewEvent")

-- Backwards compatibility with old Net APIs
Ext.BroadcastMessage = CallDeprecated(Ext.Net.BroadcastMessage, "BroadcastMessage", "Net.BroadcastMessage")
Ext.PostMessageToClient = CallDeprecated(Ext.Net.PostMessageToClient, "PostMessageToClient", "Net.PostMessageToClient")
Ext.PostMessageToUser = CallDeprecated(Ext.Net.PostMessageToUser, "PostMessageToUser", "Net.PostMessageToUser")
Ext.PlayerHasExtender = CallDeprecated(Ext.Net.PlayerHasExtender, "PlayerHasExtender", "Net.PlayerHasExtender")

-- Backwards compatibility with old custom stat APIs
Ext.CreateCustomStat = CallDeprecated(Ext.CustomStat.Create, "CreateCustomStat", "CustomStat.Create")
Ext.GetCustomStatById = CallDeprecated(Ext.CustomStat.GetById, "GetCustomStatById", "CustomStat.GetById")
Ext.GetCustomStatByName = CallDeprecated(Ext.CustomStat.GetByName, "GetCustomStatByName", "CustomStat.GetByName")
Ext.GetAllCustomStats = CallDeprecated(Ext.CustomStat.GetAll, "GetAllCustomStats", "CustomStat.GetAll")
