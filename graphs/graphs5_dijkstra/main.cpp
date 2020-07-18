#include <iostream>
#include <limits.h>
#include <stdio.h>

#define dugum 9 //graftaki köşe(dugum) sayısı

using namespace std;
//Dijkstra en kısa yol algoritması

//en kısa yol ağacına henüz dahil olmayan köşe kümesinden minimum mesafe değerine sahip köşe noktasını bulmak için fonksiyon
int minDistance(int dist[], bool sptSet[])
{
    // minimum değeri başlatır
    int min = INT_MAX, min_index;

    for (int v = 0; v < dugum; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

//oluşturulan minDistance dizisini yazdırmak fonksiyon
int printSolution(int dist[])
{
    cout<<"Köşe \t Kaynağa olan uzaklık\n"<<endl;
    for (int i = 0; i < dugum; i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}

//bitişik matris gösterimi kullanılarak temsil edilen bir graf için Dijkstra'nın tek kaynaklı en kısa yol algoritmasını uygulayan fonksiyon
void dijkstra(int graph[dugum][dugum], int src)
{
    int dist[dugum]; //dist [i] en kısa yolu tutar

    bool sptSet[dugum]; // sptSet[i] vertex i en kısa sürede dahil edilirse doğru olacaktır
    // yol ağacı veya src'den i'ye en kısa mesafe

    // tüm mesafeleri sonsuz olarak başlat ve sptSet[]'i false olarak ayarla
    for (int i = 0; i < dugum; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // kaynak tepe noktasının kendisinden uzaklığı her zaman 0'dır
    dist[src] = 0;

    // tüm düğümler için en kısa yolu bulun
    for (int count = 0; count < dugum - 1; count++) {
       //henüz işlenmemiş düğümlerin kümesinden minimum mesafe köşesini seçer.
       //u her zaman ilk yinelemede src eşittir.
        int u = minDistance(dist, sptSet);

        //seçilen düğümü işaretler
        sptSet[u] = true;

        //seçilen köşenin bitişik köşelerinin dist değerini günceller
        for (int v = 0; v < dugum; v++)

            /*update dist [v] sadece sptset'te değilse, u'dan V'ye bir kenar vardır ve src'den V'ye u'ya giden yolun
            toplam ağırlığı, dist[v] ' nin geçerli değerinden daha küçüktür]*/
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX

                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // oluşturulan dist dizisini yazdırır
    printSolution(dist);
}

int main()
{
    // graf oluşturulur
    int graph[dugum][dugum] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}