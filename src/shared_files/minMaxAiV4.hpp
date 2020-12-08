#ifndef MINMAXAIV4_H
#define MINMAXAIV4_H
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include<iostream>
#include "bitboard.hpp"
short minMaxAiV4(std::vector<std::vector<short>>);
short minMaxAiV4(Bitboard, int, int, int, std::map<uint64_t,short> &);
#endif