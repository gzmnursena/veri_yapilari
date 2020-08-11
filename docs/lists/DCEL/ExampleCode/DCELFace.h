// DCELFace.h: interface for the DCELFace class.


#if !defined(AFX_DCELFACE_H__A82CC426_6585_4204_BFC4_EAC734D283A5__INCLUDED_)
#define AFX_DCELFACE_H__A82CC426_6585_4204_BFC4_EAC734D283A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Vector.h"
#include "DCELHalfEdge.h"


class DCELFace  
{
public:
	DCELFace();
	~DCELFace();

	Vector normal;
	DCELHalfEdge* edge;
	void* auxData;

	void updateNormal();
	void updateVertexNormals() const;
	int getEdgeCount() const;

	friend class DCELMesh;
protected:
	DCELFace* globalPrev;
	DCELFace* globalNext;
};

#endif // !defined(AFX_DCELFACE_H__A82CC426_6585_4204_BFC4_EAC734D283A5__INCLUDED_)
