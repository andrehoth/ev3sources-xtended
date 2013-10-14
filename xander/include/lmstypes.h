/*
 * LEGO® MINDSTORMS EV3
 *
 * Copyright (C) 2010-2013 The LEGO Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#ifndef LMSTYPES_H_
#define LMSTYPES_H_

//        BASIC DATA TYPES

#ifndef LEGO_SIMULATION

#define   LFILE                 FILE

#else

#include  <Base/BasicTypes.h>
#include  <VMCalls.h>

typedef   LEGO::UInt8           uint8_t;  //!< Basic Type used to symbolise 8  bit unsigned values
typedef   LEGO::UInt16          uint16_t;  //!< Basic Type used to symbolise 16 bit unsigned values
typedef   unsigned long         uint32_t;  //!< Basic Type used to symbolise 32 bit unsigned values


typedef   LEGO::Int8            int8_t;  //!< Basic Type used to symbolise 8  bit signed values
typedef   LEGO::Int16           int16_t;  //!< Basic Type used to symbolise 16 bit signed values
typedef   LEGO::Int32           int32_t;  //!< Basic Type used to symbolise 32 bit signed values

typedef   LEGO::Real32          float;  //!< Basic Type used to symbolise 32 bit floating point values

#endif



//        VM VARIABLE TYPES

typedef   uint8_t             VARDATA;    //!< Variable base type
typedef   uint8_t             IMGDATA;    //!< Image base type

typedef   uint16_t             uint16_t;      //!< Program id type

typedef   uint16_t             OBJID;      //!< Object id type
typedef   IMGDATA*          IP;         //!< Instruction pointer type
typedef   VARDATA*          LP;         //!< Local variable pointer type
typedef   VARDATA*          GP;         //!< global variable pointer type

typedef   uint32_t             IMINDEX;    //!< ImageData index type
typedef   uint32_t             GBINDEX;    //!< GlobalBytes index type
typedef   uint32_t             LBINDEX;    //!< LocalBytes index type
typedef   uint16_t             TRIGGER;    //!< TriggerCount type
typedef   uint8_t             PARS;       //!< NoOfParameters type
typedef   int32_t             IMOFFS;     //!< ImageData offset type

typedef   int16_t            HANDLER;    //!< Memory list index



/*! \page imagelayout Image Layout
 *  The image consists of three different components in this fixed order: imageheader, objectheaders and byte codes.
 *
 *  The imageheader tells something about image version, filesize, no of objectheaders (objects) and no of global variable bytes.
 *
 *
 *  Objectheaders contains different informations depending on the nature of the object:
 *
 *- The VMTHREAD object (former TBC_TOPVI)                                                                              \n
 *  - OffsetToInstructions tells were to find the corresponding byte codes (offset from image start)                    \n
 *  - OwnerObjectId must be zero                                                                                        \n
 *  - TriggerCount is used but must be zero                                                                             \n
 *  - LocalBytes describes the number of bytes for local variables                                                      \n
 *
 *- The SUBCALL object   (former TBC_VI and TBC_VI_ALIAS)                                                               \n
 *  - OffsetToInstructions tells were to find the corresponding byte codes (if alias this is equal to mother object)    \n
 *  - OwnerObjectId must be zero                                                                                        \n
 *  - TriggerCount is used and must be one                                                                              \n
 *  - LocalBytes describes the number of bytes for local variables                                                      \n
 *
 *- The BLOCK object     (former CLUMP)                                                                                 \n
 *  - OffsetToInstructions tells were to find the corresponding byte codes (offset from image start)                    \n
 *  - OwnerObjectId is equal to object id it belongs to (not equal to zero)                                             \n
 *  - TriggerCount is used to determine how many triggers needed before the BLOCK object is activated                   \n
 *  - LocalBytes must be zero (locals are defined in the owner object)                                                  \n
 *
 *  Byte codes are described in a different section.
 *
 *  Little Endian are used (addresses and data are represented with LSB on lowest address and MSB on highest address).
 *
 *  Offset to instructions is number of bytes from start of image to start of object instructions.
 *
 *  Index to global variables are byte based and counted from start of globals (zero based).
 *
 *  Index to local variables are byte based and counted from start of object locals (zero based).
 *
 *  Object ID's is not zero based - First object (VMTHEAD) is named 1.
 *
 */

/*! \page imagelayout
 *
 *  FILE layout                         (aligned)
 *
 *- IMGHEAD                             (aligned)
 *  - Sign                              (4 bytes)
 *  - ImageSize                         (4 bytes)
 *  - VersionInfo                       (2 bytes)
 *  - NumberOfObjects                   (2 bytes)
 *  - GlobalBytes                       (4 bytes)
 */

/*! \struct IMGHEAD
 *          Image header
 */
typedef   struct
{
  uint8_t   Sign[4];                      //!< Place holder for the file type identifier
  IMINDEX ImageSize;                    //!< Image size
  uint16_t   VersionInfo;                  //!< Version identifier
  OBJID   NumberOfObjects;              //!< Total number of objects in image
  GBINDEX GlobalBytes;                  //!< Number of bytes to allocate for global variables
}
IMGHEAD;

/*! \page imagelayout
 *
 *- OBJHEAD                             (aligned)
 *  - OffsetToInstructions              (4 bytes)
 *  - OwnerObjectId                     (2 bytes)
 *  - TriggerCount                      (2 bytes)
 *  - LocalBytes                        (4 bytes)
 *
 */

/*! \struct OBJHEAD
 *          Object header used for all types of objects (VMTHREAD, SUBCALL, BLOCK and ALIAS)
 */
typedef   struct                        // Object header
{
  IP      OffsetToInstructions;         //!< Offset to instructions from image start
  OBJID   OwnerObjectId;                //!< Used by BLOCK's to hold the owner id
  TRIGGER TriggerCount;                 //!< Used to determine how many triggers needed before the BLOCK object is activated
  LBINDEX LocalBytes;                   //!< Number of bytes to allocate for local variables
}
OBJHEAD;


/*! \struct LABEL
 *          Label data hold information used for labels
 */
typedef   struct
{
  IMINDEX Addr;                         //!< Offset to breakpoint address from image start
}
LABEL;


#endif /* LMSTYPES_H_ */
