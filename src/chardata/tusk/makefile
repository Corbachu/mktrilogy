#
# Makefile for Tusk
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make Tusk.o:
######################################################################

TARGETS =		$(PATH_MAK)/tusktxt.o $(PATH_MAK)/tuskdct.o \
				$(PATH_MAK)/tuskatxt.o $(PATH_MAK)/tuskf2txt.o

OBJECTS_TXT	=	mktusk.o mktusk1.o 
OBJECTS_DCT	=	mktuskdct.o 
OBJECTS_TXTA	=	mktuska.o 
OBJECTS_TXTF2	=	mktuskf2.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make tusktxt*.o:
######################################################################
$(PATH_MAK)/tusktxt.o: $(OBJECTS_TXT) mktusk.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tuskatxt.o: $(OBJECTS_TXTA)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tuskf2txt.o: $(OBJECTS_TXTF2) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTF2) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tuskdct.o: $(OBJECTS_DCT) mktusk.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

