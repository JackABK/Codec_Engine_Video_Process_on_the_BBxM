/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-u17
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     MODULE INCLUDES
 *     
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *     
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */



/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path to program's assembly directory
 */
xdc__META(__ASM__, "@(#)__ASM__ = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 64P");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.platforms.evm3530");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.C64P");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.cof.Coff");


/*
 * ======== ti.sdo.ce.ipc.Settings TEMPLATE ========
 */


/*
 * ======== ti.sdo.ce.osal.Global TEMPLATE ========
 */



/*
 *  ======== Global Configuration ========
 *  Do not modify the following; it is automatically generated from the template
 *  Server.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */

Bool Memory_skipVirtualAddressTranslation = FALSE;


/* List of all packages and their versions and paths, for diagnostics */
String Global_buildInfo[] = {
    "    package ti.xdais.dm.examples.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/auddec_copy/) [2, 0, 0]",
    "    package ti.xdais (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/) [1, 2.0, 1]",
    "    package ti.sdo.fc.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/global/) [1, 0, 0]",
    "    package ti.sdo.utils.trace (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/utils/trace/) [1, 0, 0]",
    "    package ti.rtdx (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/rtdx/) [2, 0, 0, 5]",
    "    package ti.psl (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/psl/) [5, 0, 0, 0]",
    "    package ti.pmi (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/pmi/) [1, 0, 0, 0]",
    "    package ti.pscl (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/pscl/) [1, 0, 0, 0]",
    "    package ti.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/bios/) [5, 2, 5, 28]",
    "    package ti.sdo.fc.dskt2 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/dskt2/) [1, 0, 4]",
    "    package ti.sdo.ce.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/global/) [1, 0, 0]",
    "    package ti.xdais.dm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/dm/) [1, 0, 5]",
    "    package ti.sdo.ce.utils.xdm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/utils/xdm/) [1, 0, 2]",
    "    package ti.sdo.ce.node (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/node/) [1, 0, 0]",
    "    package ti.sdo.fc.dman3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/dman3/) [1, 0, 4]",
    "    package ti.sdo.fc.memutils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/memutils/) [1, 0, 0]",
    "    package ti.sdo.fc.acpy3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/acpy3/) [1, 0, 4]",
    "    package ti.bios.utils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/biosutils_1_02_02/packages/ti/bios/utils/) [2, 0, 2, 02]",
    "    package ti.catalog.c6000 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/c6000/) [1, 0, 0, 0]",
    "    package ti.catalog (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/) [1, 0, 0]",
    "    package ti.catalog.arm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/arm/) [1, 0, 1, 0]",
    "    package ti.platforms.evm3530 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/platforms/evm3530/) [1, 0, 0]",
    "    package ti.sdo.ce.osal (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/) [2, 0, 2]",
    "    package ti.sdo.ce.osal.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/bios/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/bios/) [2, 0, 1]",
    "    package ti.sdo.ce.alg (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/alg/) [1, 0, 1]",
    "    package ti.sdo.ce (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/) [1, 0, 6]",
    "    package ti.sdo.ce.audio (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/audio/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.audenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/audenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.apps.audio_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/apps/audio_copy/) [1, 0, 0]",
    NULL
};

/*
 * ======== ti.sdo.ce.Engine TEMPLATE ========
 */

/*
 *  ======== Engine Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  Engine.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
#include <ti/sdo/ce/Engine.h>
#include <ti/xdais/ialg.h>

#include <ti/xdais/idma3.h>

#include <ti/xdais/ires.h>

/* type tables for algorithms */
extern IALG_Fxns AUDENCCOPY_TI_AUDENCCOPY;
static String typeTab_AUDENCCOPY_TI_AUDENCCOPY[] = {
    "ti.sdo.ce.audio.IAUDENC",
    NULL
};

extern IALG_Fxns AUDDECCOPY_TI_IAUDDECCOPY;
static String typeTab_AUDDECCOPY_TI_IAUDDECCOPY[] = {
    "ti.sdo.ce.audio.IAUDDEC",
    NULL
};


