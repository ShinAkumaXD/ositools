BEGIN_CLS(eoc::ItemDefinition)
P_RO(Version)
P_RO(NetID)
P_RO(ItemNetId)
P(RootTemplate)
P_RO(RootTemplateType)
P(OriginalRootTemplate)
P_RO(OriginalRootTemplateType)
P_RO(InventoryNetID)
P_RO(InventorySubContainerNetID)
P(Slot)
P(Amount)
P(GoldValueOverwrite)
P(WeightValueOverwrite)
P(DamageTypeOverwrite)
P(SomeOverwrite)
P(ItemType)
P(CustomDisplayName)
P(CustomDescription)
P(CustomBookContent)
P(GenerationStatsId)
P(GenerationItemType)
P(GenerationRandom)
P(GenerationLevel)
P_REF(GenerationBoostSet)
P_RO(LevelGroupIndex)
P_RO(RootGroupIndex)
P_RO(NameIndex)
P_RO(NameCool)
P(StatsLevel)
P(Key)
P(LockLevel)
P(StatsEntryName)
P(EquipmentStatsType)
P(HasModifiedSkills)
P(Skills)
P_REF(RuneBoostSet)
P_REF(DeltaModSet)
P(HasGeneratedStats)
P(IsIdentified)
P(GMFolding)
P(CanUseRemotely)

P_FUN(ResetProgression, ResetProgression)

#if defined(GENERATING_PROPMAP)
pm.AddRawProperty("GenerationBoosts",
	&(GenericGetOffsetProperty<decltype(PM::ObjectType::GenerationBoostSet)>),
	&(GenericSetOffsetProperty<decltype(PM::ObjectType::GenerationBoostSet)>),
	offsetof(PM::ObjectType, GenerationBoostSet)
);
pm.AddRawProperty("RuneBoosts",
	&(GenericGetOffsetProperty<decltype(PM::ObjectType::RuneBoostSet)>),
	&(GenericSetOffsetProperty<decltype(PM::ObjectType::RuneBoostSet)>),
	offsetof(PM::ObjectType, RuneBoostSet)
);
pm.AddRawProperty("DeltaMods",
	&(GenericGetOffsetProperty<decltype(PM::ObjectType::DeltaModSet)>),
	&(GenericSetOffsetProperty<decltype(PM::ObjectType::DeltaModSet)>),
	offsetof(PM::ObjectType, DeltaModSet)
);
#endif

END_CLS()

BEGIN_CLS(esv::ItemGeneration)
P_RO(Base)
P_RO(ItemType)
P_RO(Random)
P_RO(Level)
P_RO(Boosts)
END_CLS()

BEGIN_CLS(esv::Item)
INHERIT(IEoCServerObject)
P_RO(WorldPos)
P(Flags)
P_BITMASK(Flags)
P(Flags2)
P_BITMASK(Flags2)
/*
// Make dangerous flags read-only
propertyMap.Flags[GFS.strActivated].Flags &= ~kPropWrite;
propertyMap.Flags[GFS.strOffStage].Flags &= ~kPropWrite;
propertyMap.Flags[GFS.strDestroyed].Flags &= ~kPropWrite;
propertyMap.Flags[GFS.strGlobal].Flags &= ~kPropWrite;
*/
P_RO(CurrentLevel)
// Available via IGameObject
// P_RO(Scale)
P_REF(AI)
P_REF(CurrentTemplate)
P(OriginalTemplateType)
P(CustomDisplayName)
P(CustomDescription)
P(CustomBookContent)
P(StatsId)
P_REF(Stats)
P_REF(StatsFromName)
P_REF(Generation)
P_RO(InventoryHandle)
P_RO(ParentInventoryHandle)
P_RO(Slot)
P(Amount)
P(Vitality)
P(Armor)
P_RO(InUseByCharacterHandle)
P(UserId)
P(Key)
P(LockLevel)
P_REF(StatusMachine)
P_RO(VisualResourceID)
P_RO(OwnerHandle)
P_RO(OriginalOwnerCharacter)
// FIXME - Sockets?
P(ComputedVitality)
P(Rarity)
P(GoldValueOverwrite)
P(WeightValueOverwrite)
P_REF(Tags)
P_RO(TeleportTargetOverride)
P(TreasureLevel)
P_RO(LevelOverride)
P_RO(ForceSynch)
P_RO(TeleportUseCount)
P_RO(PreviousLevel)

// v55 compatibility
PN_REF(RootTemplate, CurrentTemplate)

P_FUN(GetInventoryItems, GetInventoryItemGuids)
P_FUN(GetNearbyCharacters, GetNearbyCharacters)
P_FUN(GetDeltaMods, GetDeltaMods)
P_FUN(SetDeltaMods, LuaSetDeltaMods)
P_FUN(GetGeneratedBoosts, GetGeneratedBoosts)
P_FUN(SetGeneratedBoosts, LuaSetGeneratedBoosts)

P_FALLBACK(&esv::Item::LuaFallbackGet, &esv::Item::LuaFallbackSet)
END_CLS()


BEGIN_CLS(ecl::Item)
INHERIT(IEoCClientObject)
P_RO(WorldPos)
P_RO(CurrentLevel)
// Available via IGameObject
// P_RO(Scale)
P_REF(CurrentTemplate)
P_REF(Stats)
P_RO(StatsId)
P_REF(StatsFromName)
P_RO(Weight)
P_RO(KeyName)
P_RO(Level)
P_RO(ItemType)
P_RO(GoldValueOverride)
P_RO(BaseWeightOverwrite)
P_RO(ItemColorOverride)

// v55 compatibility
PN_REF(RootTemplate, CurrentTemplate)

P_FUN(GetInventoryItems, GetInventoryItemGuids)
P_FUN(GetOwnerCharacter, GetOwnerCharacter)
P_FUN(GetDeltaMods, GetDeltaMods)
END_CLS()
