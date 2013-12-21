#ifndef OTREE_UTILS_LOG_H
#define OTREE_UTILS_LOG_H

#include <iostream>

#ifdef DEBUG
#define LOG(statement) std::cout << statement << std::endl
#else // !DEBUG
#define LOG(statement) (void)0
#endif // DEBUG

#define ERROR(statement) std::cout << statement << std::endl;
#define INFO(statement) std::cout << statement << std::endl;

#endif // OTREE_UTILS_LOG_H

