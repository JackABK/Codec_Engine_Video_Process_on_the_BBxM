#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,6.1,14
#
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.s62 package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asm64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -qq -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14   $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fr=./package/cfg/bin/ti_platforms_evm3530 -fa $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530 -s o64P $< -C  -qq -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14   $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P: app.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530/app_local -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/cfg/bin/ti_platforms_evm3530/app_local/app.s64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/app.s64P: app.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530/app_local -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/app.s64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local/app.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P: main_BIOS.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530/app_local -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.s64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.s64P: main_BIOS.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530/app_local -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530/app_local -fr=./package/cfg/bin/ti_platforms_evm3530/app_local
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.s64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530 -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530 -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.s64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.s64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530 -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530 -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.s64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64P.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mo --no_compress -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530 -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530 -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mo --no_compress -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/cfg/bin/ti_platforms_evm3530/app_local_x64P.s64P: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.s64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64P.c package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530 -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/bin/ti_platforms_evm3530 -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/audio_copy/package/cfg/bin/ti_platforms_evm3530/app_local_x64P.h'  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2 -DBUFALIGN=128 -DCACHE_ENABLED  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/cfg/bin/ti_platforms_evm3530 -fr=./package/cfg/bin/ti_platforms_evm3530
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.s64P:C_DIR=
package/cfg/bin/ti_platforms_evm3530/app_local_x64P.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P ::
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/app.s64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.s64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.s64P
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64P.s64P

bin/ti_platforms_evm3530/app_local.x64P: package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg.o64P package/cfg/bin/ti_platforms_evm3530/app_local/app.o64P package/cfg/bin/ti_platforms_evm3530/app_local/main_BIOS.o64P package/cfg/bin/ti_platforms_evm3530/app_local_x64Pcfg_c.o64P package/cfg/bin/ti_platforms_evm3530/app_local_x64P.o64P package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak

clean::
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_x64P.mak
