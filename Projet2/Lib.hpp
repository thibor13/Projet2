#pragma once

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

namespace Lib {
	//in secs
	double getTimeStamp() //retourne le temps actuel en seconde
	{
		chrono::nanoseconds ns =
			duration_cast<chrono::nanoseconds>(system_clock::now().time_since_epoch());
		return ns.count() / 1000000000.0;
	}
}
