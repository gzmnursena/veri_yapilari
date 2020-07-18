#include <iostream>
#include <vector>
using namespace std;

//STL kullanarak graf uygulaması

//graf kenarlarını depolamak için struct
struct Edge {
    int src, dest;
};

//graf nesnesini temsil eden sınıf
class Graph
{
public:
    // bitişiklik listesini temsil etmek için bir vektör
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &kenarlar, int dugumSayisi)//constructor
    {
        // vektör türünü N öğelerine yeniden boyutlandırma vector < int>
        adjList.resize(dugumSayisi);

        // yönlendirilmiş grafa kenarlar ekleme
        for (auto &kenar: kenarlar)
        {
            adjList[kenar.src].push_back(kenar.dest);//push_back() fonksiyonu ile yönlendirilmiş grafın sonuna ekler

            // adjList[kenar.dest].push_back(kenar.src);//yönlendirilmemiş grafın sonuna ekler
        }
    }
};

// grafı yazdıran fonksiyon
void printGraph(Graph const& graph, int dugumSayisi)
{
    for (int i = 0; i < dugumSayisi; i++)
    {
        cout << i << " --> ";//köşe numarasını yazdırır

        for (int j : graph.adjList[i])//vertex'in tüm komşu köşelerini yazdırır
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    //graf kenarlarını gösteren vektör
    vector<Edge> kenarlar =
            {
                    { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
                    { 3, 2 }, { 4, 5 }, { 5, 4 }
            };

    int dugumSayisi = 6;//graftaki düğüm sayısı

    Graph graph(kenarlar, dugumSayisi);//graf oluşturur

    printGraph(graph, dugumSayisi);//grafı yazdırır

    return 0;
}