/* tables of engine algorithms */
extern IALG_Fxns AUDDECCOPY_TI_IAUDDECCOPY;
extern IALG_Fxns AUDENCCOPY_TI_AUDENCCOPY;

/* algorithm-specific stub/skeleton config data objects */

static Engine_AlgDesc engineAlgs0[] = {
    {
        "auddec_copy",       /* name */
        {2922333659U},   /* uuid */
        &AUDDECCOPY_TI_IAUDDECCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDDECCOPY_TI_IAUDDECCOPY,              /* typeTab */
        TRUE,          /* isLocal */
        0,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio.IAUDDEC",
    },
    {
        "audenc_copy",       /* name */
        {2937237973U},   /* uuid */
        &AUDENCCOPY_TI_AUDENCCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDENCCOPY_TI_AUDENCCOPY,              /* typeTab */
        TRUE,          /* isLocal */
        1,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio.IAUDENC",
    },
    {NULL},
};
static Engine_AlgDesc engineAlgs1[] = {
    {NULL},
};

/* table of all engines available in this application */
static Engine_Desc engineTab[] = {
    {"audio_copy",	/* engine name */
      engineAlgs0,	/* alg table */
      NULL,		/* (optional) server name */
      NULL,        /* (optional) Link config ID */
      2 /* number of algs in alg table */
    },
    {"local",	/* engine name */
      engineAlgs1,	/* alg table */
      NULL,		/* (optional) server name */
      NULL,        /* (optional) Link config ID */
      0 /* number of algs in alg table */
    },
    {NULL, NULL, NULL, 0}	/* NULL-terminate the engine table */
};

Engine_Config Engine_config = {
    engineTab,		    /* table of all engines */
    "local"   /* local RMS engine name */
};

Bool ti_sdo_ce_Engine_noCommName = FALSE;

/*
 * ======== ti.sdo.ce.CERuntime TEMPLATE ========
 */


#include <ti/sdo/ce/osal/Global.h>
#include <ti/sdo/ce/ipc/Comm.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/osal/Queue.h>
#include <ti/sdo/ce/osal/Sem.h>
#include <ti/sdo/ce/osal/SemMP.h>
#include <ti/sdo/ce/osal/Thread.h>
#include <ti/sdo/ce/ipc/Processor.h>
#include <ti/sdo/ce/alg/Algorithm.h>
#include <ti/sdo/ce/osal/Lock.h>
#include <ti/sdo/ce/osal/LockMP.h>
#include <ti/sdo/ce/Server.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/rms.h>
#include <ti/sdo/ce/utils/xdm/XdmUtils.h>

#include <ti/sdo/utils/trace/gt.h>

/* This symbol is referenced by Server_init() */
Int Global_useLinkArbiter = FALSE;

/*
 *  ======== CERuntime_init ========
 */
Void CERuntime_init(Void)
{

    GT_init();



    /* allow user to over-ride via CE_TRACE. */
    GT_set(Global_getenv("CE_TRACE"));
    Global_init();

    Sem_init();
    SemMP_init();


    Memory_init();
    Queue_init();
    Comm_init();
    Thread_init();
    Processor_init();
    LockMP_init();  /* Must be called before DMAN3_init() */
    Algorithm_init();
    XdmUtils_init();
    Lock_init();

    Engine_init();
    Server_init();

}

/*
 *  ======== CERuntime_exit ========
 */
Void CERuntime_exit(Void)
{
    Global_exit();
}

/* for backward compatibility with xdc-m based tools */
Void ti_sdo_ce_CERuntime_init__F(Void) {
    CERuntime_init();
}

/*
 * ======== ti.sdo.ce.Settings TEMPLATE ========
 */

/*
 *  ======== ti.sdo.ce Settings Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  Settings.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
Bool VISA_checked = FALSE;

/*
 * ======== ti.sdo.fc.dskt2.DSKT2 TEMPLATE ========
 */

