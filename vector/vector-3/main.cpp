#include <iostream>
#include <vector>
using namespace std;

void yazdir(vector<int>sayilar)
{
    for(int i=0; i<sayilar.size(); i++)//dongu vektorun boyutuna kadar dönerek vektorun elemanlarını yazdırır
    {
        cout << sayilar[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    vector<int> sayilar(10,0);//boyutu 10 olan ve elemanları 0 olan vektor

    vector<int>::iterator it = sayilar.begin() + 2;//2. index konum olarak belirtilir
    sayilar.insert(it,66); //belirtilen konuma eleman ekler
    yazdir(sayilar);


    it = sayilar.begin() + 2;
    sayilar.erase(it);//vektör içerisinden eleman çıkartır
    yazdir(sayilar);

    //fill_n() fonksiyonu kullanımı...

    fill_n(sayilar.begin(),4,8);//dizi başından itibaren 4 adet 8 değerini ekler
    yazdir(sayilar);

    fill_n(sayilar.begin() + 3,2,7);//dizinin ilk 3 elemanından sonra 2 adet 7 değerini ekler
    yazdir(sayilar);

    return 0;
}