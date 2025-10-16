#pragma once

typedef struct array_list ArrayList;

struct array_list {
  int size;
  int length;
  void *items;
};

void wr_array_list_init(ArrayList *self, int size, int count);
void wr_array_list_cleanup(ArrayList *self);
int wr_array_list_add(ArrayList *self, void *item);
void *wr_array_list_get(ArrayList *self, int index);