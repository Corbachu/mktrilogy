#include <regdef.h>
#include "mkbkgd.inc"
#include "mkchar.inc"

	.option pic0

	.set noreorder
	
	.data

/*
;******************************************************************************
; File: mktextdt.s
;
; By: David Schwartz
;
; Date: Dec 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Text Data
;******************************************************************************
*/

	
	.extern	bpal_flash4_P	
	.extern	bpal_flash5_P	
	.extern	bpal_flash6_P	
	.extern	bpal_flash7_P	

/*
;
; KEEP PALETTE FROM BEING NTSC CORRECTED, MAKES THIS LOOK UGLY IF IT IS
;
*/
	.align 2
	.globl YELLOW_p
YELLOW_p:
	.word	16
	.half 0x0000, 0x0001, 0x8401, 0x8C41, 0x9481, 0xA501, 0xAD41, 0xB581, 0xBDC1, 0xC601
	.half 0xCE41, 0xD681, 0xE701, 0xEF41, 0xF781, 0xFFC1

/*
;*************************************************
;mkguys text, mkguys.c
;*************************************************
*/
	.align 2
	.globl	pf_credit_mode
pf_credit_mode:
	.half	FONT15,1,160-8,45+0x4e
	.word  WHITE_p
	.half	STRCNRMOS,0
	.asciiz	"KREDITS %d"

	.align 2
	.globl	txt_2_on_2
txt_2_on_2:
	.asciiz	"TWO ON TWO\nKOMBAT"

	.align 2
	.globl	txt_3_on_3
txt_3_on_3:
	.asciiz	"THREE ON THREE\nKOMBAT"

	.align 2
	.globl	txt_p1_ic
txt_p1_ic:
	.asciiz	"PLAYER 1\nJOIN IN"

	.align 2
	.globl	txt_p1_ps
txt_p1_ps:
	.asciiz	"PLAYER 1\nPLAYS FREE"

	.align 2
	.globl	txt_p2_ic
txt_p2_ic:
	.asciiz	"PLAYER 2\nJOIN IN"

	.align 2
	.globl	txt_p2_ps
txt_p2_ps:
	.asciiz	"PLAYER 2\nPLAYS FREE"

/* ;SK treasures */
	.align 2
	.globl	txt_pick1
txt_pick1:
	.ascii	"YOU HAVE DISCOVERED THE LOST TREASURES\n"
	.ascii	"OF SHAO KAHN\n"
	.asciiz	"CHOOSE YOUR REWARD WISELY!"
 
/*
;*************************************************
;bio text, mkbio.c
;*************************************************
*/
	.align 2
	.globl	pf_bio
pf_bio:
	.half	FONT7,0xffff,122-8,14
	.word  WHITE_p
	.half	STRRNRMO_SCR,0
	.byte	0

	.align 2
	.globl	txt_kitana_bio
txt_kitana_bio:
	.asciiz "KITANA\n"
	.asciiz "KITANA IS ACCUSED OF\n"
	.asciiz "TREASON BY THE HIGH\n"
	.asciiz "COURTS OF THE OUTWORLD\n"
	.asciiz "AFTER MURDERING HER EVIL\n"
	.asciiz "TWIN MILEENA. SHAO KAHN\n"
	.asciiz "APPOINTS A GROUP OF\n"
	.asciiz "WARRIORS SPECIFICALLY TO\n"
	.asciiz "CATCH HIS DAUGHTER AND\n"
	.asciiz "BRING HER BACK ALIVE. BUT\n"
	.asciiz "KITANA MUST FIND A WAY TO\n"
	.asciiz "REACH THE NEWLY CROWNED\n"
	.asciiz "QUEEN SINDEL FIRST AND\n"
	.asciiz	"WARN HER OF THEIR TRUE\n"
	.asciiz "PAST.\n"
	.byte	-1

	.align 2
	.globl	txt_jade_bio
txt_jade_bio:
	.asciiz "JADE\n"
	.asciiz "WHEN THE RENEGADE\n"
	.asciiz "PRINCESS KITANA MAKES\n"
	.asciiz "HER ESCAPE INTO THE\n"
	.asciiz "UNKNOWN REGIONS OF\n"
	.asciiz	"EARTH, JADE IS APPOINTED\n"
	.asciiz "BY SHAO KAHN TO BRING\n"
	.asciiz "HER BACK ALIVE. ONCE A\n"
	.asciiz "CLOSE FRIEND OF THE\n"
	.asciiz "PRINCESS, SHE IS FACED\n"
	.asciiz "WITH THE CHOICE OF\n"
	.asciiz	"BETRAYING HER FRIEND\n"
	.asciiz "OR DISOBEYING HER\n"
	.asciiz	"EMPEROR.\n"
	.byte	-1

	.align 2
	.globl	txt_scorpion_bio
txt_scorpion_bio:
	.asciiz "SCORPION\n"
	.asciiz "WHEN SHAO KAHN MAKES\n"
	.asciiz "A FAILED ATTEMPT AT\n"
	.asciiz "STEALING THE SOULS\n"
	.asciiz "WHICH OCCUPY EARTH'S\n"
	.asciiz "HELL, SCORPION IS ABLE\n"
	.asciiz "TO ESCAPE FROM THE\n"
	.asciiz "NETHER REGION. FREE TO\n"
	.asciiz "ROAM THE EARTH ONCE\n"
	.asciiz "MORE, SCORPION HOLDS\n"
	.asciiz "ALLEGIANCE WITH NO\n"
	.asciiz "ONE. HE'S A WILD CARD\n"
	.asciiz	"IN EARTH'S STRUGGLE\n"
	.asciiz	"AGAINST THE OUTWORLD.\n"
	.byte	-1

	.align 2
	.globl	txt_reptile_bio
txt_reptile_bio:
	.asciiz "REPTILE\n"
	.asciiz "ALWAYS A RELIABLE\n"
	.asciiz "SERVANT TO SHAO KAHN,\n"
	.asciiz "REPTILE IS CHOSEN TO\n"
	.asciiz "ASSIST JADE IN THE\n"
	.asciiz "CAPTURE OF KITANA. IN\n"
	.asciiz "CONTRAST TO JADE'S\n"
	.asciiz "INSTRUCTIONS, REPTILE\n"
	.asciiz	"IS ORDERED TO STOP THE\n"
	.asciiz "RENEGADE PRINCESS AT\n"
	.asciiz	"ALL COSTS...\n\n"
	.asciiz	"EVEN IF IT MEANS HER\n"
	.asciiz	"DEATH."
	.byte	-1
	
	.align 2
	.globl txt_kano_bio
txt_kano_bio:
	.asciiz "KANO\n"
	.asciiz "KANO IS THOUGHT TO HAVE\n"
	.asciiz "BEEN KILLED IN THE FIRST\n"
	.asciiz "TOURNAMENT. INSTEAD, HE'S\n"
	.asciiz "FOUND ALIVE IN THE OUT-\n"
	.asciiz "WORLD WHERE HE ONCE AGAIN\n"
	.asciiz "ESCAPES CAPTURE BY SONYA.\n"
	.asciiz "BEFORE THE ACTUAL OUT-\n"
	.asciiz "WORLD INVASION, KANO\n"
	.asciiz "CONVINCES SHAO KAHN TO\n"
	.asciiz "SPARE HIS SOUL. KAHN\n"
	.asciiz "NEEDS SOMEONE TO TEACH\n"
	.asciiz "HIS WARRIORS HOW TO USE\n"
	.asciiz "EARTH'S WEAPONS. KANO IS\n"
	.asciiz "THE MAN TO DO IT.\n"
	.byte	-1

	.align 2
	.globl txt_sonya_bio
txt_sonya_bio:
	.asciiz "LT. SONYA BLADE\n"
	.asciiz "SONYA DISAPPEARED AFTER\n"
	.asciiz "THE FIRST TOURNAMENT BUT\n"
	.asciiz "WAS LATER RESCUED FROM\n"
	.asciiz "THE OUTWORLD BY JAX.\n"
	.asciiz "AFTER RETURNING TO EARTH,\n"
	.asciiz "SHE AND JAX TRY TO WARN\n"
	.asciiz "THE U.S. GOVERNMENT OF\n"
	.asciiz "THE LOOMING OUTWORLD\n"
	.asciiz "MENACE. LACKING PROOF,\n"
	.asciiz "THEY WATCH HELPLESSLY\n"
	.asciiz "AS SHAO KAHN BEGINS HIS\n"
	.asciiz "INVASION."
	.byte	-1

	.align 2
	.globl txt_jax_bio
txt_jax_bio:
	.asciiz "MAJ. JAX BRIGGS\n"
	.asciiz "AFTER FAILING TO CONVINCE\n"
	.asciiz "HIS SUPERIORS OF THE\n"
	.asciiz "COMING OUTWORLD MENACE,\n"
	.asciiz "JAX BEGINS TO COVERTLY\n"
	.asciiz "PREPARE FOR FUTURE BATTLE\n"
	.asciiz "WITH KAHN'S MINIONS. HE\n"
	.asciiz "OUTFITS BOTH ARMS WITH \n"
	.asciiz "INDESTRUCTIBLE BIONIC\n"
	.asciiz "IMPLANTS. THIS IS A WAR\n"
	.asciiz "JAX IS PREPARED TO WIN.\n"
	.byte	-1

	.align 2
	.globl txt_ind_bio
txt_ind_bio:
	.asciiz "NIGHTWOLF\n"
	.asciiz "WORKS AS A HISTORIAN AND\n"
	.asciiz "PRESERVER OF HIS PEOPLE'S\n"
	.asciiz "CULTURE. WHEN KAHN'S\n"
	.asciiz "PORTAL OPENS OVER NORTH\n"
	.asciiz "AMERICA, NIGHTWOLF USES\n"
	.asciiz "THE MAGICS OF HIS SHAMEN\n"
	.asciiz "TO PROTECT HIS TRIBE'S\n"
	.asciiz "SACRED LAND. THIS AREA\n"
	.asciiz "BECOMES A VITAL THREAT TO\n"
	.asciiz "KAHN'S OCCUPATION OF THE\n"
	.asciiz "EARTH.\n"
	.byte	-1

	.align 2
	.globl txt_jc_bio
txt_jc_bio:
	.asciiz "JOHNNY CAGE\n"
	.asciiz "KILLED IN BATTLE WITH AN\n"
	.asciiz "OUTWORLD EXTERMINATION\n"
	.asciiz "SQUAD, JOHNNY CAGE'S LIFE\n" 
	.asciiz "CAME TO A TRAGIC END. BUT\n" 
	.asciiz "THE CELLUOID SUPERSTAR\n" 
	.asciiz "MANAGES TO CHEAT DEATH\n" 
	.asciiz "WHEN HIS PATH TO THE AFTER\n"
	.asciiz "LIFE IS BLOCKED BY THE MERG-\n" 
	.asciiz "ER OF EARTH AND THE OUT-\n"
	.asciiz "WORLD.  HIS SOUL TAKES\n"
	.asciiz "POSSESSION OF ITS BODY ONCE\n" 
	.asciiz "AGAIN AND ENABLES CAGE TO\n" 
	.asciiz "REJOIN HIS FRIENDS TO\n" 
	.asciiz "BATTLE FOR EARTH'S SURVIVAL.\n"
	.byte	-1

	.align 2
	.globl txt_swat_bio
txt_swat_bio:
	.asciiz "STRYKER\n"
	.asciiz "WHEN THE OUTWORLD PORTAL\n"
	.asciiz "OPENS OVER A LARGE CITY IN\n"
	.asciiz "NORTH AMERICA, PANIC AND\n"
	.asciiz "CHAOS RAGE OUT OF CONTROL.\n"
	.asciiz "KURTIS STRYKER WAS THE\n"
	.asciiz "LEADER OF A RIOT CONTROL\n"
	.asciiz "BRIGADE WHEN SHAO KAHN\n"
	.asciiz "BEGAN TAKING SOULS. HE\n"
	.asciiz "FINDS HIMSELF THE LONE\n"
	.asciiz "SURVIVOR OF A CITY ONCE\n"
	.asciiz "POPULATED BY MILLIONS.\n"
	.byte	-1

	.align 2
	.globl txt_sektor_bio
txt_sektor_bio:
	.asciiz "SEKTOR\n"
	.asciiz "SEKTOR IS ACTUALLY THE\n"
	.asciiz "CODE NAME FOR UNIT LK-9T9.\n"
	.asciiz "HE WAS THE FIRST OF THREE\n"
	.asciiz "PROTOTYPE CYBERNETIC\n"
	.asciiz "NINJAS BUILT BY THE LIN\n"
	.asciiz "KUEI. SEKTOR WAS ONCE A\n"
	.asciiz "HUMAN ASSASSIN TRAINED BY\n"
	.asciiz "THE LIN KUEI. HE VOLUN-\n"
	.asciiz "TEERED FOR AUTOMATION BE-\n"
	.asciiz "CAUSE OF HIS LOYALTY FOR\n"
	.asciiz "THE CLAN. SEKTOR SURVIVES\n"
	.asciiz "THE OUTWORLD INVASION - HE\n"
	.asciiz "HAS NO SOUL TO TAKE.\n"
	.byte	-1

	.align 2
	.globl txt_cyrax_bio
txt_cyrax_bio:
	.asciiz "CYRAX\n"
	.asciiz "CYRAX IS UNIT LK-4D4.\n"
	.asciiz "THE 2ND OF THREE PROTO-\n"
	.asciiz "TYPE CYBERNETIC NINJAS\n"
	.asciiz "BUILT BY THE LIN KUEI.\n"
	.asciiz "LIKE HIS COUNTERPARTS\n"
	.asciiz "HIS LAST PROGRAMMED COM-\n"
	.asciiz "MAND IS TO FIND AND TER-\n"
	.asciiz "MINATE THE ROGUE NINJA,\n"
	.asciiz "SUB-ZERO. WITHOUT A SOUL,\n"
	.asciiz "CYRAX GOES UNDETECTED BY\n"
	.asciiz "SHAO KAHN AND REMAINS A\n"
	.asciiz "POSSIBLE THREAT AGAINST\n"
	.asciiz "HIS OCCUPATION OF EARTH.\n"
	.byte	-1

	.align 2
	.globl txt_lao_bio
txt_lao_bio:
	.asciiz "KUNG LAO\n" 
	.asciiz "KUNG LAO'S PLAN TO REFORM\n"
	.asciiz "THE WHITE LOTUS SOCIETY\n"
	.asciiz "COMES TO A HALT WHEN SHAO\n"
	.asciiz "KAHN'S INVASION TAKES THE\n"
	.asciiz "EARTH BY STORM. AS A\n"
	.asciiz "CHOSEN WARRIOR, KUNG LAO\n"
	.asciiz "MUST USE HIS GREATEST\n"
	.asciiz "FIGHTING SKILLS TO BRING\n"
	.asciiz "DOWN SHAO KAHN'S REIGN\n"
	.asciiz "OF TERROR.\n"
	.byte	-1

	.align 2
	.globl txt_kabal_bio
