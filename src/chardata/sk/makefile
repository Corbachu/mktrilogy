#
# Makefile for sk
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make sk.o:
######################################################################

TARGETS =		$(PATH_MAK)/sktxt.o $(PATH_MAK)/skdct.o $(PATH_MAK)/skdietxt.o

OBJECTS_TXT	=	mksk.o 
OBJECTS_TXTD	=	mkskdie.o 
OBJECTS_DCT	=	mkskdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sktxt*.o:
######################################################################
$(PATH_MAK)/sktxt.o: $(OBJECTS_TXT) mksk.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/skdietxt.o: $(OBJECTS_TXTD) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/skdct.o: $(OBJECTS_DCT) mksk.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

