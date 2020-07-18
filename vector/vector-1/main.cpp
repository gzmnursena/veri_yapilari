#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> sayilar(10,5);//10 elemanlı vektor boyutu ve her eleman için 5 değeri atar
    for(int i= 0; i<sayilar.size(); i++)//sayilar vektorunun boyutu kadar(10) döngü döner
    {
        cout << sayilar[i]<<"  ";//vektoru yazdırır
    }

    cout<<endl;
    vector <int> sayilar2(10);//10 elemanlı vektor
    for(int i=10; i>=1; i--)
    {
        vector<int>::iterator it = sayilar2.begin() + 1;  //başlangıçtan itibaren bir ileri
        sayilar2.insert(it,i);  //vektore i'yi ekler
    }

    cout<<"sayilar2.size()= "<<sayilar2.size()<<endl;
    for(int i=0; i<sayilar2.size(); i++)
    {
        cout<< sayilar2[i]<<"  ";//vektoru yazdırır
    }

    cout<<endl;
    vector<int> sayilar3;//Başlangıçta boyutu belli olmayan dinamik vektor.

    for(int i=0; i<10; i++)
        sayilar3.push_back(i);//vektorun sonuna push_back() fonksiyonu ile 0-10 arası sayıları ekler


    for(int i=0; i<sayilar3.size(); i++)
        cout<<sayilar3[i]<<"  ";//vektorun yazdırır

    return 0;
}