txt_kabal_bio:
	.asciiz "KABAL\n"
	.asciiz "AS A CHOSEN WARRIOR, HIS\n"
	.asciiz "IDENTITY IS A MYSTERY TO\n"
	.asciiz "ALL. IT'S BELIEVED THAT\n"
	.asciiz "HE IS THE SURVIVOR OF AN\n"
	.asciiz "ATTACK BY SHAO KAHN'S EX-\n"
	.asciiz "TERMINATION SQUADS. AS A\n"
	.asciiz "RESULT, HE IS VICIOUSLY\n"
	.asciiz "SCARRED AND KEPT ALIVE\n"
	.asciiz "ONLY BY ARTIFICIAL RESPIR-\n"
	.asciiz "ATORS AND A RAGE FOR END-\n"
	.asciiz "ING SHAO KAHN'S CONQUEST.\n"
	.byte	-1

	.align 2
	.globl txt_sg_bio
txt_sg_bio:
	.asciiz "SHEEVA\n"
	.asciiz "SHE WAS HAND PICKED BY\n"
	.asciiz "SHAO KAHN TO SERVE AS \n"
	.asciiz "SINDEL'S PERSONAL\n"
	.asciiz "PROTECTOR. SHE BECOMES\n"
	.asciiz "SUSPICIOUS OF SHAO KAHN'S\n"
	.asciiz "LOYALTY TOWARDS HER RACE\n"
	.asciiz "OF SHOKAN WHEN HE PLACES\n"
	.asciiz "MOTARO AS THE LEADER OF\n"
	.asciiz "HIS EXTERMINATION SQUADS.\n"
	.asciiz "ON THE OUTWORLD, MOTARO'S\n"
	.asciiz "RACE OF CENTAURIANS ARE\n"
	.asciiz "THE NATURAL ENEMY OF\n"
	.asciiz "SHOKAN.\n"
	.byte	-1

	.align 2
	.globl txt_st_bio
txt_st_bio:
	.asciiz "SHANG TSUNG\n"
	.asciiz "TSUNG IS SHAO KAHN'S LEAD\n"
	.asciiz "SORCEROR. HE ONCE FELL\n"
	.asciiz "OUT OF FAVOR WITH HIS\n"
	.asciiz "EMPEROR AFTER FAILING TO\n"
	.asciiz "WIN THE EARTH REALM\n"
	.asciiz "THROUGH TOURNAMENT BATTLE.\n"
 	.asciiz "BUT THE EVER SCHEMING\n"
 	.asciiz "SHANG TSUNG IS INSTRUMENT-\n"
 	.asciiz "AL IN KAHN'S CONQUEST OF\n"
 	.asciiz "EARTH HE HAS NOW BEEN\n"
 	.asciiz "GRANTED MORE POWER THAN\n"
	.asciiz "EVER.\n"
	.byte	-1

	.align 2
	.globl txt_lk_bio
txt_lk_bio:
	.asciiz "LIU KANG\n"
	.asciiz "AFTER THE OUTWORLD\n"
	.asciiz "INVASION, LIU KANG FINDS\n"
	.asciiz "HIMSELF THE PRIME TARGET\n"
	.asciiz "OF KAHN'S EXTERMINATION\n"
	.asciiz "SQUADS. HE IS THE SHAOLIN\n"
	.asciiz "CHAMPION AND HAS THWATED\n"
	.asciiz "KAHN'S SCHEMES IN THE\n"
	.asciiz "PAST. OF ALL THE HUMANS,\n"
	.asciiz "KANG POSES THE GREATEST\n"
	.asciiz "THREAT TO SHAO KAHN'S\n"
	.asciiz "RULE.\n"
	.byte	-1

	.align 2
	.globl txt_sindel_bio
txt_sindel_bio:
	.asciiz "SINDEL\n"
	.asciiz "SHE ONCE RULED THE OUT-\n"
	.asciiz "WORLD AT SHAO KAHN'S SIDE\n"
	.asciiz "AS HIS QUEEN. NOW 10,000\n"
	.asciiz "YEARS AFTER HER UNTIMELY\n"
	.asciiz "DEATH, SHE IS REBORN ON\n"
	.asciiz "EARTH. HER EVIL INTENT IS\n"
	.asciiz "EVERY MATCH FOR SHAO\n"
	.asciiz "KAHN'S TYRANNY. SHE IS\n"
	.asciiz "THE KEY TO HIS OCCUPATION\n"
	.asciiz "OF EARTH.\n"
	.byte	-1
	
	.align 2
	.globl txt_smoke_bio
txt_smoke_bio:
	.asciiz "SMOKE\n"
	.asciiz "FINDS HIMSELF BROUGHT BACK AS\n"	
	.asciiz "ONE OF THE LIN KUEI'S MOST\n" 
	.asciiz "DANGEROUS ASSASSINS, SMOKE\n" 
	.asciiz "FALLS VICTIM TO THEIR\n" 
	.asciiz "AUTOMATION PROCESS. HE'S\n" 
	.asciiz "TRANSFORMED INTO A CYBER-\n"
	.asciiz "NETIC NINJA AGAINST HIS\n" 
	.asciiz "WILL. HIS NEW MISSION IS\n" 
	.asciiz "TO FIND AND ASSASSINATE\n" 
	.asciiz "HIS FORMER FRIEND AND ALLY,\n" 
	.asciiz "SUB-ZERO.\n"
	.byte	-1
	
	.align 2
	.globl txt_mileena_bio
txt_mileena_bio:
	.asciiz "MILEENA\n"
	.asciiz "MURDERED BY HER TWIN\n" 
	.asciiz "SISTER KITANA, MILEENA\n" 
	.asciiz "FINDS HERSELF BROUGHT BACK\n" 
	.asciiz "TO LIFE BY SHAO KAHN HIM-\n"
	.asciiz "SELF. HER SKILLS AS A\n" 
	.asciiz "VICIOUS FIGHTER WILL BE\n" 
	.asciiz "NEEDED TO DEFEAT EARTH'S\n" 
	.asciiz "CHOSEN WARRIORS. HER\n" 
	.asciiz "ABILITY TO READ THE\n" 
	.asciiz "THOUGHTS OF HER TWIN\n" 
	.asciiz "SISTER WILL ENABLE KAHN\n" 
	.asciiz "TO STAY ONE STEP AHEAD\n"
	.asciiz "OF THEM."
	.byte	-1
	
	.align 2
	.globl txt_ermac_bio
txt_ermac_bio:
	.asciiz "ERMAC\n"
	.asciiz "AN ENIGMA TO ALL WHO\n"
	.asciiz "COME INTO CONTACT WITH\n"
	.asciiz "HIM, ERMAC'S PAST RE-\n"
	.asciiz "MAINS SHROUDED IN\n"
	.asciiz "MYSTERY. IT'S BELIEVED\n"
	.asciiz "THAT HE EXISTS AS A\n"
	.asciiz "LIFE FORCE BROUGHT TO-\n"
	.asciiz "GETHER BY THE SOULS OF\n"
	.asciiz "EXTINGUISHED OUTWORLD\n"
	.asciiz "WARRIORS. SHAO KAHN HAS\n"
	.asciiz "MANAGED TO TAKE POSS-\n" 
	.asciiz "ESSION OF THESE SOULS AND\n" 
	.asciiz "USE THEM TO FIGHT ON THE\n"
	.asciiz "SIDE OF TYRANNY.\n"
	.byte	-1

	
	.align 2
	.globl txt_oldsz_bio
txt_oldsz_bio:
	.asciiz "SUBZERO\n"
	.asciiz "HE WAS BETRAYED\n"
	.asciiz "BY HIS OWN NINJA CLAN-\n"
	.asciiz "THE LIN KUEI. HE BROKE\n"
	.asciiz "SACRED CODES OF HONOR BY\n"
	.asciiz "LEAVING THE CLAN AND IS\n"
	.asciiz "MARKED FOR DEATH. BUT UN-\n"
	.asciiz "LIKE THE NINJA OF OLD, HIS\n"
	.asciiz "PURSUERS COME AS MACHINES.\n"
	.asciiz "HE MUST NOT ONLY DEFEND\n"
	.asciiz "AGAINST THE OUTWORLD MEN-\n"
	.asciiz "ACE BUT MUST ALSO ELUDE\n"
	.asciiz	"HIS SOULLESS ASSASSINS.\n"
	.byte	-1
	
	
	.align 2
	.globl txt_oldsmoke_bio
txt_oldsmoke_bio:
	.asciiz "HUMAN SMOKE\n"
	.asciiz "IN HIS HUMAN FORM, SMOKE\n" 
	.asciiz "WAS A LETHAL ASSASSIN\n" 
	.asciiz "WORKING FOR THE LIN KUEI.\n" 
	.asciiz "BUT WHEN THEY DECIDE TO\n" 
	.asciiz "AUTOMATE THEIR NINJAS,\n" 
	.asciiz "SMOKE IS CAUGHT IN THE\n" 
	.asciiz "MIDDLE. HE BECOMES A\n" 
	.asciiz "CYBORG ASSASSIN. FROM THAT\n"
	.asciiz "DAY FORWARD, HIS HUMAN\n" 
	.asciiz "FORM WOULD EXIST AS ONLY A\n" 
	.asciiz "MEMORY.\n" 
	.byte	-1
	
	
	.align 2
	.globl txt_noob_bio
txt_noob_bio:
	.asciiz "NOOB SAIBOT\n"
	.asciiz "NOOB SAIBOT EMERGES FROM\n"
	.asciiz "THE DARKEST REGION OF\n"
	.asciiz "REALITY; A REGION KNOWN\n"
	.asciiz "AS THE NETHEREALM. HE\n"
	.asciiz "BELONGS TO A GROUP CALLED\n"
	.asciiz "THE BROTHERS OF THE\n"
	.asciiz "SHADOW, AND WORSHIPS AN\n"
	.asciiz "EVIL AND MYSTERIOUS FALLEN\n"
	.asciiz "ELDER GOD. HIS MISSION IS\n"
	.asciiz "TO SPY ON THE EVENTS\n"
	.asciiz "TAKING PLACE IN THE BATTLE\n"
	.asciiz "BETWEEN THE REALMS, AND\n"
	.asciiz "REPORT BACK TO HIS\n"
	.asciiz "ENIGMATIC LEADERS.\n"
	.byte	-1
	
	.align 2
	.globl txt_rain_bio
txt_rain_bio:
	.asciiz "RAIN\n"
	.asciiz "BORN IN KITANA'S FORMER\n"
	.asciiz "WORLD OF EDENIA, RAIN\n"
	.asciiz "WAS SMUGGLED AWAY FROM\n" 
	.asciiz "THE REALM AS A SMALL\n" 
	.asciiz "CHILD SHORTLY AFTER SHAO\n"
	.asciiz "KAHN'S TAKE OVER. THOU-\n"
	.asciiz "SANDS OF YEARS LATER HE\n" 
	.asciiz "RESURFACED, HIS ALLEGIANCE\n"
	.asciiz "BELONGING TO KAHN. HE\n"
	.asciiz "CHOSE TO BETRAY HIS HOME-\n"
	.asciiz "LAND RATHER THAN SUFFER\n" 
	.asciiz "AT THE HANDS OF KAHN'S\n" 
	.asciiz "EXTERMINATION SQUADS.\n"  
	.byte	-1

	.align 2
	.globl txt_rayden_bio
txt_rayden_bio:
#if 0
	.asciiz "RAYDEN\n"
	.asciiz "AS EARTH'S SWORN PRO-\n"
	.asciiz "TECTOR, RAYDEN FINDS\n"
	.asciiz "HIMSELF BANISHED IN THE\n" 
	.asciiz "MERGER BETWEEN EARTH AND\n" 
	.asciiz "OUTWORLD. BUT, WHEN THE\n"
	.asciiz "ELDER GODS REFUSE TO\n"
	.asciiz "ASSIST HIM IN AIDING\n"
	.asciiz "EARTH ANY FURTHER, THE\n"
	.asciiz "THUNDER GOD IS FORCED TO\n"
	.asciiz "TAKE MATTERS INTO HIS OWN\n"
	.asciiz "HANDS. HE TRANSFORMS\n"
	.asciiz "HIMSELF INTO A MORTAL\n"
	.asciiz "WARRIOR IN ORDER TO EXIST\n"
	.asciiz "ONCE AGAIN ON EARTH AND\n"
	.asciiz "FIGHT ON THE SIDE OF HIS\n"
	.asciiz "HUMAN COMRADES; THIS TIME\n"
	.asciiz "RISKING HIS PLACE IN THE\n"
	.asciiz "PANTHEON OF GODS, AND\n"
	.asciiz "GIVING UP HIS OWN\n"
	.asciiz "IMMORTALITY.\n"
	.byte	-1
#endif
	.asciiz "RAYDEN\n"
	.asciiz "AS EARTH'S SWORN PRO-\n"
	.asciiz "TECTOR, RAYDEN FINDS\n"
	.asciiz "HIMSELF BANISHED IN THE\n" 
	.asciiz "EARTH-OUTWORLD MERGER.\n" 
	.asciiz "WHEN THE ELDER GODS REFUSE\n"
	.asciiz "TO ASSIST HIM IN AIDING\n"
	.asciiz "EARTH, THE THUNDER GOD\n"
	.asciiz "TAKES MATTERS INTO HIS OWN\n"
	.asciiz "HANDS. HE TRANSFORMS INTO\n"
	.asciiz "A MORTAL SO HE CAN EXIST\n"
	.asciiz "ONCE AGAIN ON EARTH AND\n"
	.asciiz "FIGHT WITH HIS HUMAN\n"
	.asciiz "COMRADES; THIS TIME RISK-\n"
	.asciiz "ING HIS PLACE IN THE PAN-\n"
	.asciiz "THEON OF GODS, AND HIS OWN\n"
	.asciiz "IMMORTALITY.\n"
	.byte	-1

	.align 2
	.globl txt_baraka_bio
txt_baraka_bio:
	.asciiz "BARAKA\n"
	.asciiz "BARAKA WAS SENT TO QUELL\n"
	.asciiz "THE UPRISING OF A RENE-\n"
	.asciiz "GADE RACE IN OUTWORLD'S\n"
	.asciiz "LOWER REGIONS. AFTER A\n"
	.asciiz "VICTORIOUS BATTLE, THE\n" 
	.asciiz "NOMADIC WARRIOR RETURNS\n"
	.asciiz "TO FIGHT ON THE SIDE OF\n"
	.asciiz "VILLAINY. UNDER THE GUID-\n"
	.asciiz "ANCE OF SHAO KAHN, BARAKA\n"
	.asciiz "WILL ONCE AGAIN POSE A\n" 
	.asciiz "FORMIDABLE THREAT TO HIS\n"
	.asciiz "EARTHEN COUNTERPARTS.\n"
	.byte	-1
	
	
	.align 2
	.globl txt_kamel_bio
txt_kamel_bio:
	.asciiz	"KHAMELEON\n"
	.asciiz "REPTILE WAS ONCE THOUGHT TO\n"
	.asciiz "BE THE LAST MEMBER OF AN EX-\n"
	.asciiz "TINCT RACE OF REPTILIAN\n"
	.asciiz "CREATURES, UNTIL THE APPEARANCE\n"
	.asciiz "OF KHAMELEON. SHE ALONE KNOWS THE\n"
	.asciiz "TRUTH ABOUT THEIR HISTORY AND\n"
	.asciiz "CHOOSES TO FIGHT ON THE SIDE OF\n"
	.asciiz "EARTH, MAKING THE LAST SURVIVORS\n"
	.asciiz "OF THEIR RACE LETHAL ENEMIES.\n"
	.byte -1

