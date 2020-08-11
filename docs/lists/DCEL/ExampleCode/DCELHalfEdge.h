// DCELHalfEdge.h: interface for the DCELHalfEdge class.

#if !defined(AFX_DCELHALFEDGE_H__A8186B0F_19D5_48EF_BD30_EB266F9A8215__INCLUDED_)
#define AFX_DCELHALFEDGE_H__A8186B0F_19D5_48EF_BD30_EB266F9A8215__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class DCELFace;
class DCELVertex;

class DCELHalfEdge  
{
public:
	DCELHalfEdge();
	~DCELHalfEdge();

	enum DCEL_EDGE_BITS {
		// Herhangi bir işleme döngüsü sırasında yarım kenarın işlendiğini göstermek için ayarlayın. (örn. tüm yarım kenarlardan geçerken ve
        //kenarları yeniden oluşturma, bir kenarın yeniden oluşturulmasını önlemek için ikiz üzerine ayarlanır) Bu uçucudur ... yani, bir işlevin başında ayarlandığı veya ayarlanmayacağı varsayılmamalıdır ve bir
        //bir fonksiyonun sonunda anlamlı durum
		DCEL_EDGE_PROCESSED_BIT	= 1,
		// yarım kenarın veya ikizinin sonsuz yüze baktığını belirtmek için ayarlayın
		DCEL_EDGE_BOUNDARY_BIT = 2,
        // yarım kenarın seçildiğini belirtmek için ayarlayın.
		DCEL_EDGE_SELECTED_BIT = 4,
        // yarım kenarın işaretlendiğini belirtmek için ayarlayın.
		DCEL_EDGE_MARKED_BIT = 8,
        // yarım kenar ve ikizinin bir siluet kenar içerdiğini belirtmek için ayarlanmıştır.
		DCEL_EDGE_SILHOUETTE_BIT = 16
	};

	DCELHalfEdge* twin;
	DCELHalfEdge* next;
	DCELFace* face;
	DCELVertex* origin;
	void* auxData;
	// İşlemler sırasında bazı durumları depolamak için isteğe bağlı üye. Tam mesh üzerinde kullanıcı tarafından başlatılan
	çağrılar dışında dahili olarak muhafaza edilmez.*/
	unsigned int displayBits;

	DCELHalfEdge* getPrev();
    //DisplayBits özelliğini değiştirmek için yardımcı fonksiyonlar
	bool isMaskSet(unsigned int mask) const { return ((displayBits & mask) == mask); };
	void setMask(unsigned int mask, bool value) { displayBits = (value ? (displayBits | mask) : (displayBits & ~mask)); };

	friend class DCELMesh;
protected:
	DCELHalfEdge* globalNext;
	DCELHalfEdge* globalPrev;
};

#endif // !defined(AFX_DCELHALFEDGE_H__A8186B0F_19D5_48EF_BD30_EB266F9A8215__INCLUDED_)
