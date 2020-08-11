#include <iostream>
using namespace std;

#define STACK_SIZE 100//stack'e max eklenecek eleman sayısı

/*Bu örnekte max eleman sayısı 100 olabilecek bir dizi oluşturulup bu dizi üzerine stack işlemleri yaptırılmıştır.
Stack işlemlerinde kullanılan metotlar hazır kullanılmamıştır.*/

//Stack ilk giren son çıkar mantığı ile çalışır

class Stack {
public:
    int elemanSayisi;

public:
    int stackBoyutu[STACK_SIZE];//yığındaki elemanlar bu değişkende saklanır
    Stack() { elemanSayisi = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int eleman) //yığına eleman ekler
{
    if (elemanSayisi >= (STACK_SIZE - 1)) {//eleman sayısı STACK_SIZE'dan buyuk ise yığın tasması
        cout << "Yıgın tasması"<< endl;
        return false;
    }
    else {//yığına elemanı ekler ve elemanSayisini arttırır
        stackBoyutu[elemanSayisi] = eleman;
        elemanSayisi++;
        cout << eleman << " Yigina eleman eklendi"<< endl;
        return true;
    }
}

int Stack::pop() //yığından eleman çıkarır
{
    if (elemanSayisi < 0) {//yığındaki eleman sayısı<0 ise
        cout << "Yigina eleman eklenemez";
        return 0;
    }
    else {
        int x = stackBoyutu[elemanSayisi--];//yığına son eklenen elamanı yığından atar ve eleman sayısını azaltır
        cout<< "Son eklenen eleman yigindan atildi"<< endl;
        return x;
    }
}
int Stack::peek()//eleman sayısı<0 olursa ve  STACK_SIZE 100'den buyuk olursa bu fonksiyon çalışır.
{
    if (elemanSayisi < 0) {
        cout << "Yigindan eleman tasmasi"<< endl;
        return 0;
    }
    else {
        int x = stackBoyutu[elemanSayisi];
        return x;
    }
}

bool Stack::isEmpty()//yığın boş ise bu fonksiyon çalışır
{
    return (elemanSayisi < 0);
}

int main()
{
    class Stack s;
    s.push(10);//yığına elemanlar eklenir
    s.push(20);
    s.push(30);
    s.pop() ;//yığından elemanları siler

    cout<< endl << endl;

    for(int i=0;i<120;i++)
    {
        s.push(i);//0-120 arası sayılar yığına eklenir
    }

    return 0;
}
