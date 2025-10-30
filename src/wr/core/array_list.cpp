#include "wr/core/array_list.h"

#include <stdlib.h>
#include <string.h>

void wr_array_list_init(wr_array_list* self, int size, int count) {
    if (self == NULL) {
        return;
    }

    self->size = size;
    self->length = 0;
    self->items = malloc(size * count);
    memset(self->items, 0, size * count);
}

void wr_array_list_cleanup(wr_array_list* self) {
    if (self == NULL) {
        return;
    }

    free(self->items);
    self->items = NULL;
    self->length = 0;
    self->size = 0;
}

int wr_array_list_add(wr_array_list* self, void* item) {
    if (self == NULL) {
        return -1;
    }

    void* current = (char*)self->items + (self->length * self->size);
    memcpy(current, item, self->size);
    return self->length++;
}

void* wr_array_list_get(wr_array_list* self, int index) {
    if (self == NULL) {
        return NULL;
    }

    if (index < 0 || index >= self->length) {
        return NULL;
    }

    return (char*)self->items + (index * self->size);
}