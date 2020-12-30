//
// Created by rhys on 29/12/2020.
//

#ifndef BUILDDIR_NETWORK_H
#define BUILDDIR_NETWORK_H

#include <gdk/gdk.h>

struct MemoryStruct {
    guint8 *memory;
    int size;
};

struct MemoryStruct get_url(const char* url);

#endif //BUILDDIR_NETWORK_H
