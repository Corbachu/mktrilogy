#
# Makefile for lao
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make lao.o:
######################################################################

TARGETS =		$(PATH_MAK)/laotxt.o $(PATH_MAK)/laodct.o

OBJECTS_TXT	=	mklao.o mklao1.o 
OBJECTS_DCT	=	mklaodct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make laotxt*.o:
######################################################################
$(PATH_MAK)/laotxt.o: $(OBJECTS_TXT) mklao.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/laodct.o: $(OBJECTS_DCT) mklao.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

