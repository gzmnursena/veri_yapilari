#pragma once

#include "DCELHalfEdge.h"


class HalfEdgeList
{
public:
	HalfEdgeList(void);
	~HalfEdgeList(void);

	DCELHalfEdge* edge;
	HalfEdgeList* next;

	static void addToList(HalfEdgeList* &head, DCELHalfEdge* newEdge);
	static void addToList(HalfEdgeList* &head, HalfEdgeList* newItem);
	static void deleteList(HalfEdgeList* &head);
	static int getListLength(HalfEdgeList* head);
	static bool removeFromList(HalfEdgeList* &head, DCELHalfEdge* edge);

};
