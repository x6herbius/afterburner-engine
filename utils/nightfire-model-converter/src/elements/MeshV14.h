#pragma once

#include <cstdint>
#include "ElementTraits.h"

namespace NFMDL
{
#pragma pack(push, 1)
	struct MeshV14
	{
		int8_t boneMappings[24];
		uint16_t trianglesIndex;
		uint16_t trianglesCount;
		uint16_t verticesIndexFrom;
		uint16_t verticesIndexTo;
	};
#pragma pack(pop)

	template<>
	struct ElementTraits<MeshV14>
	{
		static constexpr const char* ELEMENT_NAME = "MeshV14";
	};
}