/*
;*************************************************
;buyin text, mkbuyin.c
;*************************************************
*/
	.align 2
	.globl	pf_credit_info1
pf_credit_info1:
	.half	FONT15,2,84,184
	.word  WHITE_p
	.half	STRCNRMOS,0
	.asciiz	"KREDITS %d"

	.align 2
	.globl	pf_credit_info2
pf_credit_info2:
	.half	FONT15,2,240,184
	.word  WHITE_p
	.half	STRCNRMOS,0
	.asciiz	"KREDITS %d"

	.align 2
	.globl	pf_player1
pf_player1:
	.half	FONT7N,2,84,143+12+16
	.word  WHITE_p
	.half	STRCNRMOS,0
	.asciiz	"PLAYER 1"

	.align 2
	.globl	pf_player2
pf_player2:
	.half	FONT7N,2,240,143+12+16
	.word  WHITE_p
	.half	STRCNRMOS,0
	.asciiz	"PLAYER 2"

	.align 2
	.globl	pf_pmessage
pf_pmessage:
	.half	FONT15,0,14,82
	.word	WHITE_p
	.half	STRCNRMOS,0
	.byte	0

	.align 2
	.globl	txt_prepare
txt_prepare:
	.ascii	"PREPARE\n"
	.ascii	"FOR YOUR\n"
	.ascii	"NEXT\n"
	.asciiz	"CHALLENGE"

	.align 2
	.globl	txt_start_to_continue
txt_start_to_continue:
	.ascii	"PRESS START\n"
	.asciiz	"TO KONTINUE"

	.align 2
	.globl	txt_press_join
txt_press_join:
	.ascii	"PRESS START\n"
	.ascii	"TO\n"
	.asciiz	"JOIN IN"

	.align 2
	.globl	txt_insert_start
txt_insert_start:
	.asciiz	"\nGAME OVER\n"

	.align 2
	.globl	fl_num
fl_num:
	.word	bpal_flash2_P
	.half	6
	.half	RGB_RED
	.half	RGB_WHITE
	.half	END_STUFF

	.align 2
	.globl	fl_kidd
fl_kidd:
	.word	bpal_flash1_P
	.half	4
	.half	0xffff
	.half	RGB_BLUE
	.half	END_STUFF

	.align 2
	.globl	pf_kidd
pf_kidd:
	.half	FONT15,2,160,0x50
	.word  WHITE_p
	.half	STRCNRMOS_SCR,0
	.asciiz "KIDD THUNDER !!"

/* ; COIN PAGE  */
	.align 2
	.globl	fl_coin_cursor
fl_coin_cursor:
	.word	bpal_flash1_P
	.half	8
	.half	0xf801
	.half	0x7801
	.half	END_STUFF
#if 0
	.align 2
	.globl	txt_mkcoin1
txt_mkcoin1:
	.asciiz	"MORTAL\nKOMBAT"

	.align 2
	.globl	txt_mkcoin2a
txt_mkcoin2a:
	.asciiz	"4\n"

	.align 2
	.globl	txt_mkcoin2b
txt_mkcoin2b:
/*	.ascii	"PLAYER\n" */
	.ascii	"2 ON 2\n"
	.asciiz	"KOMBAT"


	.align 2
	.globl	txt_mkcoin4a
txt_mkcoin4a:
	.asciiz	"6\n"

	.align 2
	.globl	txt_mkcoin4b
txt_mkcoin4b:
/*	.ascii	"PLAYER\n" */
	.ascii	"3 ON 3\n"
	.asciiz	"KOMBAT"

	.align 2
	.globl	txt_mkcoin3a
txt_mkcoin3a:
	.asciiz	"8\n"

	.align 2
	.globl	txt_mkcoin3b
txt_mkcoin3b:
/*	.ascii	"PLAYER\n" */
	.ascii	"TOURNAMENT\n"
	.asciiz	"KOMBAT"
#endif

	.align 2
	.globl	txt_mkcoin4
txt_mkcoin4:
	.asciiz	"PRESS UP AND START FOR OPTIONS"

/*
;*************************************************
; main text, mkmain.c
;*************************************************
*/
	.align 2
	.globl	pf_round_num
pf_round_num:
	.half	FONT15,0xffff,160,75
	.word  WHITE_p
	.half	STRCNRMOS_SCR,0
	.asciiz "ROUND %d"

	.align 2
	.globl	fl_entered
fl_entered:
	.word	bpal_flash1_P
	.half	4
	.half	RGB_BLUE
	.half	0xffff
	.half	END_STUFF

	.align 2
	.globl	fl_finish
fl_finish:
	.word	bpal_flash1_P
	.half	4
	.half	0xffff
	.half	RGB_RED
	.half	END_STUFF


	.align 2
	.globl	pf_entered
pf_entered:
	.half	FONT15,0,320/2,0x40
	.word  bpal_flash1_P
	.half	STRCNRMOS_SCR,0
	.byte	0

/*
;*************************************************
; text, mktext.c
;*************************************************
*/
	.align 2
	.globl	pf_15point
pf_15point:
	.half	FONT15,0x0,0,0 
	.word  WHITE_p
	.half	STRCNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	pf_15point_left
pf_15point_left:
	.half	FONT15,0x0,0,0 
	.word  WHITE_p
	.half	STRLNRMOS_SCR,0
	.byte	0


	.align 2
	.globl	pf_15point_soff
pf_15point_soff:
	.half	FONT15,0x0,0,0
	.word  WHITE_p
	.half	STRCNRMO_SCR,0
	.byte	0

	.align 2
	.globl	pf_7point
pf_7point:
	.half	FONT7N,2,0,0
	.word  WHITE_p
	.half	STRCNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	pf_7point_left
pf_7point_left:
	.half	FONT7N,2,0,0
	.word  WHITE_p
	.half	STRLNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	pf_dave_smallc_soff
pf_dave_smallc_soff:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p
	.half	STRCNRMO_SCR,0
	.byte	0

	.align 2
	.globl	pf_dave_smalll_soff
pf_dave_smalll_soff:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p
	.half	STRLNRMO_SCR,0
	.byte	0

	.align 2
	.globl	pf_dave_smallr_soff
pf_dave_smallr_soff:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p
	.half	STRRNRMO_SCR,0
	.byte	0


	.align 2
	.globl	pf_dave_smallc
pf_dave_smallc:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p  
	.half	STRCNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	pf_dave_smallr
pf_dave_smallr:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p
	.half	STRRNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	pf_dave_smalll
pf_dave_smalll:
	.half	FONT7,0xffff,0,0
	.word  WHITE_p
	.half	STRLNRMOS_SCR,0
	.byte	0


/*
;*************************************************
; player select text, mksel.c
;*************************************************
*/

	.align 2
	.globl	fl_cursor1
fl_cursor1:
	.word bpal_flash1_P
	.half 4
	.half 0x03c1			/* %0000001111000001 */
	.half 0x07c1			/* %0000011111000001 */
	.half END_STUFF

	.align 2
	.globl	fl_cursor2
fl_cursor2:
	.word bpal_flash2_P
	.half 4
	.half 0x8001			/* %0111100000000001 */
	.half 0xf801			/* %1111100000000001 */
	.half END_STUFF

	.align 2
	.globl	fl_cursor3
fl_cursor3:
	.word bpal_flash3_P
	.half 4
	.half 0x003f			/* %00000000000111111 */
	.half 0x001f			/* %00000000000011111 */
	.half END_STUFF

	.align 2
	.globl	fl_cursor4
fl_cursor4:
	.word bpal_flash4_P
	.half 4
	.half 0xf83f				/* %0111110000011111 */
	.half 0x781f				/* %0011110000001111 */
	.half END_STUFF

	.align 2
	.globl	fl_cursor5
fl_cursor5:
	.word bpal_flash6_P
	.half 4
	.half 0x83c1				/* %0111110000011111 */
	.half 0xffc1				/* %0011110000001111 */
	.half END_STUFF

	.align 2
	.globl	fl_cursor6
fl_cursor6:
	.word bpal_flash7_P
	.half 4
	.half 0xfbc1				/* %0111110000011111 */
	.half 0x7fdf				/* %0011110000001111 */
	.half END_STUFF

	.align 2
	.globl	fl_auto
fl_auto:
	.word bpal_flash5_P
	.half 4
	.half RGB_BLUE
	.half 0xffff
	.half END_STUFF

	.align 2
	.globl	pf_auto_msg_1
pf_auto_msg_1:
	.half	FONT7N,2,26+18+4,212
	.word  bpal_flash5_P
	.half	STRCNRMO_SCR,0
	.asciiz "RANDOM\nSELECT"

	.align 2
	.globl	pf_auto_msg_2
pf_auto_msg_2:
	.half	FONT7N,2,290-18,212
	.word  bpal_flash5_P
	.half	STRCNRMO_SCR,0
	.asciiz "RANDOM\nSELECT"

	.align 2
	.globl	pf_bk_setup
pf_bk_setup:
	.half	FONT7N,2,160,40
	.word  YELLOW_p
	.half	STRCNRMOS_SCR,0
	.byte	0

	.align 2
	.globl	coin_mess
coin_mess:
	.half	FONT7,1,160,198
	.word  YELLOW_p
	.half	STRCNRMOS,0
	.byte	0

	.align 2
	.globl	buyin_coin_mess
buyin_coin_mess:
	.half	FONT7,1,160,198
	.word  YELLOW_p
	.half	STRCNRMOS,0
	.byte	0
#if 0
	.align 2
	.globl	txt_p1_entered
txt_p1_entered:
	.asciiz	"PLAYER 1 HAS ENTERED\nTHE TOURNAMENT !"

	.align 2
	.globl	txt_p2_entered
txt_p2_entered:
	.asciiz	"PLAYER 2 HAS ENTERED\nTHE TOURNAMENT !"
#endif

/*
;*************************************************
; round intro messages, mkr1.asm
;*************************************************
*/
	.align 2
	.globl	fl_r1
fl_r1:
	.word bpal_white_P
	.half 4
	.half RGB_BLUE
	.half 0xffff
	.half END_STUFF

/*
;*************************************************
; attract mode, amode
;*************************************************
*/
	.align 2
	.globl	txt_invade_game_intro
txt_invade_game_intro:
	.ascii	"YOU HAVE BEEN TRANSPORTED\n"
	.ascii	"TO ANOTHER REALM\n\n"
	.ascii	"A REALM WHERE NEITHER\n"
	.ascii	"THE EARTH WARRIORS\n"
	.ascii	"NOR SHAO KAHN HAVE ANY CONTROL\n\n"
	.ascii	"BEWARE THE REALM OF\n"
	.asciiz	"YRREK DIVAD"

	.align 2
	.globl	txt_space_game_intro
txt_space_game_intro:
	.ascii	"YOU HAVE BEEN TRANSPORTED\n"
	.ascii	"TO ANOTHER REALM\n\n"
	.ascii	"A REALM WHERE NEITHER\n"
	.ascii	"THE EARTH WARRIORS\n"
	.ascii	"NOR SHAO KAHN HAVE ANY CONTROL\n\n"
	.ascii	"BEWARE THE REALM OF\n"
	.asciiz	"RELLIM OHCANEP"

	.align 2
	.globl	txt_pong_game_intro
txt_pong_game_intro:
	.ascii	"YOU HAVE REACHED THE OUTER LIMITS\n\n"
	.ascii	"OF THE TOURNAMENT. NOW YOU BOTH MUST\n\n"
	.asciiz	"FACE A CHALLENGE FROM YOUR PAST..."

	.align 2
	.globl txt_sclue1
txt_sclue1:
	.byte 0x34, 0x32, 0x23, 0x49, 0x44, 0x52, 0x44, 0x40, 0x4c, 0x59, 0x2b, 0x45, 0x43, 0x2e, 0x4e, 0x30 
	.byte 0x43, 0x5d, 0x44, 0x1e, 0x42, 0x5f, 0x5b, 0x54, 0x39, 0x4e, 0x5a, 0x57, 0x58, 0x3e, 0x46, 0x6f 
	.byte 0x74, 0x28, 0x61, 0x65, 0x66, 0x6d, 0x07, 0x61, 0x67, 0x0a, 0x7f, 0x65, 0x60, 0x6b, 0x0e,0xff
/*
	.ascii	"50 MATCHES IN A ROW\n"
	.ascii	"WILL TAKE YOU\n"
	.asciiz	"BACK IN TIME!"
*/	
	.align 2
txt_sclue2:
	.byte 0x30, 0x32, 0x33, 0x24, 0x48, 0x47, 0x53, 0x4b, 0x41, 0x4f, 0x58, 0x2c, 0x44, 0x40, 0x2f, 0x51 
	.byte 0x31, 0x40, 0x5c, 0x43, 0x1f, 0x41, 0x5e, 0x54, 0x55, 0x3a, 0x4f, 0x5d, 0x56, 0x5b, 0x3f, 0x79 
	.byte 0x6e, 0x77, 0x03, 0x70, 0x6a, 0x06, 0x73, 0x60, 0x6c, 0x0a, 0x67, 0x6d, 0x63, 0x6a, 0x25, 0x62 
	.byte 0x74, 0x7e, 0x7f, 0x7d, 0x78, 0x16, 0x78, 0x70, 0x7a, 0x7b, 0x75, 0x79, 0x6d, 0xff

/*
	.ascii	"100 MATCHES IN A ROW\n"
	.ascii	"WILL TAKE YOU TO THE LAND\n"
	.asciiz	"RELLIM OHCANEP"
*/
	
	.align 2
txt_sclue3:
	.byte 0x51, 0x50, 0x46, 0x57, 0x56, 0x26, 0x52, 0x58, 0x29, 0x4b, 0x45, 0x48, 0x2d, 0x5d, 0x5b, 0x51 
	.byte 0x43, 0x46, 0x33, 0x5b, 0x5b, 0x1c, 0x44, 0x57, 0x57, 0x43, 0x5a, 0x3c, 0x49, 0x51, 0x3f, 0x65 
	.byte 0x6f, 0x63, 0x61, 0x68, 0x60, 0x06, 0x6c, 0x67, 0x64, 0x68, 0x6a, 0x78, 0x27, 0x74, 0x60, 0x7e 
	.byte 0x74, 0x12, 0x60, 0x71, 0x79, 0x73, 0x74, 0x6c, 0x17, 0xff

/*
	.ascii	"PRESS UP AND START ON\n"
	.ascii	"SONYA TO ENABLE KOMBAT\n"
	.asciiz "ZONE SELECT."
*/
	
	.align 2
