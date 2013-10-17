#ifndef OTREE_UTILS_LOG_H
#define OTREE_UTILS_LOG_H

#ifdef DEBUG
#include <iostream>
#define LOG(statement) std::cout << statement
#else // !DEBUG
#define LOG(statement)
#endif // DEBUG

#endif // OTREE_UTILS_LOG_H

