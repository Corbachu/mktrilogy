#
# Makefile for swat
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make swat.o:
######################################################################

TARGETS =		$(PATH_MAK)/swattxt.o $(PATH_MAK)/swatdct.o

OBJECTS_TXT	=	mkswat.o mkswat1.o 
OBJECTS_DCT	=	mkswatdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make swattxt*.o:
######################################################################
$(PATH_MAK)/swattxt.o: $(OBJECTS_TXT) mkswat.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/swatdct.o: $(OBJECTS_DCT) mkswat.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

