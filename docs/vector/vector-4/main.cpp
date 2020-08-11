#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<std::pair<int, string>> vektor = { {1, "C++"},{2, "Python"},{3, "C#"}};
    //std::pair= farklı tipte iki değeri birleştirmek için kullanılır. Örnekte int ve string tipindeki veriler birleştirilmiştir
    sort(vektor.begin(), vektor.end());//vektoru küçükten->büyüğe doğru sıralar
    for(auto item: vektor) {//foreach döngüsü
        cout << "(" << item.first << "," << item.second << ")\n";//vektürün birinci ve ikinci değerlerini yazdırır
    }
}