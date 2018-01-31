#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int read_count=0;
int j=0,k=0; // Variables to iterate in for loops
char data_temp, RFID_data[12];
char Saved_Tags[2][8]={
                       {'0','7','5','3','8','3','8','9'},
                       {'0','7','5','4','0','4','9','3'}};
boolean tag_check,tag_status,entry_control;
void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
}

void loop()
{
RecieveData();
CheckData();
AccessCheck();
}

void RecieveData()
{
if(mySerial.available()>0)
{
data_temp=mySerial.read();
RFID_data[read_count]=data_temp;
read_count++;
}}

void CheckData()
{
if(read_count==8)
{
entry_control=true;  
for(k=0;k<2;k++)
{
for(j=0;j<8;j++)
{
  if(Saved_Tags[k][j]==RFID_data[j])
 {
  tag_check=true;
  }
  else
  {
  tag_check=false;
  break;
  }
}
if(tag_check==true)
{
tag_status=true;
}}
read_count=0;
}}

void AccessCheck()
{
if(entry_control==true)
{
if(tag_status==true)
{
  if(digitalRead(8)==HIGH)
  {
Serial.println("led is on");
}
else
{ 
  Serial.println("led is off");
  }

}
}

entry_control=false;
tag_status=false;
}

