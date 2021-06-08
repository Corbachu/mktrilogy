#
# Makefile for st
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make st.o:
######################################################################

TARGETS =		$(PATH_MAK)/sttxt.o $(PATH_MAK)/stdct.o $(PATH_MAK)/statxt.o

OBJECTS_TXT	=	mkst.o mkst1.o 
OBJECTS_TXTA =	mksta.o
OBJECTS_DCT	=	mkstdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sttxt*.o:
######################################################################
$(PATH_MAK)/sttxt.o: $(OBJECTS_TXT) mkst.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/statxt.o: $(OBJECTS_TXTA) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXTA) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/stdct.o: $(OBJECTS_DCT) mkst.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