txt_sclue4:
	.byte 0x4e, 0x4c, 0x23, 0x50, 0x4d, 0x43, 0x27, 0x5b, 0x4c, 0x46, 0x4e, 0x4f, 0x59, 0x2e, 0x5c, 0x53 
	.byte 0x43, 0x57, 0x56, 0x5a, 0x1f, 0x46, 0x45, 0x5d, 0x4a, 0x49, 0x3b, 0x58, 0x52, 0x49, 0x51, 0x00 
	.byte 0x60, 0x6c, 0x67, 0x04, 0x76, 0x72, 0x66, 0x7a, 0x7d, 0x0a, 0x64, 0x62, 0x27, 0x65, 0x6e, 0x7e 
	.byte 0x7e, 0x12, 0x67, 0x7b, 0x15, 0x73, 0x79, 0x79, 0x7b, 0x76, 0x7e, 0x1c, 0x6e, 0x7b, 0x7c, 0x12 
	.byte 0x04, 0x16, 0x49, 0x01, 0x0b, 0x02, 0x12, 0x1a, 0x08, 0x04, 0x08, 0x09, 0x6d, 0x02, 0x0e, 0x14 
	.byte 0x15, 0x17, 0x01, 0x07, 0x7b, 0xff

/*
	.ascii	"ON THE SELECT SCREEN\n"
	.ascii	"PRESS DOWN AND START ON\n"
	.ascii	"KANO TO ENABLE SECRET\n"
	.asciiz "ENDURANCE LADDERS."
*/
	
	.align 2
txt_sclue5:
	.byte 0x43, 0x43, 0x41, 0x45, 0x49, 0x4f, 0x53, 0x41, 0x4c, 0x59, 0x2b, 0x4d, 0x5f, 0x4b, 0x2f, 0x42 
	.byte 0x54, 0x44, 0x56, 0x46, 0x46, 0x57, 0x55, 0x54, 0x5c, 0x10, 0x59, 0x45, 0x3d, 0x4e, 0x4d, 0x65 
	.byte 0x72, 0x71, 0x6a, 0x6a, 0x62, 0x06, 0x6f, 0x78, 0x09, 0x66, 0x7b, 0x0c, 0x65, 0x65, 0x0f, 0x7c 
	.byte 0x7a, 0x38, 0x71, 0x71, 0x73, 0x79, 0x65, 0x7d, 0x19, 0x6e, 0x73, 0x79, 0x1d, 0x7b, 0x71, 0x04 
	.byte 0x61, 0x0d, 0x05, 0x64, 0x11, 0x0e, 0x02, 0x42, 0x0c, 0x12, 0x1b, 0x00, 0x02, 0x1d, 0x06, 0x1f 
	.byte 0x1f, 0x58, 0xff

/*
	.ascii	"BABALITIES ARE REVERSABLE\n"
	.ascii	"BY PRESSING HP LP HK LK\n"
	.ascii	"BEFORE THE END OF THE\n"
	.asciiz "EXPLOSION\n"
*/
	
	.align 2
txt_sclue6:
	.byte 0x45, 0x57, 0x51, 0x4d, 0x4b, 0x41, 0x27, 0x5c, 0x41, 0x4f, 0x2b, 0x4d, 0x59, 0x5a, 0x5d, 0x51 
	.byte 0x52, 0x46, 0x33, 0x59, 0x5a, 0x52, 0x52, 0x12, 0x5c, 0x54, 0x4f, 0x59, 0x4f, 0x14, 0x32, 0x00 
	.byte 0x69, 0x69, 0x03, 0x68, 0x6e, 0x06, 0x6f, 0x78, 0x09, 0x66, 0x7b, 0x0c, 0x65, 0x65, 0x25, 0x7c 
	.byte 0x7a, 0x12, 0x7b, 0x64, 0x15, 0x7a, 0x67, 0x18, 0x7b, 0x76, 0x70, 0x1c, 0x6f, 0x70, 0x1f, 0x6d 
	.byte 0x4b, 0x04, 0x0c, 0x16, 0x65, 0x15, 0x02, 0x0b, 0x1b, 0x0f, 0x1f, 0x6c, 0x02, 0x1e, 0x1b, 0x19 
	.byte 0x1e, 0x1c, 0x00, 0x74, 0x18, 0x13, 0x19, 0x0d, 0x79, 0x6b, 0x51, 0xff

/*
	.ascii	"DURING THE ATTRACT MODE\n"
	.ascii	"ENTER\n"
	.ascii  "- HK LK HP LP HK\n"
	.ascii	"LK HP LP BLK RN -\n"
	.asciiz	"FOR SECRET OPTIONS MENU 1\n"
*/
	
	.align 2
txt_sclue7:
	.byte 0x45, 0x57, 0x51, 0x4d, 0x4b, 0x41, 0x27, 0x5c, 0x41, 0x4f, 0x2b, 0x4d, 0x59, 0x5a, 0x5d, 0x51 
	.byte 0x52, 0x46, 0x33, 0x59, 0x5a, 0x52, 0x52, 0x12, 0x5c, 0x54, 0x4f, 0x59, 0x4f, 0x14, 0x32, 0x68 
	.byte 0x71, 0x02, 0x6b, 0x6f, 0x05, 0x6a, 0x6c, 0x08, 0x65, 0x7a, 0x0b, 0x7e, 0x63, 0x24, 0x6d, 0x7c 
	.byte 0x7a, 0x12, 0x71, 0x78, 0x7e, 0x16, 0x75, 0x74, 0x72, 0x1a, 0x69, 0x72, 0x1d, 0x6c, 0x71, 0x60 
	.byte 0x6c, 0x48, 0x05, 0x0b, 0x17, 0x66, 0x14, 0x0d, 0x0a, 0x18, 0x0e, 0x18, 0x6d, 0x01, 0x1f, 0x04 
	.byte 0x18, 0x1d, 0x1d, 0x07, 0x75, 0x1b, 0x12, 0x16, 0x0c, 0x7a, 0x69, 0x56, 0xff

/*
	.ascii	"DURING THE ATTRACT MODE\n"
	.ascii	"ENTER\n"
	.ascii	"-HP HK LK LP RN\n"
	.ascii  "BLK BLK BLK RN RN -\n"
	.asciiz	"FOR SECRET OPTIONS MENU 2\n"
*/
	
	.align 2
txt_sclue8:
	.byte 0x45, 0x57, 0x51, 0x4d, 0x4b, 0x41, 0x27, 0x5c, 0x41, 0x4f, 0x2b, 0x4d, 0x59, 0x5a, 0x5d, 0x51 
	.byte 0x52, 0x46, 0x33, 0x59, 0x5a, 0x52, 0x52, 0x12, 0x5c, 0x54, 0x4f, 0x59, 0x4f, 0x14, 0x5b, 0x00 
	.byte 0x65, 0x02, 0x76, 0x04, 0x70, 0x06, 0x75, 0x08, 0x7b, 0x0a, 0x67, 0x0c, 0x61, 0x24, 0x69, 0x7f 
	.byte 0x63, 0x12, 0x66, 0x7a, 0x79, 0x7f, 0x7a, 0x71, 0x6d, 0x7f, 0x7f, 0x1c, 0x76, 0x6c, 0x7a, 0x04 
	.byte 0x08, 0x16, 0x10, 0xff

/*
	.ascii	"DURING THE ATTRACT MODE\n"
	.ascii	"ENTER\n"
	.ascii	"D D U U R R L L\n"
	.asciiz	"FOR UNLIMITED KREDITS"
*/
	
	.align 2
txt_sclue9:
	.byte 0x4e, 0x4c, 0x23, 0x50, 0x4d, 0x43, 0x27, 0x47, 0x5b, 0x43, 0x4c, 0x45, 0x43, 0x4f, 0x43, 0x30 
	.byte 0x5c, 0x59, 0x33, 0x44, 0x5c, 0x42, 0x1d, 0x48, 0x4b, 0x5f, 0x48, 0x4f, 0x3d, 0x4d, 0x5a, 0x6c 
	.byte 0x64, 0x61, 0x77, 0x04, 0x61, 0x73, 0x75, 0x61, 0x67, 0x6d, 0x0b, 0x6d, 0x27, 0x7d, 0x66, 0x7c 
	.byte 0x7e, 0x7a, 0x76, 0x60, 0x61, 0x73, 0x17, 0x77, 0x77, 0x30, 0x6f, 0x74, 0x78, 0x1e, 0x72, 0x0f 
	.byte 0x0e, 0x0c, 0x63, 0x10, 0x0a, 0x66, 0x17, 0x04, 0x08, 0x13, 0x6b, 0x0d, 0x03, 0x6e, 0x00, 0x1c 
	.byte 0x15, 0x1b, 0x16, 0x5e, 0x17, 0x03, 0x03, 0x78, 0x18, 0x7a, 0x1c, 0x13, 0x12, 0x1a, 0x16, 0x25 
	.byte 0x6b, 0xff

/*
	.ascii	"ON THE ORIGINAL MK PIT\n"
	.ascii	"PRESS SELECT DURING A\n"
	.ascii	"SILOHETTE ON\n"
	.ascii	"THE MOON TO PLAY AN OLDIE\n"
	.asciiz "BUT A GOODIE\n"
*/
	
	.align 2
txt_sclue10:
	.byte 0x55, 0x4d, 0x23, 0x42, 0x4c, 0x41, 0x4f, 0x5c, 0x29, 0x41, 0x4a, 0x41, 0x48, 0x42, 0x4a, 0x5f 
	.byte 0x5f, 0x32, 0x43, 0x46, 0x50, 0x45, 0x44, 0x12, 0x5d, 0x55, 0x4c, 0x52, 0x3d, 0x5f, 0x51, 0x64 
	.byte 0x01, 0x71, 0x77, 0x65, 0x77, 0x72, 0x07, 0x6c, 0x7c, 0x78, 0x62, 0x62, 0x6a, 0x24, 0x7b, 0x7f 
	.byte 0x70, 0x61, 0x67, 0x6d, 0x15, 0x79, 0x79, 0x18, 0x6d, 0x72, 0x7e, 0x1c, 0x6e, 0x6a, 0x7e, 0x12 
	.byte 0x61, 0x00, 0x11, 0x0d, 0x01, 0x01, 0x02, 0x66, 0x43, 0xff

/*
	.ascii	"TO FIGHT KAMELEON PRESS\n"
	.ascii	"DOWN AND START DURING\n"
	.asciiz	"TOASTY ON THE STAR BRIDGE.\n"
*/
	
	.align 2
txt_sclue11:
	.byte 0x52, 0x4a, 0x42, 0x4b, 0x25, 0x4d, 0x46, 0x40, 0x47, 0x2a, 0x42, 0x5f, 0x2d, 0x5e, 0x43, 0x51 
	.byte 0x48, 0x53, 0x51, 0x58, 0x50, 0x36, 0x58, 0x56, 0x13, 0x4e, 0x53, 0x59, 0x3d, 0x55, 0x5e, 0x76 
	.byte 0x64, 0x0e, 0x03, 0x74, 0x6c, 0x72, 0x07, 0x61, 0x60, 0x63, 0x07, 0x0c, 0x7f, 0x61, 0x60, 0x76 
	.byte 0x65, 0x7d, 0x63, 0x14, 0x3f, 0x7f, 0x71, 0x18, 0x60, 0x75, 0x6e, 0x1c, 0x6d, 0x6c, 0x7a, 0x13 
	.byte 0x12, 0x62, 0x0b, 0x14, 0x65, 0x0a, 0x17, 0x68, 0x0d, 0x05, 0x1c, 0x02, 0x47, 0x0c, 0x0a, 0x16 
	.byte 0x1e, 0x00, 0x16, 0x74, 0x01, 0x1e, 0x12, 0x78, 0x1f, 0x13, 0x1c, 0x14, 0x09, 0x7e, 0x0c, 0x34 
	.byte 0x20, 0x30, 0x37, 0x37, 0x4b, 0x6c, 0xff

/*
	.ascii	"SHAO KAHN IS PLAYABLE ON\n"
	.ascii	"THE KAVE, PIT III, ROOFTOP \n"
	.ascii	"IF YOU PRESS HP LP DOWN\n"
	.asciiz	"BEFORE THE FIGHT STARTS.\n"
*/

	.align 2
txt_sclue12:
	.byte 0x4c, 0x4d, 0x57, 0x45, 0x57, 0x49, 0x27, 0x41, 0x5a, 0x2a, 0x5b, 0x40, 0x4c, 0x57, 0x4e, 0x52
	.byte 0x5d, 0x57, 0x33, 0x5b, 0x5b, 0x36, 0x43, 0x50, 0x5c, 0x10, 0x5f, 0x59, 0x4e, 0x5b, 0x4d, 0x74
	.byte 0x0d, 0x02, 0x61, 0x65, 0x69, 0x65, 0x68, 0x66, 0x70, 0x06, 0x0b, 0x6e, 0x6c, 0x7a, 0x7b, 0x7c
	.byte 0x74, 0x74, 0x7a, 0x71, 0x79, 0x72, 0x17, 0x32, 0x70, 0x7c, 0x1b, 0x65, 0x72, 0x6b, 0x1f, 0x10
	.byte 0x13, 0x07, 0x10, 0x17, 0x65, 0x0e, 0x0c, 0x68, 0x05, 0x01, 0x6b, 0x0d, 0x1a, 0x0f, 0x16, 0x5a
	.byte 0x13, 0x17, 0x15, 0x1b, 0x07, 0x13, 0x77, 0x0c, 0x11, 0x1f, 0x7b, 0x1a, 0x14, 0x19, 0x17, 0x34
	.byte 0x41, 0x31, 0x37, 0x25, 0x37, 0x32, 0x34, 0x46, 0x63, 0xff

/*
	.ascii	"MOTARO IS PLAYABLE ON THE\n"
	.ascii	"DESERT, BALCONY, BATTLEFIELD \n"
	.ascii	"IF YOU PRESS HK LK AWAY\n"
	.asciiz	"BEFORE THE FIGHT STARTS.\n"
*/
	
	.align 2
txt_sclue13:
	.byte 0x49, 0x57, 0x4e, 0x45, 0x4b, 0x26, 0x54, 0x45, 0x46, 0x41, 0x4e, 0x2c, 0x44, 0x5d, 0x2f, 0x40 
	.byte 0x5d, 0x53, 0x4a, 0x55, 0x57, 0x5a, 0x52, 0x12, 0x50, 0x5c, 0x3b, 0x45, 0x52, 0x4b, 0x3f, 0x73 
	.byte 0x75, 0x63, 0x71, 0x70, 0x05, 0x67, 0x74, 0x08, 0x7a, 0x67, 0x64, 0x67, 0x68, 0x0e, 0x6e, 0x7e 
	.byte 0x75, 0x38, 0x63, 0x66, 0x70, 0x65, 0x64, 0x18, 0x71, 0x6a, 0x1b, 0x74, 0x76, 0x1e, 0x7d, 0x0c 
	.byte 0x0a, 0x62, 0x11, 0x0a, 0x65, 0x07, 0x10, 0x09, 0x10, 0x40, 0x09, 0x09, 0x0b, 0x01, 0x1d, 0x15 
	.byte 0x71, 0x06, 0x1b, 0x11, 0x75, 0x10, 0x1e, 0x1f, 0x11, 0x0e, 0x7b, 0x0f, 0x09, 0x1f, 0x0d, 0x34 
	.byte 0x32, 0x4c, 0x69, 0xff

