/*!
*********************************************************************************************************
* @file     LedModule.c
* @author   Abdelrahman Mohammed
* @tester   Abdelrahman Mohammed
* @test     To be added here
* @cover    To be added here
* @brief    This template module.
* @version  V1.0
*
* <b>References</b>\n
* TDD Book
*
* <b>File History</b>\n
* This section contains comments describing changes made to this file.\n
* Notice that changes are listed in reverse chronological order.\n
* <table border>
* <tr>
* <td><b> when </b></td>
* <td><b> who </b></td>
* <td><b> why </b></td>
* <tr>
* <td><b> 04/19/2020 </b></td>
* <td><b> Abdelrahman Mohammed </b></td>
* <td><b> As A Proof Of Concept </b></td>
* </table>\n
*
* @note This file.c of LedModule
*/

/*
*********************************************************************************************************
* (Project)
*
* (c) @copyright 2017-2020; Swift Act, LLC; Giza, Mohandseen
*
* All rights reserved. Protected by international copyright laws.
*
* (Project) is provided in source form to registered licensees ONLY. It is
* illegal to distribute this source code to any third party unless you receive
* written permission by an authorized Swift Act representative. Knowledge of
* the source code may NOT be used to develop a similar product.
*
* You can contact us at www.swift-act.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* INCLUDE FILES
*********************************************************************************************************
*/
/*
  * @brief
*/

#include <stdint.h>
#include "LedModule.h"


/*
*********************************************************************************************************
* EXTERNAL C LANGUAGE LINKAGE
*
* Note(s) : (1) C++ compilers MUST 'extern'ally declare ALL C function prototypes & variable/object
* declarations for correct C language linkage.
*********************************************************************************************************
*/
#ifdef __cplusplus
extern "C" { /* See Note #1. */
#endif

/*
*********************************************************************************************************
* LOCAL SIMPLE MACROS
*********************************************************************************************************
*/
/*!
  * @brief
*/

/*
*********************************************************************************************************
* LOCAL PARAMETERIZED MACROS
*********************************************************************************************************
*/
/*!
  * @brief
*/

/*
*********************************************************************************************************
* LOCAL DATA TYPES
*********************************************************************************************************
*/
/*!
  * @brief
*/



/*
*********************************************************************************************************
* LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
/*!
  * @brief This is local global variables used only in this file
*/

static uint16_t * LedsAddress;
static uint16_t   LedsImage;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED   =  1, LAST_LED     =  16         };
enum {TRUE        = ~0, FALSE        = ~TRUE       };

/*
*********************************************************************************************************
* LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/
#ifdef TEMPLATE_INTERN_ACCESS_EN
#define TEMPLATE_INTERN
#else
#define TEMPLATE_INTERN static
#endif

/*!
  * @brief        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.
  * @param [in]   yyyy:  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.
  * @param [out]  yyyy:  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.
  * @retval       yyyy:  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.
  * @author       Ahmed Salah
  * @tester       Ahmed Salah
  * @test         To be added.
  * @cover        To be added.
*/


