#pragma once

struct wr_array_list
{
  int size;
  int length;
  void *items;
};

void wr_array_list_init (wr_array_list *self, int size, int count);
void wr_array_list_cleanup (wr_array_list *self);
int wr_array_list_add (wr_array_list *self, void *item);
void *wr_array_list_get (wr_array_list *self, int index);