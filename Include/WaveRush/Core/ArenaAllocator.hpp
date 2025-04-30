#pragma once

#include "WaveRush/Core/Types.hpp"

struct ArenaAllocator {
	void* memory;
	usize size;
	usize offset;
};

ArenaAllocator ArenaAllocatorNew(usize size);
void ArenaAllocatorDelete(ArenaAllocator* allocator);
void* ArenaAllocatorAllocate(ArenaAllocator* allocator, usize size);