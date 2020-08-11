// DCELVertex.h: interface for the DCELVertex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCELVERTEX_H__8642D25D_42CE_4863_9FBD_5CF0825670E2__INCLUDED_)
#define AFX_DCELVERTEX_H__8642D25D_42CE_4863_9FBD_5CF0825670E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Vector.h"
#include "DCELHalfEdge.h"


class DCELVertex  
{
public:
	DCELVertex();
	~DCELVertex();

	Vector coords;
	Vector normal;
	DCELHalfEdge* leaving;

	void* auxData;

	DCELHalfEdge* getEdgeTo(const DCELVertex* v) const;

	friend class DCELMesh;
protected:
	DCELVertex* globalNext;
	DCELVertex* globalPrev;
};

#endif // !defined(AFX_DCELVERTEX_H__8642D25D_42CE_4863_9FBD_5CF0825670E2__INCLUDED_)
