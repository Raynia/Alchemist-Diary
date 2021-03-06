// ⓒFox Tales Studio

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UNREALRPG_API TimeConversion
{
public:
	TimeConversion();
	~TimeConversion();

	//Convert hours to seconds
	static int _internal_Hours(int Hours)
	{
		return Hours * 3600;
	}

	//Convert minutes to seconds
	static int _internal_Minutes(int Minutes)
	{
		return Minutes * 60;
	}

	//NOT USED TO CONVERTING TIME
	//For explicit representation of time
	static int _internal_Seconds(int Seconds)
	{
		return Seconds; 
	}

	//Convert float real time to in-game time
	static float InGameTime(float RealTime)
	{
		return RealTime * 20.0f;
	}

	//Convert integer real time to in-game time
	static int InGameTime(int RealTime)
	{
		return RealTime * 20;
	}

#define Hours(x) TimeConversion::_internal_Hours(x)
#define Minutes(x) TimeConversion::_internal_Minutes(x)
#define Seconds(x) TimeConversion::_internal_Seconds(x)

};
