/*!
*********************************************************************************************************
* @file     LEdModule.h
* @author   Abdelrahman Mohammed
* @tester   Abdelrahman Mohammed
* @test     To be added here
* @cover    To be added gere
* @brief    This is dummy module to make sure we understand all concepts.
* @version  V1.0
*
* <b>File History</b>\n
* I Added Two New Functions in This Module.\n
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
* @note This file.h of LedModule
*/

/*
*********************************************************************************************************
* (Project)
*
* (c) Copyright 2017-2020; Swift Act, LLC; Giza, Mohandseen
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
* MODULE
*********************************************************************************************************
*/
#ifndef TEMPLATE_MODULE_PRESENT
#define TEMPLATE_MODULE_PRESENT

/*
*********************************************************************************************************
* INCLUDE FILES
*********************************************************************************************************
*/
/*
  * @brief
*/

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
* SIMPLE MACROS
*********************************************************************************************************
*/
/*!
  * @brief
*/

/*
*********************************************************************************************************
* PARAMETERIZED MACROS
*********************************************************************************************************
*/
/*!
  * @brief
*/

/*
*********************************************************************************************************
* DATA TYPES
*********************************************************************************************************
*/
/*!
  * @brief this is data types used in this module
*/

typedef int BOOL;

/*
*********************************************************************************************************
* GLOBAL VARIABLES
*********************************************************************************************************
*/
/*!
  * @brief
*/

/*
*********************************************************************************************************
* FUNCTION PROTOTYPES
*********************************************************************************************************
*/
/*!
  * @brief        this function initialize all leds off.
  * @param [in]   VirtualLeds:  This is the addres you in which you connect your leds.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_Create(uint16_t * address);

/*!
  * @brief        this function turns on a specific led.
  * @param [in]   LedNumber:  This is the number of led you want to turn on.
  * @param [out]  void:  it returns nothing.
  * @retval       This function returns nothing.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
void LedModule_TurnOn(int  LedNumber);




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
void LedModule_TurnOff(int LedNumber);


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
void LedModule_TurnOnAllLeds(void);


/*!
  * @brief        this function returns if given led is on.
  * @param [in]   LedNumber:  Takes the number of led.
  * @param [out]  BOOL:  it returns true if led is on else false.
  * @retval       This function returns true if led is on else false.
  * @author       Abdelrahman Mohammed
  * @tester       Abdelrahman Mohammed
  * @test         To be added.
  * @cover        To be added.
*/
BOOL LedModule_IsOn(int LedNumber);


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
BOOL LedModule_IsOff(int LedNumber);



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
void LedModule_TurnOffAllLeds(void);



/*
*********************************************************************************************************
* EXTERNAL C LANGUAGE LINKAGE END
*********************************************************************************************************
*/
#ifdef __cplusplus
} /* End of 'extern'al C lang linkage. */
#endif

/*
*********************************************************************************************************
* MODULE END
*********************************************************************************************************
*/
#endif /* End of template module include. */
