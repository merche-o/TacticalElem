#include	"Settings.h"
#include	"Utils.h"

std::string		IntToString(int number)
{
  std::ostringstream	oss;

  oss << number;
  return (oss.str());
}

int			StringToInt(std::string str)
{
  int			number;
  std::istringstream	iss(str);

  iss >> number;
  return (number);
}

int			Case(int n)
{
  return (n * Settings::CASE_SIZE);
}

void		BubbleSortUnitsInitiative(std::vector<Unit*> & units)
{
	int cpt = 0;

	if (units.size() > 1)
	{
		for (int i = 1; i < units.size(); ++i)
		{
			if (units[i - 1]->initiative < units[i]->initiative)
			{
				Unit* u;
				
				u = units[i - 1];
				units[i - 1] = units[i];
				units[i] = u;

				++cpt;
			}
		}
	}

	if (cpt > 0)
		BubbleSortUnitsInitiative(units);
}