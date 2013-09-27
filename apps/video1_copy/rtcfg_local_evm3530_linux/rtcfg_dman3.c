/* 
 * Copyright (c) 2010, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/*
 *  ======== rtcfg_dman3.c ========
 *  DMAN3 configuration for non-RTSC config example. Compile this file as is,
 *  with apps that don't use DMAN3. For apps whose local codecs use DMAN3, copy
 *  this file and modify as needed.
 */

#include <xdc/std.h>

/*
 *  Set USE_DMAN3 to 1 if the app has a local codec that uses DMAN3, otherwise
 *  set to 0. If USE_DMAN3 is set to 1, the user may need to modify the
 *  following:
 *
 *  DMAN3_QDMA_PARAM_BASE   - Physical address of PaRam 0.
 *  DMAN3_MAX_PARAM_ENTRIES - Total number of PaRam entries on hardware
 *
 *  DMAN3_PARAM_BASE_INDEX  - First index of PaRam block assigned to DMAN3
 *  DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES - Number of PaRam entries for DMAN3
 *  DMAN3_NULLPARAM         - A reserved PaRam.
 *  DMAN3_TCC_FREEMASK_H    - Bit mask of TCCs between 32 and 63 for DMAN3 use
 *  DMAN3_TCC_FREEMASK_L    - Bit mask of TCCs between 0 and 31 for DMAN3 use
 *
 *  DMAN3_NUMPARAM_GROUP    - Array containing # of shared PaRams per group
 *  DMAN3_NUMTCC_GROUP      - Array containing # of shared Tccs per group
 *
 *  DMAN3_MAX_QDMA_CHANNELS - Total number of QDMA channels on hardware
 *  DMAN3_NUM_QDMA_CHANNELS - Number of QDMA channels for DMAN3 use.
 *  DMAN3_QDMA_QUEUE_MAP    - Array of QDMA channels for DMAN3 use.
 *  DMAN3_MAX_TCS           - Number of transfer controllers on hardware.
 *  DMAN3_QUEUE_TC_MAP      - Event queue to Transfer Controller map
 *  DMAN3_QUEUE_PRIORITIES  - Event queue priorities
 *
 *  See comments below for further description of these elements.
 *
 *  If USE_DMAN3 is set to 1, the app must also link in a DMAN3 library,
 *  otherwise, do not link a DMAN3 library with the app.
 */
#define USE_DMAN3 1


#if USE_DMAN3

/*
 * ======== ti.sdo.fc.dman3.DMAN3 Configuration ========
 */

#include <ti/sdo/fc/dman3/dman3.h>
#include <ti/sdo/fc/acpy3/acpy3.h>


/*
 */

/*
 *  ======== DMAN3_QDMA_PARAM_BASE ========
 *  Set to the physical base address for PARAM0 in the EDMA3/QDMA hardware.
 */
#define DMAN3_QDMA_PARAM_BASE  (Uns *)((Uns)0x01C00000 + 0x4000)

/*
 *  ======== DMAN3_MAX_PARAM_ENTRIES ========
 *  Total numbar of PaRam entries on the hardware (= 128 for IVA2).
 */
#define DMAN3_MAX_PARAM_ENTRIES 128

/*
 *  ======== DMAN3_PARAM_BASE_INDEX ========
 *  (0 <= value < DMAN3_MAX_PARAM_ENTRIES) represents the first PARAM TABLE
 *  ENTRY NUMBER to be assigned for exclusive DMAN3 allocation.
 */
#define DMAN3_PARAM_BASE_INDEX 96

/*
 *  ======== DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES ========
 *  The number of PARAM Table entries starting at DMAN3_PARAM_BASE_INDEX to
 *  be assigned for exclusive DMAN3 allocation.
 */
#define DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES  32

