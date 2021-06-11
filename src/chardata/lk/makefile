#
# Makefile for lk
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make lk.o:
######################################################################

TARGETS =		$(PATH_MAK)/lktxt.o $(PATH_MAK)/lkdct.o

OBJECTS_TXT	=	mklk.o mklk1.o 
OBJECTS_DCT	=	mklkdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make lktxt*.o:
######################################################################
$(PATH_MAK)/lktxt.o: $(OBJECTS_TXT) mklk.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/lkdct.o: $(OBJECTS_DCT) mklk.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

mklk.o: mklk.atd
mklk1.o: mklk.att2
mklkdct.o: mklk.dct