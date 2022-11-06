/*
 * platform_types.h
 *
 *  Created on: 12 Mar 2022
 *      Author: Dell
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*****unsigned data types*****/
typedef unsigned char        uint8_t;
typedef unsigned short      u16;
typedef unsigned int         u32;
typedef unsigned long long   uint64_t;


/*****signed data types*****/
typedef signed char        sint8_t;
typedef signed short       sint16_t;
typedef signed int         sint32_t;
typedef signed long long   sint64_t;


/*****real data types*****/
typedef  float      fint32_t;
typedef  double     fint64_t;
typedef long double fint128_t;


/*****volatile unsigned data types*****/
typedef volatile unsigned char      vuint8_t;
typedef volatile unsigned short     vuint16_t;
typedef volatile unsigned int       vuint32_t;
typedef volatile unsigned long long vuint64_t;


/*****volatile signed data types*****/
typedef volatile signed char      vsint8_t;
typedef volatile signed short     vsint16_t;
typedef volatile signed int       vsint32_t;
typedef volatile signed long long vsint64_t;


#endif /* PLATFORM_TYPES_H_ */
