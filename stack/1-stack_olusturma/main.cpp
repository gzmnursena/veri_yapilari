#include <iostream>
#include <stack>
using namespace std;
//Bu örnekte aşağıdaki hazır yığın fonksiyonları kullanılmıştır.

//Stack ilk giren son çıkar mantığı ile çalışır

class Stack{
public:
    void yiginGoster(stack <int>);
};
void Stack::yiginGoster(stack <int> stack)//stack'teki elemanları yazdırır
{
    while (!stack.empty())//empty(): yığının boş olup olmadığını kontrol eder
    {
        cout << "\t" << stack.top();//yığının en üstteki (en yeni) elemanını verir
        stack.pop();//yığından eleman çıkarır
    }
    cout << endl;
}

int main ()
{
    Stack yigin;
    stack <int> stack;
    stack.push(10);//yığına elemanlar eklenir
    stack.push(30);
    stack.push(20);
    stack.push(5);
    stack.push(1);

    cout << "Stack: ";
    yigin.yiginGoster(stack);//yıgındaki elemanlar yazdırılır

    cout << endl <<"s.size() : " << stack.size();//yığının boyutunu verir
    cout << endl<< "s.top() : " << stack.top();//yığının en üstteki (en yeni) elemanını verir


    cout << endl<< "s.pop() : ";
    stack.pop();//yığından eleman çıkarır
    yigin.yiginGoster(stack);//yıgındaki elemanlar yazdırılır

    return 0;
}