/*
	.ascii	"HUMAN SMOKE IS PLAYABLE\n"
	.ascii  "IF YOU START AS SMOKE AND\n"
	.ascii	"PRESS HP HK BLK RN AWAY\n"
	.asciiz	"BEFORE THE FIGHT STARTS.\n"
*/
	
	.align 2
txt_sclue14:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3f, 0x3f, 0x29 
	.byte 0x28, 0x22, 0x22, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 109901\n"
*/
	
	.align 2
txt_sclue15:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3a, 0x37, 0x24 
	.byte 0x25, 0x2a, 0x27, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 484484\n"
*/
	
	.align 2
txt_sclue16:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3c, 0x3d, 0x22
	.byte 0x23, 0x20, 0x21, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 222222\n"
*/
	
	.align 2
txt_sclue17:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3b, 0x3a, 0x25 
	.byte 0x24, 0x27, 0x25, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 555556\n"
*/
	
	.align 2
txt_sclue18:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3a, 0x3b, 0x24
	.byte 0x25, 0x26, 0x27, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 444444\n"
*/
	
	.align 2
txt_sclue19:
	.byte 0x4a, 0x4d, 0x4e, 0x46, 0x44, 0x52, 0x27, 0x43, 0x46, 0x4e, 0x4e, 0x36, 0x2d, 0x3e, 0x3d, 0x24
	.byte 0x27, 0x2a, 0x2a, 0x1e, 0xff

/*
	.asciiz	"KOMBAT KODE: 024689\n"
*/
	
	.align 2
txt_sclue20:
	.byte 0x52, 0x4d, 0x4d, 0x5d, 0x44, 0x21, 0x54, 0x28, 0x4b, 0x58, 0x5e, 0x58, 0x4c, 0x42, 0x46, 0x44 
	.byte 0x48, 0x28, 0x19, 0x5c, 0x45, 0x36, 0x5b, 0x53, 0x39, 0x58, 0x57, 0x57, 0x3d, 0x56, 0x4f, 0x00 
	.byte 0x6d, 0x69, 0x03, 0x66, 0x69, 0x6d, 0x2d, 0x60, 0x79, 0x0a, 0x67, 0x7c, 0x0d, 0x6c, 0x63, 0x7b 
	.byte 0x11, 0x7a, 0x78, 0x14, 0x79, 0x7d, 0x3d, 0xff

/*
	.ascii	"SONYA'S BRUTALITY:\n"
	.ascii 	"HP LK BLK HP LK BLK\n"
	.asciiz "HP LP BLK HK LK\n"
*/
	
	.align 2
txt_sclue21:
	.byte 0x53, 0x43, 0x5a, 0x40, 0x40, 0x48, 0x20, 0x5b, 0x29, 0x48, 0x59, 0x59, 0x59, 0x4f, 0x43, 0x59 
	.byte 0x45, 0x4b, 0x29, 0x1e, 0x5d, 0x46, 0x37, 0x50, 0x49, 0x3a, 0x57, 0x57, 0x3d, 0x52, 0x54, 0x00 
	.byte 0x6d, 0x69, 0x03, 0x6c, 0x6e, 0x2c, 0x6b, 0x78, 0x09, 0x66, 0x7b, 0x0c, 0x61, 0x7e, 0x0f, 0x72 
	.byte 0x7d, 0x79, 0x13, 0x76, 0x79, 0x7d, 0x3d, 0xff

/*
	.ascii	"RAYDEN'S BRUTALITY:\n"
	.ascii 	"HP HP LK LK LK HK\n"
	.asciiz "LP LP LP BLK BLK\n"
*/

	.align 2
	.globl txt_sclue22
txt_sclue22:
	.byte 0x52, 0x47, 0x48, 0x50, 0x4a, 0x54, 0x20, 0x5b, 0x29, 0x48, 0x59, 0x59, 0x59, 0x4f, 0x43, 0x59 
	.byte 0x45, 0x4b, 0x29, 0x1e, 0x5d, 0x46, 0x37, 0x50, 0x49, 0x3a, 0x59, 0x50, 0x56, 0x3e, 0x5d, 0x6c 
	.byte 0x6a, 0x2, 0x6b, 0x6f, 0x2f, 0x6e, 0x6c, 0x8, 0x65, 0x61, 0xb, 0x60, 0x66, 0xe, 0x63, 0x60 
	.byte 0x11, 0x7e, 0x63, 0x14, 0x79, 0x66, 0x3d, 0xff
/*
	.ascii	"SEKTOR'S BRUTALITY:\n"
	.ascii 	"HP HP BLK BLK HK\n"
	.asciiz "HK LK LK LP LP LP\n"
*/
	.align 2
txt_sclue23:
	.byte 0x52, 0x47, 0x40, 0x56, 0x40, 0x52, 0x27, 0x44, 0x48, 0x4e, 0x4f, 0x49, 0x5f, 0x2e, 0x4a, 0x5e 
	.byte 0x55, 0x47, 0x41, 0x55, 0x5b, 0x55, 0x52, 0x12, 0x4c, 0x54, 0x57, 0x53, 0x5e, 0x55, 0x4c, 0x00 
	.byte 0x6c, 0x6d, 0x71, 0x61, 0x05, 0x65, 0x6b, 0x7d, 0x6c, 0x79, 0x0b, 0x6d, 0x79, 0x24, 0x7c, 0x78 
	.byte 0x70, 0x7d, 0x13, 0x7f, 0x74, 0x7e, 0x79, 0x1f, 0x6a, 0x1a, 0x7f, 0x79, 0x70, 0x77, 0x6c, 0x05 
	.byte 0x4b, 0xff

/*
	.ascii	"SECRET LADDER ENDURANCE\n"
	.ascii	"UNLOCKS MORE CLUES AT\n"
	.asciiz	"SHAO KAHN'S DEMISE\n"
*/
	.align 2
	.globl cheat_message
cheat_message:
	.ascii	"KNOWLEDEGE IS POWER\n"
	.ascii	"TO THOSE WHO EARN IT!\n"
	.ascii	"DISABLE ONE HITS AND\n"
	.ascii	"DIFFICULTY MUST BE AT\n"
	.ascii	"LEAST NORMAL IN ORDER\n"
	.ascii	"TO GAIN INNERMOST\n"
	.asciiz	"KNOWLEDGE.\n"

	.align 2
txt_found_1:
	.asciiz "CONGRATULATIONS !!"

	.align 2
txt_found_2:			  
	.ascii	"YOU HAVE FOUND THE\nPASSAGE\n"
	.asciiz	"TO THE OUTLAND."

	.align 2
txt_found_3:
	.ascii	"NOW YOU MUST BATTLE WITH\n"
	.ascii	"AN UNDISCOVERED WARRIOR\n"
	.asciiz	"FROM MORTAL KOMBAT"

	.align 2
txt_found_4:
	.asciiz	"PREPARE YOURSELF !!"

	.align 2
txt_found_5:
	.asciiz	"TO RETURN TO THE FOREST"

	.align 2
	.globl	txt_victory1
txt_victory1:
	.asciiz "SHAO KAHN IS NO MORE"

	.align 2
	.globl	txt_victory2
txt_victory2:
	.ascii	"YOU ARE THE\n"
	.asciiz	"MK TRILOGY CHAMPION"

	.align 2
	.globl	pf_rise
pf_rise:
	.half FONT15,0xffff,160,240
	.word WHITE_p
	.half STRCNRMOS_SCR
	.byte	0

	.align 2
	.globl	end_winner_text
end_winner_text:
	.word txt_victory1
	.word txt_victory2
	.word txt_found_1		
	.word txt_found_2
	.word txt_found_3
	.word txt_found_4
	.word txt_found_5
	.globl secret_clue_table
secret_clue_table:	
	.word	txt_sclue1		
	.word	txt_sclue3		
	.word	txt_sclue4		
	.word	txt_sclue23		
	.word	txt_sclue15		
	.word	txt_sclue2		
	.word	txt_sclue16		
	.word	txt_sclue7		
	.word	txt_sclue13		
	.word	txt_sclue18		
	.word	txt_sclue19		
	.word	txt_sclue21		
	.word	txt_sclue5		
	.word	txt_sclue8		
	.word	txt_sclue9		
	.word	txt_sclue6		
	.word	txt_sclue10		
	.word	txt_sclue11		
	.word	txt_sclue20		
	.word	txt_sclue17		
	.word	txt_sclue12		
	.word	txt_sclue14		
	.word	txt_sclue22		
							
/*							
;*********************************
;*********************************
;ENDING STORIES				
*/							
							
	.align 2
	.globl	ochar_endings1
ochar_endings1:
#if 1
	.word	txt_kano_ending
	.word	txt_sonya_ending
	.word	txt_jax_ending
	.word	txt_nightwolf_ending
	.word	txt_jc_ending
	.word	txt_stryker_ending
	.word	txt_sindel_ending
	.word	txt_sektor_ending
	.word	txt_cyrax_ending
	.word	txt_lao_ending
	.word	txt_kabal_ending
	.word	txt_sheeva_ending
	.word	txt_st_ending
	.word	txt_lk_ending
	.word	txt_smoke_ending

	.word	txt_kitana_ending
	.word	txt_jade_ending
	.word	txt_mileena_ending

	.word	txt_scorpion_ending
	.word	txt_reptile_ending
	.word	txt_ermac_ending
	.word	txt_oldsz_ending
	.word	txt_oldsmoke_ending

	.word	txt_noob_ending
	.word	txt_rayden_ending	
	.word	txt_baraka_ending	
	.word	txt_rain_ending	
	.word	txt_kamel_ending	
	.word	txt_oldsmoke_ending	
	.word	txt_oldsmoke_ending	
	.word	txt_oldsmoke_ending	
	.word	txt_oldsmoke_ending	
	.word	txt_oldsmoke_ending	
#endif	

pause_stop	= -2
pause		= -3

	.align 2
txt_kano_ending:
	.asciiz "WHEN SHAO KAHN LETS KANO"
	.asciiz	"LIVE, HE FAILS TO REALIZE THE"
	.asciiz "RESOURCEFULNESS OF THE"
	.asciiz "SCHEMING HUMAN. KANO LURES"
	.asciiz "KAHN'S ARMY AWAY ON A"
	.asciiz "FALSE MISSION; THEN NUKES THEM"
	.asciiz "USING A STOLEN WEAPON. HE"
	.asciiz "FIGHTS THE REMAINING WARRIORS"
	.asciiz	"AND FINALLY DEFEATS KAHN HIMSELF."
	.byte	pause_stop
	.asciiz "KANO'S TRUE INTENTION IS TO TAKE"
	.asciiz "OVER THE SOULS WHICH KAHN ONCE"
	.asciiz "POSSESSED. BUT KANO IS UNABLE TO"
	.asciiz "CONTROL THE SPIRITS AS THEY ESCAPE"
	.asciiz "AND ATTACK HIM. RUMORED TO HAVE"
	.asciiz "SUFFERED A VIOLENT DEATH, KANO"
	.asciiz	"WAS IGNORANT OF THE FACT THAT"
	.asciiz	"HE SAVED THE WORLD HE TRIED"
	.asciiz	"TO CONQUER."
	.byte	pause_stop
	.byte	-1
#if 1
	.align 2
txt_sonya_ending:
	.asciiz "SONYA DEFEATS HER ARCH"
	.asciiz "ENEMY KANO HIGH ATOP A"
	.asciiz "SKYSCRAPER NEAR SHAO KAHN'S"
	.asciiz	"FORTRESS. SHE THEN COMES FACE"
	.asciiz "TO FACE WITH THE EMPEROR"
	.asciiz "HIMSELF. IN AN INCREDIBLE"
	.asciiz	"DISPLAY OF COURAGE, SONYA WINS."
	.asciiz "WHEN THE WORLD RETURNS TO ITS"
	.asciiz "NORMAL STATE, SONYA HAS NO"
	.byte	pause_stop
	.asciiz "TROUBLE CONVINCING HER"
	.asciiz "SUPERIORS TO FORM THE OUTER"
	.asciiz "WORLD INVESTIGATION AGENCY;"
	.asciiz	"DEVOTED TO PROTECTING THE"
	.asciiz	"EARTH AGAINST POSSIBLE FUTURE"
	.asciiz	"INVASIONS FROM OTHER REALMS."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_jax_ending:
	.asciiz "THE SECOND TIME JAX BATTLES"
	.asciiz "THE FORCES OF SHAO KAHN, HE"
	.asciiz "COMES PREPARED. THOUGHT TO BE"
	.asciiz "THE STRONGEST MAN ON EARTH HE"
	.asciiz "HAS NO PROBLEM PROVING IT;"
	.asciiz	"FIRST BY BEATING KAHN'S ARMIES"
	.asciiz "THEN BY DEFEATING THE EMPEROR"
	.asciiz	"HIMSELF. WHEN THE WORLD REVERTS"
	.asciiz "BACK TO NORMAL, JAX AND SONYA"
	.byte	pause_stop
	.asciiz "START THE OUTER WORLD"
	.asciiz	"INVESTIGATION AGENCY. JAX RUNS"
	.asciiz	"THE EXPLORATORY DIVISION WHICH"
	.asciiz	"LEARNS TO OPEN PORTALS THROUGH"
	.asciiz "SCIENCE RATHER THAN MAGIC."
	.asciiz "HE LEADS THE FIRST EXPEDITION"
	.asciiz	"INTO A MYSTERIOUS NEW REALM."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_nightwolf_ending:
	.asciiz	"NIGHTWOLF HELPS OTHER EARTH"
	.asciiz "WARRIORS ESCAPE TO HIS SACRED"
	.asciiz "LAND. ONCE THERE, THEY REGROUP"
	.asciiz "AND FORM A PLAN OF ATTACK"
	.asciiz "AGAINST SHAO KAHN'S INVASION."
	.asciiz "NIGHTWOLF HAS TRAINED"
	.asciiz "HARD FOR THIS BATTLE;"
	.asciiz "FINALLY HE FACES SHAO KAHN"
	.asciiz	"AND EMERGES VICTORIOUS."
	.byte	pause_stop
	.asciiz	"WHEN THE EARTH RETURNS TO"
	.asciiz "ITS NORMAL STATE, NIGHTWOLF"
	.asciiz	"PEACEFULLY REGAINS THE"
	.asciiz "LANDS HIS NATIVE-AMERICAN"
	.asciiz "PEOPLE LOST OVER MANY YEARS."
	.asciiz "THEY ESTABLISH THEIR OWN"
	.asciiz	"PROUD NATION AND SOON BECOME"
	.asciiz	"THE GREAT LEADERS OF EARTH."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_sindel_ending:
	.asciiz	"SINDEL RECEIVES VISIONS OF"
	.asciiz	"HER TRUE PAST AND TURNS AGAINST"
	.asciiz	"SHAO KAHN. SHE DISCOVERS THAT"
	.asciiz	"HER TRUE KING WAS NAMED JERROD."
	.asciiz	"THEY ONCE HAD A DAUGHTER NAMED"
	.asciiz	"KITANA AND RULED A REALM CALLED"
	.asciiz	"EDENIA; BEFORE KAHN TOOK IT"
	.asciiz	"AWAY IN THEIR OWN MORTAL KOMBAT."
	.asciiz	"HE USED SINDEL AS A PAWN IN HIS"
	.byte	pause_stop
	.asciiz	"QUEST FOR EARTH AND TOOK"
	.asciiz	"KITANA AS HIS OWN DAUGHTER."
	.asciiz	"BUT IN DEFEATING SHAO KAHN,"
	.asciiz	"SINDEL FREES THE EARTH. IN"
	.asciiz	"DOING SO, SHE ALSO LIBERATES"
	.asciiz	"EDENIA AND INSURES A REUNION"
	.asciiz	"WITH HER 1000 YEAR OLD"
	.asciiz	"DAUGHTER- KITANA."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_kamel_ending:
	.asciiz	"KHAMELEON'S FORMER RACE WERE\n"
	.asciiz	"KNOWN AS RAPTORS, THEY EVOLVED\n"
	.asciiz	"MILLIONS OF YEARS AGO ON EARTH\n"
	.asciiz	"INTO INTELLIGENT CREATURES BUT\n"
	.asciiz	"FLED THE REALM WHEN IT WAS\n"
	.asciiz	"DESTROYED IN A BATTLE BETWEEN\n"
	.asciiz	"THE GODS. THEY REPOPULATED A\n"
	.asciiz	"NEW REALM KNOWN AS ZATERRA ONLY\n"
	.byte	pause_stop
	.asciiz	"TO BE DRIVEN TO EXTINCTION BY\n"
	.asciiz	"SHAO KAHN WHEN THEY LOST TO\n"
	.asciiz	"OUTWORLD IN MORTAL KOMBAT.\n"
	.asciiz	"WITH SHAO KAHN NEAR VICTORY\n"
	.asciiz	"AGAINST EARTH, KHAMELEON CONTACTS\n"
	.asciiz	"REPTILE AND SHARES THE TRUTH ABOUT\n"
	.asciiz	"THEIR RACE WITH HIM. THIS TURNS\n" 
	.asciiz	"HIM AGAINST KAHN, ALLOWING\n"
	.asciiz	"KHAMELEON TO LEAD A SNEAK ATTACK\n"
	.byte	pause_stop
	.asciiz	"AGAINST THE EMPEROR. THIS LAST\n"
	.asciiz	"BATTLE RESULTS IN THE END OF SHAO\n"
	.asciiz	"KAHN AND UNIFICATION OF EARTH,\n"
	.asciiz	"GIVING REPTILE AND KHAMELEON THE\n"
	.asciiz	"CHANCE TO BEGET A NEW GENERATION\n"
	.asciiz	" OF RAPTORS.\n"
	.byte	pause_stop
	.byte	-1

	.align 2
