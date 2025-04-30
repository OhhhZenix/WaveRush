#include "WaveRush/Core/ArenaAllocator.hpp"

#include <cstdlib>

ArenaAllocator ArenaAllocatorNew(usize size) {
	ArenaAllocator allocator;
	allocator.memory = malloc(size);
	allocator.size = size;
	allocator.offset = 0;

	if (!allocator.memory) {
		// Handle memory allocation failure
		allocator.size = 0;
	}

	return allocator;
}

void ArenaAllocatorDelete(ArenaAllocator* allocator) {
	if (allocator->memory) {
		free(allocator->memory);
		allocator->memory = nullptr;
		allocator->size = 0;
		allocator->offset = 0;
	}
}

void* ArenaAllocatorAllocate(ArenaAllocator* allocator, usize size) {
	if (allocator->offset + size > allocator->size) {
		// Handle out of memory situation
		return nullptr;
	}

	void* ptr = static_cast<char*>(allocator->memory) + allocator->offset;
	allocator->offset += size;
	return ptr;
}