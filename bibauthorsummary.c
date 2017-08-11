static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,79,66,50,66,88,74,72,104,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,67,50,55,54,67,72,
 69,78,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,65,85,84,72,79,0,0,0,0,0,0,0,0,
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


#line 1 "bibauthorsummary.sqc"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <string.h>

/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 5 "bibauthorsummary.sqc"
 
int main(int argc, char *argv[]){
   
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 7 "bibauthorsummary.sqc"

   char name[23];
   sqlint32 a;
   sqlint32 b;
   sqlint32 myaid;
   char db[6] = "cs348";
   
/*
EXEC SQL END DECLARE SECTION;
*/

#line 13 "bibauthorsummary.sqc"

   printf("Sample C program: CONNECT\n");
   
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 15 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 16 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 16 "bibauthorsummary.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 16 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 16 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 16 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 16 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 16 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 16 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 16 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 16 "bibauthorsummary.sqc"

   printf("Connected to DB2\n");
   strcpy(name,argv[1]);
   printf("%s ", name);
   
/*
EXEC SQL SELECT aid INTO :myaid from author where name = :name;
*/

{
#line 20 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 20 "bibauthorsummary.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 23;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 20 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 20 "bibauthorsummary.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)&myaid;
#line 20 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 20 "bibauthorsummary.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 20 "bibauthorsummary.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 20 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 20 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 20 "bibauthorsummary.sqc"

   printf("(aid:%d)\n",myaid);
   
/*
EXEC SQL DECLARE cursor1 CURSOR FOR 
             select count (*) as c1, numberOfAuthor from 
             (SELECT pubid,count(*) as numberOfAuthor FROM wrote where pubid in 
               (select pubid from wrote where aid=:myaid) group by pubid) 
             group by numberOfAuthor;
*/

#line 26 "bibauthorsummary.sqc"

   
/*
EXEC SQL OPEN cursor1;
*/

{
#line 27 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 27 "bibauthorsummary.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 27 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 27 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)&myaid;
#line 27 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 27 "bibauthorsummary.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 27 "bibauthorsummary.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 27 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 27 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 27 "bibauthorsummary.sqc"

   for (;;){
     
/*
EXEC SQL FETCH cursor1 INTO :a, :b;
*/

{
#line 29 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 29 "bibauthorsummary.sqc"
  sqlaaloc(3,2,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[0].sqldata = (void*)&a;
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[1].sqldata = (void*)&b;
#line 29 "bibauthorsummary.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 29 "bibauthorsummary.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 29 "bibauthorsummary.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 29 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 29 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 29 "bibauthorsummary.sqc"

     if(SQLCODE==100){
      break;
     }
     if (SQLCODE<0){
      break;
     }
     if(b == 1){
      printf("%d:%d\n",a,b-1);
     }
     else{printf("%d:%d\n",a,b);}
   };
   
/*
EXEC SQL CLOSE cursor1;
*/

{
#line 41 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 41 "bibauthorsummary.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 41 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 41 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 41 "bibauthorsummary.sqc"

   
/*
EXEC SQL COMMIT;
*/

{
#line 42 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 42 "bibauthorsummary.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 42 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 42 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 42 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT reset;
*/

{
#line 43 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 43 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 43 "bibauthorsummary.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 43 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 43 "bibauthorsummary.sqc"

   exit(0);
error:
   check_error("My error",&sqlca);
   
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 47 "bibauthorsummary.sqc"

   
/*
EXEC SQL ROLLBACK;
*/

{
#line 48 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 48 "bibauthorsummary.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 48 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 48 "bibauthorsummary.sqc"

   
/*
EXEC SQL CONNECT reset;
*/

{
#line 49 "bibauthorsummary.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 49 "bibauthorsummary.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 49 "bibauthorsummary.sqc"
  sqlastop(0L);
}

#line 49 "bibauthorsummary.sqc"

   exit(1);
}
