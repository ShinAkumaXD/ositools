#pragma once

#include "BaseTypes.h"
#include "Enumerations.h"
#include "Net.h"

namespace dse
{

#pragma pack(push, 1)
	namespace eocnet
	{
		struct DummyMessage : public net::Message
		{
			inline ~DummyMessage() override {}
			inline void Serialize(net::BitstreamSerializer & serializer) override {}
			inline void Unknown() override {}
			inline Message * CreateNew() override { return this; }
			inline void Reset() override {}
		};

		struct CustomStatDefinitionSyncInfo
		{
			NetId NetId{ NetIdUnassigned };
			uint8_t _Pad1[4];
			uint64_t Unknown1{ 0 };
			FixedString Id;
			STDWString Name;
			STDWString Description;
		};

		struct CustomStatsDefinitionSyncMessage : public DummyMessage
		{
			ObjectSet<CustomStatDefinitionSyncInfo> StatDefns;
		};

		struct CustomStatsDefinitionRemoveMessage : public DummyMessage
		{
			void * PrimSetVMT;
			ObjectSet<uint32_t> StatDefns; // NetID list
			uint64_t Unkn{ 0 };
		};

		struct CustomStatsSyncInfo
		{
			NetId NetId{ NetIdUnassigned };
			uint8_t _Pad1[4];
			FixedStringMapBase<int> Stats;
			uint8_t _Pad2[4];
		};

		struct CustomStatsSyncMessage : public DummyMessage
		{
			ObjectSet<CustomStatsSyncInfo> Stats;
		};
	}

	namespace eoc
	{
		struct CustomStatsComponent : public BaseComponent
		{
			FixedStringMapBase<int> StatValues;
		};

		struct CustomStatDefinitionComponent : public ProtectedGameObject<CustomStatDefinitionComponent>
		{
			void * VMT;
			FixedString Id;
			STDWString Name;
			STDWString Description;
		};
	}

	namespace esv
	{
		struct NetComponent : public ProtectedGameObject<NetComponent>
		{
			BaseComponent Base;
			FixedString FixedStr1;
			NetId NetID;
			uint8_t _Pad[4];
		};

		struct CustomStatDefinitionComponent : public eoc::CustomStatDefinitionComponent
		{
			BaseComponent Base;
			FixedString someStr;
			NetId NetID;
			uint8_t _Pad[4];
			uint64_t Unkn1;
		};

		struct CustomStatSystem : public ProtectedGameObject<CustomStatSystem>
		{
			void * GameEventListenerVMT;
			void * Unkn1;
			void * NetEventListenerVMT;
			void * BaseComponentVMT;
			EntityWorld * EntityWorld;
			ObjectSet<ComponentHandle> CreatedDefinitions;
			ObjectSet<ComponentHandle> InSyncDefinitions;
			ObjectSet<ComponentHandle> RemovedDefinitions;
			ObjectSet<ComponentHandle> UpdatedDefinitions;
			ObjectSet<ComponentHandle> CustomStatComponents;
			PrimitiveSet<short> PeerIDClassnames;
			uint64_t Unkn2;
			uint64_t Unkn3;
		};

		typedef int(*CustomStatsProtocol__ProcessMsg)(void * self, void * unkn, void * unkn2, net::Message * msg);
	}
#pragma pack(pop)
}