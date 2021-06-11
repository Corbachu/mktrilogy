#
# Makefile for sa
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make sa.o:
######################################################################

TARGETS =		$(PATH_MAK)/satxt.o $(PATH_MAK)/sadct.o

OBJECTS_TXT	=	mksa.o mksa1.o 
OBJECTS_DCT	=	mksadct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make satxt*.o:
######################################################################
$(PATH_MAK)/satxt.o: $(OBJECTS_TXT) mksa.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/sadct.o: $(OBJECTS_DCT) mksa.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