/*
 *  ======== DMAN3_TCC_FREEMASK_L,H ========
 *  These 32-bit bitmasks represent the list of TCCs for exclusive DMAN3 
 *  allocation.
 * 
 *  For TCC's in the range 0-31, DMAN3_TCC_FREEMASK_L (the low mask), is
 *  assigned a value with a '1' in bit position 'i' if TCC 'i' is to be
 *  for DMAN3 use.
 *  For TCC's in the range of 32-63, assign DMAN3_TCC_FREEMASK_H (the high
 *  mask) a value with a '1' in bit position 'i' if TCC '32 + i' is for
 *  DMAN3 use.
 */
#define DMAN3_TCC_FREEMASK_H  0xFFFFFFFF
#define DMAN3_TCC_FREEMASK_L  0x0 

/*
 *  ======== DMAN3_NULLPARAM ========
 *  Index of PARAM to be reserved as a "null" PaRam. This index will be
 *  used to set QCHMAP when the corresponding QDMA channel is not active.
 *  The value of DMAN3_NULLPARAM should be outside of the range of
 *  PaRam indices alloted to DMAN3, i.e., nullPaRamIndex should be less
 *  than paRamBaseIndex, or greater than paRamBaseIndex + numPaRamEntries.
 *  If PaRam registers are shared between two processors (eg, an Arm
 *  and a DSP), make sure the nullPaRamIndex is not used by the other
 *  processor.
 *
 *  WARNING: Make sure the value set to DMAN3_NULLPARAM is not used by any
 *  other application. Failure to do so may result in ACPY3_start() hanging.
 *  If PaRam 0 is used by another application, DMAN3_NULLPARAM could be set
 *  to 127 and DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES could be reduced by 1, so
 *  as not to include DMAN3_NULLPARAM as one of the PaRams allocated to DMAN3.
 *  For example,
 *
 *      #define DMAN3_NULLPARAM 127
 *      #define DMAN3_PARAM_BASE_INDEX 96
 *      #define DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES 31
 *  
 */
#define DMAN3_NULLPARAM 0

/*
 *  ======== DMAN3_MAX_QDMA_CHANNELS ========
 *  The total number of Physical QDMA channels available on the hardware.
 *
 */
#define DMAN3_MAX_QDMA_CHANNELS   8 

/*
 *  ======== DMAN3_NUM_QDMA_CHANNELS ========
 *  The number of Physical QDMA channels that are assigned to
 *  DMAN3 via configuration. These channels will be granted either 
 *  as scratch or persistently as part of IDMA3 handles.   
 */
#define DMAN3_NUM_QDMA_CHANNELS 4

/*
 *  ======== DMAN3_QDMA_CHANNELS ========
 *  Array containing the list of physical QDMA channels assigned to DMAN3.
 *
 *  This array is of size DMAN3_NUM_QDMA_CHANNELS
 *
 *  For example, to assign channels 2 and 3 to DMAN3, set the following:
 *
 *  #define DMAN3_NUM_QDMA_CHANNELS 2
 *  DMAN3_QDMA_CHANNELS[DMAN3_NUM_QDMA_CHANNELS] = {2, 3};
 */
__FAR__ Uns DMAN3_QDMA_CHANNELS[DMAN3_NUM_QDMA_CHANNELS] = {0, 1, 2, 3};

/*
 *  ======= DMAN3_QDMA_QUEUE_MAP ========
 *  Array contaning the mapping from QDMA Channels to Event Queues
 *
 *  Indicates mapping of all channels in DMAN3_QDMA_CHANNELS[] defined above
 *  to a particular Event Queue.  For example, DMAN3_QDMA_QUEUE_MAP[0]
 *  specifies queue number for DMAN3_QDMA_CHANNELS[0], etc.
 */
__FAR__ Uns DMAN3_QDMA_QUEUE_MAP[DMAN3_NUM_QDMA_CHANNELS] = {1, 1, 1, 1};

/*
 *  ======== DMAN3_MAX_TCS ========
 *  Number of transfer controllers on hardware
 */
#define DMAN3_MAX_TCS 8

