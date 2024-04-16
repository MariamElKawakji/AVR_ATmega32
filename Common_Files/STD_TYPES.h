/*
 * STD_TYPES.h
 *
 *  Created on: Mar 4, 2024
 *      Author: Marii
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef float f32;

typedef enum{
	FALSE= 0,
	TRUE= 1
}bool_t;

#define NULLPTR ((void*)0)

#endif /* STD_TYPES_H_ */
