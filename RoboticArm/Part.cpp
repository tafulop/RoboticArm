#include "Part.h"



Part::Part()
{
	Part::count++;
}


Part::~Part()
{

}

int Part::getNumberOfParts()
{	
	return Part::count;
}
