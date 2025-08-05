/*
Dave Logs  
Copyright (c) 2025 Seid Eshetu.

Licensed under the Apache License, Version 2.0 (the "License"). You may not use this file
except in compliance with the License. You may obtain a copy of the License at:

    http://www.apache.org/licenses/LICENSE-2.0

This software is the product of significant time, expertise, and effort invested in its
development, testing, and documentation. While every reasonable measure has been taken to 
ensure its reliability and functionality, it is provided on an "as is" basis, without 
warranty of any kind—express or implied—including, but not limited to, warranties of 
merchantability, fitness for a particular purpose, or non-infringement.

In no event shall the authors or copyright
holders be liable for any claim, damages, or other liability—whether in an action of
contract, tort, or otherwise—arising from, out of, or in connection with the software or
the use or other dealings in the software.
*/

#pragma once

// #define STRIP_OUT_DAVE_LOGS // uncomment to strip out all your log messages globally
// #define VERBOSE	// uncomment to get verbose output globally

#ifndef STRIP_OUT_DAVE_LOGS
	#include <iostream>
	#include <mutex>
	#include <thread>

	#define RESET "\033[0m"
	#define BLACK "\033[30m"
	#define RED "\033[31m"
	#define DARK_GREEN "\033[32m"
	#define ORANGE "\033[33m"
	#define BLUE "\033[34m"
	#define PURPLE "\033[35m"
	#define LIGHT_BLUE "\033[36m"
	#define WHITE "\033[37m"
	#define GREEN "\033[38m"
	#define COLORLESS

extern std::mutex out_mutex;

	#ifdef VERBOSE
		#define LOG(color, level, ...)                                   \
			out_mutex.lock();                                           \
			std::cout << color << level << __VA_ARGS__ << RESET << '\n'  \
					  << "[Thread-" << std::this_thread::get_id() << "]" \
					  << "[ file: " << __FILE__ << ":" << __LINE__       \
					  << " | function: " << __func__ << " ]\n"           \
					  << std::endl;                                      \
			out_mutex.unlock();

	#else
		#define LOG(color, level, ...)                                        \
			out_mutex.lock();                                                \
			std::cout << color << level << __VA_ARGS__ << RESET << std::endl; \
			out_mutex.unlock();

	#endif	// VERBOSE

	// convinience macro wrappers
	#define LOG_TRACE(...) LOG(LIGHT_BLUE, "[🩺 TRACE]: ", __VA_ARGS__)
	#define LOG_DEBUG(...) LOG(PURPLE, "[🚧 DEBUG]: ", __VA_ARGS__)
	#define LOG_INFO(...) LOG(GREEN, "[ℹ️ INFO]: ", __VA_ARGS__)
	#define LOG_WARNING(...) LOG(ORANGE, "[⚠️ WARNING]: ", __VA_ARGS__)
	#define LOG_ERROR(...) LOG(RED, "[❗ ERROR]: ", __VA_ARGS__)
	#define LOG_CRITICAL(...) LOG(RED, "[🚨 CRITICAL]: ", __VA_ARGS__)
#else
	// strip every log message out
	#define LOG(color, level, ...)
	#define LOG_TRACE(...)
	#define LOG_DEBUG(...)
	#define LOG_INFO(...)
	#define LOG_WARNING(...)
	#define LOG_ERROR(...)
	#define LOG_CRITICAL(...)

#endif	// STRIP_OUT_DAVE_LOGS