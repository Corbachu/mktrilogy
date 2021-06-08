#
# Makefile for mot
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make mot.o:
######################################################################

TARGETS =		$(PATH_MAK)/mottxt.o $(PATH_MAK)/motdct.o

OBJECTS_TXT     =       mkmot.o 
OBJECTS_DCT	=	mkmotdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make mottxt*.o:
######################################################################
$(PATH_MAK)/mottxt.o: $(OBJECTS_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/motdct.o: $(OBJECTS_DCT) mkmot.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

mkmot.o: mkmot.atd 

mkmot1.o: mkmot.att1
