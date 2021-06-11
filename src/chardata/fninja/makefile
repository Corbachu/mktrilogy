#
# Makefile for fn
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make fn.o:
######################################################################

TARGETS =		$(PATH_MAK)/fntxt.o $(PATH_MAK)/fndct.o \
				$(PATH_MAK)/fnftxt.o $(PATH_MAK)/fnmlf1txt.o

OBJECTS_TXT	=	mkfn.o mkfn1.o 
OBJECTS_DCT	=	mkfndct.o 
OBJECTSF_TXT	=	mkfnf.o
OBJECTSMLF1_TXT	=	mkmlf1.o 
OBJECTSJDF1_TXT	=	mkjdf1.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make fntxt*.o:
######################################################################
$(PATH_MAK)/fntxt.o: $(OBJECTS_TXT) mkfn.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/fnftxt.o: $(OBJECTSF_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTSF_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/fnmlf1txt.o: $(OBJECTSMLF1_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTSMLF1_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/fnjdf1txt.o: $(OBJECTSJDF1_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTSJDF1_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/fndct.o: $(OBJECTS_DCT) mkfn.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

