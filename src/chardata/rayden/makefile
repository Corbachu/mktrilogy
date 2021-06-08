#
# Makefile for rd
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make rd.o:
######################################################################

TARGETS =		$(PATH_MAK)/rdtxt.o $(PATH_MAK)/rddct.o

OBJECTS_TXT	=	mkrd.o mkrd1.o 
OBJECTS_DCT	=	mkrddct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make rdtxt*.o:
######################################################################
$(PATH_MAK)/rdtxt.o: $(OBJECTS_TXT) mkrd.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/rddct.o: $(OBJECTS_DCT) mkrd.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

# DO NOT DELETE THIS LINE -- make depend uses it
# DO NOT DELETE THIS 2nd LINE -- make depend uses it
