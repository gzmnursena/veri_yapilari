#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void yazdir(vector <int> vektor)
{
    if(vektor.size()!=0)
    {
        for(int i=0; i<vektor.size(); i++)//dongu vektorun boyutuna kadar dönerek vektorun elemanlarını yazdırır
        {
            cout<< vektor[i] << "  ";
        }
        cout<< endl;
    }

    else//boyut 0 ise vektorun hiç elemanı yoktur
    {
        cout<<"clear çalıştı"<< endl;
    }
}

int main()
{
//begin : vektorun ilk elemanı
//back : vektorun son elemanı

    vector <int> sayilar(10); //sayilar vektörü oluşturuldu

    for(int i=0; i<sayilar.size(); i++)
    {
        sayilar[i]=i;  //vektöre sayılar atandı
    }

    yazdir(sayilar);

    sayilar.push_back(40);  //vektorun sonuna sayılar eklendi
    sayilar.push_back(50);
    sayilar.push_back(60);
    yazdir(sayilar);

    sayilar.pop_back(); //vektörün son elemanını sildi
    yazdir(sayilar);

    sayilar.insert(sayilar.begin()+2,66);  //2. indeksi 66 olarak değiştirir.
    sayilar.insert(sayilar.begin()+3,74); //3. indeksi 74 olarak değiştirir.
    yazdir(sayilar);

    sayilar.erase(sayilar.begin()+2);  //verilen konumdaki elemanı siler. (2. indeksi)
    yazdir(sayilar);
    sayilar.erase(sayilar.begin()+2);
    yazdir(sayilar);

    cout<<"end: ";
    sayilar.end();  //vektörun tamamını ekrana yazdırır
    yazdir(sayilar);

    sort (sayilar.begin (), sayilar.end ());//vektoru küçükten->buyuge (azdan->çoğa) sıralar
    cout << "Siralanmis hali: ";
    copy (sayilar.begin (), sayilar.end (), ostream_iterator <int> (cout, " "));//vektoru yazdırır

    cout<<endl;
    vector <int> sayilar2(10,0);
    sayilar.swap(sayilar2);//iki vektoru yer değiştirir
    yazdir(sayilar2);

    sayilar.clear();  //vektoru siler
    yazdir(sayilar);

    return 0;
}