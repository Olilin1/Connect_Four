#ifndef MINMAXAIV2_H
#define MINMAXAIV2_h
#include<vector>
#include<functional>
#include<algorithm>
#include<iostream>
short minMaxAiV2(std::vector<std::vector<short>>);
short minMaxAiV2(std::vector<std::vector<short>>&, int,int,int, bool, bool);
short minMaxGetWinnerV2(std::vector<std::vector<short>>&);
#endif