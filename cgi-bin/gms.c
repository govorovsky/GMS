#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gms.h"
#include "gen_index.h"
#include "add_message.h"

char *cgi_data;

 
/*
После получения данных от сервера их надо еще декодировать. Можно это сделать сразу, а можно по мере надобности. Если Вы будете это делать сразу, то Вам также придется их разбить на куски, так как при декодировании могут появиться лишние знаки "&" и "=", которые больше не позволят вам отделять пары "имя=значение" друг от друга.

Вот пример процедуры, которая декодирует данные из буфера:
*/
/* Возвращает верхний регистр символа*/
char upperchar(char ch)
{
  if ((ch>='a') && (ch<='z'))
  {
      ch='A'+(ch - 'a');
      return ch;
   }
  else return ch;
};

/* Переводит из Hex в Dec*/
char gethex(char  ch)
{
  ch=upperchar(ch);
  if ((ch>='0')&&(ch<= '9')) return (ch-'0');
  if ((ch>='A')&&( ch<='F')) return (ch-'A'+10);
  return 0;
};

/* 
  Ищет и возвращает параметр с именем name, в buffer.
  Если параметр name не найден, возвращает NULL.
  
Пример : message = getparam(post_buffer,"message=");

Замечание : символ "=" после имени параметра не удаляется
  и входит в возвращаемый результат, поэтому рекомендуется
  искать параметр вместе с символом "=".
 */
 
char *getparam(char *buffer,char *name)
{

 
 if (buffer==NULL) return NULL;


 char *pos;
 long leng=512,i=0,j=0;
 char h1,h2; //Тут была ещё переменная Hex

 char *p=(char *)malloc(leng);
 pos=strstr(buffer,name);
 if (pos == NULL) return NULL;

 if ((pos!=buffer) && (*(pos-1)!='&')) return NULL; 

 pos+=strlen(name);
 
 while ( (*(pos+i)!='&')&&( *(pos+i)!='\0' ))
 {
  if ( *(pos+i)=='%' )
  {
    i++;
    h1=gethex(*(pos+i));
    i++;
    h2=gethex(*(pos+i));
    h1=h1<<4;
    *(p+j)=h1+h2;
  }
  else
  {
    if (*(pos+i)!='+') *(p+j)=*(pos+i);
     else *(p+j)=' ';
  };
  i++;
  j++;
  if (j >= leng) p=(char*)realloc(p,leng+20);
  leng+=20;
 };
 if (j < leng) p=(char*)realloc(p,j+1);
      
 *(p+j)='\0';
 return p;
};














int main(void) 
{
 


/*
printf("<form action=\"http://localhost/cgi-bin/index.cgi\" method=GET>\
Введите свое имя пользователя:\
<input type=text maxlength=150 name=user>\
<p><input type=submit value=Send>\
</form>");
*/



  char *value=NULL;
  char *content=NULL;
  char *request_method=getenv("REQUEST_METHOD");
  if (strcmp(request_method,"GET")!=0)
	{
		printf("Content-type: text/html\n\n");
		printf("Unknown REQUEST_METHOD. Use only GET !\n");
		return -1;
	};
  
  content=getenv("QUERY_STRING");
  value=getparam(content,"set=");
  if(value==NULL) value="index";
  

if(strcmp("clock", value)==0)
{
#include "gen_clock.h"
GMS_block_big_clock_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_big_clock();
GMS_block_body_close();
};


if(strcmp("index", value)==0)

{
GMS_block_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_menu();
GMS_block_content_open();
GMS_block_content_post();
GMS_block_content_close();
GMS_block_welcom();
GMS_block_news();
GMS_block_about();
GMS_block_body_close();



};


if(strcmp("ping", value)==0)

{
GMS_block_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_menu();
GMS_block_content_open();

system("ping -c 5 vpn.murom.net > /tmp/gms-command-out");


FILE *fp;

fp=fopen("/tmp/gms-command-out","r");

char ch;
while((ch=getc(fp))!=EOF) 
{

if(ch=='\n'){printf("<br>");};
printf("%c",ch);




};
fclose(fp);
system("rm -f /tmp/gms-command-out");

GMS_block_content_close();
GMS_block_welcom();
GMS_block_news();
GMS_block_about();
GMS_block_body_close();



};


if(strcmp("ssh", value)==0)

{

#include "gms_ssh_vm.h"
GMS_block_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_menu();
GMS_block_content_open();
GMS_ssh_vm();
GMS_block_content_close();
GMS_block_welcom();
GMS_block_news();
GMS_block_about();
GMS_block_body_close();



};


if(strcmp("message", value)==0)

{
GMS_block_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_menu();
GMS_block_content_open();
GMS_add_message();
GMS_block_content_close();
GMS_block_welcom();
GMS_block_news();
GMS_block_about();
GMS_block_body_close();



};



if(strcmp("ls-repo", value)==0)

{
GMS_block_head();
GMS_block_body_open();
GMS_block_logo();
GMS_block_menu();
GMS_block_content_open();

system("cd  /media/draft/apt-repo; ls -R ./ > /tmp/gms-ls-apt-command-out");


FILE *fp;

fp=fopen("/tmp/gms-ls-apt-command-out","r");

char ch;
while((ch=getc(fp))!=EOF) 
{

if(ch=='\n'){printf("<br>");};


if(ch=='.'&&(ch=getc(fp))=='/'){printf("<h2>");};
if(ch==':'){ch=' ';printf("</h2>");};

printf("%c",ch);

};
fclose(fp);
system("rm -f /tmp/gms-ls-apt-command-out");

GMS_block_content_close();
GMS_block_welcom();
GMS_block_news();
GMS_block_about();
GMS_block_body_close();



};










return 0;
}
