#
# Makefile for lia
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make lia.o:
######################################################################

TARGETS =		$(PATH_MAK)/liatxt.o $(PATH_MAK)/liadct.o $(PATH_MAK)/liaatxt.o

OBJECTS_TXT	=	mklia.o mklia1.o 
OBJECTS_TXTA =	mkliaa.o 
OBJECTS_DCT	=	mkliadct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make liatxt*.o:
######################################################################
$(PATH_MAK)/liatxt.o: $(OBJECTS_TXT) mklia.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/liaatxt.o: $(OBJECTS_TXTA)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/liadct.o: $(OBJECTS_DCT) mklia.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

