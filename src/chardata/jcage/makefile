#
# Makefile for subz
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make subz.o:
######################################################################

TARGETS =		$(PATH_MAK)/jcagetxt.o $(PATH_MAK)/jcagedct.o 

OBJECTS_TXT	=	mkjc.o mkjc1.o
OBJECTS_DCT	=	mkjcdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make jctxt*.o:
######################################################################
$(PATH_MAK)/jcagetxt.o: $(OBJECTS_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/jcagedct.o: $(OBJECTS_DCT) mkjc.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

