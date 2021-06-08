#
# Makefile for verse
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make verse.o:
######################################################################

TARGETS =		$(PATH_MAK)/versetxt.o 

OBJECTS_TXT 	=	artkano.o artindian.o artjax.o artlao.o artfninja.o artlia.o artlk.o \
					artmninja.o artrobo.o artshang.o artsg.o artsonya.o artswat.o \
					arttusk.o artvspal.o vsdummy.o artnu.o artjohn.o
#OBJECTS_COD		=	mkverse.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS)

include $(COMMONRULES)

######################################################################
# Make verse_*.o:
######################################################################
$(PATH_MAK)/versetxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

#$(PATH_MAK)/versecod.o: $(OBJECTS_COD)
#	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
#		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

