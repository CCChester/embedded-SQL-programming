static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,98,66,50,66,88,74,72,104,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,67,50,55,54,67,72,
 69,78,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,77,65,73,78,84,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "bibmaint.sqc"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define BUF_SIZE 4096

/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 5 "bibmaint.sqc"


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 6 "bibmaint.sqc"

     sqlint32 aid;
     char name[23];
     char url[43];
     char pubid[11];
     sqlint32 aorder;
     char title[71];
     char publisher[51];
     sqlint32 year;
     sqlint32 volume;
     sqlint32 number;
     char appearsin[11];
     sqlint32 startpage;
     sqlint32 endpage;
     sqlint32 check_value;
     const char db[6] = "CS348";

/*
EXEC SQL END DECLARE SECTION;
*/

#line 22 "bibmaint.sqc"


void author(){
	aid = atoi(strtok(NULL, "#"));
	char *mytemp;
	mytemp = strtok(NULL,")");
	strcpy(name,mytemp);
	
/*
EXEC SQL select count(*) INTO :check_value from author where aid = :aid;
*/

{
#line 29 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 29 "bibmaint.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 29 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 29 "bibmaint.sqc"
  sqlaaloc(3,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&check_value;
#line 29 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 29 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 29 "bibmaint.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 29 "bibmaint.sqc"
  sqlastop(0L);
}

#line 29 "bibmaint.sqc"

    if(check_value == 0){
      
/*
EXEC SQL insert into author (aid,name) values (:aid, :name);
*/

{
#line 31 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 31 "bibmaint.sqc"
  sqlaaloc(2,2,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 31 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 31 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 31 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 31 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 23;
#line 31 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)name;
#line 31 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 31 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 31 "bibmaint.sqc"
  sqlacall((unsigned short)24,2,2,0,0L);
#line 31 "bibmaint.sqc"
  sqlastop(0L);
}

#line 31 "bibmaint.sqc"

	}
    else{
   	  
/*
EXEC SQL update author set name = :name where aid = :aid;
*/

{
#line 34 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 34 "bibmaint.sqc"
  sqlaaloc(2,2,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 34 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 23;
#line 34 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 34 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 34 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 34 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 34 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 34 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 34 "bibmaint.sqc"
  sqlacall((unsigned short)24,3,2,0,0L);
#line 34 "bibmaint.sqc"
  sqlastop(0L);
}

#line 34 "bibmaint.sqc"

    }
	printf("Author ID: %d\nName:%s\n", aid, name);
}

void authorurl(){
	aid = atoi(strtok(NULL,"#"));
	char *mytemp;
	mytemp = strtok(NULL,"");
	printf("Anthor ID:%d\nURL:%s\n", aid, url);
	
/*
EXEC SQL update author set url = :url where aid = :aid;
*/

{
#line 44 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 44 "bibmaint.sqc"
  sqlaaloc(2,2,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 44 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 43;
#line 44 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)url;
#line 44 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 44 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 44 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 44 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 44 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 44 "bibmaint.sqc"
  sqlacall((unsigned short)24,4,2,0,0L);
#line 44 "bibmaint.sqc"
  sqlastop(0L);
}

#line 44 "bibmaint.sqc"

}

void journal(){
	char *mytemp;
    mytemp = strtok(NULL,"#");
    strcpy(pubid,mytemp);
    mytemp = strtok(NULL,"#");
    strcpy(title,mytemp);
    
/*
EXEC SQL delete from wrote where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 54 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 54 "bibmaint.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 54 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 54 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 54 "bibmaint.sqc"
  sqlacall((unsigned short)24,5,2,0,0L);
#line 54 "bibmaint.sqc"
  sqlastop(0L);
}

#line 54 "bibmaint.sqc"

    
/*
EXEC SQL delete from proceedings where pubid in
     (select pubid from publication where pubid = :pubid);
*/

{
#line 56 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 56 "bibmaint.sqc"
  sqlaaloc(2,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 56 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 56 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 56 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 56 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 56 "bibmaint.sqc"
  sqlacall((unsigned short)24,6,2,0,0L);
#line 56 "bibmaint.sqc"
  sqlastop(0L);
}

#line 56 "bibmaint.sqc"

    
/*
EXEC SQL delete from jornal where pubid in
     (select pupid from publication where pubid = :pubid);
*/

/*
SQL0204N  "C276CHEN.JORNAL" is an undefined name.  
SQLSTATE=42704

*/

{
#line 58 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 58 "bibmaint.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 58 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 58 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 58 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 58 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 58 "bibmaint.sqc"
  sqlacall((unsigned short)24,7,2,0,0L);
#line 58 "bibmaint.sqc"
  sqlastop(0L);
}

#line 58 "bibmaint.sqc"

    
/*
EXEC SQL delete from book where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 60 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 60 "bibmaint.sqc"
  sqlaaloc(2,1,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 60 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 60 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 60 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 60 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 60 "bibmaint.sqc"
  sqlacall((unsigned short)24,8,2,0,0L);
#line 60 "bibmaint.sqc"
  sqlastop(0L);
}

#line 60 "bibmaint.sqc"

    
/*
EXEC SQL delete from article where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 62 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 62 "bibmaint.sqc"
  sqlaaloc(2,1,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 62 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 62 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 62 "bibmaint.sqc"
  sqlacall((unsigned short)24,9,2,0,0L);
#line 62 "bibmaint.sqc"
  sqlastop(0L);
}

#line 62 "bibmaint.sqc"

    
/*
EXEC SQL select count(*) INTO: check_value from 
      publication where pubid = :pubid;
*/

{
#line 64 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 64 "bibmaint.sqc"
  sqlaaloc(2,1,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 64 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 64 "bibmaint.sqc"
  sqlaaloc(3,1,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&check_value;
#line 64 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 64 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 64 "bibmaint.sqc"
  sqlacall((unsigned short)24,10,2,3,0L);
#line 64 "bibmaint.sqc"
  sqlastop(0L);
}

#line 64 "bibmaint.sqc"

    if(check_value == 0){
      
/*
EXEC SQL insert into publication values (:pubid, :title);
*/

{
#line 66 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 66 "bibmaint.sqc"
  sqlaaloc(2,2,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 66 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 66 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 71;
#line 66 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 66 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 66 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 66 "bibmaint.sqc"
  sqlacall((unsigned short)24,11,2,0,0L);
#line 66 "bibmaint.sqc"
  sqlastop(0L);
}

#line 66 "bibmaint.sqc"

    }
    else{
      
/*
EXEC SQL update publication set title = :title where pubid = :pubid;
*/

{
#line 69 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 69 "bibmaint.sqc"
  sqlaaloc(2,2,14,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 69 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 71;
#line 69 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 69 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 69 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 69 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 69 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 69 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 69 "bibmaint.sqc"
  sqlacall((unsigned short)24,12,2,0,0L);
#line 69 "bibmaint.sqc"
  sqlastop(0L);
}

#line 69 "bibmaint.sqc"

    }
	volume = atoi(strtok(NULL,"#"));
    number = atoi(strtok(NULL,"#"));
    year = atoi(strtok(NULL,")"));
    printf("Pubid: %s\n", pubid);
    printf("Type: journal\n");
    printf("Authors:\n");
    printf("Title: %s\n", title);
    printf("Volume: %d\nNumber: %d\nYear:%d\n", volume, number, year);
    
/*
EXEC SQL insert into journal values (:pubid, :volume, :number, :year);
*/

{
#line 79 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 79 "bibmaint.sqc"
  sqlaaloc(2,4,15,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 79 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 79 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 79 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 79 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 79 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&volume;
#line 79 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 79 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 79 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&number;
#line 79 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 79 "bibmaint.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 79 "bibmaint.sqc"
      sql_setdlist[3].sqldata = (void*)&year;
#line 79 "bibmaint.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 79 "bibmaint.sqc"
      sqlasetdata(2,0,4,sql_setdlist,0L,0L);
    }
#line 79 "bibmaint.sqc"
  sqlacall((unsigned short)24,13,2,0,0L);
#line 79 "bibmaint.sqc"
  sqlastop(0L);
}

#line 79 "bibmaint.sqc"

}

void proceedings(){
	char *mytemp;
    mytemp = strtok(NULL,"#");
    strcpy(pubid,mytemp);
    mytemp = strtok(NULL,"#");
    strcpy(title,mytemp);
    
/*
EXEC SQL delete from wrote where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 89 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 89 "bibmaint.sqc"
  sqlaaloc(2,1,16,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 89 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 89 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 89 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 89 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 89 "bibmaint.sqc"
  sqlacall((unsigned short)24,14,2,0,0L);
#line 89 "bibmaint.sqc"
  sqlastop(0L);
}

#line 89 "bibmaint.sqc"

    
/*
EXEC SQL delete from proceedings where pubid in
     (select pubid from publication where pubid = :pubid);
*/

{
#line 91 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 91 "bibmaint.sqc"
  sqlaaloc(2,1,17,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 91 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 91 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 91 "bibmaint.sqc"
  sqlacall((unsigned short)24,15,2,0,0L);
#line 91 "bibmaint.sqc"
  sqlastop(0L);
}

#line 91 "bibmaint.sqc"

    
/*
EXEC SQL delete from jornal where pubid in
     (select pupid from publication where pubid = :pubid);
*/

/*
SQL0204N  "C276CHEN.JORNAL" is an undefined name.  
SQLSTATE=42704

*/

{
#line 93 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 93 "bibmaint.sqc"
  sqlaaloc(2,1,18,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 93 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 93 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 93 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 93 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 93 "bibmaint.sqc"
  sqlacall((unsigned short)24,16,2,0,0L);
#line 93 "bibmaint.sqc"
  sqlastop(0L);
}

#line 93 "bibmaint.sqc"

    
/*
EXEC SQL delete from book where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 95 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 95 "bibmaint.sqc"
  sqlaaloc(2,1,19,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 95 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 95 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 95 "bibmaint.sqc"
  sqlacall((unsigned short)24,17,2,0,0L);
#line 95 "bibmaint.sqc"
  sqlastop(0L);
}

#line 95 "bibmaint.sqc"

    
/*
EXEC SQL delete from article where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 97 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 97 "bibmaint.sqc"
  sqlaaloc(2,1,20,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 97 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 97 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 97 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 97 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 97 "bibmaint.sqc"
  sqlacall((unsigned short)24,18,2,0,0L);
#line 97 "bibmaint.sqc"
  sqlastop(0L);
}

#line 97 "bibmaint.sqc"

    
/*
EXEC SQL select count(*) INTO: check_value from 
      publication where pubid = :pubid;
*/

{
#line 99 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 99 "bibmaint.sqc"
  sqlaaloc(2,1,21,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 99 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 99 "bibmaint.sqc"
  sqlaaloc(3,1,22,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&check_value;
#line 99 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 99 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 99 "bibmaint.sqc"
  sqlacall((unsigned short)24,19,2,3,0L);
#line 99 "bibmaint.sqc"
  sqlastop(0L);
}

#line 99 "bibmaint.sqc"

    if(check_value == 0){
      
/*
EXEC SQL insert into publication values (:pubid, :title);
*/

{
#line 101 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 101 "bibmaint.sqc"
  sqlaaloc(2,2,23,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 101 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 101 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 101 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 101 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 71;
#line 101 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 101 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 101 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 101 "bibmaint.sqc"
  sqlacall((unsigned short)24,20,2,0,0L);
#line 101 "bibmaint.sqc"
  sqlastop(0L);
}

#line 101 "bibmaint.sqc"

    }
    else{
      
/*
EXEC SQL update publication set title = :title where pubid = :pubid;
*/

{
#line 104 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 104 "bibmaint.sqc"
  sqlaaloc(2,2,24,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 104 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 71;
#line 104 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 104 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 104 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 104 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 104 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 104 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 104 "bibmaint.sqc"
  sqlacall((unsigned short)24,21,2,0,0L);
#line 104 "bibmaint.sqc"
  sqlastop(0L);
}

#line 104 "bibmaint.sqc"

    }
	year = atoi(strtok(NULL,")"));
	printf("Pubid: %s\n", pubid);
    printf("Type: proceedings\n");
    printf("Authors:\n");
    printf("Title: %s\n", title);
    printf("Year: %d\n", year);
    
/*
EXEC SQL insert into proceedings values (:pubid, :year);
*/

{
#line 112 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 112 "bibmaint.sqc"
  sqlaaloc(2,2,25,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 112 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 112 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 112 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 112 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 112 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)&year;
#line 112 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 112 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 112 "bibmaint.sqc"
  sqlacall((unsigned short)24,22,2,0,0L);
#line 112 "bibmaint.sqc"
  sqlastop(0L);
}

#line 112 "bibmaint.sqc"

}

void book(){
	char *mytemp;
    mytemp = strtok(NULL,"#");
    strcpy(pubid,mytemp);
    mytemp = strtok(NULL,"#");
    strcpy(title,mytemp);
    
/*
EXEC SQL delete from wrote where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 122 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 122 "bibmaint.sqc"
  sqlaaloc(2,1,26,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 122 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 122 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 122 "bibmaint.sqc"
  sqlacall((unsigned short)24,23,2,0,0L);
#line 122 "bibmaint.sqc"
  sqlastop(0L);
}

#line 122 "bibmaint.sqc"

    
/*
EXEC SQL delete from proceedings where pubid in
     (select pubid from publication where pubid = :pubid);
*/

{
#line 124 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 124 "bibmaint.sqc"
  sqlaaloc(2,1,27,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 124 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 124 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 124 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 124 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 124 "bibmaint.sqc"
  sqlacall((unsigned short)24,24,2,0,0L);
#line 124 "bibmaint.sqc"
  sqlastop(0L);
}

#line 124 "bibmaint.sqc"

    
/*
EXEC SQL delete from jornal where pubid in
     (select pupid from publication where pubid = :pubid);
*/

/*
SQL0204N  "C276CHEN.JORNAL" is an undefined name.  
SQLSTATE=42704

*/

{
#line 126 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 126 "bibmaint.sqc"
  sqlaaloc(2,1,28,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 126 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 126 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 126 "bibmaint.sqc"
  sqlacall((unsigned short)24,25,2,0,0L);
#line 126 "bibmaint.sqc"
  sqlastop(0L);
}

#line 126 "bibmaint.sqc"

    
/*
EXEC SQL delete from book where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 128 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 128 "bibmaint.sqc"
  sqlaaloc(2,1,29,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 128 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 128 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 128 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 128 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 128 "bibmaint.sqc"
  sqlacall((unsigned short)24,26,2,0,0L);
#line 128 "bibmaint.sqc"
  sqlastop(0L);
}

#line 128 "bibmaint.sqc"

    
/*
EXEC SQL delete from article where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 130 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 130 "bibmaint.sqc"
  sqlaaloc(2,1,30,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 130 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 130 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 130 "bibmaint.sqc"
  sqlacall((unsigned short)24,27,2,0,0L);
#line 130 "bibmaint.sqc"
  sqlastop(0L);
}

#line 130 "bibmaint.sqc"

    
/*
EXEC SQL select count(*) INTO: check_value from 
      publication where pubid = :pubid;
*/

{
#line 132 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 132 "bibmaint.sqc"
  sqlaaloc(2,1,31,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 132 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 132 "bibmaint.sqc"
  sqlaaloc(3,1,32,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&check_value;
#line 132 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 132 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 132 "bibmaint.sqc"
  sqlacall((unsigned short)24,28,2,3,0L);
#line 132 "bibmaint.sqc"
  sqlastop(0L);
}

#line 132 "bibmaint.sqc"

    if(check_value == 0){
      
/*
EXEC SQL insert into publication values (:pubid, :title);
*/

{
#line 134 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 134 "bibmaint.sqc"
  sqlaaloc(2,2,33,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 134 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 134 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 134 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 134 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 71;
#line 134 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 134 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 134 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 134 "bibmaint.sqc"
  sqlacall((unsigned short)24,29,2,0,0L);
#line 134 "bibmaint.sqc"
  sqlastop(0L);
}

#line 134 "bibmaint.sqc"

    }
    else{
      
/*
EXEC SQL update publication set title = :title where pubid = :pubid;
*/

{
#line 137 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 137 "bibmaint.sqc"
  sqlaaloc(2,2,34,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 137 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 71;
#line 137 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 137 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 137 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 137 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 137 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 137 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 137 "bibmaint.sqc"
  sqlacall((unsigned short)24,30,2,0,0L);
#line 137 "bibmaint.sqc"
  sqlastop(0L);
}

#line 137 "bibmaint.sqc"

    }
	char *newchar;
	char *newauthor;
	newauthor = strtok(NULL,"#");
	newchar = strtok(NULL, "#");
	strcpy(publisher,newchar);
	year = atoi(strtok(NULL, ")"));
	printf("Pubid: %s\n", pubid);
    printf("Type: book\n");
    char *mytemp2 = newauthor;
    printf("Authors: ", pubid); 
    int aorder = 1;
    while (mytemp2 = strtok(mytemp2,";")){
        aid = atoi(mytemp);
        
/*
EXEC SQL insert into wrote (aid,pubid,aorder) values (:aid, :pubid, :aorder);
*/

{
#line 152 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 152 "bibmaint.sqc"
  sqlaaloc(2,3,35,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 152 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 152 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 152 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 152 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 152 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 152 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 152 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 152 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&aorder;
#line 152 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 152 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 152 "bibmaint.sqc"
  sqlacall((unsigned short)24,31,2,0,0L);
#line 152 "bibmaint.sqc"
  sqlastop(0L);
}

#line 152 "bibmaint.sqc"

        
/*
EXEC SQL select trim(name) INTO :name from author where aid = :aid;
*/

{
#line 153 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 153 "bibmaint.sqc"
  sqlaaloc(2,1,36,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 153 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 153 "bibmaint.sqc"
  sqlaaloc(3,1,37,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 23;
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 153 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 153 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 153 "bibmaint.sqc"
  sqlacall((unsigned short)24,32,2,3,0L);
#line 153 "bibmaint.sqc"
  sqlastop(0L);
}

#line 153 "bibmaint.sqc"

        printf("%s", name);
        if ((mytemp2 = strtok(NULL,";")) == NULL){
            break;
        }
        printf(", ");
        aorder++;
    }
    printf("");
    printf("\n");
    printf("Publisher: %s\nYear:%d\n", publisher, year);
    
/*
EXEC SQL insert into book values (:pubid, :publisher, :year);
*/

{
#line 164 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 164 "bibmaint.sqc"
  sqlaaloc(2,3,38,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 164 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 164 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 164 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 164 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 51;
#line 164 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)publisher;
#line 164 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 164 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 164 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&year;
#line 164 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 164 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 164 "bibmaint.sqc"
  sqlacall((unsigned short)24,33,2,0,0L);
#line 164 "bibmaint.sqc"
  sqlastop(0L);
}

#line 164 "bibmaint.sqc"

}

void article(){
	char *mytemp;
    mytemp = strtok(NULL,"#");
    strcpy(pubid,mytemp);
    mytemp = strtok(NULL,"#");
    strcpy(title,mytemp);
    
/*
EXEC SQL delete from wrote where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 174 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 174 "bibmaint.sqc"
  sqlaaloc(2,1,39,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 174 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 174 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 174 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 174 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 174 "bibmaint.sqc"
  sqlacall((unsigned short)24,34,2,0,0L);
#line 174 "bibmaint.sqc"
  sqlastop(0L);
}

#line 174 "bibmaint.sqc"

    
/*
EXEC SQL delete from proceedings where pubid in
     (select pubid from publication where pubid = :pubid);
*/

{
#line 176 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 176 "bibmaint.sqc"
  sqlaaloc(2,1,40,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 176 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 176 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 176 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 176 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 176 "bibmaint.sqc"
  sqlacall((unsigned short)24,35,2,0,0L);
#line 176 "bibmaint.sqc"
  sqlastop(0L);
}

#line 176 "bibmaint.sqc"

    
/*
EXEC SQL delete from jornal where pubid in
     (select pupid from publication where pubid = :pubid);
*/

/*
SQL0204N  "C276CHEN.JORNAL" is an undefined name.  
SQLSTATE=42704

*/

{
#line 178 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 178 "bibmaint.sqc"
  sqlaaloc(2,1,41,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 178 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 178 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 178 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 178 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 178 "bibmaint.sqc"
  sqlacall((unsigned short)24,36,2,0,0L);
#line 178 "bibmaint.sqc"
  sqlastop(0L);
}

#line 178 "bibmaint.sqc"

    
/*
EXEC SQL delete from book where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 180 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 180 "bibmaint.sqc"
  sqlaaloc(2,1,42,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 180 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 180 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 180 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 180 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 180 "bibmaint.sqc"
  sqlacall((unsigned short)24,37,2,0,0L);
#line 180 "bibmaint.sqc"
  sqlastop(0L);
}

#line 180 "bibmaint.sqc"

    
/*
EXEC SQL delete from article where pubid in 
     (select pubid from publication where pubid = :pubid);
*/

{
#line 182 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 182 "bibmaint.sqc"
  sqlaaloc(2,1,43,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 182 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 182 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 182 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 182 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 182 "bibmaint.sqc"
  sqlacall((unsigned short)24,38,2,0,0L);
#line 182 "bibmaint.sqc"
  sqlastop(0L);
}

#line 182 "bibmaint.sqc"

    
/*
EXEC SQL select count(*) INTO: check_value from 
      publication where pubid = :pubid;
*/

{
#line 184 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 184 "bibmaint.sqc"
  sqlaaloc(2,1,44,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 184 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 184 "bibmaint.sqc"
  sqlaaloc(3,1,45,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&check_value;
#line 184 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 184 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 184 "bibmaint.sqc"
  sqlacall((unsigned short)24,39,2,3,0L);
#line 184 "bibmaint.sqc"
  sqlastop(0L);
}

#line 184 "bibmaint.sqc"

    if(check_value == 0){
      
/*
EXEC SQL insert into publication values (:pubid, :title);
*/

{
#line 186 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 186 "bibmaint.sqc"
  sqlaaloc(2,2,46,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 186 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 186 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 186 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 186 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 71;
#line 186 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 186 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 186 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 186 "bibmaint.sqc"
  sqlacall((unsigned short)24,40,2,0,0L);
#line 186 "bibmaint.sqc"
  sqlastop(0L);
}

#line 186 "bibmaint.sqc"

    }
    else{
      
/*
EXEC SQL update publication set title = :title where pubid = :pubid;
*/

{
#line 189 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 189 "bibmaint.sqc"
  sqlaaloc(2,2,47,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 189 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 71;
#line 189 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 189 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 189 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 189 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 189 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 189 "bibmaint.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 189 "bibmaint.sqc"
  sqlacall((unsigned short)24,41,2,0,0L);
#line 189 "bibmaint.sqc"
  sqlastop(0L);
}

#line 189 "bibmaint.sqc"

    }
	char *newchar;
	char *newauthor;
	newauthor = strtok(NULL,"#");
    newchar = strtok(NULL,"#");
    strcpy(appearsin, newchar);
    startpage = atoi(strtok(NULL,"#"));
    endpage = atoi(strtok(NULL,"#"));
    printf("Pubid: %s\n", pubid);
    printf("Type: article\n");
    char *mytemp2 = newauthor;
    printf("Authors: ", pubid); 
    int aorder = 1;
    while(mytemp = strtok(mytemp2,";")){
        aid = atoi(mytemp2);
        
/*
EXEC SQL insert into wrote (aid,pubid,aorder) values (:aid, :pubid, :aorder);
*/

{
#line 205 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 205 "bibmaint.sqc"
  sqlaaloc(2,3,48,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 205 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 205 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 205 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 205 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 205 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)pubid;
#line 205 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 205 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 205 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&aorder;
#line 205 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 205 "bibmaint.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 205 "bibmaint.sqc"
  sqlacall((unsigned short)24,42,2,0,0L);
#line 205 "bibmaint.sqc"
  sqlastop(0L);
}

#line 205 "bibmaint.sqc"

        
/*
EXEC SQL select trim(name) INTO :name from author where aid = :aid;
*/

{
#line 206 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 206 "bibmaint.sqc"
  sqlaaloc(2,1,49,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 206 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 206 "bibmaint.sqc"
  sqlaaloc(3,1,50,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 23;
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 206 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 206 "bibmaint.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 206 "bibmaint.sqc"
  sqlacall((unsigned short)24,43,2,3,0L);
#line 206 "bibmaint.sqc"
  sqlastop(0L);
}

#line 206 "bibmaint.sqc"

        printf("%s", name);
        if ((mytemp2 = strtok(NULL,";")) == NULL){
            break;
        }
        printf(", ");
        aorder++;
    }
    printf("");
    printf("\n");
    printf("Title: %s\n", title);
    printf("In:%s\nPages: %d-%d\n", appearsin, startpage, endpage);
    
/*
EXEC SQL insert into article values (:pubid, :appearsin, :startpage, :endpage);
*/

{
#line 218 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 218 "bibmaint.sqc"
  sqlaaloc(2,4,51,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 218 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 218 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)pubid;
#line 218 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 218 "bibmaint.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 11;
#line 218 "bibmaint.sqc"
      sql_setdlist[1].sqldata = (void*)appearsin;
#line 218 "bibmaint.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 218 "bibmaint.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 218 "bibmaint.sqc"
      sql_setdlist[2].sqldata = (void*)&startpage;
#line 218 "bibmaint.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 218 "bibmaint.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 218 "bibmaint.sqc"
      sql_setdlist[3].sqldata = (void*)&endpage;
#line 218 "bibmaint.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 218 "bibmaint.sqc"
      sqlasetdata(2,0,4,sql_setdlist,0L,0L);
    }
#line 218 "bibmaint.sqc"
  sqlacall((unsigned short)24,44,2,0,0L);
#line 218 "bibmaint.sqc"
  sqlastop(0L);
}

#line 218 "bibmaint.sqc"

}

int main(){
	
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 222 "bibmaint.sqc"

	
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 223 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 223 "bibmaint.sqc"
  sqlaaloc(2,1,52,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 223 "bibmaint.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 223 "bibmaint.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 223 "bibmaint.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 223 "bibmaint.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 223 "bibmaint.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 223 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 223 "bibmaint.sqc"
  sqlastop(0L);
}

#line 223 "bibmaint.sqc"

    printf("CONNECTED\n");
    size_t bufsize = (BUF_SIZE);
    char *token;
    char *args = malloc(BUF_SIZE);
    while(getline(&args,&bufsize,stdin)){
    	if(feof(stdin)){
    		break;
    	}
    	token = strtok(args, "(");
    	if (strcmp(token,"author") == 0){
            author();
    	} 
        if (strcmp(token,"authorurl") == 0) {
        	authorurl();
        }
        if (strcmp(token,"book") == 0){
        	book();
        }
        if (strcmp(token,"journal") == 0){
        	journal();
        }
        if (strcmp(token,"proceedings") == 0){
        	proceedings();
        }
        if (strcmp(token,"article") == 0){
        	article();
        }
    }
    free(args);
	
/*
EXEC SQL COMMIT;
*/

{
#line 253 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 253 "bibmaint.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 253 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 253 "bibmaint.sqc"
  sqlastop(0L);
}

#line 253 "bibmaint.sqc"

	
/*
EXEC SQL CONNECT reset;
*/

{
#line 254 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 254 "bibmaint.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 254 "bibmaint.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 254 "bibmaint.sqc"
  sqlastop(0L);
}

#line 254 "bibmaint.sqc"

	exit(0);
error:
	check_error("My error",&sqlca);
	
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 258 "bibmaint.sqc"

	
/*
EXEC SQL ROLLBACK;
*/

{
#line 259 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 259 "bibmaint.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 259 "bibmaint.sqc"
  sqlastop(0L);
}

#line 259 "bibmaint.sqc"

	
/*
EXEC SQL CONNECT reset;
*/

{
#line 260 "bibmaint.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 260 "bibmaint.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 260 "bibmaint.sqc"
  sqlastop(0L);
}

#line 260 "bibmaint.sqc"

	return 1;
}
