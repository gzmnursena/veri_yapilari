// DCELTools.h: interface for the DCELTools class.
//

#if !defined(AFX_DCELTOOLS_H__70D80E10_60CB_4206_9FC0_8F32881E97ED__INCLUDED_)
#define AFX_DCELTOOLS_H__70D80E10_60CB_4206_9FC0_8F32881E97ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DCELMesh.h"


class DCELTools  
{
private:
	DCELTools();
	~DCELTools();

public:
	static bool isConsistent(DCELHalfEdge* e);
	static bool isConsistent(DCELFace* f);
	static bool isConsistent(DCELVertex* v);
	static bool isConsistent(DCELMesh* m);

	static bool loadFromOFF(LPCTSTR filename, DCELMesh* m);
	static bool storeToOFF(LPCTSTR filename, DCELMesh* m);
};

#endif // !defined(AFX_DCELTOOLS_H__70D80E10_60CB_4206_9FC0_8F32881E97ED__INCLUDED_)
