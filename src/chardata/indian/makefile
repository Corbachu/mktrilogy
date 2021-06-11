#
# Makefile for indian
#
# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make indian.o:
######################################################################

TARGETS =		$(PATH_MAK)/indianatxt.o $(PATH_MAK)/indianftxt.o $(PATH_MAK)/indiantxt.o $(PATH_MAK)/indiandct.o \
				$(PATH_MAK)/indianf2txt.o 

OBJECTS_TXT	=	mkind.o mkind1.o 
OBJECTS_DCT	=	mkinddct.o 
OBJECTS_TXTA = 	mkinda.o
OBJECTS_TXTF = 	mkindf.o
OBJECTSF2_TXT = 	mkindf2.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make indiantxt*.o:
######################################################################
$(PATH_MAK)/indiantxt.o: $(OBJECTS_TXT) mkind.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/indianatxt.o: $(OBJECTS_TXTA)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/indianftxt.o: $(OBJECTS_TXTF) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTF) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/indianf2txt.o: $(OBJECTSF2_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTSF2_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/indiandct.o: $(OBJECTS_DCT) mkind.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

mkind.o: mkind.atd
mkind1.o: mkind.att1
mkind2.o: mkind.att2
mkinddct.o: mkind.dct
