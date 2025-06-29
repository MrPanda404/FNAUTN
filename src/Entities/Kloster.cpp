#include "Kloster.h"

void Kloster::Start()
{
    {
        name = "Kloster";
        ID = 0;
        currentPos = { 4, 4 };

        sequence = {
            {4,4},
            {4,5},
            {4,3},
            {1,1},
            {5,2},
            {1,2},
            {3,3},
            {1,3},
            {1,4},
            {1,5},
            {0,4},
            {0,3},
            {0,7},
            {7,2}
        };

        difficulty = { 0, 0, 1, 2, 3, 4 };
    }
}

void Kloster::Update()
{
}

void Kloster::Stop()
{
}
