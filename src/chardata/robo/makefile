#
# Makefile for robo
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make robo.o:
######################################################################

TARGETS =		$(PATH_MAK)/robotxt.o $(PATH_MAK)/robodct.o \
				$(PATH_MAK)/robo1atxt.o $(PATH_MAK)/robo3atxt.o	$(PATH_MAK)/r1f1txt.o $(PATH_MAK)/r1f2txt.o  \
				$(PATH_MAK)/r2f1txt.o $(PATH_MAK)/r2f2txt.o $(PATH_MAK)/r3f1txt.o $(PATH_MAK)/r3f2txt.o \
				$(PATH_MAK)/roboftxt.o $(PATH_MAK)/robo2atxt.o

OBJECTS_TXT	=	mkrobo.o mkrobo1.o 
OBJECTS_DCT	=	mkrobodct.o 
OBJECTS_R1ATXT = 	mkrobo1a.o
OBJECTS_R2ATXT = 	mkrobo2a.o
OBJECTS_R1F1TXT = 	mkr1f1.o
OBJECTS_R1F2TXT = 	mkr1f2.o
OBJECTS_R2F1TXT = 	mkr2f1.o
OBJECTS_R2F2TXT = 	mkr2f2.o
OBJECTS_R3F1TXT = 	mkr3f1.o
OBJECTS_R3F2TXT = 	mkr3f2.o
OBJECTS_R3ATXT = 	mkrobo3a.o
OBJECTS_RFTXT = 	mkrobof.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make robotxt*.o:
######################################################################
$(PATH_MAK)/robotxt.o: $(OBJECTS_TXT) mkrobo.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/robodct.o: $(OBJECTS_DCT) mkrobo.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/robo1atxt.o: $(OBJECTS_R1ATXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R1ATXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r1f1txt.o: $(OBJECTS_R1F1TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R1F1TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r1f2txt.o: $(OBJECTS_R1F2TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R1F2TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r2f1txt.o: $(OBJECTS_R2F1TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R2F1TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r2f2txt.o: $(OBJECTS_R2F2TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R2F2TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r3f1txt.o: $(OBJECTS_R3F1TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R3F1TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/r3f2txt.o: $(OBJECTS_R3F2TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R3F2TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/robo3atxt.o: $(OBJECTS_R3ATXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R3ATXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/robo2atxt.o: $(OBJECTS_R2ATXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_R2ATXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/roboftxt.o: $(OBJECTS_RFTXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_RFTXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
