#
# Makefile for kano
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make kano.o:
######################################################################

TARGETS =		$(PATH_MAK)/kanotxt.o $(PATH_MAK)/kanodct.o

OBJECTS_TXT     =       mkkano.o mkkano1.o
OBJECTS_DCT	=	mkkanodct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make kanotxt*.o:
######################################################################
$(PATH_MAK)/kanotxt.o: $(OBJECTS_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/kanodct.o: $(OBJECTS_DCT) mkkano.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

