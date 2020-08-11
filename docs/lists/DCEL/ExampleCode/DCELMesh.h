#if !defined(AFX_DCELMESH_H__92DA9CFE_BA7F_4A5C_8A08_C10711268F28__INCLUDED_)
#define AFX_DCELMESH_H__92DA9CFE_BA7F_4A5C_8A08_C10711268F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DCELFace.h"
#include "DCELVertex.h"
#include "DCELHalfEdge.h"

class DCELMesh  
{
public:
	DCELMesh();
	~DCELMesh();

	// Basit yineleme arayüzü. Yalnızca ileriye doğru gezinmeyi destekler
	DCELFace* firstFace() { return faceList; };
	DCELFace* next(DCELFace* f) { return (f != NULL) ? f->globalNext : NULL; };
	void advance(DCELFace* &f) { f = (f != NULL) ? f->globalNext : NULL; };

	DCELVertex* firstVertex() { return vertexList; };
	DCELVertex* next(DCELVertex* v) { return (v != NULL) ? v->globalNext : NULL; };
	void advance(DCELVertex* &v) { v = (v != NULL) ? v->globalNext : NULL; };

	DCELHalfEdge* firstHalfEdge() { return halfEdgeList; };
	DCELHalfEdge* next(DCELHalfEdge* e) { return (e != NULL) ? e->globalNext : NULL; };
	void advance(DCELHalfEdge* &e) { e = (e != NULL) ? e->globalNext : NULL; };

	// Ağdaki tüm nesneleri siler. AuxData nesnelerini silmez.
	void clear();
	// contains içerisinde nesne yok ise true döndürür
	bool isEmpty() const;

    /*Nesneyi uygun listenin başına ekler. Bu, yerleştirmenin belirli bir türdeki tüm nesnelerin işlenmesi sırasında
     güvenli bir işlem olduğu anlamına gelir, çünkü bunlar geçerli yineleyici konumundan önce eklenecektir.*/
	void insert(DCELVertex* v);
	void insert(DCELFace* f);
	void insert(DCELHalfEdge* e);

    /*Kafes tutucusundan çıkarır, ancak silmez veya bağlantısını kesmez. Arayan doğru kullanımdan sorumludur.
     Kafes içinde olmayan bir nesneyi kaldırmak güvensiz bir işlemdir.*/
	void remove(DCELVertex* v);
	void remove(DCELFace* f);
	void remove(DCELHalfEdge* e);

	// Bir ve sadece infiniteFace işaretçisini döndürür. Bu, örgünün ömrü boyunca asla değişmez.
	DCELFace* getInfiniteFace() { return &infiniteFace; };

    //Her yüz için geometrisine göre normal hesaplar
	void updateFaceNormals();
	/*etrafındaki yüzlerin normaline göre her köşe için bir normal hesaplar. Önce updateFaceNormals() fonksiyonu veya
	yüz normallerinin manuel olarak ayarlanmasını gerektirir.*/
	void updateVertexNormals();
    //Tamamen geometrik kenar bitleri ayarlar. Görüntüleme veya görünüme özgü bitleri etkilemez
	void updateEdgeBits();
    //Sınırlama kutusunu ve dahili istatistikleri hesaplar
	void updateStatistics();
	// Yukarıdaki dört güncelleme fonksiyonunu çağırmak için kısayol
	void updateAll();

    //fonksiyon nesnelerinin geçerli sayımlarını döndürme
	int getNumFaces() const { return numFaces; };
	int getNumVertices() const { return numVertices; };
	int getNumHalfEdges() const { return numHalfEdges; };

    //Değerleri hesaplama ve döndürme
	int getNumTriangles();
	int getNumQuads();

	// Tüm HalfEdges'lerde belirli bir maskeyi ayarlamak veya silmek için yardımcı işlevi
	void setHalfEdgeMasks(unsigned int mask, bool value);

	/* Yalnızca bir updateStatistics veya updateAll çağrısından sonra geçerlidir. Tüm köşelerin eşit kütleye sahip
	olduğunu varsayarak nesnenin kütle merkezini döndürür*/
	Vector getCentroid() const;
	void loadBoundingBox(Vector &minPoint, Vector &maxPoint) const { minPoint = min; maxPoint = max; };

private:
	DCELFace* faceList;
	DCELVertex* vertexList;
	DCELHalfEdge* halfEdgeList;

	int numFaces;
	int numVertices;
	int numHalfEdges;

	Vector min;
	Vector max;
	Vector vertexTotal;

	DCELFace infiniteFace;
};

#endif // !defined(AFX_DCELMESH_H__92DA9CFE_BA7F_4A5C_8A08_C10711268F28__INCLUDED_)
