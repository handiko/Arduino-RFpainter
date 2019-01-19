/*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <avr/pgmspace.h>

#define CLK   11
#define FQ    10
#define DATA  9
#define RST   8

#define D0    7
#define D1    7
#define D2    6

#define TD    1

unsigned long freq=35000000;

#define CAT_WIDTH  134
#define CAT_HEIGHT 95
const byte cat[CAT_HEIGHT][CAT_WIDTH + 1] PROGMEM = {
"                                                              aaaaaa                                         aa                       ",
"                                                              aa  aaaa                                     aaaaaa                     ",
"                                                              a     aaaa                                 aaaa  aaa                    ",
"                                                              aa      aaaa                              aaa     aa                    ",
"                                                              aa  aaa  aaaa                           aaa        aa                   ",
"                                                              aa    aa  aaaaa                        aaa    aa   aa                   ",
"                                                               a   aaaa  aaaaaa                     aaa     aaa  aa                   ",
"                                                               aa    aa   a  aaa                    aa   aaaaaaa aa                   ",
"                                                               aa   aaa    a  aaaa                 aa    aaaaaaa aa                   ",
"                                                                a    aaa    a   aaa               aa    aaa aa   aa                   ",
"                                                                aa   aaaa    a   aaaaaaaaaaaaaaaaaa      aaa     aa                   ",
"                                                                aa     aa     a    aaaa        aaaa    a  a      aa                   ",
"                                                                 aa  aaaa    aa  aa    a      aaaa      aaaa a   aa                   ",
"                        aaaaaaa                                  aa   aaa     a       a      aa a     aaaaa a    aa                   ",
"                      aaaaaaaaaa                                  a   aaaa           aa    aaa         aa   a    aa                   ",
"                     aaaa     aa                                  aa  aaaa       aa  a   aaaa         aaaa      aaa                   ",
"                   aaaa        a                                  aa a aa       aa   a  aaaa           aaa  a   aaa                   ",
"                  aaaa         a                                   aaa aaa      a      aa aa            a  aa  aaaa                   ",
"                 aaaa          a                                   aaa aa      aa   a aaa a                a   a aa                   ",
"                aaa a         aa                                   aa aa a     aa     aa aa                 a aa aa                   ",
"                aa           aa                                     a a a     aa    a aa a                   aa  aa                   ",
"               aa a         aaa                                     aa aa   aaaa     aa  a                   a   a                    ",
"              aa  aa        aa                                      aa a   aaaa      a  aa aa               aa   a                    ",
"              aa  aa       aaa                                      aaaa  aaaaa        aa  a                 a   a                    ",
"             aa  a        aaa                                       a aa  aa a         aa aa                 aa  a                    ",
"             aa  a       aaa                                        a    a   a        aaaaa                   aa aa                   ",
"            aa   a        aa                                       aa  aaaa  a        aa                       a aa                   ",
"            aa   a       aa                                        aa  aaaaa a        a   aa                     aa                   ",
"            aa           aa                                        aa  a  aaa          aaaaaaa                   aaa                  ",
"           aa           aaa                                        aa  a aaaa         aa  a  aa                 aaaaa                 ",
"           aa           aa                                         aaaaaa a a         aa  a   a  aaa            aaaaaa                ",
"           aa           aa                                         aaa aa   a        aaa  a  a  aaaaaaaaaaa     aa  aaa               ",
"           aa           aa                                         aaaaaaaaaa        aaa    aa     aaaaaaaaaa  aaa  aaaa              ",
"           aa           aa                                         aa     aaa       aaaaaaaaa     aaaa      aa  aa  a aaa             ",
"           aa           aa                                         aa       a       a    aa      aaa          aaaa  a  aaa            ",
"           aa           aa                                         aa aa   aa       a   aa aaaaaaaa            aaa a    aaa           ",
"           aa           aa                                          aaa    a           aaaa                    aaa       aa           ",
"           aa           aa                                          aa     a               aaa aaaaaaa       aaaa a       aa          ",
"            aa           a                                           a a  aa     aa    a   aaaaaaa           aaaaaa       aa          ",
"            aa           aa                                      aaaaaaa  aaaaaaaa      aaa                  aa  a        aa          ",
"            aa           aa                                     a aaaaaa  aa a aaa       aaaaaaa           aaaaaa         aaa         ",
"            aaa          aa                                 aaaaaaaaaaaaa aaa aaa   aa a  a aaaa          aaaaa           aa          ",
"             aaa          aa                          aaaaaaaaaaaaaaaaaaaaa aaaa        a aaa   aa         aaa             aaa        ",
"              aaa          aa                    aaaaaaaaaaaaaaa a    aaaaaa aa    a aaaa    aaa aa      aaaaa       aa    aaaa       ",
"              aaaa         aaaa               aaaaaaa a  aa      a aa aaaaa  a  a aa  aa  aaa    aaa    aaaaaa    aaaaa    aaaaa      ",
"               aaaa         aaa             aaaaa       a         aaa  aaaa  aa    aaa  a   a      a    aaaaa   aaaaaa      aaaa      ",
"                aaaa         aaaaa       aaaaa           a     aa      aaaaaaaaa    aaa aaa  aaa   aa   aaa a  aaaa         aa aa     ",
"                aaaaaa         aaaaaaaaaaaa            aa    a        aaaaa  a  aaaaa aaa aa   a      aaaa   aaaa            a aa     ",
"                 aaa aaaa        aaaaaaaaa             aa  a        aa  aaaa a      a  aa   a   a      aa    aa              a  aa    ",
"                  aaa  a       aaaaaa   a              a           a   aa  aaa      a   aa   a      aaaaa   aa               a  aa    ",
"                   aaaa a   aaaaaaa    a        a      a       a  a    a   aaaa          aaaaaaaaaaa aa    aaa  a            a   aa   ",
"                    aaaaaaaaaaaa a a a a         a    a  a       a    a    aa aaaaaaaaaaaaaaaaaa     a a  aaa  a     a           aa   ",
"                     aaaaaaaa  aa    aaaa        aaaaa   aaa       aaaa aaa  aaaaaaaaaa aa   aaaaaa    aaaaa    aaa     aa     aaa    ",
"                    aaaaa                      a                          aaa a     aaaaaaaa    a    a  aaaa                      aa  ",
"              aaaaaaaaa               a        a                          aa   aa      aaa  a    a  a aaaaa                       aa  ",
"         aaaaaaaaaa             a     a       a                          aaa    aaaa     a        aaaaaaa              a          aaa ",
"       aaaaaa                                a                           aa      a           a   aaaaaa                aa         aaa ",
"     aaaa                       aaaaaaaa    a                            aa       aaa         aaaaaa                    aa        aaa ",
"    aaa                 aaaaaaaaaaaaaaaaaaa     aaaa                    aa         aa        aaa                         aa       aaa ",
"   aa                 aaaa              aaaaaaaaaaaa                    aa          aa      aaa                aaa        a       a aa",
"  aaaa             aaaaa                          aa                    a           aa      a               aaaa          aa        aa",
" aaa           aaaaaa                             a                    aa a aa       aa                   aaaaa           aa        aa",
" aa          aaaa                                 a                    aaa aa aa      a                 aaaa               aa     a aa",
"aa aa       aaa                                 a                      aaa aaaaa     a                aaaa                 aa    aaaa ",
"aaaa       aaaaaa                             a a                     aaa    aaaaa    a              aaaa                  aa    a aa ",
"aaa      a aaaa                                a                      aa      aaaa    a              aaa                   aa   aa aa ",
" aa    aa aaa                                 a    a                 aaa       aaaa   a             aa                      a   a  aa ",
"  aaaaaa aaaaa                              aaa    a                aaaaaa      aa a               aa                      aaa    aa  ",
"   aaaaaaaaaaaaa                   aaaaa aaaa                      aaaaaaaaa     aa aa            aa                        aaaa  aa  ",
"       aa aaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa        aa   aaaaa     aaaa            aa                        aaaa  aa  ",
"          aaaaaa   aa aaaaa   aaa          aaaaaaaaaaaaaaa        aa  aaaaaa a    aa aa           a                          aaa  aa  ",
"           aaaaaaaaaaaaa                                aaaaaaaaaaa        aaaaa  aaaaa                                     a aa  aa  ",
"             aaaaaaaaa                                     aaaaaaaa          aaaa  aaaa                                      aaaaaa   ",
"                                                                aa            aaa  aaaaa                                 a    aaaaa   ",
"                                                                aaaaaa          aa  aaaa               aaaa aaaaaaaaaaa        aaaa   ",
"                                                               aa    aa         aa   aaa         aaaaaaaaaaaaaaaaaaaaa    a     aaa   ",
"                                                             aaaa               aa    aaa    aaaaaaa           aaaa        a    aaa   ",
"                                                           aaaaaaaa            a  aa aaaaa aaaaaaaa      a        aa       aa    aa   ",
"                                                          aaaa               a    aaaaaaaaaaa aaaaaaa     a        aa      aa    aa   ",
"                                                         aaa                a    aaaa  aaaa     aa aa     aa        a       aa    aa  ",
"                                                        aaa                aa  aaa  aaaaa        aa aa     aa        a      aa    aa  ",
"                                                        aaa  aa    a       a aaaaaaaaaaa                    aa       a     aaa    aa  ",
"                                                        aaa  aa   aa      aaaaaaaa   aaaaaa                 aaa       a    aa     aa  ",
"                                                        aaaa aa a aa  a   aaaaaa         a a           a    aaa       a    a a  aaaa  ",
"                                                        a aa a  a  a  a   aaaaa  a           a         a     aa      a    aaaaaaaaa   ",
"                                                        aaaaaa  a a  aaa aaaaa  aa   a                       aa     aa aaaaaaaaa      ",
"                                                        aaaaaaaaa a  aaaaaaaaa aa   aa                  a    aaaaaaaaaaaaaaaa         ",
"                                                         aaaaa aaaaaaaaaaa aaa aa   a   a aa            aaaaaaaaaaaaaaaa              ",
"                                                          aaaaaaaaaaaaaa   aaa a  aaa  aa a           aaaaaaaaa                       ",
"                                                           aaaaaaaaaaa     aaa a  a a  a aa         aaaaaaa                           ",
"                                                                           aaaaaa a a  a          aaaaa                               ",
"                                                                            aaaaaaaaaa aaaaa    aaaa                                  ",
"                                                                              aaaaaaa aaa  aaaaaaa                                    ",
"                                                                                   aaaaaaaaaaaaa                                      ",
"                                                                                      aa  aa                                          "
};


void dds_init(void);
void dds_reset(void);
void writeFreq(unsigned long in_freq);
void drawCat(unsigned long in_freq, int scale, int repeat);

void dds_init(void)
{
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(FQ, OUTPUT);
  pinMode(CLK, OUTPUT);

  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);

  digitalWrite(RST, HIGH);
  digitalWrite(DATA, HIGH);
  digitalWrite(FQ, LOW);
  digitalWrite(CLK, LOW);
}

void dds_reset(void)
{
  digitalWrite(CLK, LOW);
  digitalWrite(FQ, LOW);
  digitalWrite(DATA, LOW);

  digitalWrite(RST, LOW); delayMicroseconds(5);
  digitalWrite(RST, HIGH);delayMicroseconds(5);
  digitalWrite(RST, LOW); delayMicroseconds(5);

  digitalWrite(CLK, LOW); delayMicroseconds(5);
  digitalWrite(CLK, HIGH);delayMicroseconds(5);
  digitalWrite(CLK, LOW); delayMicroseconds(5);

  digitalWrite(DATA, LOW);

  digitalWrite(FQ, LOW);  delayMicroseconds(5);
  digitalWrite(FQ, HIGH); delayMicroseconds(5);
  digitalWrite(FQ, LOW);
}

void writeFreq(unsigned long in_freq)
{
  unsigned long data_word = ((in_freq * 4294967296UL ) / 180000000UL); 
  boolean bits;

  digitalWrite(FQ, HIGH); delayMicroseconds(TD);
  digitalWrite(FQ, LOW);

  Serial.print("Set Frequency :");
  Serial.print(in_freq);
  Serial.println(" Hz");

  for(int i=0; i<32; i++)
  {
    bits = ((data_word >> i) & 0x01);
    digitalWrite(DATA, bits);

    delayMicroseconds(TD);
    
    digitalWrite(CLK, HIGH);
    delayMicroseconds(TD);
    digitalWrite(CLK, LOW);
  }

  Serial.print(' ');

  for(int i=0; i<8; i++)
  {
    if(i<1)
      digitalWrite(DATA, HIGH);
    else
      digitalWrite(DATA, LOW);

    delayMicroseconds(TD);
    
    digitalWrite(CLK, HIGH);
    delayMicroseconds(TD);
    digitalWrite(CLK, LOW);
  }

  delayMicroseconds(TD);
    
  digitalWrite(FQ, HIGH);
  delayMicroseconds(TD);
  digitalWrite(FQ, LOW);

  return;
}


void drawCat(unsigned long in_freq, int scale, int repeat)
{
  char c;
  
  for(int i=CAT_HEIGHT-1;i>-1;i--)
  {
    for(int k=0;k<repeat;k++)
    {
      for(int j=0;j<CAT_WIDTH;j++)
      {
        c = pgm_read_byte(&(cat[i][j]));
        
        if(isAscii(c) && !isSpace(c) && !isWhitespace(c))
        {
          writeFreq((unsigned long)(in_freq + j*scale*100UL));
        }
        
        else if(isSpace(c) || isWhitespace(c))
        {
          writeFreq(1000);
        }
      }
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println(" ");
  
  delay(2000);

  dds_init();
  dds_reset();
  writeFreq(freq);
}

void loop()
{
  //void drawCat(unsigned long in_freq, int scale, int repeat)
  drawCat(35000000, 3, 9);
  delay(5000);
}
