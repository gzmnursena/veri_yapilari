// Vector.h: interface for the Vector class.


#if !defined(AFX_VECTOR_H__0AFDDCFD_6A7A_4943_8068_CBA5CEC834C5__INCLUDED_)
#define AFX_VECTOR_H__0AFDDCFD_6A7A_4943_8068_CBA5CEC834C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include <math.h>

#ifndef M_PI
	#define M_PI 3.141592653589793
#endif
#ifndef DEG_TO_RAD
	#define DEG_TO_RAD 0.017453292519943
#endif

#define VECTOR_X 0
#define VECTOR_Y 1
#define VECTOR_Z 2

class Vector  
{
public:
	Vector();
	Vector(double x, double y, double z);
	Vector(double[]);
	Vector(float[]);
	Vector(int[]);
#ifdef DIRECT3D_VERSION
	Vector(D3DXVECTOR3 d3dV);
#endif
	virtual ~Vector();

	double x;
	double y;
	double z;


	//Direct3D vektörlerini desteklemek için operatör

#ifdef DIRECT3D_VERSION
	operator D3DXVECTOR3() const;
#endif

//Vektör toplama için operatörler. Bunların yeni bir Vector oluşturduğunu unutmayın.

	Vector operator+(const Vector& rhs) const;
	Vector operator-(const Vector& rhs) const;

	// Skaler çarpım için operatörler. Bunların yeni bir Vector oluşturduğunu unutmayın

	Vector operator*(const double factor) const;
	Vector operator/(const double factor) const;

	/*
    Dizi operatörü, sırasıyla VECTOR_X, VECTOR_Y ve VECTOR_Z endeksleri aracılığıyla (0, 1 ve 2) x, y ve z üyelerine
	 erişime izin verir. Sadece bu üç değer kullanılmalıdır. Başka bir dizin kullanılırsa, Z değeri döndürülür.
	*/
	double operator[](const int index) const;

	/* Dizi operatörü, sırasıyla VECTOR_X, VECTOR_Y ve VECTOR_Z endeksleri aracılığıyla (0, 1 ve 2) x, y ve z üyelerine
	 erişime izin verir. Sadece bu üç değer kullanılmalıdır. Başka bir dizin kullanılırsa, Z değeri döndürülür.
	*/
	double& operator[](const int index);

	/* Vektör ekleme işlemi. Bu işlem orijinal Vector öğesini değiştirir. İşlemden sonra orijinale gerek duyulmazsa,
	 bu yeni bir Vector nesnesi oluşturmaktan daha hızlıdır.
	*/
    void translateBy(const Vector& rhs);

	/* Skaler çarpma işlemi. Bu işlem orijinal Vector öğesini değiştirir. İşlemden sonra orijinale gerek duyulmazsa,
	 bu yeni bir Vector nesnesi oluşturmaktan daha hızlıdır.
	*/
	void scaleBy(const double factor);


    //Vektör sıfır vektör değilse vektörü normalleştirir. Sıfır vektörüyse, değişmez

	void normalize();


    /*Vektör sıfır vektör değilse vektörü normalleştirir. Sıfır vektörüyse, değişmez. Vektörün kendisini döndürür,
    böylece başka ifadelerde kullanılabilir.*/

	Vector& normalized();

//Vektör sıfır vektör değilse vektörü normalleştirir. Sıfır vektörüyse, değişmez. Vektörün normalleştirmeden önceki uzunluğunu döndürür.

	double normalizeAndReturn();

	// Vektörleri sıfırlar.

	void zero();

	// Vektörün uzunluğunu döndürme

	double getLength() const;
	//Vektörün kare uzunluğunu döndür. Biraz daha hızlı ve yalnızca göreli uzunlukları karşılaştırmamız gerekebilir.

	double getSquaredLength() const;

	//Bu vektörün nokta ürününü belirtilen sağ taraf vektörüyle döndürün.

	double Dot(const Vector& rhs) const;

	//Bu vektörün çapraz ürününü belirtilen sağ taraf vektörüyle döndürün.

	Vector Cross(const Vector& rhs) const;

    //Bu vektörü belirtilen çift diziye koyun. Dizi en az 3 eleman uzunluğunda olmalıdır
	void toArray(double array[]) const;

	/*Bu vektörü belirtilen kayan diziye koyun. Dizi en az 3 eleman uzunluğunda olmalıdır. Her bileşen bir şamandıraya
	 dökülür, bu nedenle hassasiyet kaybı olasılığı vardır.
	*/
	void toArray(float array[]) const;


	// bu vektörü belirtilen çift dizinin ilk üç elemanının içeriğine ayarlayın. Dizi en az 3 eleman uzunluğunda olmalıdır.
	void fromArray(double array[]);
	/
    //Bu vektörü, belirtilen kayan noktalı dizinin ilk üç öğesinin içeriğine ayarlayın. Dizi en az 3 eleman uzunluğunda olmalıdır

	void fromArray(float array[]);

    //Bu vektörü bir eksen etrafında döndürün. Dönüş derece cinsindendir.

	void rotateX(const double degrees);
	void rotateY(const double degrees);
	void rotateZ(const double degrees);

	/* Bu vektörü bir eksen etrafında döndürün. Dönüş radyan cinsinden belirtilir. Radyanları zaten biliyorsanız,
	 bu derece olarak belirtilen rotasyonlardan biraz daha hızlıdır.
	*/
	void radianRotateX(const double radians);
	void radianRotateY(const double radians);
	void radianRotateZ(const double radians);

	/* Bu vektörü rastgele bir eksen etrafında döndürün. Dönüş
 derece cinsinden belirtilir.
	*/
	void rotateAxis(const Vector& axis, const double degrees);

	/* Bu vektörü rastgele bir eksen etrafında döndürün. Döndürme belirtildi
radyan cinsinden. Radyanları zaten biliyorsanız, bu derece olarak belirtilen rotasyonlardan biraz daha hızlıdır.
	*/
	void radianRotateAxis(const Vector& axis, const double radians);

	// Bu vektör ve bir uç nokta arasında doğrusal olarak enterpolasyonlu bir vektör döndürün. t 0 ile 1 arasında değişmelidir.

	Vector interpolate1(const Vector& endPoint, const double t) const;

    //Üç kontrol noktaları bu vektör, midControl ve endControl ile ikinci bir Bezier enterpolasyonlu vektör döndürün. t 0 ile 1 arasında değişmelidir.

	Vector interpolate2(const Vector& midControl, const Vector& endControl, const double t) const;

	/* Dört kontrol noktası olan bu vektör, leftControl, rightControl ve endControl ile kübik bir Bezier enterpolasyonlu
	 vektör döndürün. t 0 ile 1 arasında değişmelidir.
	*/
	Vector interpolate3(const Vector& leftControl, const Vector& rightControl, const Vector& endControl, const double t) const;

};

#endif // !defined(AFX_VECTOR_H__0AFDDCFD_6A7A_4943_8068_CBA5CEC834C5__INCLUDED_)
