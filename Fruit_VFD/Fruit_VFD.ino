// Output pins defined.
int CLK = 4;
int DIN = 3;
int RST = 2;

void setup()
{
// Setting the pins as outputs.
pinMode(CLK, OUTPUT);
pinMode(DIN, OUTPUT);
pinMode(RST, OUTPUT);

// Makes shore the display is enabled.
digitalWrite(RST, LOW);
digitalWrite(CLK, HIGH);
sendbyte(0x85);
sendbyte(0x14);
}

void loop()
{
// put your main code here, to run repeatedly:
//digitalWrite(CLK, LOW);
//delay(1);

sendbyte(0xA2);
delay(1);
sendbyte(0x54);
delay(100);
sendbyte(0x48);
delay(100);
sendbyte(0x45);
delay(100);
sendbyte(0x20);
delay(100);
sendbyte(0x45);
delay(100);
sendbyte(0x50);
delay(100);
sendbyte(0x52);
delay(100);
sendbyte(0x4F);
delay(100);
sendbyte(0x4D);
delay(100);
sendbyte(0x39);
delay(100);
sendbyte(0x20);
delay(100);
sendbyte(0x20);
delay(100);
sendbyte(0x20);
delay(100);
delay(2000);
//Serial1.println("Hello! Can anybody hear me?");  // Print "Hello!" over hardware UART
}

void sendbyte(uint8_t d_chr)
{
unsigned char bit_cnt;
  for(bit_cnt=0; bit_cnt<8; bit_cnt++)
  {
    if(d_chr & 0x80) digitalWrite(DIN,HIGH);
    else digitalWrite(DIN,LOW);
  d_chr <<= 1;
  digitalWrite(CLK,LOW);
  digitalWrite(CLK,HIGH);
  }
}

void Reset_VFD(void)
{
digitalWrite (RST, HIGH );
delay(10);
digitalWrite (CLK, HIGH);
digitalWrite (RST, LOW );
delay(50);
}
