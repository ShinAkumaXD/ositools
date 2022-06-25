BEGIN_CLS(esv::AiHelpersModifiers)
P_REF(Modifiers)
END_CLS()


BEGIN_CLS(esv::AiModifiers)
P_REF(BaseModifiers)
P_REF(Archetypes)
P_REF(ArchetypeNames)
END_CLS()


BEGIN_CLS(esv::AiScoreImpl)
P(Reason)
P(Flags1)
P_RO(field_4)
P_REF(DamageAmounts)
P(FutureScore)
P(FailScore)
P(SoftReasonFlags2)
END_CLS()


BEGIN_CLS(esv::AiScoreImpl::DamageAmount)
P(DamageAmount)
P(HealAmount)
P(DoTAmount)
P(HoTAmount)
P(ControlAmount)
P(BoostAmount)
P(ArmorDamage)
P(MagicArmorDamage)
P(PositionScore)
END_CLS()


BEGIN_CLS(esv::AiScore)
P_REF(Score)
END_CLS()


BEGIN_CLS(esv::AiAction)
P(ActionType)
P(SkillId)
P(SkillItemHandle)
P_REF(AIParams)
P(MovementSkillId)
P_REF(MovementSkillItem)
P_RO(IsFinished)
P(SavingActionPoints)
P(IgnoreMovementScore)
P(TargetHandle)
P(TargetPosition2)
P(Target2Handle)
P(LookAtPosition)
P(MovementSkillTargetPosition)
P(EndPosition)
P(EndPosition2)
P(CloseEnough)
P(CloseEnough2)
P(MovementType)
P(field_94)
P_RO(AiHandle)
P(FinalScore)
P_REF(Score1)
P_REF(ScoreWithoutMovement)
P(TauntedSourceHandle)
P(ActionFinalScore)
P(PositionFinalScore)
P(MovementFinalScore)
P(APCost)
P(APCost2)
P(MagicCost)
P(field_D8)
P(IsPositionCalculated)
P(field_DA)
P(UseMovementSkill)
P(Distance)
P(FreeActionMultiplier)
P(CostModifier)
END_CLS()


BEGIN_CLS(esv::AiSkillData)
P(SkillId)
P(ItemHandle)
P_REF(AIParams)
END_CLS()


BEGIN_CLS(esv::AiItemData)
P(ItemHandle)
P_REF(AIParams)
END_CLS()


BEGIN_CLS(esv::AiRequest)
P_RO(IsCalculating)
P_REF(AiActions)
P(AiActionToExecute)
P_RO(ActionCount)
P_RO(LastStep)
P_RO(CalculationFinished)
P(CanMove)
P_RO(UseBehaviorVariables)
P_RO(HasAiOnPositionSkillData)
P_RO(CurrentAiSkillIndex)
P_RO(CurrentAiItemIndex)
P_RO(CurrentAiActionIndex)
P_RO(CurrentAiSkill2Index)
P(HighestActionScore)
P_REF(Skills)
P_REF(OnPositionSkills)
P_REF(Items)
P_REF(UnknownHandles)
END_CLS()


BEGIN_CLS(esv::AiCombos)
P_REF(Combos)
P_REF(SurfaceComboIndices)
P_REF(DamageTypes)
P_REF(SkillPrototypes)
END_CLS()


BEGIN_CLS(esv::AiCombos::Combo)
P(SurfaceType1)
P(SurfaceType2)
P(TransformType)
P(field_C)
END_CLS()


BEGIN_CLS(esv::AiKnownStateSet)
P_REF(StatusInteractions)
P_REF(SurfaceOnObjectActions)
P_REF(SurfaceInteractions)
END_CLS()


BEGIN_CLS(esv::AiKnownStateSet::StatusInteraction)
P(TargetHandle)
P(StatusId)
P(HasLifeTime)
END_CLS()


BEGIN_CLS(esv::AiKnownStateSet::SurfaceOnObjectAction)
P(TargetHandle)
P(SurfaceTypeId)
P(HasLifeTime)
END_CLS()


BEGIN_CLS(esv::AiKnownStateSet::SurfaceInteraction)
P(SurfaceHandle)
P(SurfaceTransform)
P_REF(SurfaceTypeByLayer)
P(field_14)
END_CLS()


BEGIN_CLS(esv::AiKnownStateImpl)
P_REF(States)
P_REF(States2)
END_CLS()


BEGIN_CLS(esv::AiKnownState)
P_REF(State)
END_CLS()


BEGIN_CLS(esv::AiTranslateOverride)
P(OriginalTranslate)
P(NewTranslate)
END_CLS()


BEGIN_CLS(esv::AiHelpers)
P_REF(CharacterAiRequests)
P_REF(PendingCharacters)
P_REF(PreparingCharacter)
P_REF(PreparingAiGrid)
P_REF(PreparingLevel)
P_REF(Modifiers)
P_REF(AiFlagsStack)
P(Flags)
P_REF(Combos)
P_REF(CurrentItem)
P_REF(KnownStateStack)
P_REF(KnownState)
P_REF(OS_FixedString)
P_REF(Surfaces)
P_REF(EnemyCharacters)
P_REF(AllyCharacters2)
P_REF(NeutralCharacters)
P_REF(SameCombatCharacters)
P_REF(SameCombatEnemyCharacters)
P_REF(AllyCharacters)
P_REF(SameCombatNeutralCharacters)
P_REF(Items)
P_REF(CurrentAiRequestObjects)
P(LowestCharacterHP)
P(HighestCharacterHP)
P(OverrideTranslate)
P_REF(AiTranslateOverrides)
END_CLS()