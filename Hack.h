#pragma once

#include "Windows.h"
#include <vector>

using std::vector;

typedef uintptr_t ADDRESS;
typedef uintptr_t OFFSET;

class Hack {
private:
	union {
		ADDRESS BaseAddress;
		ADDRESS StaticAddress;
	};
	vector<OFFSET> Offsets;
	int pLevel = -1;

public:
	Hack::Hack() = delete;
	Hack::Hack(ADDRESS StaticAddress);
	Hack::Hack(ADDRESS BaseAddy, vector<OFFSET> Offsets);

	ADDRESS Hack::GetAddress();
	bool Hack::IsPointer();

	void Hack::SetValue(void* ValueAddress, int Bytes);

	void Hack::GetValue(void* DestAddress, int Bytes);

	template<typename T>
	static void SetValue(Hack hack, T Value) {
		ADDRESS Address = hack.GetAddress();

		*(T*)Address = Value;
	}

	template<typename T>
	static T GetValue(Hack hack) {
		ADDRESS Address = hack.GetAddress();

		return (Address) ? *(T*)Address : NULL;
	}
};