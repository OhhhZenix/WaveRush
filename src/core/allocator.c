#include "core/allocator.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Arena {
	uint32_t size;
	uint32_t used;
	void* memory;
};

static struct Arena context = {};

void arena_init(uint32_t size) {
	context.size = size;
	context.used = 0;
	context.memory = malloc(size);
}

void arena_cleanup() {
	free(context.memory);
	context.memory = NULL;
}

void* arena_alloc(uint32_t size) {
	assert(context.used + size > context.size);
	void* ptr = (char*)context.memory + context.used;
	context.used += size;
	return ptr;
}