/*
 *  ======= DMAN3_QUEUE_TC_MAP ========
 *  Array contaning the mapping from Event Queues to Transfer Controllers.
 *
 *  Indicates mapping of individual hardware Event Queues to the Transfer
 *  Controllers.
 */
__FAR__ Uns DMAN3_QUEUE_TC_MAP[DMAN3_MAX_TCS] = {0, 1, 2, 3, 4, 5, 6, 7};

/*
 *  ======= DMAN3_QUEUE_PRIORITIES ========
 *  Array contaning priorities of the event queues
 *
 *  Indicates the priority accorded to each physical event queue.
 */
__FAR__ Uns DMAN3_QUEUE_PRIORITIES[DMAN3_MAX_TCS] = {3, 7, 0, 0, 0, 0, 0, 0};

/*
 *  ======== DMAN3_MAXGROUPS ========
 *  Number of PaRam/Tcc scratch groups. Do not modify this value!
 */
#define DMAN3_MAXGROUPS 20

/*
 *  ======== DMAN3_NUMPARAM_GROUP ========
 *  Array containing the number of PaRam entries that will be assigned to
 *  groups for sharing. The ith entry is the number of PaRams that will be
 *  assigned to group number i.
 *
 *  Channels created with a given group ID will use TCCs and PaRams
 *  allocated for that group ID, and may share them with other channels
 *  created with the same group ID.
 *
 *  The default behavior when the value corresponding to group i is left
 *  as 0, is the following (DMAN3_ALLOWUNSHARED = TRUE):
 *  The fisrt channel created with group ID i, will determine the number of
 *  PaRams assigned to group i. If a second channel is created with group ID i,
 *  before the first channel is deleted, the second channel can share the
 *  PaRams with the first channel, as long as the second channel does not
 *  require more PaRams then the first channel. If the second channel needs
 *  more PaRams then the first channel, DMAN3 will attempt to assign it PaRams
 *  that cannot be shared by any other channel. Once all channels sharing
 *  PaRams for a given group ID are deleted, the number of PaRams assigned
 *  to the group is reset.
 *  This default behavior also applies if the value in DMAN3_NUMPARAM_GROUP
 *  for group i is less than the number of PaRams needed by the first channel
 *  created with group ID i. In that case, DMAN3 will bump up the number of
 *  PaRams for group i, to the number of PaRams needed by the channel.
 *
 *  The non-default behavior (DMAN3_ALLOWUNSHARED = FALSE) when the value
 *  in DMAN3_NUMPARAM_GROUP for group ID i is less than the number of PaRams
 *  required by a channel created with group ID i, is to fail creation of the
 *  channel. However, this non-default behavior is only available for
 *  C64P targets.
 *
 *  PaRams and Tccs may be shared among threads within the same process
 *  only! They cannot be shared across processes.
 */
#define DMAN3_NUMPARAM_GROUP {0, 0, 0, 0, 0, \
                              0, 0, 0, 0, 0, \
                              0, 0, 0, 0, 0, \
                              0, 0, 0, 0, 0}

/*
 *  ======== DMAN3_NUMTCC_GROUP ========
 *  Array containing the number of Tccs that will be assigned to groups
 *  for sharing.
 *
 *  Channels created with a given group ID will use TCCs and PaRams
 *  allocated for that group ID, and may share them with other channels
 *  created with the same group ID.
 *
 *  The same behavior as with DMAN3_NUMPARAM_GROUP applies, when values
 *  are less than the number of Tccs required by the first channel created
 *  with a given group ID. (See description of DMAN3_NUMPARAM_GROUP above).
 *
 *  PaRams and Tccs may be shared among threads within the same process
 *  only! They cannot be shared across processes.
 */
#define DMAN3_NUMTCC_GROUP {0, 0, 0, 0, 0, \
                            0, 0, 0, 0, 0, \
                            0, 0, 0, 0, 0, \
                            0, 0, 0, 0, 0}

