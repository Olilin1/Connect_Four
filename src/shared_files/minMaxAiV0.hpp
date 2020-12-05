#ifndef MINMAXAIV0_H
#define MINMAXAIV0_h
#include<vector>
#include<functional>
#include<algorithm>
#include"connectfourgame.hpp"
short minMaxAiV0(std::vector<std::vector<short>>);
short minMaxAiV0(std::vector<std::vector<short>>&, int, bool, bool);
short minMaxGetWinnerV0(std::vector<std::vector<short>>);
#endif