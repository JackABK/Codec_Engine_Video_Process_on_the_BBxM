#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,6.1,14
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P.dep
endif

package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P: | .interfaces
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P: package/package_ti.sdo.ce.examples.codecs.imgdec_copy.c lib/imgdec_copy.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy/package -fr=./package/lib/lib/imgdec_copy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/imgdec_copy/package -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy/package -fr=./package/lib/lib/imgdec_copy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P:C_DIR=
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.s64P: | .interfaces
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.s64P: package/package_ti.sdo.ce.examples.codecs.imgdec_copy.c lib/imgdec_copy.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy/package -fr=./package/lib/lib/imgdec_copy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/imgdec_copy/package -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy/package -fr=./package/lib/lib/imgdec_copy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.s64P:C_DIR=
package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/imgdec_copy/imgdec_copy.o64P.dep
endif

package/lib/lib/imgdec_copy/imgdec_copy.o64P: | .interfaces
package/lib/lib/imgdec_copy/imgdec_copy.o64P: imgdec_copy.c lib/imgdec_copy.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy -fr=./package/lib/lib/imgdec_copy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/imgdec_copy -s o64P $< -C   -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy -fr=./package/lib/lib/imgdec_copy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/imgdec_copy/imgdec_copy.o64P:C_DIR=
package/lib/lib/imgdec_copy/imgdec_copy.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/imgdec_copy/imgdec_copy.s64P: | .interfaces
package/lib/lib/imgdec_copy/imgdec_copy.s64P: imgdec_copy.c lib/imgdec_copy.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy -fr=./package/lib/lib/imgdec_copy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/imgdec_copy -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -pden -pds=195  -mv64p -eo.o64P -ea.s64P  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_6_1_14 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/imgdec_copy -fr=./package/lib/lib/imgdec_copy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/imgdec_copy/imgdec_copy.s64P:C_DIR=
package/lib/lib/imgdec_copy/imgdec_copy.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P ::
	-$(RM) package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P
	-$(RM) package/lib/lib/imgdec_copy/imgdec_copy.o64P
	-$(RM) package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.s64P
	-$(RM) package/lib/lib/imgdec_copy/imgdec_copy.s64P

lib/imgdec_copy.a64P: package/lib/lib/imgdec_copy/package/package_ti.sdo.ce.examples.codecs.imgdec_copy.o64P package/lib/lib/imgdec_copy/imgdec_copy.o64P lib/imgdec_copy.a64P.mak

clean::
	-$(RM) lib/imgdec_copy.a64P.mak
