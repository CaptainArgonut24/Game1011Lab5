#pragma once
#ifndef __CUSTOM_EXCEPTIONS_H__
#define __CUSTOM_EXCEPTIONS_H__
#include <exception>

class OutOfPancake : public std::exception
{
public:
	OutOfPancake() noexcept : exception("WE OUT OF PANCAKES!! WE NEED MORE PANCAKES PAPA LOUIE STAT!!!! COOK MORE OR YOUR FIRED!!! AND STOP EATING ALL THE PANCAKES FATSON!!!", 1) {}
};

#endif //!__CUSTOM_EXCEPTIONS_H__