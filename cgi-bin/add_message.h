
void GMS_add_message(void)
{



char msg_form[]="\
  <label for=\"msg-title\">Заглавие:</label>\
  <br>\
  <input type=text id=\"message_title\" name=msg-title value="">\
  <br>\
  <label for=\"title\">Сообщение:</label>\
  <br>\
  <textarea id=\"message\" required name=\"title\"></textarea>\
  <br>\
  <br>\
  <button type=title>Поместить</button>\
  <button type=submit name=preview>Предпросмотр</button>\
  <button type=reset name=cancel id=\"cancelButton\">Отменить</button>\
  <p>Ознакомьтесь с правилами разметки <a href='/cgi-bin/index.cgi?set=bdcode'><span>BDCODE</span></a></p>\
  ";


printf("%s",msg_form);










};
