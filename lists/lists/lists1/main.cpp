#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<int> sayilar;
    sayilar.push_front(1); //Listenin başına 1 ekler. Eleman yoksa ilk elemanı oluşturur.
    //push_front(): Basa eleman ekleme.
    //push_back(): Sona eleman ekleme.
    sayilar.push_front(2); //Başa 2 ekler.
    sayilar.push_back(3); //Sona 3 ekler.
    sayilar.push_back(4); //Sona 4 ekler.
    cout<<"sayilar1: ";
    for(auto& item: sayilar) cout << item << ' ';//foreach döngüsü ile listeyi yazdırır
    cout<<endl;

    list<int> sayilar2{0, 1, 2, 3, 4, 5, 6, 7};//liste oluşturulurken elemanları tanımlanabilir
    cout<<"sayilar2: ";
    if(sayilar2.empty()==1)  cout<<"liste boş"; // liste boş ise
    else {
        for(auto& item: sayilar2) cout << item << ' ';//foreach döngüsü ile listeyi yazdırır
        cout<<endl;
    }

    //iterator: adres döndürür
    list<int> ::iterator x=sayilar2.begin();//ilk elemanın adresini döndürür
    advance(x,3); //baştan 2. elemanı verir
    list<int> ::iterator y=sayilar2.end();//son elemanın adresini döndürür
    advance(y,2); //sondan 5. elemanı verir


    list<string> metin{"Merhaba", "Dünya"};//string liste
    for(auto& item: metin) cout << item << ' ';
    cout<<endl;

    list<string> metin2(metin);  //metin'i metin2'ye atar.
    for(auto& item: metin2) cout << item << ' ';
    cout<<endl;

    list<string> metin3(metin.begin(), metin.end()); // metinin başlangıcından sonuna metin3'e atar.
    for(auto& item: metin3) cout << item << ' ';
    cout<<endl;

    list<string> metin4(5, "A"); //5 tane A ekler
    for(auto& item: metin4) cout << item << ' ';
    cout<<endl;
    metin4.erase(metin4.begin());//listenin ilk elemanını siler
    //begin(): ilk elemanı dondurur
    //erase(): parametre verilen elemanı siler
    for(auto& item: metin4) cout << item << ' ';
    cout<<endl;

    list<int> liste1 = { 1,2,3,4,5 };
    list<int> liste2 = { 6,7,8,9 };

    liste1.sort();//sort():k->b sıralar

    liste2.sort();
    cout<<"liste1: ";
    for(auto& item: liste1) cout << item << ' ';
    cout<<endl;
    cout<<"liste2: ";
    for(auto& item: liste2) cout << item << ' ';
    cout<<endl;

    cout<<"sıralı liste: ";
    liste1.merge(liste2); //merge(): listeleri birleştir
    for(auto& item: liste1) cout << item << ' ';
    cout<<endl;

    liste2.merge(liste1);
    for(auto& item: liste2) cout << item << ' ';
    cout<<endl;
    //  liste1.merge(liste2); ile liste2.merge(liste1); aynı sonucu verirler


    list<char> karakter;
    karakter.assign(5, 'x');  //listeye 5 tane char degeri atar.
    //assing(): atama yapar.
    for (char item : karakter) cout << item << ' ';
    cout<<endl;

    return 0;
}