/*!
  * @brief        this function converts number of led to bits.
  * @param [in]   LedNumber:  This is the number of led you want to convert it to bits.
  * @param [out]  uint16_t :  it returns the number of leds as bits.
  * @retval       This function converts the number of leds to bits.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
static uint16_t ConvertLedNumberToBit(int LedNumber);


/*!
  * @brief        this function updates the hardware.
  * @param [in]   void:  This function takes nothing.
  * @param [out]  void:  this function return nothing.
  * @retval       This function store the value of ledsimage in ledsaddress.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
static void UpdateHardware(void);




/*!
  * @brief        this function checks if the led number out of boundary.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  int:  this function return one or zero.
  * @retval       This function returns true if there are out of boundary else it returns false.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

static BOOL IsOutOfBoundries(int LedNumber);


/*!
  * @brief        this function clears given bit in LedsImage.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  void:  this function returns nothing.
  * @retval       this function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

static void SetLedImageBit(int LedNumber);


/*!
  * @brief        this function clears given bit in LedsImage.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  void:  this function returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
static void ClearLedImageBit(int LedNumber);


/*
*********************************************************************************************************
*********************************************************************************************************
* GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/
/*
  * @brief        this function initialize all leds off.
  * @param [in]   VirtualLeds:  This is the addres you in which you connect your leds.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

void LedModule_Create(uint16_t * address)
{
	  LedsAddress   = address;
	  LedsImage     = ALL_LEDS_OFF;
	  UpdateHardware();
}


/*!
  * @brief        this function turns on a specific led.
  * @param [in]   VirtualLeds:  This is the number of led you want to turn on.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_TurnOn(int  LedNumber)
{
	if (IsOutOfBoundries(LedNumber)) {
		return;
	}
	SetLedImageBit(LedNumber);
	UpdateHardware();
}



/*!
  * @brief        this function turns off a specific led.
  * @param [in]   LedNumbers:  This is the number of led you want to turn off.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_TurnOff(int LedNumber)
{
	if (IsOutOfBoundries(LedNumber)) {
			return;
	}
	ClearLedImageBit(LedNumber);
	UpdateHardware();
}


/*!
  * @brief        this function turns on all leds.
  * @param [in]   void:  Takes Nothing.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_TurnOnAllLeds(void)
{
	LedsImage   = ALL_LEDS_ON;
	UpdateHardware();
}


/*!
  * @brief        this function returns if given led is on or off.
  * @param [in]   LedNumber:  Takes the number of led.
  * @param [out]  BOOL:  it returns true if led is on else false.
  * @retval       This function returns true if led is on else false.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
BOOL LedModule_IsOn(int LedNumber)
{
	if(IsOutOfBoundries(LedNumber)) {
		return FALSE;
	}
	return (LedsImage & ConvertLedNumberToBit(LedNumber));
}


/*!
  * @brief        this function returns if given led is  off.
  * @param [in]   LedNumber:  Takes the number of led.
  * @param [out]  BOOL:  it returns true if led is on else false.
  * @retval       This function returns true if led is on else false.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
BOOL LedModule_IsOff(int LedNumber)
{
	return !LedModule_IsOn(LedNumber);
}


/*!
  * @brief        this function turns all leds off.
  * @param [in]   void:  Takes nothing.
  * @param [out]  void:  it returns nothing.
  * @retval       it returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_TurnOffAllLeds(void)
{
	LedsImage = ALL_LEDS_OFF;
	UpdateHardware();
}

/*
*********************************************************************************************************
*********************************************************************************************************
* LOCAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/
/*!
  * @brief        this function converts number of led to bits.
  * @param [in]   LedNumber:  This is the number of led you want to convert it to bits.
  * @param [out]  uint16_t :  it returns the number of leds as bits.
  * @retval       This function converts the number of leds to bits.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/


static uint16_t ConvertLedNumberToBit(int LedNumber)
{
	return (1 << (LedNumber - 1));
}



/*!
  * @brief        this function updates the hardware.
  * @param [in]   void:  This function takes nothing.
  * @param [out]  void:  this function return nothing.
  * @retval       This function store the value of ledsimage in ledsaddress.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
static void UpdateHardware(void)
{
	* LedsAddress = LedsImage;
}


/*!
  * @brief        this function checks if the led number out of boundary.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  BOOL:  this function return one or zero.
  * @retval       This function returns true if there are out of boundary else it returns false.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

static BOOL IsOutOfBoundries(int LedNumber)
{
	return (LedNumber < FIRST_LED || LedNumber > LAST_LED);
}


/*!
  * @brief        this function clears given bit in LedsImage.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  void:  this function returns nothing.
  * @retval       this function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

static void SetLedImageBit(int LedNumber)
{
	LedsImage |=  ConvertLedNumberToBit(LedNumber);
}


/*!
  * @brief        this function clears given bit in LedsImage.
  * @param [in]   LedNumber:  This function takes number of led.
  * @param [out]  void:  this function returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/

static void ClearLedImageBit(int LedNumber)
{
	LedsImage &= ~ConvertLedNumberToBit(LedNumber);
}


/*
*********************************************************************************************************
* EXTERNAL C LANGUAGE LINKAGE END
*********************************************************************************************************
*/
#ifdef __cplusplus
} /* End of 'extern'al C lang linkage. */
#endif
