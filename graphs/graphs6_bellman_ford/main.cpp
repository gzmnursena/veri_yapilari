#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//Bellman-Ford ile en kısa yolu bulma...

// grafta kenarları gösteren struct
struct Edge {
    int src, dest, weight;
};

//bağlı, yönlendirilmiş ve ağırlıklı bir grafları gösteren struct
struct Graph {

   // V: köşe sayısı, E: kenar sayısı
    int V, E;


    struct Edge* edge;// grafı kenar dizisi olarak temsil eder
};

// V Köşeli ve E kenarlarlı olan bir graf oluşturur
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
//oluşturulan grafı yazdırmak için fonksiyon
void printArr(int dist[], int n)
{
    cout<<"Köşe \t Kaynağa olan uzaklık\n";
    for (int i = 0; i < n; ++i)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}

//Bellman-Ford algoritmasını kullanarak src'den diğer tüm köşelere en kısa mesafeleri bulan fonksiyon
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // src'den diğer tüm köşelere sonsuz olarak mesafeleri başlatın
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // src'den diğer herhangi bir köşeye basit bir en kısa yol en fazla |V|-1 kenarlara sahip olabilir
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

   //negatif ağırlık döngüler kontrol edilir. Yukarıda, graf negatif ağırlık döngüsü içermiyorsa en kısa mesafeleri garanti eder.
   // Daha kısa bir yol alırsak, o zaman bir döngü olur
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; //negatif döngü tespit edilirse, sadece return edilir
        }
    }

    printArr(dist, V);

    return;
}

int main()
{
    int V = 5; //graftaki köşe sayısı
    int E = 8; //graftaki kenar sayısı
    struct Graph* graph = createGraph(V, E);

    // 0-1 kenara düğüm eklenir
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // 0-2 kenara düğüm eklenir
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // 1-2 kenara düğüm eklenir
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // 1-3 kenara düğüm eklenir
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // 1-4 kenara düğüm eklenir
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // 3-2 kenara düğüm eklenir
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // 3-1 kenara düğüm eklenir
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // 4-3kenara düğüm eklenir
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}
