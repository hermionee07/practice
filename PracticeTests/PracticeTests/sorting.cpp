#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "sorting.h"
using namespace std;

vector<int> insertionSort(vector<int> input)
{
    for (int i = 1; i < input.size(); ++i)
    {
        int key = input[i];
        int n = i - 1;

        for (; n >= 0; --n)
        {
            if (input[n] >= key)
            {
                input[n + 1] = input[n];
            }
            else
            {
                input[n + 1] = key;
                break;
            }
        }
        if (n == -1)
            input[n + 1] = key;

    }

    return input;
}

vector<int> mergeSort(vector<int> input, int size)
{
    if (input.size() == 1)
    {
        vector<int> ret;
        ret.push_back(input[0]);
        return ret;
    }
    if (input.size() == 0)
    {
        return vector<int>();
    }
    else
    {
        int temp1 = size / 2;
        vector<int> sideA(input.begin(), input.begin() + temp1);
        vector<int> sideB(input.begin() + temp1, input.end());
        vector<int> resultA = mergeSort(sideA, sideA.size());
        vector<int> resultB = mergeSort(sideB, sideB.size());

        // merge the 2 sorted lists
        vector<int> finalV;
        if (resultA.size() == 0 && resultB.size() != 0)
        {
            finalV.push_back(resultB[0]);
            return finalV;
        }
        if (resultB.size() == 0 && resultA.size() != 0)
        {
            finalV.push_back(resultA[0]);
            return finalV;
        }

        else
        {
            int n = resultA.size();
            int m = resultB.size();
            int j = 0;
            int i = 0;
            for (; i < n && j < m;)
            {
                if (resultA[i] < resultB[j])
                {
                    finalV.push_back(resultA[i]);
                    i++;
                }
                else if (resultA[i] > resultB[j])
                {
                    finalV.push_back(resultB[j]);
                    j++;
                }
                else
                {
                    finalV.push_back(resultA[i]);
                    finalV.push_back(resultB[j]);
                    i++;
                    j++;
                }
            }
            if (i < n)
            {
                for (int m = i; m < n; ++m)
                {
                    finalV.push_back(resultA[m]);
                }
            }

            if (j < m)
            {
                for (int mm = j; mm < m; ++mm)
                {
                    finalV.push_back(resultB[mm]);
                }
            }
            return finalV;
        }

    }

}