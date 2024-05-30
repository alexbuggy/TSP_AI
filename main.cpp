#include "TSP.h"
#include <chrono>  
int main()
{
    void dfs(TSP & tsp);
    void ucs(TSP & tsp);
    void a_star(TSP & tsp);
    TSP tsp(11);
    tsp.cities = {{0, "Man"},{1, "Liv"},{2, "Lon"},{3, "Ams"},{4, "Mad"},{5, "Bar"},{6, "Mil"},{7, "Mun"},{8, "Par"},{9, "Rom"},{10,"Tur"}};

    tsp.AddDistance(0, 1, 50);
    tsp.AddDistance(0, 2, 262);
    tsp.AddDistance(0, 3, 496);
    tsp.AddDistance(0, 4, 1456);
    tsp.AddDistance(0, 5, 1384);
    tsp.AddDistance(0, 6, 1214);
    tsp.AddDistance(0, 7, 1138);
    tsp.AddDistance(0, 8, 606);
    tsp.AddDistance(0, 9, 1690);
    tsp.AddDistance(0, 10, 1179);

    tsp.AddDistance(1, 2, 287);
    tsp.AddDistance(1, 3, 543);
    tsp.AddDistance(1, 4, 1445);
    tsp.AddDistance(1, 5, 1391);
    tsp.AddDistance(1, 6, 1246);
    tsp.AddDistance(1, 7, 1180);
    tsp.AddDistance(1, 8, 629);
    tsp.AddDistance(1, 9, 1721);
    tsp.AddDistance(1, 10, 1207);

    tsp.AddDistance(2, 3, 358);
    tsp.AddDistance(2, 4, 1263);
    tsp.AddDistance(2, 5, 1138);
    tsp.AddDistance(2, 6, 960);
    tsp.AddDistance(2, 7, 921);
    tsp.AddDistance(2, 8, 343);
    tsp.AddDistance(2, 9, 1435);
    tsp.AddDistance(2, 10, 920);

    tsp.AddDistance(3, 4, 1481);
    tsp.AddDistance(3, 5, 1238);
    tsp.AddDistance(3, 6, 829);
    tsp.AddDistance(3, 7, 669);
    tsp.AddDistance(3, 8, 430);
    tsp.AddDistance(3, 9, 1296);
    tsp.AddDistance(3, 10, 836);

    tsp.AddDistance(4, 5, 506);
    tsp.AddDistance(4, 6, 1190);
    tsp.AddDistance(4, 7, 1487);
    tsp.AddDistance(4, 8, 1052);
    tsp.AddDistance(4, 9, 1367);
    tsp.AddDistance(4, 10, 1064);

    tsp.AddDistance(5, 6, 726);
    tsp.AddDistance(5, 7, 1055);
    tsp.AddDistance(5, 8, 830);
    tsp.AddDistance(5, 9, 861);
    tsp.AddDistance(5, 10, 606);

    tsp.AddDistance(6, 7, 348);
    tsp.AddDistance(6, 8, 640);
    tsp.AddDistance(6, 9, 477);
    tsp.AddDistance(6, 10, 125);

    tsp.AddDistance(7, 8, 686);
    tsp.AddDistance(7, 9, 696);
    tsp.AddDistance(7, 10, 452);

    tsp.AddDistance(8, 9, 1106);
    tsp.AddDistance(8, 10, 584);

    tsp.AddDistance(9, 10, 524);


    auto start = chrono::high_resolution_clock::now();
    dfs(tsp);
   auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "DFS Execution time: " << duration << " seconds" << endl << endl;

     start = chrono::high_resolution_clock::now();
    a_star(tsp);
     end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "A* Execution time: " << duration << " seconds" << endl<< endl;

    start = chrono::high_resolution_clock::now();
    ucs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "UCS Execution time: " << duration << " seconds" << endl;

 
    return 0;
}

