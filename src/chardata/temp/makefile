#
# Makefile for Sonya
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make sonya.o:
######################################################################

TARGETS =		$(PATH_MAK)/sonyatxt.o $(PATH_MAK)/sonyadct.o

OBJECTS_TXT	=	mksonya.o mksonya1.o 
OBJECTS_DCT	=	mksondct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sonyatxt*.o:
######################################################################
$(PATH_MAK)/sonyatxt.o: $(OBJECTS_TXT) mksonya.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/sonyadct.o: $(OBJECTS_DCT) mksonya.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

