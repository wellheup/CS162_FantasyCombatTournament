/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Prototypes several functions useful for input
** validation. Each function receives parameters and returns whether
** or not they are valid input with a bool value.
*********************************************************************/
#ifndef ISVALIDINPUT_HPP
#define ISVALIDINPUT_HPP

/*********************************************************************
** Description: isInt() takes a string parameter and returns true if
** the string contains only an integer.
*********************************************************************/ 
bool isInt(std::string userIn);

/*********************************************************************
** Description: isIntInRange() takes in a string parameter, and a low
** and high integer parameter then returns true only if the string
** is an integer between the low and high values.
*********************************************************************/
bool isIntInRange(std::string userIn, int low, int high);

/*********************************************************************
** Description: isDouble() takes a string parameter and returns true if
** the string contains only a numbers and only one decimal point
** within the string.
*********************************************************************/ 
bool isDouble(std::string userIn);

/*********************************************************************
** Description: isDoubleInRange() takes in a string parameter, and a low
** and high double parameter then returns true only if the string
** is an double between the low and high values.
*********************************************************************/
bool isDoubleInRange(std::string userIn, double low, double high);

/*********************************************************************
** Description: isYesNo() takes a string parameter and returns true
** only if the string is a stand-alone Y or N character. Reference:
** http://www.cplusplus.com/reference/string/string/compare/
*********************************************************************/
bool isYesNo(std::string userIn);

/*********************************************************************
** Description: istTxtFile() takes ina string parameter and returns 
** true only if the string provided will work as a valid file name
*********************************************************************/
bool isTxtFile(std::string userIn);

/*********************************************************************
** Description: isString() takes in a string parameter and returns
** true only if the string provided is a string between the low and
** high parameters
*********************************************************************/
bool isStringWithinRange(std::string userIn, unsigned int low, unsigned
 int high);

#endif