#
# Makefile for nj
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make nj.o:
######################################################################

TARGETS =		$(PATH_MAK)/nj64txt.o $(PATH_MAK)/nj64dct.o 
#				$(PATH_MAK)/njatxt.o $(PATH_MAK)/njftxt.o  $(PATH_MAK)/njftxt.o \
#				$(PATH_MAK)/njscf1txt.o $(PATH_MAK)/njscf2txt.o $(PATH_MAK)/njrpf2txt.o $(PATH_MAK)/njrpf1txt.o 

OBJECTS_TXT	=	mknj64.o mknj641.o 
OBJECTSA_TXT	=	mknja.o
OBJECTSF_TXT	=	mknjf.o
OBJECTSSCF1_TXT	=	mknjscf1.o
OBJECTSSCF2_TXT	=	mknjscf2.o
OBJECTSRPF1_TXT	=	mknjrpf1.o
OBJECTSRPF2_TXT	=	mknjrpf2.o
OBJECTS_DCT	=	mknj64dct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make njtxt*.o:
######################################################################
$(PATH_MAK)/nj64txt.o: $(OBJECTS_TXT) mknj64.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

#$(PATH_MAK)/njatxt.o: $(OBJECTSA_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSA_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#		
#$(PATH_MAK)/njftxt.o: $(OBJECTSF_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSF_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#		
#$(PATH_MAK)/njscf1txt.o: $(OBJECTSSCF1_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSSCF1_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#
#$(PATH_MAK)/njscf2txt.o: $(OBJECTSSCF2_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSSCF2_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#
#$(PATH_MAK)/njrpf2txt.o: $(OBJECTSRPF2_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSRPF2_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#		
#$(PATH_MAK)/njrpf1txt.o: $(OBJECTSRPF1_TXT) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSRPF1_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#		
$(PATH_MAK)/nj64dct.o: $(OBJECTS_DCT) mknj64.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