txt_jc_ending:
	.asciiz	"WITH HIS NEARLY DECEASED SOUL" 
	.asciiz	"RESTORED, JOHNNY CAGE FINDS"  
	.asciiz	"HIMSELF FIGHTING ALONGSIDE HIS"  
	.asciiz	"FRIENDS ONCE AGAIN. THIS TIME HE"  
	.asciiz	"SEEKS REVENGE AGAINST THE EXTERM-" 
	.asciiz	"INATION SQUAD THAT TOOK HIS LIFE."  
	.asciiz	"BUT DURING THEIR BATTLE, CAGE"  
	.asciiz	"LEARNS THAT IF THEY WIN AGAINST"  
	.byte	pause_stop
	.asciiz	"KAHN, HIS SOUL WILL AGAIN BE"  
	.asciiz	"DECEASED WHEN EARTH REVERTS BACK"  
	.asciiz	"TO NORMAL. KNOWING THIS, THE MOVIE"
	.asciiz	"STAR EMBARKS ON A ONE WAY MISSION"  
	.asciiz	"TO DESTROY SHAO KAHN. HIS DETER-" 
	.asciiz	"MINATION FUELS HIS FELLOW"  
	.asciiz	"WARRIORS AS THEY EMBARK ON ONE"  
	.byte	pause_stop
	.asciiz	"FINAL ONSLAUGHT AGAINST THE EVIL"  
	.asciiz	"EMPEROR."
	.asciiz "THE EARTH WARRIORS EMERGE"  
	.asciiz	"VICTORIOUS AND WHEN THE" 
	.asciiz	"REALMS REVERT TO THEIR NORMAL" 
	.asciiz	"STATE, CAGE BIDS FAREWELL TO HIS" 
	.asciiz	"COMRADES AS HIS SOUL LEAVES" 
	.asciiz	"TO A HIGHER PLACE." 
	.byte	pause_stop
	.byte	-1


	.align 2
txt_sektor_ending:
	.asciiz	"AFTER EVENTUALLY TERMINATING"
	.asciiz	"SUB-ZERO, SEKTOR IS ATTACKED"
	.asciiz	"BY SHAO KAHN'S ARMY. UNFAMILIAR"
	.asciiz	"WITH THE OUTWORLD WARRIORS,"
	.asciiz	"SEKTOR FIGHTS BACK. HE TARGETS"
	.asciiz	"KAHN AND ALL OUTWORLD BEINGS"
	.asciiz	"AS THREATS TO THE LIN KUEI."
	.asciiz	"KAHN'S MINIONS ARE NO MATCH"
	.asciiz	"FOR SEKTOR WHO FIGHTS HIS WAY"
	.byte	pause_stop
	.asciiz	"INTO THE FORTRESS. ONCE INSIDE"
	.asciiz	"SEKTOR INITIATES HIS SELF"
	.asciiz	"DESTRUCT SEQUENCE. THE RESULTING"
	.asciiz	"EXPLOSION IS SO MASSIVE THAT IT"
	.asciiz	"CLOSES THE PORTAL AND RETURNS"
	.asciiz	"EARTH BACK TO NORMAL."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_cyrax_ending:
	.asciiz	"CYRAX IS CAPTURED BY SUB-ZERO"
	.asciiz	"AND REPROGRAMMED WITH NEW"
	.asciiz	"ORDERS; DESTROY SHAO KAHN."
	.asciiz	"WITH KAHN UNABLE TO DETECT"
	.asciiz	"THE ASSASSIN'S SOULLESS"
	.asciiz	"PRESENCE, CYRAX DELIVERS A"
	.asciiz	"SUCCESSFUL SNEAK ATTACK. BUT"
	.asciiz	"AFTER ELIMINATING KAHN AND"
	.asciiz	"SAVING EARTH, CYRAX AWAITS NEW"
	.byte	pause_stop
	.asciiz	"ORDERS FROM HIS LIN KUEI"
	.asciiz	"HEADQUARTERS. THE ORDERS NEVER"
	.asciiz	"COME AND CYRAX MALFUNCTIONS."
	.asciiz	"HE ENDS UP STRANDED IN THE MIDDLE"
	.asciiz	"OF A VAST DESERT, BLINDLY"
	.asciiz	"HEADING TOWARDS HIS BASE."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_sheeva_ending:
	.asciiz	"WHILE SHEEVA SERVES HER"
	.asciiz	"MASTER ON EARTH, HER RACE OF"
	.asciiz	"SHOKAN ARE BEING PUNISHED"
	.asciiz	"ON THE OUTWORLD. KAHN NOW"
	.asciiz	"FAVORS MOTARO'S RACE OF CENTAURS"
	.asciiz	"AND AIDS THEM IN DEFEATING THE"
	.asciiz	"SHOKAN. AFTER LEARNING OF"
	.asciiz	"THESE EVENTS SHEEVA TURNS ON"
	.asciiz	"HER MASTER, SHE DEFEATS MOTARO,"
	.byte	pause_stop
	.asciiz	"AND IN A RAGE BRINGS DOWN KAHN."
	.asciiz	"IN FREEING THE EARTH SHE ALSO"
	.asciiz	"FREES THE OUTWORLD. SHE THEN"
	.asciiz	"RETURNS HOME AND WORKS TO"
	.asciiz	"RESTORE THE PRIDE AND RESPECT"
	.asciiz	"OF HER RACE."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_kabal_ending:
	.asciiz	"AFTER RETURNING FROM NEAR DEATH,"
	.asciiz	"KABAL SWEARS REVENGE AGAINST HIS"
	.asciiz	"ATTACKERS. HE FIGHTS ALONGSIDE"
	.asciiz	"THE OTHER EARTH WARRIORS. WHEN"
	.asciiz	"HE DEFEATS MOTARO AND THE MIGHTY"
	.asciiz	"SHAO KAHN, HE PROVES THAT HE"
	.asciiz	"TRULY IS THE CHOSEN ONE."
	.asciiz	"BEFORE THE INVASION, KABAL"
	.asciiz	"LIVED A LIFE OF CRIME. HE WAS"
	.byte	pause_stop
	.asciiz	"ONCE A MEMBER OF THE BLACK"
	.asciiz	"DRAGON ALONG WITH KANO. NOW"
	.asciiz	"KABAL DEVOTES HIS LIFE TO"
	.asciiz	"FIGHTING INJUSTICE; HE WILL GIVE"
	.asciiz	"CRIMES' INNER CIRCLES A NEW"
	.asciiz	"REASON TO FEAR."
	.byte	pause_stop
	.byte	-1
 

	.align 2
txt_stryker_ending:
	.asciiz	"IGNORANT OF WHY HIS SOUL WAS"
	.asciiz	"SPARED FROM THE OUTWORLD"
	.asciiz	"INVASION, STRYKER RECEIVES A"
	.asciiz	"VISION FROM RAIDEN. HE IS"
	.asciiz	"INSTRUCTED TO TRAVEL WEST."
	.asciiz	"HE EVENTUALLY MEETS THE REST"
	.asciiz	"OF EARTH'S WARRIORS AND LEARNS"
	.asciiz	"THE TRUE MEANING OF HIS SURVIVAL."
	.asciiz	"HE TRAVELS BACK TO THE CITY"
	.byte	pause_stop
	.asciiz	"HE SWORE TO PROTECT. KAHN IS"
	.asciiz	"UNFAMILIAR WITH THIS NEW"
	.asciiz	"KOMBATANT AND IS CAUGHT OFF"
	.asciiz	"GUARD. STRYKER DEFEATS THE"
	.asciiz	"WARLORD AND SAVES THE ENTIRE"
	.asciiz	"PLANET. THE CHAOS THAT CONSUMED"
	.asciiz	"THE CITY IN THE HOURS BEFORE"
	.asciiz	"THE INVASION ARE GONE."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_lao_ending:
	.asciiz	"WHEN KAHN INVADES EARTH, KUNG"
	.asciiz	"LAO MUST SCRAP HIS PLANS OF"
	.asciiz	"REUNITING THE WHITE LOTUS SOCIETY."
	.asciiz	"HE INSTEAD MUST FOCUS ON THE NEW"
	.asciiz	"TOURNAMENT. HE SEEKS LIU KANG"
	.asciiz	"AND TOGETHER THEY BATTLE"
	.asciiz	"KAHN'S FORCES FEARLESSLY. USING"
	.asciiz	"THE KNOWLEDGE HE OBTAINED AS A"
	.asciiz	"SHAOLIN MONK, HE FIGHTS IN THE"
	.byte	pause_stop
	.asciiz	"NAME OF HIS GREAT ANCESTOR-"
	.asciiz	"THE ORIGINAL KUNG LAO. HE"
	.asciiz	"EMERGES VICTORIOUS BUT SUFFERS"
	.asciiz	"FROM INJURIES DURING THE BATTLE"
	.asciiz	"WITH KAHN. BELIEVED TO HAVE"
	.asciiz	"PASSED AWAY, KUNG LAO JOINS"
	.asciiz	"HIS ANCESTOR IN A NEW LIFE"
	.byte	pause_stop
	.byte	-1

																																																				
	.align 2
txt_st_ending:
	.asciiz	"WHEN SHAO KAHN OVERTAKES THE"
	.asciiz	"EARTH, HE NEEDS SHANG TSUNG TO"
	.asciiz	"HELP LOCATE THE SURVIVING HUMANS."
	.asciiz	"GRANTED NEW POWERS, HE SOON"
	.asciiz	"DISCOVERS HIS DARK EMPEROR'S"
	.asciiz	"TRUE PLAN; AS SOON AS THE"
	.asciiz	"REMAINING WARRIORS ARE DISPOSED"
	.asciiz	"OF, KAHN WILL TAKE TSUNG'S OWN"
	.asciiz	"SOUL. AFTER LEARNING OF THIS,"
	.byte	pause_stop
	.asciiz	"TSUNG TURNS ON HIS MASTER. HE"
	.asciiz	"CATCHES MOTARO OFF GUARD AND"
	.asciiz	"THEN DEFEATS SHAO KAHN. BUT"
	.asciiz	"BEFORE THE EARTH CAN RETURN"
	.asciiz	"TO NORMAL TSUNG TAKES ALL THE"
	.asciiz	"SOULS AS HIS OWN. HE WILL"
	.asciiz	"FOREVER RULE EARTH WITH HIS"
	.asciiz	"OWN BRAND OF EVIL."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_lk_ending:
	.asciiz	"AFTER THWARTING SHAO KAHN IN"
	.asciiz	"THE PAST, LIU KANG FINDS HIMSELF"
	.asciiz	"THE MAIN TARGET OF KAHN'S"
	.asciiz	"EXTERMINATION SQUADS. BUT KANG"
	.asciiz	"IS THE REIGNING MORTAL KOMBAT"
	.asciiz	"CHAMPION AND PROVES IT BY EASILY"
	.asciiz	"DEFEATING KAHN'S MINIONS."
	.asciiz	"BUT IT'S THE APPARENT DEATH"
	.asciiz	"OF HIS FRIEND KUNG LAO THAT"
	.byte	pause_stop
	.asciiz	"ENRAGES KANG AND ENABLES HIM"
	.asciiz	"TO FIND THE STRENGTH TO DEFEAT"
	.asciiz	"SHAO KAHN. THEN BEFORE THE"
	.asciiz	"PORTAL CLOSES, LIU KANG IS"
	.asciiz	"GREETED BY PRINCESS KITANA AND"
	.asciiz	"THANKED FOR SAVING THE EARTH"
	.asciiz	"AND THE OUTWORLD."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_mileena_ending:
	.asciiz	"WHEN MILEENA IS MURDERED," 
	.asciiz	"SHE FINDS HER SOUL REBORN" 
	.asciiz	"IN AN EVIL PLACE CALLED" 
	.asciiz	"THE NETHEREALM. HERE, SHE" 
	.asciiz	"ACCEPTS SERVITUDE TO AN" 
	.asciiz	"ALL MIGHTY GOD KNOWN AS" 
	.asciiz	"SHINNOK. IT IS SHINNOK" 
	.asciiz	"WHO ALLOWS HER SOUL TO BE" 
	.asciiz	"REBORN ON THE OUTWORLD." 
	.asciiz	"HER LOYALTY TO SHAO KAHN" 
	.asciiz	"IS REPLACED BY HER" 
	.byte	pause_stop
	.asciiz	"FEAR OF SHINNOK."
	.asciiz	"MILEENA PLOTS TO OVERTHROW" 
	.asciiz	"HER OWN FATHER.  THE"
	.asciiz	"ABILITY TO READ KITANA'S" 
	.asciiz	"MIND AND PREDICT THE EARTH" 
	.asciiz	"WARRIORS' MOTIVES, ENABLES" 
	.asciiz	"MILEENA TO SET UP HER" 
	.asciiz	"FATHERS DOWNFALL. WHEN" 
	.byte	pause_stop
	.asciiz	"KAHN IS WEAKENED BY THE" 
	.asciiz	"ONSLAUGHT OF ATTACKS," 
	.asciiz	"MILEENA TAKES THE" 
	.asciiz	"OPPORTUNITY TO DESTROY HER" 
	.asciiz	"FATHER AND ALLOW SHINNOK" 
	.asciiz	"TO STEP FORWARD AND TAKE" 
	.asciiz	"BOTH REALMS FOR HIS OWN" 
	.asciiz	"SINISTER PURPOSES."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_oldsz_ending:
	.asciiz	"HAVING BEEN KILLED IN"
	.asciiz	"THE FIRST TOURNAMENT"
	.asciiz	"SUB-ZERO SOMEHOW SEEMS"
	.asciiz	"TO HAVE EMERGED TO WIN"
	.asciiz	"THE THIRD TOURNAMENT."
	.asciiz	"HOWEVER, UPON REMOVING"
	.asciiz	"HIS MASK BOTH THE"
	.asciiz	"OUTWORLD AND THE"
	.asciiz	"EARTH-BORN WARRIORS. . ."
	.byte	pause_stop
	.asciiz	"ARE SHOCKED TO DISCOVER"
	.asciiz	"THE TRUE IDENTITY OF"
	.asciiz	"THIS WARRIOR. A WARRIOR"
	.asciiz	"WHO HAS LONG BEEN"
	.asciiz	"MISSING FROM A PREVIOUS"
	.asciiz	"MORTAL KOMBAT, AND ONE"
	.asciiz	"WHO WILL RETURN IN THE"
	.asciiz	"FOURTH TOURNAMENT."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_ermac_ending:
	.asciiz	"WHEN KAHN FINALLY ELIMINATES HIS" 
	.asciiz	"OPPOSITION, HE FINDS A NEW AND"
	.asciiz	"SURPRISING FOE IN ERMAC.  THE" 
	.asciiz	"OUTWORLD SOULS THAT GIVE LIFE TO" 
	.asciiz	"THE WARRIOR DID NOT TRUST THEIR" 
	.asciiz	"TYRANNICAL LEADER WHO PLANNED TO" 
	.asciiz	"CONSUME THE POWERFUL LIFE FORCE" 
	.asciiz	"FOR HIS OWN POWER."
	.byte	pause_stop
	.asciiz	"EVEN SHAO KAHN'S POWER WAS NO" 
	.asciiz	"MATCH FOR THE OVERWHELMING" 
	.asciiz	"STRENGTH OF THE LEGIONS OF DECEASED" 
	.asciiz	"OUTWORLD WARRIORS. THEY DESTROYED" 
	.asciiz	"THEIR MASTER IN BATTLE THAT" 
	.asciiz	"DEVASTATED THE ENTIRE REALM. ERMAC" 
	.asciiz	"WAS LEFT BEHIND TO RULE IT WITH" 
	.asciiz	"HIS OWN BRAND OF OPPRESSION."
	.byte	pause_stop
	.byte	-1

	.align 2 
