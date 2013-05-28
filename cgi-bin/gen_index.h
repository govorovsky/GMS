




//1
/////////////////////////////////////////////////////////////////////////////////

void GMS_block_head(void)
{
printf("Content-Type: text/html; charset=utf-8\n\n");
printf("%s",head);

}
////////////////////////////////////////////////////////////////////////////////




//2
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_body_open(void)
{

printf("%s",body_open);

}
////////////////////////////////////////////////////////////////////////////////





//3
/////////////////////////////////////////////////////////////////////////////////
  const char LOCATION_TEXT_LOGO[]="/usr/lib/cgi-bin/base/static/block-logo";
  #define MAX_LINE_TEXT_LOGO 50


void GMS_block_logo(void)
{

FILE *fp;
char ch;
char GMSlogo[MAX_LINE_TEXT_LOGO]=" ";
 
  if((fp=fopen(LOCATION_TEXT_LOGO, "r"))==NULL)
  {
    printf("Опа, что-то пошло не так, \
                  логотип похоже кто-то съел, \
                  ещё маленько и мы это исправим.");
    exit(1);
  }
    
    int counter=0;

    while((ch=getc(fp))!=EOF) 
 {
    
  if(counter==MAX_LINE_TEXT_LOGO-1){printf("Опа, что-то пошло не так,\
  похоже кто-то превысил длинну %d символов у логотипа,    \
  ещё маленько и мы это исправим.",MAX_LINE_TEXT_LOGO);};

  if(ch=='\n') 
  {
      GMSlogo[counter++]='<';
      GMSlogo[counter++]='b';
      GMSlogo[counter++]='r';
      GMSlogo[counter++]='>';
  };
 
      GMSlogo[counter++]=ch;

 };
   printf("%s%s%s",logo_open,GMSlogo,logo_close); 


 }


//4
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_menu(void)
{

printf("%s",menu);

}
////////////////////////////////////////////////////////////////////////////////



//5
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_content_open(void)
{

printf("%s",content_open);

}
////////////////////////////////////////////////////////////////////////////////



//6
/////////////////////////////////////////////////////////////////////////////////
  const char LOCATION_TEXT_CONTENT[]="/usr/lib/cgi-bin/base/content/block-content";

void GMS_block_content_post(void)
{
   FILE *fp;
   int ch;
   int point=0;

  if((fp=fopen(LOCATION_TEXT_CONTENT, "r"))==NULL)
  {
    printf("Не удается открыть файл.\n");
    exit(1);
  }

   while((ch=getc(fp))!=EOF) 
   {
   
    
    


     if(ch==':'&&(ch=getc(fp))=='d')
     {
         ch=' ';
         FILE *fp;
         system("touch /tmp/gms-command-out-date");
         fp=fopen("/tmp/gms-command-out-date","r");
         system("date    > /tmp/gms-command-out-date");
         char ch;
         while((ch=getc(fp))!=EOF) 
         {

           // if(ch=='\n'){printf("<br>");};
           printf("%c",ch);

         };
   
           fclose(fp);
           system("cat /dev/null > /tmp/gms-command-out-date");
     };












     if(ch=='#')
     {
         while((ch=getc(fp))!='\n'){};
     };

   if(ch=='\n'&&point==1) 
   {
         printf("<br>"); 
   };

   if(ch=='{'&&point==0){printf("%s",content_post_open); point=1;ch=getc(fp);};

   if(ch=='!'&&point==1)  
   {
         printf("%s",content_title_open);
   
        while((ch=getc(fp))!=EOF) 
        {

            if(ch=='\n')
            { 
                ch=getc(fp); 
                printf("%s",content_title_close);
                break;
            };

            printf("%c",ch);
        };
   };

   if(ch=='}'&&point==1) {ch=getc(fp); printf("%s",content_post_close);  point=0; };
 

   if(ch=='[')
   {
        
        int counter=0;
        printf("%s",code_open);

        while((ch=getc(fp))!=']')
        {

            if(ch=='\n'&&point==1) 
            {
                 printf("<br>"); 
            };

                 printf("%c",ch);
                 counter++;

        //автоперенос вызывыет багу с некоректным отображением
        //if(counter==80){printf(" <br> \n");counter=0; };

        };
       printf("%c",getc(fp));
       ch=' ';
       printf("%s",code_close);
       
     };
   
       if(point==1&&ch!=']') {printf("%c",ch);};
     
    };

      if(point==1){printf("%s",content_post_close);  };

   }