/*
 *  Base key value for DMAN3 Linux IPC objects. The only reason for modifying
 *  this, is if the value is the same as the key of another Linux IPC object.
 */
UInt32 _DMAN3_ipcKeyBase = 0x4e414d44;

/*
 *  ===================================================
 *  None of the code below this line should be modified
 *  ===================================================
 */

/*
 *  ======== DMAN3_HEAP_INTERNAL ========
 *  DMAN3_HEAP_INTERNAL: BIOS Heap ID for dynamic allocation of DMAN3 objects 
 *  must be allocated in L1D Internal RAM.
 *  (Not used for Linux or WinCE).
 */
#define DMAN3_HEAP_INTERNAL  -1 

/*
 *  ======== DMAN3_HEAP_EXTERNAL ========
 *  DMAN3_HEAP_EXTERNAL: BIOS Heap ID for dyn allocation of private DMAN3
 *  data structures. 
 *  A value of -1 indicates that the heap is not defined.
 *  (Not used for Linux or WinCE).
 */
#define DMAN3_HEAP_EXTERNAL  0 

/*
 *  ======== DMAN3_IDMA3INTERNAL ========
 *  DMAN3_IDMA3INTERNAL: Use the internal DMAN3 memory heap to allocate IDMA3
 *  objects.
 *  Not used for Linux or WinCE.
 */
#define DMAN3_IDMA3INTERNAL  1

/*
 *  ======== DMAN3_ALLOWUNSHARED ========
 *  DMAN3_ALLOWUNSHARED: Allow more TCCs or PaRams to be allocated to a given
 *  scratch group than the number configured. Also allow allocation of unshared
 *  TCCs and PaRams to an algorithm, if the number currently allocated to the
 *  scratch group is less than requested by the algorithm.
 *
 *  Not used for Linux or WinCE.
 */
#define DMAN3_ALLOWUNSHARED  1


/*
 *  ======== DMAN3_PARAMS ========
 *  Default module configuration structure for DMAN3 implementation.
 *  It is set at design time by the system integrator to adjust the behaviour
 *  of the module to be optimal for its execution environment.
 */
DMAN3_Params DMAN3_PARAMS = {

    /* qdmaPaRamBase: Physical base address for PARAM0 */
    DMAN3_QDMA_PARAM_BASE,

    /* The maxPaRamEntries:  Total number of PARAM Table entries on the
     * hardware (eg, for IVA2 this is 128, for Himalaya, this is 256).
     */
    DMAN3_MAX_PARAM_ENTRIES,

    /*
     * paRamBaseIndex: (0>value>255) represents the first PARAM TABLE ENTRY
     * NUMBER that is assigned by configuration for exclusive DMAN3 allocation.
     */
    DMAN3_PARAM_BASE_INDEX,

    /*
     * numPaRamEntries:  number of PARAM Table entries starting at
     * DMAN3_PARAM_BASE_INDEX assigned by configuration for exclusive DMAN3
     * allocation.
     */
    DMAN3_NUM_CONTIGUOUS_PARAM_ENTRIES,


    /* maxQdmaChannels:  contains the total number of Physical QDMA channels
     * available on the hardware (eg, 8 for DaVinci, 4 for IVA2).
     */
    DMAN3_MAX_QDMA_CHANNELS,

    /*
     * numQdmaChannels: contains the number of Physical QDMA channels
     * that are assigned to DMAN3 via configuration.
     * qdmaChannels: array containing list of DMAN3_NUM_QDMA_CHANNELS
     * many Physical QDMA channels assigned to DMAN3 via configuration.
     */
    DMAN3_NUM_QDMA_CHANNELS,

    DMAN3_QDMA_CHANNELS,

    /*
     * tccAllocationMaskH and tccAllocationMaskL:  are 32-bit bitmasks
     * representing configuration provided list of TCCs for exclusive DMAN3
     * allocation.
     *
     * For example, for TCC's in the range 0-31 the Low Mask (tccAllocationMaskL)
     * is configured so that a '1' in bit position 'i' indicates the TCC 'i' is
     * assigned to DMAN3
     */
    DMAN3_TCC_FREEMASK_H,
    DMAN3_TCC_FREEMASK_L,

     /*
      * heapInternal: BIOS Heap ID for dynamic allocation of DMAN3 objects
      * must be allocated in L1D Internal RAM.
      * heapExternal: BIOS Heap ID for dyn allocation of private DMAN3
      * data structures.
      *
      * A value of -1 indicates that the heap is NOT DEFINED.
      */
    DMAN3_HEAP_INTERNAL,
    DMAN3_HEAP_EXTERNAL,

    /* numTccGroup[DMAN3_MAXGROUPS] */
    DMAN3_NUMTCC_GROUP,

    /* numPaRamGroup[DMAN3_MAXGROUPS] */
    DMAN3_NUMPARAM_GROUP,

    /* idma3Internal */
    DMAN3_IDMA3INTERNAL,

    /* scratchAllocFxn */
    NULL,

    /* scratchFreeFxn */
    NULL,

    /* nullPaRamIndex */
    DMAN3_NULLPARAM,

    /* maxTcs */
    DMAN3_MAX_TCS,

    DMAN3_QDMA_QUEUE_MAP,

    DMAN3_QUEUE_TC_MAP,

    DMAN3_QUEUE_PRIORITIES,

    /* allowUnshared */
    DMAN3_ALLOWUNSHARED,
};


