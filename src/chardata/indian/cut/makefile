#
# Makefile for indian
#
# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make indian.o:
######################################################################

TARGETS =		$(PATH_MAK)/indian64txt.o $(PATH_MAK)/indian64dct.o 

OBJECTS_TXT	=	mkind64.o mkind641.o mkind642.o 
OBJECTS_DCT	=	mkind64dct.o 
OBJECTS_TXTA = 	mkinda.o
OBJECTS_TXTF = 	mkindf.o
OBJECTSF2_TXT = 	mkindf2.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make indiantxt*.o:
######################################################################
$(PATH_MAK)/indian64txt.o: $(OBJECTS_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

#$(PATH_MAK)/indianatxt.o: $(OBJECTS_TXTA)
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#
#$(PATH_MAK)/indianftxt.o: $(OBJECTS_TXTF) 
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTF) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#
#$(PATH_MAK)/indianf2txt.o: $(OBJECTSF2_TXT)
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTSF2_TXT) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
#
$(PATH_MAK)/indian64dct.o: $(OBJECTS_DCT) mkind64.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

mkind64.o: mkind64.atd
mkind641.o: mkind64.att1
mkind642.o: mkind64.att2
mkind64dct.o: mkind64.dct