txt_rain_ending:
	.asciiz	"RAIN FIGHTS VALIANTLY FOR THE" 
	.asciiz	"EMPEROR SHAO KAHN. BUT IT WOULD" 
	.asciiz	"BE KAHN'S OWN STEP DAUGHTER, THE" 
	.asciiz	"PRINCESS KITANA, WHO TURNS RAIN" 
	.asciiz	"AGAINST HIM. LIKE KITANA, RAIN'S" 
	.asciiz	"ORIGINS ALSO COME FROM THEIR" 
	.asciiz	"FORMER REALM OF EDENIA. HE LEARNS"
	.byte	pause_stop
	.asciiz	"THAT HIS FATHER WAS ONCE A"
	.asciiz	"GENERAL IN EDENIA'S ARMY AND DIED"
	.asciiz	"AT THE HANDS OF SHAO KAHN HIMSELF."
	.asciiz	"ENRAGED AT THE TRUTH ABOUT HIS" 
	.asciiz	"HISTORY, HE JOINS KITANA IN"
	.asciiz	"ALLYING WITH THE EARTH REALM"
	.byte	pause_stop
	.asciiz	"WARRIORS. BUT HIS ALLEGIANCE COMES"
	.asciiz	"UNDER QUESTION WHEN HE MYSTERIOUSLY" 
	.asciiz	"DISAPPEARS DURING AN EXTERMINATION" 
	.asciiz	"SQUAD ATTACK. TO PROVE HIS LOYALTY"
	.asciiz	"HE EMBARKED ON A SUICIDE MISSION TO"
	.asciiz	"DESTROY SHAO KAHN AND END THE"
	.asciiz	"MENACE ONCE AND FOR ALL."
	.byte	pause_stop
	.byte	-1

	.align 2 
txt_noob_ending:
	.asciiz	"AT FIRST A PASSIVE OBSERVER, NOOB" 
	.asciiz	"SAIBOT WOULD SOON RECEIVE ORDERS" 
	.asciiz	"TO SIDE WITH THE EVIL EMPEROR" 
	.asciiz	"SHAO KAHN. SAIBOT'S LEADERS IN THE" 
	.asciiz	"NETHEREALM WANT HIM TO JOIN KAHN'S" 
	.asciiz	"BATTLE TO GAIN HIS TRUST AND TO" 
	.asciiz	"GAIN ENTRANCE INTO THE EARTH REALM."
	.byte	pause_stop
	.asciiz	"WHEN KAHN DROPS HIS GUARD, NOOB" 
	.asciiz	"SAIBOT IS ORDERED TO ATTACK. WITH"
	.asciiz	"BOTH THE EARTH REALM AND THE" 
	.asciiz	"OUTWORLD'S EMPEROR DEFEATED, THE"
	.asciiz	"FALLEN ELDER GOD KNOWN AS SHINNOK" 
	.asciiz	"CAN TAKE BOTH REALMS AND GAIN THE" 
	.asciiz	"POWER HE NEEDS TO STRIKE BACK AT" 
	.asciiz	"THE ELDER GOD'S WHO BANISHED" 
	.asciiz	"HIM INTO THE NETHEREALM."
	.byte	pause_stop
	.byte	-1
#endif

	.align 2 
txt_rayden_ending:
	.asciiz	"WHEN OUTWORLD AND EARTH MERGE," 
	.asciiz	"RAYDEN FINDS HIMSELF BATTLING SHAO" 
	.asciiz	"KAHN WITHOUT THE ASSISTANCE OF THE" 
	.asciiz	"ELDER GODS. THE THUNDER GOD MUST" 
	.asciiz	"TRANSFORM INTO A MORTAL IN ORDER" 
	.asciiz	"EXIST IN THE COMBINED REALMS. WHEN" 
	.asciiz	"HE DOES THIS, HE PUTS HIS OWN"
	.asciiz	"IMMORTALITY AT RISK."
	.byte	pause_stop
	.asciiz	"BUT RAYDEN HAS ALWAYS FOUND WAYS OF" 
	.asciiz	"FOULING KAHN'S PLOTS. HE GUIDES THE" 
	.asciiz	"CHOSEN EARTH WARRIORS INTO BATTLE" 
	.asciiz	"AGAINST THE OUTWORLD EMPEROR'S ARMIES," 
	.asciiz	"THEN FINALLY FACES KAHN HIMSELF. THE" 
	.asciiz	"POWERFUL BEINGS FIGHT UNTIL THE VERY" 
	.asciiz	"CORE OF THE EARTH IS SHAKEN, AND" 
	.asciiz	"RAYDEN EMERGES VICTORIOUS."
	.byte	pause_stop
	.byte	-1

	.align 2 
txt_baraka_ending:
	.asciiz	"WHEN BARAKA'S FAILURE TO APPREHEND"
	.asciiz	"SEVERAL EARTH WARRIORS NEARLY"
	.asciiz	"RESULTS IN  SHAO KAHN'S DEMISE," 
	.asciiz	"THE NOMAD FINDS HIMSELF FEARING" 
	.asciiz	"FOR HIS OWN LIFE. HE FALLS OUT OF" 
	.asciiz	"FAVOR WITH HIS EMPEROR, AND"
	.asciiz	"REALIZES THAT IT'S ONLY A MATTER" 
	.asciiz	"OF TIME BEFORE KAHN ENACTS REVENGE."
	.byte	pause_stop
	.asciiz	"BARAKA REMAINS LOYAL UNTIL THE"
	.asciiz	"OPPOSITION FROM THE EARTH REALM HAS" 
	.asciiz	"BEEN DEFEATED. WITH KAHN IN A"
	.asciiz	"WEAKENED STATE FROM HIS BATTLE WITH" 
	.asciiz	"RAYDEN, BARAKA STRIKES. THE" 
	.asciiz	"DESPONDENT EMPEROR IS NO MATCH FOR"
	.asciiz	"BARAKA'S ATTACK. THEN, FEARING"
	.asciiz	"REPRISAL FROM THOSE LOYAL TO KAHN,"
	.asciiz	"BARAKA ESCAPES BACK INTO THE NOMADIC"
	.asciiz	"RUINS FROM WHICH HE CAME."
	.byte	pause_stop
	.byte	-1

	
	.align 2
txt_oldsmoke_ending:
	.asciiz "BEFORE HIS TRANSFORMATION INTO A"
	.asciiz "CYBERNETIC ASSASSIN, SMOKE WAS" 
	.asciiz "ONE OF THE LIN KUEI'S FINEST" 
	.asciiz "NINJAS. IT WAS DURING THIS TIME"
	.asciiz "THAT HE CAME TO KNOW HIS GREATEST" 
	.asciiz "ALLY- SUB-ZERO. WHEN THE LIN KUEI" 
	.asciiz "DECIDE TO AUTOMATE THEIR WARRIORS," 
	.asciiz "THE TWO ATTEMPT TO ESCAPE."
	.byte	pause_stop
	.asciiz "WHILE SUB-ZERO SUCCESSFULLY ELUDED" 
	.asciiz "CAPTURE, SMOKE DID NOT. HE WOULD"
	.asciiz "BECOME A ROBOTIC NIGHTMARE, HIS"
	.asciiz "SOUL TRAPPED INSIDE A LIVING"
	.asciiz "MACHINE. IN HIS HUMAN FORM, SMOKE"
	.asciiz "WAS A FIERCE WARRIOR, IN HIS MECH-"
	.asciiz "ANICAL BODY, HE IS EVEN MORE LETHAL." 
	.asciiz "BUT, HIS TRUE FORM IS THAT OF A"
	.asciiz "HUMAN, ONE HE'LL KNOW AGAIN ONLY"
	.asciiz "IN DREAMS."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_kitana_ending:
	.asciiz	"KITANA EVADES THE EVIL"
	.asciiz	"CLUTCHES OF SHAO KAHN"
	.asciiz	"AND ESCAPES INTO THE"
	.asciiz	"UNKNOWN  REGIONS OF EARTH."
	.asciiz	"SHE SURVIVES AN ASSASSINATION"
	.asciiz	"ATTEMPT BY THE VILE CREATURE"
	.asciiz	"REPTILE, AND ALLIES HERSELF"
	.asciiz	"WITH HER ONE TIME"
	.asciiz	"COMRADE - JADE"
	.byte	pause_stop
	.asciiz	"TOGETHER, WITH THE HELP"
	.asciiz	"OF EARTH'S WARRIORS,"
	.asciiz	"KITANA REACHES SINDEL AND"
	.asciiz	"TURNS THE QUEEN AGAINST HER"
	.asciiz	"EMPEROR. WITH SHAO KAHN DEFEATED,"
	.asciiz	"THE EARTH IS CHANGED BACK TO"
	.asciiz	"ITS ORIGINAL STATE, AS IS"
	.asciiz	"KITANA'S REALM OF EDENIA."
	.byte	pause_stop
	.asciiz	"SHE WILL BE FOREVER IN DEBT"
	.asciiz	"TO HER FRIENDS FROM EARTH AS"
	.asciiz	"SHE RULES THE NEW REALM OF"
	.asciiz	"EDENIA AT QUEEN SINDEL'S"
	.asciiz	"SIDE."
	.byte	pause_stop
	.byte	-1

	.align 2
txt_jade_ending:
	.asciiz	"JADE MAKES THE DECISION TO"
	.asciiz	"ASSIST HER LONGTIME FRIEND,"
	.asciiz	"KITANA. SHE THWARTS AN"
	.asciiz	"ASSASSINATION  ATTEMPT BY"
	.asciiz	"REPTILE AGAINST THE PRINCESS"
	.asciiz	"AND FENDS OFF THEIR OTHER"
	.asciiz	"OUTWORLD ENEMIES."
	.asciiz	"THIS CLEARS THE PATH FOR"
	.asciiz	"KITANA TO TURN SINDEL"
	.byte	pause_stop
	.asciiz	"AGAINST THE EMPEROR"
	.asciiz	"SHAO KAHN. WITH SINDEL"
	.asciiz	"REMOVED AS AN ENEMY,"
	.asciiz	"JADE FINDS HERSELF"
	.asciiz	"FACING THE  EMPEROR IN"
	.asciiz	"KOMBAT. SHE DEFEATS HIM"
	.asciiz	"AND BOTH EARTH AND HER"
	.asciiz	"FORMER HOMELAND OF EDENIA"
	.asciiz	"ARE TRANSFORMED"
	.byte	pause_stop
	.asciiz	"TO THEIR ORIGINAL"
	.asciiz "STATES. JADE HAS EARNED"
	.asciiz	"HERSELF A PLACE"
	.asciiz	"ALONGSIDE THE GREAT"
	.asciiz	"HEROES OF"
	.asciiz	"MORTAL KOMBAT."
	.byte	pause_stop
	.byte	-1


	.align 2
txt_reptile_ending:
	.asciiz	"REPTILE IS ORDERED BY SHAO"
	.asciiz	"KAHN FIND AND KILL"
	.asciiz	"KITANA. HE IS SUCCESSFUL IN"
	.asciiz	"COMPLETING HIS TASK, BUT"
	.asciiz	"UPON RETURNING, FINDS HIMSELF"
	.asciiz	"SHUNNED BY THE EMPEROR. SHAO"
	.asciiz	"KAHN PROMISED REPTILE THAT IF"
	.asciiz	"HE WAS SUCCESSFUL THAT HE WOULD"
	.asciiz	"RESURRECT REPTILE'S RACE."
	.byte	pause_stop
	.asciiz	"SHAO KAHN NEVER HAD ANY"
	.asciiz	"INTENTION OF FULFILLING HIS"
	.asciiz	"PROMISE. ENRAGED, REPTILE"
	.asciiz	"TURNS AGAINST HIS MASTER AND"
	.asciiz	"DEFEATS HIM IN BATTLE BUT BY"
	.asciiz	"KILLING HIS MASTER, REPTILE"
	.asciiz	"DESTROYS THE ONE CHANCE"
	.asciiz	"TO EVER KNOW HIS TRUE RACE.  "
	.byte	pause_stop
	.byte	-1

	.align 2
