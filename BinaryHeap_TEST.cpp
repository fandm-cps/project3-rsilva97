#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BinaryHeap.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing shortestPath"){

    SECTION("Constructor"){
        double* priorities = new double[6];
        priorities[0] = 2.6;
        priorities[1] = 0.6;
        priorities[2] = 4.4;
        priorities[3] = 4;
        priorities[4] = 1.5;
        priorities[5] = 0.7;

        BinaryHeap h(priorities, 6);

        delete[] priorities;
    }

    SECTION("function"){
        double* priorities = new double[6];
        priorities[0] = 2.6;
        priorities[1] = 0.6;
        priorities[2] = 4.4;
        priorities[3] = 4;
        priorities[4] = 1.5;
        priorities[5] = 0.7;

        BinaryHeap h(priorities, 6);

        REQUIRE(h.getMin() == 1);
        REQUIRE(h.contains(1) == true);
        REQUIRE(h.getPos(5) == 2);
        REQUIRE(h.getPriority(2) == 4.4);
        h.popMin();
        h.decreasePriority(2, 0.3);
        REQUIRE(h.getPriority(2) == 0.3);
        REQUIRE(h.getMin() == 2);
        REQUIRE(h.getItem(3) == 3);
        REQUIRE(h.contains(1) == false);
        h.popMin();
        REQUIRE(h.contains(2) == false);
        REQUIRE(h.getMin() == 5);
        REQUIRE(h.getSize() == 4);
        

        delete[] priorities;
    }

/*
    SECTION("functions"){
        double* priorities = new double[6];
        priorities[0] = 2.6;
        priorities[1] = 0.6;
        priorities[2] = 4.4;
        priorities[3] = 4;
        priorities[4] = 1.5;
        priorities[5] = 0.7;

        BinaryHeap h(priorities, 6);

        REQUIRE(h.getMin() == 1);
        REQUIRE(h.getItem(4) == 0);
        REQUIRE(h.contains(1) == true);
        REQUIRE(h.getPriority(0) == 2.6);
        REQUIRE(h.getPriority(3) == 4);
        REQUIRE(h.getPos(0) == 4);
        //h.decreasePriority(0, 30);
        //REQUIRE(h.getPriority(0) == 20.6);
        //h.decreasePriority(0, 2.7);
        //REQUIRE(h.getPriority(0) == 2.7);
        h.popMin();
        REQUIRE(h.getMin() == 5);
        REQUIRE(h.getItem(0) == 5);
        REQUIRE(h.contains(1) == false);
        

        delete[] priorities;
    }
*/
}