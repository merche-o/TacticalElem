#ifndef	__UTILS_HPP__
#define	__UTILS_HPP__

#include	<sstream>
#include	<string>
#include	<vector>
#include	"Unit.h"

#define	ABS(x)	(x > 0) ? x : -x

std::string		IntToString(int);
int			StringToInt(std::string);
//int			Case(int);
void		BubbleSortUnitsInitiative(std::vector<Unit*> & units);

#endif
