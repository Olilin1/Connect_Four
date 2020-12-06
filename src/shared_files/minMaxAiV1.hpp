#ifndef MINMAXAIV1_H
#define MINMAXAIV1_h
#include<vector>
#include<functional>
#include<algorithm>
#include<iostream>
short minMaxAiV1(std::vector<std::vector<short>>);
short minMaxAiV1(std::vector<std::vector<short>>&, int,int,int, bool, bool);
short minMaxGetWinnerV1(std::vector<std::vector<short>>&);
#endif