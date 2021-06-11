#
# Makefile for sheeva
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make sheeva.o:
######################################################################

TARGETS =		$(PATH_MAK)/sheevatxt.o $(PATH_MAK)/sheevadct.o

OBJECTS_TXT	=	mksg.o mksg1.o 
OBJECTS_DCT	=	mksgdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sheevatxt*.o:
######################################################################
$(PATH_MAK)/sheevatxt.o: $(OBJECTS_TXT) mksg.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/sheevadct.o: $(OBJECTS_DCT) mksg.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

