
int colred=2;
int colgreen=3;
int colblue=4;
int avg_val;
int black_red_val;
int black_blue_val;
int black_green_val;
int final_red_val;
int final_green_val;
int final_blue_val;
int red_val;
int green_val;
int blue_val;
int white_red_val;
int white_green_val;
int white_blue_val;
double k;
double o;









void setup() 
{
  delay(5000);
  Serial.begin(9600);
  pinMode(colred,OUTPUT);
  pinMode(colblue,OUTPUT);
  pinMode(colgreen,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(colred,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colred,LOW);
  black_red_val=avg_val;
  delay(200);
  digitalWrite(colgreen,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colgreen,LOW);
  black_green_val=avg_val;
  delay(200);
  digitalWrite(colblue,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colblue,LOW);
  black_blue_val=(avg_val);
  delay(200);
  Serial.print(black_red_val);
  Serial.print(" ");
  Serial.print(black_green_val);
  Serial.print(" ");
  Serial.print(black_blue_val);
  Serial.println();
  
  delay(8000);
  digitalWrite(colred,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colred,LOW);
  white_red_val=avg_val;
  delay(200);
  digitalWrite(colgreen,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colgreen,LOW);
  white_green_val=avg_val;
  delay(200);
  digitalWrite(colblue,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colblue,LOW);
  white_blue_val=avg_val;
  delay(200);

  Serial.print(white_red_val);
  Serial.print(" ");
  Serial.print(white_green_val);
  Serial.print(" ");
  Serial.print(white_blue_val);
  Serial.println();
  delay(5000);
  
}

void loop() {
  digitalWrite(colred,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colred,LOW);
  final_red_val=avg_val;
  delay(200);
  digitalWrite(colgreen,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colgreen,LOW);
  final_green_val=avg_val;
  delay(200);
  digitalWrite(colblue,HIGH);
  delay(200);
  takeReading(5);
  digitalWrite(colblue,LOW);
  final_blue_val=avg_val;
  delay(200);
  Serial.print(final_red_val);
  Serial.print(" ");
  Serial.print(final_green_val);
  Serial.print(" ");
  Serial.print(final_blue_val);
  k=((final_red_val-black_red_val));
  o=(white_red_val-black_red_val);
  red_val=k/o;
  red_val=(k/o)*255;
  red_val=manipulate(red_val);
  k=((final_green_val-black_green_val));
  o=(white_green_val-black_green_val);
  green_val=k/o;
  green_val=(k/o)*255;
  green_val=manipulate(green_val);
  k=((final_blue_val-black_blue_val));
  o=(white_blue_val-black_blue_val);
  blue_val=k/o;
  blue_val=(k/o)*255;
  blue_val=manipulate(blue_val);
  Serial.print(" ");
  
  
  Serial.print(" R = "); 
  Serial.print(red_val);
  Serial.print(" G = ");
  Serial.print(green_val);
  Serial.print(" B = ");
  Serial.print(blue_val);
  Serial.println();

  
}
void takeReading(int times)
{
  int val=0;
  avg_val=0;
  for(int i=1;i<=times;i++)
  {
   val=val+analogRead(A0); 
  }
  avg_val=(int)(val/times);
}
int manipulate(int l)
{
  if (l<0)
  {
    return 0;
  }
  else if(l>255)
  {
    return 255;
  }  else
 {
    return l;
  }
}
  
    
  
