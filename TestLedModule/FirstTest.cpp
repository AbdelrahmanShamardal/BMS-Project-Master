
static void (*real_one) ();
static void stub(){}

#include "CppUTest/TestHarness.h"
#include "../LedModule/LedModule.h"
extern "C"
{
#include<stdio.h>
#include <memory.h>

}

static uint16_t VirtualLeds;

/* declare TestGroup with name FirstTest */
TEST_GROUP(LedModule)
{


	/* declare a setup method for the test group. Optional. */
	void setup ()
	{
		LedModule_Create(&VirtualLeds);
		/* Set method real_one to stub. Automatically restore in teardown */
		UT_PTR_SET(real_one, stub);
	}


	/* declare a teardown method for the test group. Optional */
	void teardown()
	{

	}

	void expect(char * s)
	{


	}

	void given(int charsWritten)
	{


	}


}; /* do not forget semicolumn */

/* declare one test within the test group */

TEST(LedModule, LedsOffAfterCreate)
{
	uint16_t VirtualLeds = 0xffff;
	LedModule_Create(&VirtualLeds);
	LONGS_EQUAL(0x0000, VirtualLeds);
}


TEST(LedModule, TurnOnLedOne)
{
	LedModule_TurnOn(1);
	LONGS_EQUAL(1, VirtualLeds);
}


TEST(LedModule, TurnOffLedOne)
{

	LedModule_TurnOn(1);
	LedModule_TurnOff(1);
	LONGS_EQUAL(0, VirtualLeds);
}



TEST(LedModule, TurnOnMultipleLeds)
{

	LedModule_TurnOn(8);
	LedModule_TurnOn(9);
	LONGS_EQUAL(0x0180, VirtualLeds);
}


TEST(LedModule, TurnOffAnyLed)
{

	LedModule_TurnOnAllLeds();
	LedModule_TurnOff(8);
	LONGS_EQUAL(0xff7f, VirtualLeds);
}


TEST(LedModule, TurnOnAllLeds)
{
	LedModule_TurnOnAllLeds();
	LONGS_EQUAL(0xffff, VirtualLeds);
}


TEST(LedModule, LedMemoryIsNotReadable)
{
	VirtualLeds = 0xffff;
	LedModule_TurnOn(8);
	LONGS_EQUAL(0x0080, VirtualLeds);
}


TEST(LedModule, UpperAndLowerBounds)
{
	LedModule_TurnOn(1);
	LedModule_TurnOn(16);
	LONGS_EQUAL(0x8001, VirtualLeds);
}


TEST(LedModule, OutOfBoundsChangeNothing)
{
	LedModule_TurnOn(-1);
	LedModule_TurnOn(17);
	LedModule_TurnOn(0);
	LedModule_TurnOn(3141);
	LONGS_EQUAL(0x0000, VirtualLeds);
}


TEST(LedModule, OutOfBoundsTurnOffDoesNoHarm)
{
	LedModule_TurnOnAllLeds();
	LedModule_TurnOff(-1);
	LedModule_TurnOff(17);
	LedModule_TurnOff(0);
	LedModule_TurnOff(3141);
	LONGS_EQUAL(0xffff, VirtualLeds);
}


IGNORE_TEST(LedModule, OutOfBoundsToDo)
{

}


TEST(LedModule, IsOn)
{
	CHECK_FALSE(LedModule_IsOn(8));
	LedModule_TurnOn(8);
	CHECK_TRUE(LedModule_IsOn(8));
}



TEST(LedModule, OutOfBoundsAreAlwaysOff)
{
	CHECK_FALSE(LedModule_IsOn(0));
	CHECK_FALSE(LedModule_IsOn(17));
}


TEST(LedModule, IsOff)
{
	CHECK_TRUE(LedModule_IsOff(8));
	LedModule_TurnOn(8);
	CHECK_FALSE(LedModule_IsOff(8));
}


TEST(LedModule, TurnOffMultipleLeds)
{
	LedModule_TurnOnAllLeds();
	LedModule_TurnOff(8);
	LedModule_TurnOff(9);
	LONGS_EQUAL((~0x180)&0xffff, VirtualLeds);
}


TEST(LedModule, AllOff)
{
	LedModule_TurnOnAllLeds();
	LedModule_TurnOffAllLeds();
	LONGS_EQUAL(0x0000, VirtualLeds);
}

