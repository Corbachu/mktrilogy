cmake_minimum_required(VERSION 3.0)
project(MortalKombat3Trilogy LANGUAGES C Assembly)

set(PROJECT_VERSION 1.0)
set(PROJECT_DESCRIPTION "Mortal Kombat 3 Trilogy source port written in C and
Assembly")

include(GNUInstallDirs)
include(FindPkgConfig)

set(ROMFILE rom)
set(EMFILE mktrilogy)
set(SPECFILE spec)

#U64LIBNAME =		ultra_d
set(U64LIBNAME ultra_rom)

set(PATH_APP)
set(PATH_INC $(PATH_APP)/seg/gamecode)
set(PATH_SEG $(PATH_APP)/seg)
set(PATH_MAK $(PATH_APP)/make)
set(PATH_BIN $(PATH_APP)/bin)
set(PATH_BKGD $(PATH_SEG)/bkgds)
set(PATH_CHARS $(PATH_SEG)/chardata)
set(PATH_ATTRACT $(PATH_SEG)/attract)
set(PATH_COMMON $(PATH_SEG)/common)

###############################################################################
# N64 build opts
#set(PATH_PRINC $(ROOT)/usr/include/PR)
#set(PATH_PRLIB $(ROOT)/usr/lib/PR)
#set(PATH_LIB $(ROOT)/usr/lib)
#U64LIBFULL = $(PATH_LIB)/lib$(U64LIBNAME).a
#set(LCOPTS -c -g3 -O2 -mips2 -fullwarn -prototypes -Xcpluscomm -Wab,-r4300_mul -non_shared -G 0 -woff 813,819,826,827,835,852,712,822,825,665
#-wlint,-f 
#set(LCINCS -I$(PATH_PRINC) -I$(PATH_INC))
#set(LDFLAGS -r -g -nostdlib)
#set(AROPTS rc)
#set(ASFLAGS -Wab,-r4300_mul -non_shared -g -I$(PATH_PRINC) -I$(PATH_INC))
#set(MRFLAGS -m -o -s96 -f0x00)
#set(MRFLAGS -m -o -C 60850000)

################################################################################
set(PATH_SEG seg)
set(PATH_BKGD bkgd)
set(PATH_CHARS chars)
set(PATH_ATTRACT attract)
set(PATH_COMMON common)

set(ROMFILE rom)
set(EMFILE mktrilogy)
set(SPECFILE spec)

set(TARGETS $(ROMFILE) $(EMFILE)

set(OBJECTS seggamecode.o)

default:	$(TARGETS) 


set($(TARGETS): 
	$(SPECFILE) $(MAKEROM) $(OBJECTS)
	set(CFB_SOURCES $(PATH_SEG)/cfb)
	set(DSTACK_SOURCES $(PATH_SEG)/dstack)
	set(PHEAP_SOURCES $(PATH_SEG)/pheap)
	set(ARMORY_SOURCES $(PATH_BKGD)/armory)
	set(BATTLE_SOURCES $(PATH_BKGD)/battle)
	set(BELL_SOURCES $(PATH_BKGD)/bell)
	set(BRIDGE_SOURCES $(PATH_BKGD)/bridge)
	set(CAVE_SOURCES $(PATH_BKGD)/cave)
	set(DEAD_SOURCES $(PATH_BKGD)/dead)
	set(DESERT_SOURCES $(PATH_BKGD)/desert)
	set(GRAVE_SOURCES $(PATH_BKGD)/grave)
	set(HPORT_SOURCES $(PATH_BKGD)/hport)
	set(LOST_SOURCES $(PATH_BKGD)/lost)
	set(MK2PIT_SOURCES $(PATH_BKGD)/mk2pit)
	set(MONKS_SOURCES $(PATH_BKGD)/monks)
	set(PIT_SOURCES $(PATH_BKGD)/pit)
	set(SBST_SOURCES $(PATH_BKGD)/sbst)
	set(SOUL_SOURCES $(PATH_BKGD)/soul)
	set(TEMPLE_SOURCES $(PATH_BKGD)/temple)
	set(TOWER_SOURCES $(PATH_BKGD)/tower)
	set(CITY_SOURCES $(PATH_BKGD)/city)
	set(TREE_SOURCES $(PATH_BKGD)/tree)
	set(WATER_SOURCES $(PATH_BKGD)/water)
	set(KUNGFU2_SOURCES $(PATH_BKGD)/kungfu2)
	set(KUNGFU5_SOURCES $(PATH_BKGD)/kungfu5)
	set(SONYA_SOURCES $(PATH_CHARS)/sonya)
	set(ROBO_SOURCES $(PATH_CHARS)/robo)
	set(TUSK_SOURCES $(PATH_CHARS)/tusk)
	set(JCAGE_SOURCES $(PATH_CHARS)/jcage)
	set(SWAT_SOURCES $(PATH_CHARS)/swat)
	set(SHEEVA_SOURCES $(PATH_CHARS)/sheeva)
	set(BARAKA_SOURCES $(PATH_CHARS)/baraka)
	set(RAYDEN_SOURCES $(PATH_CHARS)/rayden)
	set(SK_SOURCES $(PATH_CHARS)/sk)
	set(SHANG_SOURCES $(PATH_CHARS)/shang)
	set(MOTARO_SOURCES $(PATH_CHARS)/motaro)
	set(LK_SOURCES $(PATH_CHARS)/lk)
	set(FNINJA_SOURCES $(PATH_CHARS)/fninja)
	set(MNINJA_SOURCES $(PATH_CHARS)/mninja)
	set(LIA_SOURCES $(PATH_CHARS)/lia)
	set(LAO_SOURCES $(PATH_CHARS)/lao)
	set(KANO_SOURCES $(PATH_CHARS)/kano)
	set(JAX_SOURCES $(PATH_CHARS)/jax)
	set(INDIAN_SOURCES $(PATH_CHARS)/indian)
	set(BUYIN_SOURCES $(PATH_ATTRACT)/buyin)
	set(GRADIENT_SOURCES $(PATH_ATTRACT)/gradient)
	set(OPTIONS_SOURCES $(PATH_ATTRACT)/options)
	set(SELECT_SOURCES $(PATH_ATTRACT)/select)
	set(STEELVS_SOURCES $(PATH_ATTRACT)/steelvs)
	set(TOURN_SOURCES $(PATH_ATTRACT)/tourn)
	set(KRONICLE_SOURCES $(PATH_ATTRACT)/kronicle)
	set(VS_SOURCES $(PATH_ATTRACT)/vs)
	set(ANIMAL_SOURCES $(PATH_COMMON)/animal)
	set(BABY_SOURCES $(PATH_COMMON)/baby)
	set(FRIEND_SOURCES $(PATH_COMMON)/friend)
	set(FATAL_SOURCES $(PATH_COMMON)/fatal)
	set(FIGHT_SOURCES $(PATH_COMMON)/fight)
	set(BRUTAL_SOURCES $(PATH_COMMON)/brutal)
	set(FINHER_SOURCES $(PATH_COMMON)/finher)
	set(FINHIM_SOURCES $(PATH_COMMON)/finhim)
	set(MERCY_SOURCES $(PATH_COMMON)/mercy)
	set(MUGS_SOURCES $(PATH_COMMON)/mugs)
	set(STORM_SOURCES $(PATH_COMMON)/storm)
	set(STORM_SOURCES $(PATH_COMMON)/skelfire)
	set(RIPSKEL_SOURCES $(PATH_COMMON)/ripskel)
	set(TOP_SOURCES $(PATH_COMMON)/top)
	set(LOGO_SOURCES $(PATH_COMMON)/logo)

#######
# 
#######
$(MAKEROM) $(MRFLAGS) -r $(ROMFILE) $(SPECFILE) >mapfile
set(seggamecode.o $(PATH_SEG)/gamecode)

# MortalKombat3Trilogy game
add_executable( ${PROJECT_NAME} SHARED ${SOURCE_FILES} ${INCLUDE_FILES} )
target_compile_options( ${PROJECT_NAME} PUBLIC )
target_include_directories(${PROJECT_NAME} PUBLIC 
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
			)
target_link_libraries( ${PROJECT_NAME} PUBLIC ${CRC_LIBRARIES} )

set(install_prefix "${CMAKE_INSTALL_PREFIX}")
set(install_libdir "${CMAKE_INSTALL_LIBDIR}")
set(install_includedir "${CMAKE_INSTALL_INCLUDEDIR}")

configure_file(lib${PROJECT_NAME}.pc.in ${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc @ONLY)

set(ENV{PKG_CONFIG_PATH} "${PROJECT_BINARY_DIR}:$ENV{PKG_CONFIG_PATH}")

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION
	${CMAKE_INSTALL_INCLUDEDIR}/lib${PROJECT_NAME}
	)

install(FILES ${INCLUDE_FILES} DESTINATION
	${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/)

