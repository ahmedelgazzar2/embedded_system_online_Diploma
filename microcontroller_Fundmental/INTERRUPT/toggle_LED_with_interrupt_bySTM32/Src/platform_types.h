/*
 * platform_types.h
 *
 *  Created on: 12 Mar 2022
 *      Author: Dell
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*****unsigned data types*****/
typedef unsigned char        u8;
typedef unsigned short       u16;
typedef unsigned int         u32;
typedef unsigned long long   u64;


/*****signed data types*****/
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;


/*****real data types*****/
typedef  float      f32;
typedef  double     f64;
typedef long double f128;


/*****volatile unsigned data types*****/
typedef volatile unsigned char      vu8;
typedef volatile unsigned short     vu16;
typedef volatile unsigned int       vu32;
typedef volatile unsigned long long vu64;


/*****volatile signed data types*****/
typedef volatile signed char      vs8;
typedef volatile signed short     vs16;
typedef volatile signed int       vs32;
typedef volatile signed long long vs64;


#endif /* PLATFORM_TYPES_H_ */
