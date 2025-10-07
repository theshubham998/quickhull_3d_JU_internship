#ifndef FACELIST_H_INCLUDED
#define FACELIST_H_INCLUDED

/**
 * @file facelist.h
 * @brief Single-list of face
 */

#include "facet.h"
class FaceList{

private:
    Facet *head;
    Facet *tail;

public:
    FaceList();
    void clear();
    void add(Facet *vtx);
    Facet *first();
    bool isEmpty();

};


#endif // FACELIST_H_INCLUDED