txt_scorpion_ending:
	.asciiz	"SCORPION IS INADVERTENTLY"
	.asciiz	"RELEASED FROM HIS DAMNATION"
	.asciiz	"IN HELL WHEN KAHN'S PLAN TO"
	.asciiz	"OVERTAKE THAT REALM GOES"
	.asciiz	"AWRY. FREE TO ROAM EARTH,"
	.asciiz	"SCORPION IS ENLISTED BY"
	.asciiz	"THE EMPEROR TO AID HIM IN HIS"
	.asciiz	"QUEST TO DESTROY THE"
	.asciiz	"CHOSEN WARRIORS. "
	.byte	pause_stop
	.asciiz	"BUT, HIS ALLEGIANCE TO SHAO KAHN"
	.asciiz	"FALTERS WHEN HE DISCOVERS ONE"
	.asciiz	"OF THE CHOSEN WARRIORS TO"
	.asciiz	"BE SUB-ZERO."
	.asciiz	"SCORPION HAS VOWED TO PROTECT"
	.asciiz	"THE FORMER NINJA AS RESTITUTION"
	.asciiz	"FOR KILLING HIS BROTHER."
	.asciiz	"SHAO KAHN FINDS HIMSELF"
	.asciiz	"THE VICTIM OF HIS OWN"
	.byte	pause_stop
	.asciiz	"SCHEME AS SCORPION IS"
	.asciiz	"FORCED TO TURN AGAINST HIM"
	.asciiz	"HE DESTROYS THE EMPEROR"
	.asciiz	"AND THE EARTH IS RETURNED"
	.asciiz	"TO NORMAL. SCORPION FINDS"
	.asciiz	"HIMSELF ONCE AGAIN ROAMING"
	.asciiz	"THE PITS OF HELL, ONLY TO"
	.asciiz	"ONE DAY RISE AGAIN. "
	.byte	pause_stop
	.byte	-1

	.align 2
txt_smoke_ending:
	.asciiz	"SMOKE WAS ONCE A FRIEND"
	.asciiz	"AND ALLY OF SUB-ZERO WHEN"
	.asciiz	"THEY BOTH TRIED TO ESCAPE FROM"
	.asciiz	"BEING TURNED INTO MACHINES"
	.asciiz	"BY THEIR NINJA CLAN. BUT,"
	.asciiz	"SMOKE IS CAPTURED AND"
	.asciiz	"TRANSFORMED INTO A CYBORG"
	.asciiz	"WITH A MISSION TO FIND AND"
	.asciiz	"KILL HIS OLD PARTNER."
	.byte	pause_stop
	.asciiz	"BUT SMOKE SOON FINDS HIMSELF"
	.asciiz	"BEING PURSUED BY SHAO KAHN'S"
	.asciiz	"MINIONS. HE LEARNS THAT HE"
	.asciiz	"STILL HAS A SOUL AND HIS"
	.asciiz	"TRUE MISSION IS THE"
	.asciiz	"DESTRUCTION OF THE OUTWORLD"
	.asciiz	"INVADERS. HE DEFEATS"
	.asciiz	"KAHN AND SAVES THE WORLD"
	.asciiz	"BUT IS FOREVER TRAPPED"
	.asciiz	"IN HIS ARTIFICIAL BODY."
	.byte	pause_stop
	.byte	-1

/* ;********************************* */
	.align 2
	.globl	txt_thanx_alot
txt_thanx_alot:
	.ascii	"MANY THANKS GO TO\n\n"
	.ascii	"STEVE RANCK\n"
	.ascii	"SCOTT PATTERSON\n"
	.ascii	"MIKE CUEVAS\n"
	.asciiz	"DETMAR PETERKE\n"
	.asciiz	"KERRY\n\n"

	.align 2
	.globl	txt_testers
txt_testers:
	.ascii	"UNBEATABLE KOMBAT MASTERS\n(GAME TESTERS)\n\n"
	.ascii	"WILL SHEN\n"
	.ascii	"WILLIAM SUTJIADI\n"
	.ascii	"J.R. SALAZAR\n"
	.ascii	"MARSELLE WASHINGTON\n"
	.ascii	"MIKE TURNER\n"
	.ascii	"TOAN NGO\n"
	.ascii	"STEVE KRAMER\n"
	.ascii	"JOHN UBALDE\n"
	.ascii	"BRIAN JOHNSON\n"
	.ascii	"EDDIE FERRIER\n"
	.ascii	"MIKE VINIKOUR\n"

	.align 2
	.globl	txt_production
txt_production:
	.ascii	"PRINT DESIGN AND PRODUCTION\n\n"
	.ascii	"DEBBIE AUSTIN\n"
	.ascii	"STEVE HIGH\n"
	.ascii	"SHAWN MURPHY\n"
	.asciiz	"DAVE YOUNG\n"

	.align 2
	.globl	txt_mktril
txt_mktril:
	.ascii	"WILLIAMS ENTERTAINMENT\nMK TRILOGY TEAM\n\n"
	.ascii	"DAVID SCHWARTZ\n"
	.ascii	"MARK GUIDARELLI\n"
	.ascii	"GREG MILLER\n"
	.ascii	"MARK MAY\n"
	.asciiz	"ROB ATESALP\n"
 
	.align 2
	.globl	txt_mk3_design
txt_mk3_design:
	.ascii	"MORTAL KOMBAT TRILOGY\nDESIGN TEAM\n\n"
	.ascii	"ED BOON\n"
	.ascii	"JOHN TOBIAS\n"
	.ascii	"TONY GOSKIE\n"
	.ascii	"DAN FORDEN\n"
	.ascii	"DAVE MICHICICH\n"
	.ascii	"STEVE BERAN\n"
	.asciiz	"JOHN VOGEL\n\n"

/* high score stuff (mkhstd.h) */
	.align 2
	.globl	txt_p1_enter
txt_p1_enter:
	.asciiz	"PLAYER 1\nINCREDIBLE WINNING STREAK"

	.align 2
	.globl	txt_p2_enter
txt_p2_enter:
	.asciiz	"PLAYER 2\nINCREDIBLE WINNING STREAK"

	.align 2
	.globl	txt_enter_your
txt_enter_your:
	.asciiz	"ENTER YOUR INITIALS\nTO BECOME IMMORTALIZED"

	.align 2
	.globl	txt_rank_wiar
txt_rank_wiar:
	.asciiz	"%d  WINS IN A ROW\n"
#if 0
/* ending stuff */
	.align 2
	.globl	txt_david
txt_david:
	.asciiz	"DAVID SCHWARTZ\nSOFTWARE"

	.align 2
	.globl	txt_greg
txt_greg:
	.asciiz	"GREG MILLER\nGRAPHICS"

	.align 2
	.globl	txt_markm
txt_markm:
	.asciiz	"MARK MAY\nGRAPHICS"

	.align 2
	.globl	txt_markg
txt_markg:
	.asciiz	"MARK GUIDARELLI\nART TOOLS"

	.align 2
	.globl	txt_scott
txt_scott:
	.asciiz	"SCOTT PATTERSON\nWILLIAMS AUDIO SOUND SYSTEM"

	.align 2
	.globl	txt_rob
txt_rob:
	.asciiz	"ROB ATESALP\nSOUND"

	.align 2
	.globl	txt_ed
txt_ed:
	.asciiz	"ED BOON\nSOFTWARE"

	.align 2
	.globl	txt_johnt
txt_johnt:
	.asciiz	"JOHN TOBIAS\nGRAPHICS"

	.align 2
	.globl	txt_steve
txt_steve:
	.asciiz	"STEVE BERAN\nGRAPHICS"

	.align 2
	.globl	txt_dan
txt_dan:
	.asciiz "DAN FORDEN\nSOUNDS AND MUSIC"

	.align 2
	.globl	txt_tonyg
txt_tonyg:
	.asciiz	"TONY GOSKIE\nGRAPHICS"

	.align 2
	.globl	txt_dave
txt_dave:
	.asciiz	"DAVE MICHICICH\nGRAPHICS"

	.align 2
	.globl	txt_johnv
txt_johnv:
	.asciiz	"JOHN VOGEL\nGRAPHICS"

S_X	= 80
S_Y	= 85

/* cast table */
	.align 2
	.globl	cast_table
cast_table:
	.word	OVL_END1
	.word	txt_as_kano
	.half	0x0050*S_X/100,0x0010
	.word	txt_as_sonya
 	.half	0x00c8*S_X/100,0x10
	.word	txt_as_kabal
	.half	0x140*S_X/100,0x10
	.word	0
	.half	ft_kano,0x50*S_X/100
	.half	ft_sonya,0xC8*S_X/100
	.half	ft_tusk,0x140*S_X/100
	.half	0
	.half	0x75				/*  sound: "well done" */

	.word	OVL_END2
	.word	txt_as_jax
	.half	0x0050*S_X/100,0x0010
	.word	txt_as_swat
	.half	0xc8*S_X/100,0x10
	.word	txt_as_lk
	.half	0x140*S_X/100,0x10
	.word	0
	.half	ft_jax,0x50*S_X/100
	.half	ft_swat,0xC8*S_X/100
	.half	ft_lk,0x140*S_X/100
	.half	0
	.half	0x7c				/* sound: excellent */

	.word	OVL_END3
	.word	txt_sal
	.half	0xc8*S_X/100,0x10
	.word	0 
	.half	ft_indian,0x50*S_X/100
	.half	ft_robo1,0xa0*S_X/100
	.half	ft_robo2,0xf0*S_X/100
	.half	ft_smoke,0x140*S_X/100
	.half	0
	.half	0x7e				/* sound: outstanding */

	.word	OVL_END4
	.word	txt_turk
	.half	0xc8*S_X/100,0x10
	.word	0
	.half	ft_subzero,0x30*S_X/100
	.half	ft_st,0x78*S_X/100
	.half	ft_scorpion,0xd8*S_X/100
	.half	ft_reptile,0x128*S_X/100
	.half	ft_ermac,0x160*S_X/100
	.half	0
	.half	0x79				/* sound: laugh */

	.word	OVL_END5
	.word	txt_becky
	.half	0xc8*S_X/100,0x10
	.word	0
	.half	ft_kitana,0x50*S_X/100
	.half	ft_jade,0xc8*S_X/100
	.half	ft_mileena,0x140*S_X/100
	.half	0
	.half	0x74				/* sound: Superb */

	.word	OVL_END6
	.word	txt_as_lia
	.half	0x50*S_X/100,0x10
	.word	txt_as_sk
	.half	0xc8*S_X/100,0x10
	.word	txt_as_lao
	.half	0x140*S_X/100,0x10
	.word	txt_ssr
	.half	0xc8*S_X/100,0xbe
	.word	0
	.half	ft_lia,0x50*S_X/100
	.half	ft_sk,0xc8*S_X/100
	.half	ft_lao,0x140*S_X/100
	.half	0
	.half	0x66				/* sound: sk crispy */

	.word	0

	.align 2
	.globl	txt_as_kano
txt_as_kano:
	.asciiz	"RICHARD\nDIVIZIO\nAS\nKANO"

	.align 2
	.globl	txt_as_sonya
txt_as_sonya:
	.asciiz	"KERRI\nHOSKINS\nAS\nSONYA"

	.align 2
	.globl	txt_as_kabal
txt_as_kabal:
	.asciiz	"RICHARD\nDIVIZIO\nAS\nKABAL"

	.align 2
	.globl	txt_as_jax
txt_as_jax:
	.asciiz	"JOHN\nPARRISH\nAS\nJAX"

	.align 2
	.globl	txt_as_swat
txt_as_swat:
	.asciiz	"MICHAEL\nOBRIEN\nAS\nSTRYKER"

	.align 2
	.globl	txt_as_lk
txt_as_lk:
	.asciiz	"EDDIE\nWONG\nAS\nLIU KANG"

	.align 2
	.globl	txt_as_sk
txt_as_sk:
	.asciiz	"BRIAN\nLYNN\nAS\nSHAO KAHN"

	.align 2
	.globl	txt_as_lao
txt_as_lao:
	.asciiz	"TONY\nMARQUEZ\nAS\nKUNG LAO"

	.align 2
	.globl	txt_as_lia
txt_as_lia:
	.asciiz	"LIA\nMONTELONGO\nAS\nSINDEL"


	.align 2
	.globl	txt_sal
txt_sal:
	.ascii	"SAL DIVITA\nAS\n"
	.asciiz	"NIGHTWOLF     SEKTOR      CYRAX      SMOKE"

	.align 2
	.globl	txt_turk
txt_turk:
	.ascii	"JOHN TURK\nAS\n"
	.asciiz	"SUB-ZERO  SHANG TSUNG  SCORPION  REPTILE  ERMAC"

	.align 2
	.globl	txt_becky
txt_becky:
	.ascii	"BECKY GABLE\nAS\n\n"
	.asciiz	"  KITANA                  JADE              MILEENA"

	.align 2
	.globl	txt_ssr
txt_ssr:
	.asciiz	"STEVE RITCHIE AS\nTHE VOICE OF SHAO KAHN"
#endif

/* legals */
	.align 2
	.globl txt_legals
txt_legals:
#if 1
	.ascii	"MORTAL KOMBAT[ TRILOGY\n"
	.ascii	"]1996 MIDWAY MANUFACTURING COMPANY\n"
	.ascii	"ALL RIGHTS RESERVED.\n"
	.ascii	"MIDWAY, MORTAL KOMBAT, THE DRAGON\n"
	.ascii	"DESIGN AND ALL THE CHARACTER NAMES\n"
	.ascii	"ARE TRADEMARKS OF\n"
	.ascii	"MIDWAY MANUFACTURING COMPANY.\n"
	.ascii	"DISTRIBUTED UNDER LICENSE BY\nWILLIAMS ENTERTAINMENT INC.\n"
	.ascii	"WILLIAMS[ IS A REGISTERED TRADEMARK\n"
	.ascii	"OF WILLIAMS ELECTRONICS GAMES, INC.\nUSED BY PERMISSION.\n"
	.asciiz	"LICENSED BY NINTENDO\n"
#else	
	.ascii	"MORTAL KOMBAT[ TRILOGY\n"
	.ascii	"]1996 MIDWAY MANUFACTURING COMPANY\n"
	.ascii	"ALL RIGHTS RESERVED. MIDWAY,\n"
	.ascii	"MORTAL KOMBAT, THE DRAGON DESIGN\n"
	.ascii	"AND ALL THE CHARACTER NAMES ARE\n"
	.ascii	"TRADEMARKS OF MIDWAY MANUFACTURING \n"
	.ascii	"COMPANY. DISTRIBUTED BY \n"
	.ascii	"GT INTERACTIVE SOFTWARE, INC.\n"
	.ascii	"UNDER LICENSE BY\nWILLIAMS ENTERTAINMENT INC.\n"
	.ascii	"WILLIAMS[ IS A REGISTERED TRADEMARK\n"
	.ascii	"OF WILLIAMS ELECTRONICS GAMES, INC.\nUSED BY PERMISSION.\n"
	.asciiz	"LICENSED BY NINTENDO\n"
#endif	
	

		   