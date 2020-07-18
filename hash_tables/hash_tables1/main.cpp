#include<iostream>
#include<string>

using namespace std;

const int T_S = 200;//T_S: tablo boyutunu bildirir

class HashTableEntry {//Anahtar ve değer bildirmek için hashTableEntry sınıfı oluşturulur
public:
    int anahtar;
    int deger;
    HashTableEntry(int anahtar, int deger) { //constructor
        this->anahtar= anahtar;
        this->deger = deger;
    }
};

class HashMapTable {
private:
    HashTableEntry **hash;
public:
    HashMapTable() { //Tablo oluşturmak için hashMapTable yapıcısı oluşturulur
        hash = new HashTableEntry * [T_S];
        for (int i = 0; i< T_S; i++) {
            hash[i] = NULL;
        }
    }
    int hashFunc(int anahtar) {//T_S dönüş tipinde bir hashFunc() fonksiyonu oluşturulur
        return anahtar % T_S;
    }
    void insert(int anahtar, int deger) {//Bir anahtara değer eklemek için insert() fonksiyonu oluşturulur
        int h = hashFunc(anahtar);
        while (hash[h] != NULL && hash[h]->anahtar != anahtar) {
            h = hashFunc(h + 1);
        }
        if (hash[h] != NULL)
            delete hash[h];
        hash[h] = new HashTableEntry(anahtar, deger);
    }

    int searchKey(int anahtar) {// Bir anahtardaki değeri aramak için bir searchKey() fonksiyonu oluşturulur
        int h = hashFunc(anahtar);
        while (hash[h] != NULL && hash[h]->anahtar != anahtar) {
            h = hashFunc(h + 1);
        }
        if (hash[h] == NULL)
            return -1;
        else
            return hash[h]->deger;
    }
    void remove(int anahtar) {// Bir anahtardaki değeri silmek için remove() fonksiyonu oluşturulur
        int h = hashFunc(anahtar);
        while (hash[h] != NULL) {
            if (hash[h]->anahtar == anahtar)
                break;
            h = hashFunc(h + 1);
        }
        if (hash[h] == NULL) {
            cout<<"Değer Bulunamadı"<<anahtar<<endl;
            return;
        } else {
            delete hash[h];
        }
        cout<<"Değer Silindi"<<endl;
    }
    ~HashMapTable() {//Yapıcı tarafından oluşturulan nesneleri yok etmek için bir yıkıcı (~HashMapTable) çağırılır
        for (int i = 0; i < T_S; i++) {
            if (hash[i] != NULL)
                delete hash[i];
            delete[] hash;
        }
    }
};

int main() {
    HashMapTable hash;
    int deger,anahtar;
    int tercih;
    while (1) {
        cout<<"1.Tabloya Değer Ekle\n2.Tabloda Değer Ara\n3.Tablodan Değer Sil\n4.Çıkış\nTercih= ";
        cin>>tercih;
        switch(tercih) {
            case 1:
                cout<<"Eklenecek değeri girin: ";
                cin>>deger;
                cout<<"Eklenecek değerin anahtarını girin:";
                cin>>anahtar;
                hash.insert(anahtar, deger);//Anahtar ve değerler eklemek için insert() fonksiyonu çağırılır
                break;
            case 2:
                cout<<"Aranacak değerin anahtarını girin: ";
                cin>>anahtar;
                if (hash.searchKey(anahtar) == -1) {//aranan değer hash tablosunda yoksa
                    cout<<" "<<anahtar<<endl;
                    continue;
                } else {
                    cout<<"Anahtardaki değer: "<<anahtar<<" : ";
                    cout<<hash.searchKey(anahtar)<<endl;// Değeri aramak için searchKey() fonksiyonu çağırılır
                }
                break;
            case 3:
                cout<<"Silinecek değerin anahtarını girin: ";
                cin>>anahtar;
                hash.remove(anahtar);// anahtarı kaldırmak için remove() fonksiyonu çağırılır
                break;
            case 4:
                exit(1);
            default:
                cout<<"\nDoğru seçeneği girin!!\n";
        }
    }
    return 0;
}