#
# Makefile for subz
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make subz.o:
######################################################################

TARGETS =		$(PATH_MAK)/subztxt.o $(PATH_MAK)/subzdct.o $(PATH_MAK)/subzatxt.o

OBJECTS_TXT	=	mksz.o mksz1.o mksz2.o
OBJECTS_TXTA	=	mksza.o
OBJECTS_DCT	=	mkszdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sztxt*.o:
######################################################################
$(PATH_MAK)/subztxt.o: $(OBJECTS_TXT) mksz.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/subzatxt.o: $(OBJECTS_TXTA)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/subzdct.o: $(OBJECTS_DCT) mksz.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