/* C code contribution from ti/sdo/fc/DSKT2.xdt */

#include <xdc/std.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

extern Void BCACHE_wbInv();

DSKT2_CacheWBInvFxn DSKT2_cacheWBInvFxn = (DSKT2_CacheWBInvFxn)BCACHE_wbInv;

Uns _DSKT2_ALLOW_EXTERNAL_SCRATCH = 1;

#if 20 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in DARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

#if 20 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in SARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

Uns _DSKT2_DARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

Uns _DSKT2_SARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};


/*
 * ======== ti.sdo.fc.global.Settings TEMPLATE ========
 */

Bool ti_sdo_fc_multiProcess = TRUE;

/*
 * ======== ti.sdo.utils.trace.GT TEMPLATE ========
 */




/*
 * C code contribution from ti/sdo/utils/GT.xdt 
 */
#include <xdc/std.h>
#include <ti/sdo/utils/trace/gt.h>

extern Void GTConfig_sysPrintf(String fmt, ...); 
extern Ptr GTConfig_biosMemAlloc(Int size);
 
extern Int GTConfig_tskId(void);
extern void GTConfig_sysPrintfError(String fmt, ...);
extern void GTConfig_biosMemFree(Ptr, Int);
extern UInt32 GTConfig_getTime(void);
extern Int GTConfig_semPend(void);
extern Int GTConfig_semPost(void);
extern Int GTConfig_biosInit(void);

GT_Config _ti_sdo_utils_trace_GT_params = {
    GTConfig_sysPrintf,
    NULL,
    GTConfig_tskId,
    GTConfig_sysPrintfError,
    GTConfig_biosMemAlloc,
    GTConfig_biosMemFree,
    GTConfig_getTime,
    GTConfig_semPend,
    GTConfig_semPost,
    GTConfig_biosInit    
};

GT_Config *GT = &_ti_sdo_utils_trace_GT_params;

/*
 * ======== ti.sdo.ce.ipc.bios.Ipc TEMPLATE ========
 */


/* IPC_generatedInit() function, called by CERuntime_init() */
Void IPC_generatedInit()
{
}





/* MSGQ and POOL configuration on the DSP when DSPLINK is NOT used */

#include <ti/bios/include/std.h>
#include <ti/bios/include/msgq.h>
#include <ti/bios/include/pool.h>
#include <ti/bios/include/staticpool.h>

#define Global_NUMPROC         1
#define Global_NUMALLOCATORS   1
#define Global_NUMMSGQUEUES    64
#define Global_NUMMSGPOOLS     1

#define Global_MSGSIZE         1024
#define Global_POOLBUFSIZE     (64 * Global_MSGSIZE)

static MSGQ_TransportObj Global_transports[Global_NUMPROC] =
{
     MSGQ_NOTRANSPORT,    /* Represents the local processor */
};

static MSGQ_Obj Global_msgQueues[Global_NUMMSGQUEUES] ;

MSGQ_Config MSGQ_config = {
    Global_msgQueues,
    Global_transports,
    Global_NUMMSGQUEUES,
    Global_NUMPROC,
    0,
    MSGQ_INVALIDMSGQ,
    POOL_INVALIDID
};

static Char Global_poolBuf[Global_POOLBUFSIZE];

static STATICPOOL_Params Global_poolParams = {
    Global_poolBuf,
    sizeof (Global_poolBuf),
    Global_MSGSIZE,
};
static STATICPOOL_Obj Global_poolObj;

static POOL_Obj Global_pools[Global_NUMALLOCATORS] =
{
    {
        STATICPOOL_init,                /* Init Function */
        (POOL_Fxns *)&STATICPOOL_FXNS,  /* Pool interface functions */
        &Global_poolParams,             /* Pool params */
        &Global_poolObj                 /* Pool object: init'd in pool impl. */
    }
};

POOL_Config POOL_config = {
    Global_pools,
    Global_NUMALLOCATORS
};


