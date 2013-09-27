#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.GCArmv5T{1,0,4.3,2
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T.dep
endif

package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T: | .interfaces
package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T: package/package_ti.sdo.ce.examples.codecs.sphenc_copy.c lib/sphenc_copy.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c  -fPIC -Wunused  -Wall -fno-strict-aliasing   -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv    -march=armv5t -Dfar=  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T:LD_LIBRARY_PATH=

package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.sv5T: | .interfaces
package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.sv5T: package/package_ti.sdo.ce.examples.codecs.sphenc_copy.c lib/sphenc_copy.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c -S -fPIC -Wunused  -Wall -fno-strict-aliasing   -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv    -march=armv5t -Dfar=  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.sv5T:LD_LIBRARY_PATH=

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/sphenc_copy/sphenc_copy.ov5T.dep
endif

package/lib/lib/sphenc_copy/sphenc_copy.ov5T: | .interfaces
package/lib/lib/sphenc_copy/sphenc_copy.ov5T: sphenc_copy.c lib/sphenc_copy.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c  -fPIC -Wunused  -Wall -fno-strict-aliasing   -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv    -march=armv5t -Dfar=  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sphenc_copy/sphenc_copy.ov5T:LD_LIBRARY_PATH=

package/lib/lib/sphenc_copy/sphenc_copy.sv5T: | .interfaces
package/lib/lib/sphenc_copy/sphenc_copy.sv5T: sphenc_copy.c lib/sphenc_copy.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c -S -fPIC -Wunused  -Wall -fno-strict-aliasing   -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv    -march=armv5t -Dfar=  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sphenc_copy/sphenc_copy.sv5T:LD_LIBRARY_PATH=

clean,v5T ::
	-$(RM) package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T
	-$(RM) package/lib/lib/sphenc_copy/sphenc_copy.ov5T
	-$(RM) package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.sv5T
	-$(RM) package/lib/lib/sphenc_copy/sphenc_copy.sv5T

lib/sphenc_copy.av5T: package/lib/lib/sphenc_copy/package/package_ti.sdo.ce.examples.codecs.sphenc_copy.ov5T package/lib/lib/sphenc_copy/sphenc_copy.ov5T lib/sphenc_copy.av5T.mak

clean::
	-$(RM) lib/sphenc_copy.av5T.mak
