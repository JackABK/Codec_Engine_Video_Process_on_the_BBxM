#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/../../../../../..;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/local-power-manager_1_24_02_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linuxutils_2_25_05_11/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/biosutils_1_02_02/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/local-power-manager_1_24_02_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/edma3lld_01_11_00_03/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dsplink_1_65_00_02
override XDCROOT = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36
override XDCBUILDCFG = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/../../../../../../config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = DEVICES="OMAP3530" PROGRAMS="APP_CLIENT DSP_SERVER APP_LOCAL" GPPOS="LINUX_GCC LINUX_UCLIBC WINCE" CGTOOLS_V5T=/home/jack/new/arm/4.3.2 CC_V5T=bin/arm-none-linux-gnueabi-g++ CGTOOLS_C64P=/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/cgt6x_6_1_14 CGTOOLS_C674=/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/cgt6x_6_1_14 XDCOPTIONS=v
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/../../../../../..;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/local-power-manager_1_24_02_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linuxutils_2_25_05_11/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/biosutils_1_02_02/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/local-power-manager_1_24_02_09/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/edma3lld_01_11_00_03/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dsplink_1_65_00_02;/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages;../../../../../..
HOSTOS = Linux
endif
