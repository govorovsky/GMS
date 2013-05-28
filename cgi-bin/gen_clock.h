void GMS_block_big_clock_head(void)
{
printf("Content-Type: text/html; charset=utf-8\n\n");
printf("\
\
<!DOCTYPE html>\
<html xmlns=\"http://www.w3.org/1999/xhtml\">\
<head>\
	<title></title>\
	<meta charset=\"utf-8\" />\
    <link href=\"/css/styles.css\" rel=\"stylesheet\" type=\"text/css\">           \
	<link href=\"/css/big_digital-clock.css\" rel=\"stylesheet\" />\
 	<script src=\"/js/jquery.min.js\"></script>\
	<script src=\"/js/big_digital_clock.js\"></script>\
</head>");

};

void GMS_block_big_clock(void)
{
printf("\
<br>\
<br>\
<div id=\"clock\"><center><h1>\
<script type=\"text/javascript\">\
var day=new Date();\
var weekday=new Array(7);\
weekday[0]=\"Воскресенье\";\
weekday[1]=\"Понедельник\";\
weekday[2]=\"Вторник\";\
weekday[3]=\"Среда\";\
weekday[4]=\"Четверг\";\
weekday[5]=\"Пятница\";\
weekday[6]=\"Суббота\";\
document.write(\"Сегодня \" + weekday[day.getDay()]);\
</script> \
</h1></center></div>\
<div id=\"clock\"><a href='index.cgi'><span><center><div class=\"bigtime\"></div></center></span></a> </div>\
<br>\
<br>\
<div  id=\"clock\"> <center><h3><script language=\"JavaScript\" src=\"http://www.epwr.ru/anecdote/data11utf8.js\"></script></h3></center></div>\
\
");
};

