/*
 * ======== ti.sdo.ce.alg.Settings TEMPLATE ========
 */

unsigned int ti_sdo_ce_alg_ALG_useHeap = FALSE;
unsigned int ti_sdo_ce_alg_ALG_useCache = FALSE;

unsigned int ti_sdo_ce_alg_ALG_maxGroups = 20; 

UInt32 ti_sdo_ce_alg_ipcKey = 0x4f474c41;

int _ALG_groupUsed[20] = {
     1,
     1,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
};

#include <ti/sdo/ce/osal/SemMP.h>
#include <ti/xdais/ialg.h>

SemMP_Handle _ALG_sems[20];
int _ALG_groupRefCount[20] = {
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
};

IALG_Handle _Algorithm_lockOwner[20] = {
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
};

// No IDMA3 using algs in the system, and DMAN3 is not configured into the
// system.  Stub out these fxn calls.
Void DMAN3_CE_init()
{
}
Void DMAN3_CE_exit()
{
}

int DMAN3_grantDmaChannels(int groupId, void *algHandles, void *dmaFxns,
        int numAlgs)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (0);
}

int DMAN3_releaseDmaChannels(void *algHandles, void * dmaFxns, int numAlgs)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (0);
}

// No IRES using algs in the system, and RMAN is not configured into the
// system.  Stub out these fxn calls.
#include <ti/xdais/ires.h>   /* for IRES types */

IRES_Status RMAN_activateAllResources(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_assignResources(IALG_Handle algHandle, IRES_Fxns *resFxns, 
        Int scratchGroupId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_deactivateAllResources(IALG_Handle algHandle, 
        IRES_Fxns * resFxns, Int scratchId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_freeResources(IALG_Handle algHandle, IRES_Fxns * resFxns, 
        Int scratchGroupId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_init(void)
{
    return (IRES_OK);
}

IRES_Status RMAN_exit(void)
{
    return (IRES_OK);
}




/*
 * ======== ti.sdo.ce.osal.bios.Settings TEMPLATE ========
 */


/*
 * ======== Socrates logging configuration ========
 */
#include <ti/sdo/ce/osal/Log.h>
#include <ti/bios/include/log.h>

extern far LOG_Obj ti_sdo_ce_osal_LOG_Buffer;
far Log_Handle ti_sdo_ce_dvtLog = (Log_Handle)&ti_sdo_ce_osal_LOG_Buffer;


/* Number of BIOS heaps */
Int Memory_numHeaps = 2;

/* Array containing the names of the BIOS heaps. */
String Memory_heapNames[2];

/*
 *  These arrays will contain the original base address and size of each heap.
 */
Uint32 Memory_heapBases[2];
Uint32 Memory_heapSizes[2];

/*
 *  BIOS heap segments.
 */
extern Int DDR2;
extern Int L1DSRAM;

/*
 *  ======== ti_sdo_ce_osal_bios_init ========
 *  Generated init function for BIOS OSAL.
 */
Void ti_sdo_ce_osal_bios_init()
{
    Memory_heapNames[DDR2] = "DDR2";
    Memory_heapNames[L1DSRAM] = "L1DSRAM";
}

/*
 *  Definition of the globally visible character buffer holding all trace
 *  data
 */
Char Global_traceBuffer[32768];
Int  Global_traceBufferSize = 32768;


/*
 * ======== PROGRAM GLOBALS ========
 */


/*
 * ======== CLINK DIRECTIVES ========
 */

#ifdef __ti__
#define PRAGMA(x) _Pragma(#x)
#define xdc__clink_constant(var) \
PRAGMA(DATA_SECTION(var, ".const:" #var))  \
asm("   .sect \".const:" #var "\"\n"  \
  "   .clink\n"  \
  "   .sect \"[0].const:" #var "\"\n"  \
  "   .clink\n"  \
  "   .sect \"[1].const:" #var "\"\n"  \
  "   .clink")

#endif

