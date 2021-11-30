BEGIN_CLS(lua::EmptyEventParams)
END_CLS()

BEGIN_CLS(lua::ConsoleEventParams)
P_RO(Command)
END_CLS()

BEGIN_CLS(lua::NetMessageEventParams)
P_RO(Channel)
P_RO(Payload)
P_RO(UserID)
END_CLS()

BEGIN_CLS(lua::GetHitChanceEventParams)
P_REF(Attacker)
P_REF(Target)
P(HitChance)
END_CLS()

BEGIN_CLS(lua::GetSkillDamageEventParams)
P_REF(Skill)
P_REF(Attacker)
P(IsFromItem)
P(Stealthed)
P(AttackerPosition)
P(TargetPosition)
P(Level)
P(NoRandomization)
P_REF(DamageList)
P(DeathType)
END_CLS()

BEGIN_CLS(lua::GetSkillAPCostEventParams)
P_REF(Skill)
P_REF(Character)
P_REF(AiGrid)
P_RO(Position)
P_RO(Radius)
P(AP)
P(ElementalAffinity)
END_CLS()

BEGIN_CLS(esv::lua::GameStateChangeEventParams)
P_RO(FromState)
P_RO(ToState)
END_CLS()

BEGIN_CLS(esv::lua::StatusGetEnterChanceEventParams)
P_REF(Status)
P_RO(IsEnterCheck)
P(EnterChance)
END_CLS()

BEGIN_CLS(esv::lua::ComputeCharacterHitEventParams)
P_REF(Target)
P_REF(Attacker)
P_REF(Weapon)
P_REF(DamageList)
P(HitType)
P(NoHitRoll)
P(ForceReduceDurability)
P_REF(Hit)
P_REF(SkillProperties)
P(AlwaysBackstab)
P(HighGround)
P(CriticalRoll)
P(Handled)
END_CLS()

BEGIN_CLS(esv::lua::StatusHitEnterEventParams)
P_REF(Hit)
P_REF(Context)
END_CLS()

BEGIN_CLS(esv::lua::BeforeCharacterApplyDamageEventParams)
P_REF(Target)
P_REF(Attacker)
P_REF(Hit)
P(Cause)
P(ImpactDirection)
P_REF(Context)
P(Handled)
END_CLS()

BEGIN_CLS(esv::lua::TreasureItemGeneratedEventParams)
P_REF(Item)
P_REF(ResultingItem)
END_CLS()

BEGIN_CLS(esv::lua::BeforeCraftingExecuteCombinationEventParams)
P_REF(Character)
P(CraftingStation)
P(CombinationId)
P(Quantity)
P_REF(Items)
P(Processed)
END_CLS()

BEGIN_CLS(esv::lua::AfterCraftingExecuteCombinationEventParams)
P_REF(Character)
P(CraftingStation)
P(CombinationId)
P(Quantity)
P(Succeeded)
P_REF(Items)
END_CLS()

BEGIN_CLS(esv::lua::BeforeShootProjectileEventParams)
P_REF(Projectile)
END_CLS()

BEGIN_CLS(esv::lua::ShootProjectileEventParams)
P_REF(Projectile)
END_CLS()

BEGIN_CLS(esv::lua::ProjectileHitEventParams)
P_REF(Projectile)
P_REF(HitObject)
P(Position)
END_CLS()

BEGIN_CLS(esv::lua::ExecutePropertyDataOnGroundHitEventParams)
P(Position)
P_REF(Caster)
P_REF(DamageList)
END_CLS()

BEGIN_CLS(esv::lua::ExecutePropertyDataOnTargetEventParams)
P_REF(Property)
P_REF(Attacker)
P_REF(Target)
P(ImpactOrigin)
P(IsFromItem)
P_REF(Skill)
P_REF(Hit)
END_CLS()

BEGIN_CLS(esv::lua::ExecutePropertyDataOnPositionEventParams)
P_REF(Property)
P_REF(Attacker)
P(Position)
P(AreaRadius)
P(IsFromItem)
P_REF(Skill)
P_REF(Hit)
END_CLS()

BEGIN_CLS(ecl::lua::GameStateChangeEventParams)
P_RO(FromState)
P_RO(ToState)
END_CLS()

BEGIN_CLS(ecl::lua::UIObjectCreatedEventParams)
P_REF(UI)
END_CLS()

BEGIN_CLS(ecl::lua::UICallEventParams)
P_REF(UI)
P_RO(Function)
P_RO(When)
P_REF(Args)
END_CLS()

BEGIN_CLS(ecl::lua::SkillGetDescriptionEventParams)
P_REF(Skill)
P_REF(Character)
P_REF(Params)
P(IsFromItem)
P(Description)
END_CLS()

BEGIN_CLS(ecl::lua::StatusGetDescriptionEventParams)
P_REF(Status)
P_REF(Owner)
P_REF(StatusSource)
P_REF(Params)
P(Description)
END_CLS()

BEGIN_CLS(ecl::lua::SkillGetPropertyDescriptionEventParams)
P_REF(Property)
P(Description)
END_CLS()

BEGIN_CLS(InputEvent)
P_RO(EventId)
P_RO(InputPlayerIndex)
P_RO(InputDeviceId)
P_BITMASK(Type)
P_RO(WasPreferred)
END_CLS()

BEGIN_CLS(ecl::lua::InputEventParams)
P_REF(Event)
END_CLS()
