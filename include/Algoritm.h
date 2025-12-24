#ifndef ALGORITM_H
#define ALGORITM_H

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> sortColors(const std::vector<std::string>& objects, const std::vector<std::string>& color_order);
void inputData(std::vector<std::string>& objects, std::vector<std::string>& color_order);
void printSortedObjects(const std::vector<std::string>& sorted_objects);

#endif