////////////////////////////////////////////////////////////////////////////////



//7
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_content_close(void)
{

printf("%s",content_close);

}
////////////////////////////////////////////////////////////////////////////////


//8
/////////////////////////////////////////////////////////////////////////////////
  const char LOCATION_TEXT_WELCOM[]="/usr/lib/cgi-bin/base/static/block-welcom";
  #define  MAX_LINE_TEXT_WELCOM 500


void GMS_block_welcom(void)
{

FILE *fp;
char ch;
char GMSwelcom[MAX_LINE_TEXT_WELCOM]=" ";
 
  if((fp=fopen(LOCATION_TEXT_WELCOM, "r"))==NULL)
  {
    printf("Опа, что-то пошло не так, \
                  приветствие похоже кто-то съел, \
                  ещё маленько и мы это исправим.");
    exit(1);
  }
    
    int counter=0;

    while((ch=getc(fp))!=EOF) 
 {
    
  if(counter==MAX_LINE_TEXT_WELCOM-1){printf("Опа, что-то пошло не так,\
  похоже кто-то превысил длинну %d символов у приветствия,    \
  ещё маленько и мы это исправим.",MAX_LINE_TEXT_LOGO);};

  if(ch=='\n') 
  {
      GMSwelcom[counter++]='<';
      GMSwelcom[counter++]='b';
      GMSwelcom[counter++]='r';
      GMSwelcom[counter++]='>';
  };
 
      GMSwelcom[counter++]=ch;

 };
   printf("%s%s%s",welcom_open,GMSwelcom,welcom_close); 


 }

////////////////////////////////////////////////////////////////////////////////


//9
/////////////////////////////////////////////////////////////////////////////////
  const char LOCATION_TEXT_NEWS[]="/usr/lib/cgi-bin/base/content/block-news";
  #define MAX_LINE_TEXT_NEWS 1000


void GMS_block_news(void)
{

FILE *fp;
char ch;
char GMSnews[MAX_LINE_TEXT_NEWS]=" ";
 
  if((fp=fopen(LOCATION_TEXT_NEWS, "r"))==NULL)
  {
    printf("Опа, что-то пошло не так, \
                  новости похоже кто-то съел, \
                  ещё маленько и мы это исправим.");
    exit(1);
  }
    
    int counter=0;

    while((ch=getc(fp))!=EOF) 
 {
    
  if(counter==MAX_LINE_TEXT_NEWS-1)
  {
  printf("Опа, что-то пошло не так,\
  похоже кто-то превысил длинну %d символов у новости,    \
  ещё маленько и мы это исправим.",MAX_LINE_TEXT_LOGO);
  break;
  };

  if(ch=='\n') 
  {
      GMSnews[counter++]='<';
      GMSnews[counter++]='b';
      GMSnews[counter++]='r';
      GMSnews[counter++]='>';
  };
 
      GMSnews[counter++]=ch;

 };
   printf("%s%s%s",news_open,GMSnews,news_close); 


 }

////////////////////////////////////////////////////////////////////////////////


//10
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_about(void)
{

printf("%s",about);

}
////////////////////////////////////////////////////////////////////////////////




//10
/////////////////////////////////////////////////////////////////////////////////
void GMS_block_body_close(void)
{

printf("%s",body_close);

}
////////////////////////////////////////////////////////////////////////////////






