/*
 *  ======== ti.sdo.fc.acpy3.ACPY3 ========
 *  Do not modify the following code
 */
#include <ti/sdo/fc/acpy3/acpy3_qdma_arm.h>
ACPY3_QDMA_Config ACPY3_QDMA; 
volatile ACPY3_QDMA_REG_Str *ACPY3_EDMA3BASE;
volatile UInt32 * ACPY3_QDMAPARAMBASE;  

extern UInt32 * _DMAN3_edma3Addr;
extern UInt32 _DMAN3_nullPaRam;

extern UInt32 * _DMAN3_paRamAddr;

/*
 *  ======== _ACPY3_qdmaInit ========
 *  Do not modify.
 */
Void _ACPY3_qdmaInit() 
{
    ACPY3_QDMA.nullPaRamIndex = _DMAN3_nullPaRam; 
    ACPY3_EDMA3BASE = (ACPY3_QDMA_REG_Str *)_DMAN3_edma3Addr;

    ACPY3_QDMAPARAMBASE = (UInt32 *)_DMAN3_paRamAddr;
}

/*
 *  ======== DMAN3_CE_init  ========
 */
Void DMAN3_CE_init()
{
    DMAN3_init();
    ACPY3_init();
}

/*
 *  ======== DMAN3_CE_exit  ========
 */
Void DMAN3_CE_exit()
{
    DMAN3_exit();
    ACPY3_exit();
}

extern Void  _DMAN3_initImpl(Void);

/*
 *  ======== DMAN3_init  ========
 */
Void DMAN3_init(Void)
{
    extern __FAR__ DMAN3_Params DMAN3_PARAMS;

    DMAN3_PARAMS.heapInternal = 0;
    DMAN3_PARAMS.heapExternal = 0;
    _DMAN3_initImpl();
}

#else
/*
 *  No IDMA3 using algs in the system, and DMAN3 is not configured into the
 *  system.  Stub out these fxn calls.
 */
Void DMAN3_CE_init()
{
}

Void DMAN3_CE_exit()
{
}

int DMAN3_grantDmaChannels(int groupId, void *algHandles, void *dmaFxns,
        int numAlgs)
{
    return (0);
}

int DMAN3_releaseDmaChannels(void *algHandles, void * dmaFxns, int numAlgs)
{
    return (0);
}

#endif
/*
 *  @(#) ti.sdo.ce.examples.apps.video1_copy; 1, 0, 0,261; 9-20-2010 16:40:24; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */

